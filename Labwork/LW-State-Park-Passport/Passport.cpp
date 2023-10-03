# include "Passport.h"

using std::string, std::vector;

// TODO: implement constructor using member initializer list
Passport::Passport(string camperName, bool isJuniorPassport) : 

camperName{camperName}, isJuniorPassport{isJuniorPassport}, parksVisited{vector<StatePark*>()} {
	return;
}

string Passport::getCamperName() {
	// TODO: implement getter
	return this->camperName;
	
}

bool Passport::checkJuniorPassport() {
	// TODO: implement getter

	return this->isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
	//INFO(park)

	// TODO: implement function
	this->parksVisited.push_back(park);
	park->addCamper(this);
	INFO(this->parksVisited.size());

	return;
}

double Passport::getMilesHiked() {
	// TODO: (optional) implement function

	return 0.0;
}

int Passport::getHikerLevel() {
	// TODO: (optional) implement function

	return 0;
}
