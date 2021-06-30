#pragma once


#include "Functions.h"
#include "Input.h"
#include "Player.h"
#include <iostream>
#include <iomanip>

/*
	ctime isnt even supported anymore

	
	Gonna try to use chrono
	*/
#include <chrono>
#include <ctime>
#include <limits>
#include <fstream>
#include <sstream>


using namespace boost::uuids;


class Game
{

public:

	//Constructor
	Game();


	virtual ~Game();
	
	
	//Menus
	void mainMenu();
	void saveMenu();
	void loadMenu();
	
	//Functions

	/*
	Initializes player object based on user input 
	and some defaults, should call player constructor

	*/
	void newGame();

	/*
	Writes player from file to our player object
	*/
	void loadGame();


	/*
	If the game object holds a player object,
	then we can initialize it when we load a game
	and write from it when we want to save the game
	*/

	void saveGame();


	/*
	ASSERT: The Save FIle exists and is fully instantiated when this is called
		saveGame checks if there's a file, and if there is, opens it with this
		LoadGame does the same, but opens this to see which to 
		parameter is to see if viewSaves was to save or to load
		0 - save
		1- load

		Returns the number of the save slot you want to save or load to
	*/
	int viewSaves(std::string fileName, int saveOrLoad);

	/*
		Initialize save file slots to base form
	
	*/
	void initializeSave(std::string fileName);

	template<typename T>
	std::string prd(const T x, const int decDigits, const int width);
	std::string left(const std::string s, const int w);
	std::string right(const std::string s, const int w);
	std::string center(const std::string s, const int w);
	//Operators





	//Accessors
	inline bool getPlaying() const { return this->playing; }
	std::string getTime();
	//Get path for user to save their game
	std::string getPath();

	//Modifiers
	void updateTime();

private:
	static int MAX_SAVES;
	int choice;
	bool playing;
	Player pl;
	std::time_t currTime;


	
};

