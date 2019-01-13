#pragma once
#include<string>
#include<iostream>


class TrainLeg
{
	const int trainId;
	const int departureStationId;
	const int arrivalStationId;
	const double price;
	const std::string arrivalTimeString;
	const std::string departureTimeString;

	TrainLeg(const TrainLeg&);
	TrainLeg & operator = (const TrainLeg&);
public:
	TrainLeg(int,int,int,double,std::string,std::string);

	int getTrainId() const;
	int getDepartureStationId() const;
	int getArrivalStationId() const;
	double getPrice() const;
	std::string getArrivalTimeString() const;
	std::string getDepartureTimeString() const;

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

inline std::string TrainLeg::getArrivalTimeString() const
{
	return arrivalTimeString;
}

inline std::string TrainLeg::getDepartureTimeString() const
{
	return departureTimeString;
}
