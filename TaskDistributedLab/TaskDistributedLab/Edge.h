#pragma once
#include"TrainLeg.h"

class Edge
{
	int fromVertex;
	int toVertex;
	double price;
	int trainID;
	std::string arrivalTimeString;
	std::string departureTimeString;

public:
	Edge();
	Edge(int, int, double, int, std::string, std::string);

	int getFromVertex() const;
	int getToVertex() const;
	double getPrice() const;
	int getTrainID() const;
	std::string getDepTime() const;
	std::string getArrTime() const;

	Edge & operator=(const Edge&);
};

std::ostream & operator<<(std::ostream &, const Edge&);

inline int Edge::getFromVertex() const
{
	return fromVertex;
}

inline int Edge::getToVertex() const
{
	return toVertex;
}

inline double Edge::getPrice() const
{
	return price;
}

inline int Edge::getTrainID() const
{
	return trainID;
}

inline std::string Edge::getDepTime() const
{
	return departureTimeString;
}

inline std::string Edge::getArrTime() const
{
	return arrivalTimeString;
}

