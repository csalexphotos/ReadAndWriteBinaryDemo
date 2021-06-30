
#include "Player.h"

#pragma once


/*
void Player::makeChoice() {

}

*/


/*
	Default Constructor
*/

Player::Player() {

	boost::uuids::random_generator gen;
	playerId = gen();
	playerName += "Player";
	playerName += boost::uuids::to_string(playerId).substr(0,4);
	wins = 0;

	std::time_t currTime;
	auto timeMade = std::chrono::system_clock::now();

	//You have to convert from timePoint to time_t to print as a string
	currTime = std::chrono::system_clock::to_time_t(timeMade);


}

/*
	Constructor with only name
*/

Player::Player(std::string name)
{

	boost::uuids::random_generator gen;
	playerId = gen();
	playerName = name;
	wins = 0;

}


/*
	Constructor with ID and name
*/

Player::Player(std::string s, boost::uuids::uuid passedId) {

	playerName = s;
	playerId = passedId;
	wins = 0;

}


/*
*/

Player::Player(const Player& other)
{

	playerId = other.playerId;
	wins = other.wins;
	playerName = other.playerName;

}


/*
	Assignment Operator
*/


Player& Player::operator=(const Player& rhs)
{

	playerId = rhs.playerId;
	wins = rhs.wins;
	playerName = rhs.playerName;

	return *this;

}


/*

	Description of player
*/

std::string Player::to_string() const
{
	
	std::stringstream ss;

	ss << "Name: " << playerName << "\n";
	ss << "PlayerID: " << boost::uuids::to_string(playerId) << "\n";
	ss << "Wins: " << wins << "\n";


	return ss.str();

}







