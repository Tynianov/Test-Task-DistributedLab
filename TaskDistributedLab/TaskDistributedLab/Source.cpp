#include"Graph.h"
#include"tinyxml2.h"

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


