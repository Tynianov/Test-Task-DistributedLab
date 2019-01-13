#pragma once
#include<vector>
#include<stack>
#include"Edge.h"

bool isVectorContains(std::vector<int>, int);
Edge * finMinLeg(std::vector<Edge*>, int, int);

class Graph
{
	std::vector<int> vertices;
	std::vector<Edge*> edges;
	double **shortesDistanceMatrix;
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


