#pragma once
#include"TrainLeg.h"

class Edge
{
	int fromVertex;
	int toVertex;
	double price;
	int trainID;
	Time arrivalTimeString;
	Time departureTimeString;
	Time totalTime;

public:
	Edge();
	Edge(int, int, double, int, Time, Time);

	int getFromVertex() const;
	int getToVertex() const;
	double getPrice() const;
	int getTrainID() const;
	Time getDepTime() const;
	Time getArrTime() const;
	Time getTotalTime() const;

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

inline Time Edge::getDepTime() const
{
	return departureTimeString;
}

inline Time Edge::getArrTime() const
{
	return arrivalTimeString;
}

inline Time Edge::getTotalTime() const
{
	return totalTime;
}

