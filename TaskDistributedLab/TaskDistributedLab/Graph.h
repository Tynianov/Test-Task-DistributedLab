#pragma once
#include<vector>
#include<stack>
#include"Edge.h"

typedef std::pair<double, Time> BestLeg;

bool isVectorContains(std::vector<int>, int);
Edge * finMinLeg(std::vector<Edge*>, int, int);

class Graph
{
	std::vector<int> vertices;
	std::vector<Edge*> edges;
	BestLeg **shortesDistanceMatrix;
	int **path;
	Edge **legs;

public:
	Graph(std::vector<TrainLeg*>);
	~Graph();

	void allShortestPath();
	void printPath(int,int);
	int getAmountOfVertices();
	int getAmountOfEdges();
};

inline int Graph::getAmountOfVertices()
{
	return vertices.size();
}

inline int Graph::getAmountOfEdges() {
	return edges.size();
}


