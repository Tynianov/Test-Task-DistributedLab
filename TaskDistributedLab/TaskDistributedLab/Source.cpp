#include"Graph.h"
#include"tinyxml2.h"
#include"Time.h"

void readXMLFile(const char*, std::vector<TrainLeg*>&); 

using namespace tinyxml2;

int main() {

	try
	{
		std::vector<TrainLeg*> trainLegs;
		readXMLFile("data.xml", trainLegs);
		Graph graph(trainLegs);
		graph.allShortestPath();

	}
	catch (const std::invalid_argument & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::logic_error & e) 
	{
		std::cout << e.what() << std::endl;
	}

	/*
	Time t1("01:00:00");
	Time t2("10:01:00");
	Time t;
	//Time t3 = t1 - t2; 
	//Time t4("24:00:00"); 
	//t4 -= t3;
	//std::cout << t4;
	/*Edge e(10, 11, 100.0, 20, t1, t2);
	std::cout << e << std::endl;
	std::cout << e.getTotalTime();
	std::cout << (t > t1);
	*/

	system("pause");
	return 0;
}

void readXMLFile(const char *filePath, std::vector<TrainLeg*> & vec)
{
	XMLDocument xmlDoc;
	xmlDoc.LoadFile(filePath);
	XMLElement *trainLegs = xmlDoc.FirstChildElement("TrainLegs");

	if (trainLegs) {

		int trainId, depStationId, arrStationId;
		double price;
		std::string depTimeString, arrTimeString;

		for (XMLElement *tLeg = trainLegs->FirstChildElement("TrainLeg"); tLeg; tLeg = tLeg->NextSiblingElement("TrainLeg")) {
			trainId = tLeg->IntAttribute("TrainId");
			depStationId = tLeg->IntAttribute("DepartureStationId");
			arrStationId = tLeg->IntAttribute("ArrivalStationId");
			price = tLeg->DoubleAttribute("Price");
			arrTimeString = tLeg->Attribute("ArrivalTimeString");
			depTimeString = tLeg->Attribute("DepartureTimeString");

			vec.push_back(new TrainLeg(trainId, depStationId, arrStationId, price, arrTimeString, depTimeString));
		}

	}
}


