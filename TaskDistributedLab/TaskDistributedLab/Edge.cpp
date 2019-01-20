#include "Edge.h"

Edge::Edge() : fromVertex(-1), toVertex(-1), price(INFINITY), trainID(-1), departureTimeString(), arrivalTimeString(), totalTime()
{
}

Edge::Edge(int from, int to, double p, int id, Time depTime, Time arrTime) :	fromVertex(from),
																							toVertex(to), 
																							price(p), 
																							trainID(id),
																							departureTimeString(depTime),
																							arrivalTimeString(arrTime)
{
	if (!from || !to)
		throw std::logic_error("Id of the station can't be negative!");

	if (!p)
		throw std::logic_error("Price of the ticket can't be negative");

	if (!id)
		throw std::logic_error("Id of the train can't be negative");

	Time day("24:00:00");
	totalTime = day -= (departureTimeString - arrivalTimeString);

}

Edge & Edge::operator=(const Edge & edge) {
	
	this->fromVertex = edge.fromVertex;
	this->toVertex = edge.toVertex;
	this->trainID = edge.trainID;
	this->price = edge.price;
	this->arrivalTimeString = edge.arrivalTimeString;
	this->departureTimeString = edge.departureTimeString;
	this->totalTime = edge.totalTime;

	return *this;
}

std::ostream & operator<<(std::ostream &stream, const Edge &edge)
{
	std::cout	<<"Train ID: " <<edge.getTrainID()<<" From: "<< edge.getFromVertex()
				<< " To: " << edge.getToVertex() << " Price: " << edge.getPrice()
				<< " Dep.Time: " << edge.getDepTime() << " Arr.Time: " << edge.getArrTime();

	return stream;
}
