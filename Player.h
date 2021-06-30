// Player.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "Input.h"
#include <chrono>
#include <ctime>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
//#include <boost/lexical_cast.hpp>



class Player {

private:
	std::string playerName;
	boost::uuids::uuid playerId;
	//std::string choice[3];
	int wins;
	std::chrono::system_clock::time_point timeMade;

public:

	Player();
	Player(std::string name);
	Player(std::string name, boost::uuids::uuid passedId);
	Player(const Player& other);


	//Operators
	Player& operator=(const Player& rhs);
	
	//Modifiers


	//Functions

	//Accessors
	inline std::string getName() const { return this->playerName; };
	inline boost::uuids::uuid getPlayerId() const { return this->playerId; };
	inline int getWins() const { return this->wins; };
	std::string to_string() const;

	//void makeChoice();


};

