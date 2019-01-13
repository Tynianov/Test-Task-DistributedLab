#include "Edge.h"

Edge::Edge() : fromVertex(-1), toVertex(-1), price(INFINITY), trainID(-1), departureTimeString(" "), arrivalTimeString(" ")
{
}

Edge::Edge(int from, int to, double p, int id, std::string depTime, std::string arrTime) :	fromVertex(from),
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

	if (!depTime.size() || !arrTime.size())
		throw std::logic_error("Length of the time string can't be empty!");
}

Edge & Edge::operator=(const Edge & edge) {
	
	this->fromVertex = edge.fromVertex;
	this->toVertex = edge.toVertex;
	this->trainID = edge.trainID;
	this->price = edge.price;
	this->arrivalTimeString = edge.arrivalTimeString;
	this->departureTimeString = edge.departureTimeString;

	return *this;
}

std::ostream & operator<<(std::ostream &stream, const Edge &edge)
{
	std::cout	<<"Train ID: " <<edge.getTrainID()<<" From: "<< edge.getFromVertex()
				<< " To: " << edge.getToVertex() << " Price: " << edge.getPrice()
				<< " Dep.Time: " << edge.getDepTime() << " Arr.Time: " << edge.getDepTime();

	return stream;
}
