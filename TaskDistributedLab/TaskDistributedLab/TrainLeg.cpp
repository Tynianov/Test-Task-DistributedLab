#include "TrainLeg.h"

TrainLeg::TrainLeg(	int _tId, int _depStatID, int _arrStatID, 
					double _price, std::string _arrTime, std::string  _depTime) : trainId(_tId),
																				 departureStationId(_depStatID),
																				 arrivalStationId(_arrStatID),
																				 price(_price),
																				 arrivalTimeString(_arrTime),
																				 departureTimeString(_depTime)
																				 
{
	if (!_tId)
		throw std::logic_error("Id of the train can't be negative");

	if (!_depStatID)
		throw std::logic_error("Id of the departure station can't be negative");

	if (!_arrStatID)
		throw std::logic_error("Id of the arrivial station can't be negative");

	if (!_price)
		throw std::logic_error("Price of the ticket can't be negative");
}

std::ostream & operator<<(std::ostream & stream, const TrainLeg & trainLeg) {
	
	stream << trainLeg.getTrainId() << " " << trainLeg.getArrivalStationId() << " "
		<< trainLeg.getDepartureStationId() << " " << trainLeg.getPrice() << " "
		<< trainLeg.getArrivalTimeString() << " " << trainLeg.getDepartureTimeString() << std::endl;

	return stream;
}