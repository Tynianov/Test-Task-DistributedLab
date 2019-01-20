#pragma once
#include<string>
#include"Time.h"

class TrainLeg
{
	const int trainId;
	const int departureStationId;
	const int arrivalStationId;
	const double price;
	Time arrivalTimeString;
	Time departureTimeString;

	TrainLeg(const TrainLeg&);
	TrainLeg & operator = (const TrainLeg&);
public:
	TrainLeg(int, int, int, double, std::string, std::string);

	int getTrainId() const;
	int getDepartureStationId() const;
	int getArrivalStationId() const;
	double getPrice() const;
	Time getArrivalTimeString() const;
	Time getDepartureTimeString() const;

};

std::ostream & operator <<(std::ostream & stream, const TrainLeg & trainLeg);

inline int TrainLeg::getTrainId() const {
	return trainId;
}

inline int TrainLeg::getDepartureStationId() const
{
	return departureStationId;
}

inline int TrainLeg::getArrivalStationId() const
{
	return arrivalStationId;
}

inline double TrainLeg::getPrice() const
{
	return price;
}

inline Time TrainLeg::getArrivalTimeString() const
{
	return arrivalTimeString;
}

inline Time TrainLeg::getDepartureTimeString() const
{
	return departureTimeString;
}
