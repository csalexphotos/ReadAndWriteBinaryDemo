#include "Game.h"


Game::Game()
{
	MAX_SAVES = 10;
	choice = 0;
	playing = true;
	currTime = time(NULL);
}

Game::~Game()
{

}

void Game::mainMenu()
{
	std::cout << getTime() << std::endl;
	std::cout << "MAIN MENU" << std::endl;
	std::cout << "0: Quit" << std::endl;
	std::cout << "1: New Game (Save Game as a TEST)" << std::endl;
	std::cout << "2: Load Game" << std::endl;


	/*
		These should be reserved for a pause menu. 
		No one goes to the shop from a start menu
		
		Pause Menu (P)
		std::cout << "0: Return to Game" << std::endl;
		std::cout << "1: Save Game" << std::endl;
		std::cout << "2: Load Game" << std::endl;

		Map Menu (M)
		std::cout << "0: Travel" << std::endl;
		std::cout << "1: Shop" << std::endl;
		//Maybe have an option to mark certain locations


		Inventory Menu (I)		
		std::cout << "0: Select Item" << std::endl;
		std::cout << "0: Use Item" << std::endl;
		std::cout << "0: Next Page" << std::endl;
		std::cout << "1: Previous Page" << std::endl;

		Character Menu (C)
		std::cout << "0: Level Up" << std::endl;
		std::cout << "1: Rest" << std::endl;
		std::cout << "2: Wait" << std::endl;

	
	*/


	//I could error check this
	getInput(choice, "");
	std::cout << std::endl;

	switch (choice) {
		case 0:
			playing = false;
			break;
		case 1:
			saveMenu();
			break;
		case 2:
			loadMenu();
			break;
		default:
			break;
	
	
	}

}

/*

	Menu for Save Game Button
*/
void Game::saveMenu()
{
	int saveOptions = 0;

	std::cout << "SAVE MENU" << std::endl;
	std::cout << "0: Save and Continue" << std::endl;
	std::cout << "1: Save and Quit" << std::endl;
	std::cout << "2: Cancel" << std::endl;

	getInput(saveOptions, "");
	std::cout << std::endl;

	switch (saveOptions) {
	case 0:
		saveGame();
		break;

	case 1:
		saveGame();
		playing = false;
		break;
	case 2:
		break;
	default:
		break;


	}

}


/*

	Menu for Load Game Button
*/
void Game::loadMenu()
{

	int loadOptions = 0;

	std::cout << "LOAD MENU" << std::endl;
	std::cout << "0: Load Game" << std::endl;
	std::cout << "1: Cancel" << std::endl;

	/*
		Really this menu should show all of the savefiles
		Maybe need a subfunction
	*/
	switch (loadOptions) {
	case 0:

		//Load a Game
		//Show load list as a submenu
		//Maybe all of
		loadGame();
		break;

	case 1:
		//Cancel
		break;

	default:
		break;


	}

}

/*
	Open file
	If it doesn't exist,
	tell them they don't have any saves and break
	Otherwise, set the values in the saveSlot selected to this player
*/
void Game::loadGame()
{

	//Take in a name
	std::string saveName;
	//Take in extra ID
	std::string extraIDString;
	//Get string of playerID
	std::string idString;

	//Get time string from file
	time_t tmp;
	//Default wins
	int wins;

	std::string fileName = "save.dat";

	std::fstream fs;

	fs.open(fileName, std::ios::binary | std::ios::in);

	bool hadExistingFile = true;

	if (!fs.is_open())
	{
		std::cout << "You don't have a save file. You will have to make a new game. :(" << std::endl;
		hadExistingFile = false;
	}

	fs.close();


	if (!hadExistingFile) {
		//Do nothing
		
	}
	else {
	
		int saveSlot = viewSaves(fileName, 1);
		/*
		Haven't handled actually saving to a file yet
		Random access read
		*/





	}

	






	
}

void Game::saveGame()
{
	int n = 0;
	std::string saveName = pl.getName();

	std::string extraSub = boost::uuids::to_string(pl.getPlayerId()).substr(0, 4);
	const char* extraID = (extraSub).c_str();
	

	//First 4 of id differentiate between two savefiles if you wanna keep using the same name
	const char* nameCString = saveName.c_str();

	/*
		Turns currTime into localtime and puts that into localtime
		Then puts that into a human readable format in a c string
	*/

	updateTime();

	struct tm* timeinfo;
	timeinfo = localtime(&currTime);

	const char* timeCString = asctime(timeinfo);
	/*
		Save File Format:
		Name
		4 digit extra ID to distinguish between saves of the same username
		playerID
		wins
		Date that the file was saved

	*/



	/*
		Convert UUID to a C string
	
	*/

	const std::string tmp = boost::uuids::to_string(pl.getPlayerId());
	const char* idCString = tmp.c_str();

	int saveSize = sizeof(nameCString) +sizeof(extraID) + sizeof(idCString)+ sizeof(int) + sizeof(timeCString);

	/*
		FUTURE CHANGES:
		Stop working for now. For tomorrow, make a mini project learning how to count time between
		two different time points
	
	*/

	
	std::string fileName = "save.dat";

	std::fstream fs;

	fs.open(fileName, std::ios::binary | std::ios::in | std::ios::out);

	bool hadExistingFile = true;

	if (!fs.is_open())
	{
		hadExistingFile = false;
		fs.clear();
		fs.open(fileName, std::ios::out); //Create file.
		fs.close();
	}
	fs.close();

	//File Exists
	//If we made it in the last step, we should reinitialize the file, or else, just read it like normal
	if (!hadExistingFile) {

		/* Initialize save file to MAX_SAVES slots as of now, can be changed in the future*/
		initializeSave(fileName);
	
	}

	int slotSelected = viewSaves(fileName, 0);

	/*
		Haven't handled actually saving to a file yet
		Random access write
	*/




}

int Game::viewSaves(std::string fileName, int saveOrLoad)
{

	int slotSelected;


	std::fstream fs;

	//At this point we're just displaying the saves in a menu
	fs.open(fileName, std::ios::binary | std::ios::in);


	//Take in a name
	//std::string saveName;
	char* nameCString;

	//Take in extra ID
	//std::string extraIDString;
	char* extraID;
	
	//Get string of playerID
	//std::string idString;
	char* idCString;

	//Get time string from file
	//Use atoi to

	char* timeCString;
	time_t tmp;

	//Default wins (Stays the same in binary)
	int wins;

	/*
		Save File Format:
		Name
		4 digit extra ID to distinguish between saves of the same username
		playerID
		wins
		Date that the file was saved (In the case of blank files, it's just current time)

	*/


	if (saveOrLoad == 0) {
		std::cout << "|---SAVE FILE---|" << std::endl;
	}
	else {
		std::cout << "|---LOAD FILE---|" << std::endl;
	}

	//Just use strings and cout instead. this is stupid
	//printf("%-11s| %-s| %-s| %-s| %-s | %-s |\n", CStringmap["SLOT NUMBER"], CStringmap["SAVE NAME"], CStringmap["ID"], CStringmap["WINS"], CStringmap["TIME"]);


	std::cout << center("SLOT NUMBER", 6) << " | "
		<< center("SAVE NAME", 10) << " | "
		<< center("ID", 6) << " | "
		<< center("FULL ID", 36) << " | "
		<< center("WINS", 6) << " | "
		<< center("TIME", 26) << "\n";

	std::cout << std::string((6*3)+(10)+(36)+(6)+(26)+2*6, '-') << "\n";

	for (int i = 0; i < MAX_SAVES; i++) {

		/*
		
		*/
		fs.read(nameCString, sizeof(nameCString)-1);
		fs.read(extraID, sizeof(extraID) - 1);
		fs.read(idCString, sizeof(idCString) - 1);
		fs.read((char*)(&wins), sizeof(int));
		fs.read(timeCString, sizeof(timeCString) - 1);
		

		/*
		fs >> saveName;
		fs >> extraIDString;
		fs >> idString;
		fs >> wins;
		fs >> tmp;
		
		*/



		


		/*
		Time Stuff
		*/

		/*
		struct tm* timeinfo;
		timeinfo = localtime(&tmp);

		const char* timeCString = asctime(timeinfo);
		*/

		/*
			Start outputting
		*/


		//Dumb doo doo version
		//printf("%-d| %-s| %-s| %-s| %-d| %-s |\n", i, nameCString, extraID, idCString, wins, timeCString);

			/*
			* 
			
			std::cout << prd(i, 0, 11) << " | "
			<< prd(saveName, 0, 10) << " | "
			<< prd(extraIDString, 0, 6) << " | "
			<< prd(idString, 0, 20) << " | "
			<< prd(wins, 0, 6) << " | "
			<< prd(timeCString, 0, 26) << "\n";
			
			
			*/

	}

	std::cout << std::endl;

	//Placeholder
	fs.close();

	if (saveOrLoad == 0) {
		getInput(slotSelected, "Select Save Slot:");
	}
	else {
	
		getInput(slotSelected, "Select Load Slot:");
	}
	




	
	return slotSelected;
}

void Game::initializeSave(std::string fileName)
{

	std::fstream fs;
	fs.open(fileName, std::ios::binary |std::ios::in | std::ios::out);


	//Make a fake name
	std::string saveName = "EMPTY";

	const char* nameCString = saveName.c_str();

	//Make a nil playerID
	boost::uuids::nil_generator gen;
	boost::uuids::uuid blankID = gen();

	const std::string tmp = boost::uuids::to_string(blankID);
	const char* idCString = tmp.c_str();

	//Get substring of nil player ID
	std::string blankSub = boost::uuids::to_string(blankID).substr(0, 4);
	const char* extraID = (blankSub).c_str();

	//Get current time for CString
	updateTime();

	/*
		Time CString

	*/

	//Convert time t to a string with stringstream
	//To go back, make a string with that cstring
	//Then lexical cast it back to a time_t
	

	std::stringstream ss;

	ss << currTime;

	
	std::string timeString = ss.str();
	const char* timeCString = timeString.c_str();

	//Default wins
	int wins = 0;
	
	/*
		Save File Format:
		Name
		4 digit extra ID to distinguish between saves of the same username
		playerID
		wins
		Date that the file was saved (In the case of blank files, it's just current time)

	*/



	int saveSize = sizeof(nameCString) + sizeof(extraID) + sizeof(idCString) + sizeof(int) + sizeof(timeCString);

	for (int i = 0; i < MAX_SAVES;i++) {
	
		/*

		*/


		/*
		fs << nameCString << " ";
		fs << extraID << " ";
		fs << idCString << " ";
		fs << wins << " ";
		fs << currTime << " ";
		fs << std::endl;
		
		*/

		/*
		
		*/
		fs.write(nameCString, sizeof(nameCString) - 1);
		fs.write(extraID, sizeof(extraID) - 1);
		fs.write(idCString, sizeof(idCString) - 1);
		fs.write((char*)(&wins), sizeof(int));
		fs.write(timeCString, sizeof(timeCString) - 1);

	}

	fs.close();

}

std::string Game::getTime()
{

	auto today = std::chrono::system_clock::now();
	currTime = std::chrono::system_clock::to_time_t(today);
	return ctime(&currTime);
}

std::string Game::getPath()
{
	return "Placeholder, havent figured out get env yet";
}

void Game::updateTime()
{
	auto timeMade = std::chrono::system_clock::now();

	//You have to convert from timePoint to time_t to print as a string
	currTime = std::chrono::system_clock::to_time_t(timeMade);

}


//File output stuff
/* Convert typename t to string with specified number of places after the decimal
   and left padding. */
//Does not work for doubles that well because I can't use the fixed or right thing

/*
	Double would add this in front of ss.fill() but i dont think we need doubles in the save file
	 ss << fixed << right;

*/

template<typename T>
std::string Game::prd(T x, const int decDigits, const int width) {
	std::stringstream ss;
	// set # places after decimal, only applies if this is a double I think
	ss.fill(' ');        // fill space around displayed #
	ss.width(width);     // set  width around displayed #						 
	ss << x;
	return ss.str();
}


/*! Center-aligns string within a field of width w. Pads with blank spaces
	to enforce alignment. */
std::string Game::center(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad, if there's no padding to put in, it won't
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();    // format with padding
	if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
		ss << " ";
	return ss.str();
}


/* Right-aligns string within a field of width w. Pads with blank spaces
   to enforce alignment. */
std::string Game::right(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i < padding; ++i)
		spaces << " ";
	ss << spaces.str() << s;                    // format with padding
	return ss.str();
}

/*! Left-aligns string within a field of width w. Pads with blank spaces
	to enforce alignment. */
std::string Game::left(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i < padding; ++i)
		spaces << " ";
	ss << s << spaces.str();                    // format with padding
	return ss.str();
}