# include "Database.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list
Database::Database() : stateParkList{vector<StatePark*>()}, camperList{vector<Passport*>()} {}

Database::~Database() {
	for (unsigned int i = 0; i < stateParkList.size(); ++i) {
		delete stateParkList.at(i);
	}
	
	for (unsigned int i = 0; i < camperList.size(); ++i) {
		delete camperList.at(i);
	}
}

void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
	INFO(parkName)
	INFO(entranceFee)
	INFO(trailMiles)

	// TODO: implement function
	this->stateParkList.push_back(new StatePark(parkName, entranceFee, trailMiles));

	return;
}

void Database::addPassport(string camperName, bool isJuniorPassport) {
	INFO(camperName)
	INFO(isJuniorPassport)

	// TODO: implement function
	this->camperList.push_back(new Passport(camperName, isJuniorPassport));

	return;
}

void Database::addParkToPassport(string camperName, string parkName) {
	INFO(camperName)
	INFO(parkName)

	// TODO: implement function
	Passport* camper = nullptr;
	StatePark* park = nullptr;

	for (Passport* p : this-> camperList) {
		if (p->getCamperName() == camperName) {
			camper = p;
			break;
		}
	}

	for (StatePark* p : this->stateParkList) {
		if (p->getParkName() == parkName) {
			park = p;
			break;
		}
	}
	camper->addParkVisited(park);

	return;
}

vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) {
	INFO(lowerBound)
	INFO(upperBound)

	// TODO: (optional) implement function
	
	return {};
}

vector<string> Database::getHikersAtLeastLevel(int level) {
	INFO(level)

	// TODO: (optional) implement function

	return {};
}
