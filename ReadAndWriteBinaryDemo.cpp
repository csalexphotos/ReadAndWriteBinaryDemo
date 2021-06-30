// ReadAndWriteBinaryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Game.h"



//Random Read



//Random Write



int main()
{
    using namespace boost::uuids;

    auto gen = random_generator();
    uuid playerId = gen();

    int wins = 69;
    std::string name = "Chris";


    //Example Values to practice binary input and output

    Game game;

    while (game.getPlaying()) {

        game.mainMenu();

        /*
            Oh yeah, the stuff after the main menu
        */

    }



    return 0;
}

