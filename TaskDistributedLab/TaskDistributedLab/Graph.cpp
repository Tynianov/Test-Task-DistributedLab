#include "Graph.h"

Graph::Graph(std::vector<TrainLeg*> vec)
{
	int arrStation, depStation, trainId;
	double price;
	int _size;
	Time arrivalTimeString, departureTimeString;

	for (int i = 0; i < vec.size(); i++) {
		depStation = vec[i]->getDepartureStationId();
		arrStation = vec[i]->getArrivalStationId();
		trainId = vec[i]->getTrainId();
		price = vec[i]->getPrice();
		arrivalTimeString = vec[i]->getArrivalTimeString();
		departureTimeString = vec[i]->getDepartureTimeString();
		_size = vertices.size();

		if (!isVectorContains(vertices, depStation))
			vertices.push_back(depStation);

		if (!isVectorContains(vertices, arrStation))
			vertices.push_back(arrStation);

		edges.push_back(new Edge(depStation, arrStation, price, trainId, departureTimeString, arrivalTimeString));
	}

	shortesDistanceMatrix = new BestLeg*[_size];
	path = new int*[_size];
	legs = new Edge*[_size];

	for (int i = 0; i < _size; i++) {
		shortesDistanceMatrix[i] = new BestLeg[_size];
		path[i] = new int[_size];
		legs[i] = new Edge[_size];
	}

	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++) 
			shortesDistanceMatrix[i][j].first = INFINITY;

}

Graph::~Graph()
{
	for (int i = 0; i < edges.size(); i++)
		delete edges[i];

	for (int i = 0; i < vertices.size(); i++) {
		delete[]shortesDistanceMatrix[i];
		delete[]path[i];
		delete[]legs[i];
	}

	delete[]legs;
	delete[]path;
	delete[]shortesDistanceMatrix;
}

void Graph::allShortestPath() {

	int _size = vertices.size();
	Edge edge;

	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			edge = *(finMinLeg(edges, vertices[i], vertices[j]));
			if (vertices[i] != vertices[j] && edge.getPrice() != INFINITY) {
				shortesDistanceMatrix[i][j].first = edge.getPrice();
				shortesDistanceMatrix[i][j].second = edge.getTotalTime();
				legs[i][j] = edge;
				path[i][j] = i;
			}

			else {
				shortesDistanceMatrix[i][j].first = INFINITY;
				shortesDistanceMatrix[i][j].second = Time();
				path[i][j] = -1;
				legs[i][j] = *new Edge(1, 1, INFINITY, 1, Time(), Time());
			}
		}
	}

	for (int k = 0; k < _size; k++)
		for (int i = 0; i < _size; i++)
			if (shortesDistanceMatrix[i][k].first != INFINITY) {

				for (int j = 0; j < _size; j++) {

					if (shortesDistanceMatrix[i][j].first > shortesDistanceMatrix[i][k].first + shortesDistanceMatrix[k][j].first &&
						shortesDistanceMatrix[i][j].second > shortesDistanceMatrix[i][k].second + shortesDistanceMatrix[k][j].second) {
						shortesDistanceMatrix[i][j].first = shortesDistanceMatrix[i][k].first + shortesDistanceMatrix[k][j].first;
						shortesDistanceMatrix[i][j].second = shortesDistanceMatrix[i][k].second + shortesDistanceMatrix[k][j].second;
						shortesDistanceMatrix[i][j].second += legs[k][j].getDepTime() - legs[i][k].getArrTime();
						path[i][j] = path[k][j];
						legs[i][j] = legs[k][j];
					}
				}
			}

	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			if (i != j)
				printPath(i, j);
}

void Graph::printPath(int start,int end)
{
	if (start < 0 || end < 0 || start >= vertices.size() || end >= vertices.size()) 
		throw std::invalid_argument("Invalid function parameters!");

	if (path[start][end] < 0)
		std::cout << "No actual path between " << vertices[start] << " and " << vertices[end] << std::endl;

	else
		std::cout	<< vertices[start] << " -> " << vertices[end] << "\tPrice: " << shortesDistanceMatrix[start][end].first
					<< "\tTotal time in road: " << shortesDistanceMatrix[start][end].second << std::endl;

	Edge e;
	std::stack<int> stack;
	std::stack<Edge> eStack;
	stack.push(end);
	while (true) {
		e = legs[start][end];
		end = path[start][end];
		if (end == -1) 
			return;
		
		stack.push(end);
		eStack.push(e);

		if (end == start) 
			break;
		
	}
	
	while (!eStack.empty())
	{
		std::cout << eStack.top() << std::endl;
		eStack.pop();
	}

	std::cout << std::endl;
	
}

bool isVectorContains(std::vector<int> vec, int element)
{
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == element)
			return true;

	return false;
}

Edge * finMinLeg(std::vector<Edge*> edges,int fromVert, int toVert)
{
	double minPrice = INT_MAX;
	Time minTime;
	Edge *e = new Edge();
	for (int i = 0; i < edges.size(); i++)
		if (edges[i]->getFromVertex() == fromVert && edges[i]->getToVertex() == toVert) {
			if (edges[i]->getPrice() < minPrice && edges[i]->getTotalTime() < minTime) {
				minPrice = edges[i]->getPrice();
				minTime = edges[i]->getTotalTime();
				e = edges[i];
			}
		}

	return e;
}
