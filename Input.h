#pragma once

#include <iostream>
#include <string>
#include <sstream>

template<typename T>
void getInput(T& input, const std::string msg) {


	std::cout << msg;
	std::cin >> input;

	while (std::cin.fail()) {

		std::cin.clear();

		/*
			Notes on cin.ignore()

			Extracts characters from the input sequence and discards them
			until either n characters have been extracted
			or one compares equal to delim

			(So maybe I could take in a newline using it too!)
			However ignore for a large number of characters deals with the edge case that there is no newline
		
		*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "ErrorCode 1: INPUT ERROR! PLEASE TRY AGAIN! \n";

		std::cout << msg;
		std::cin >> input;

	}



}

template<typename T>
void printOnNewLine(T& output) {

	std::stringstream ss;
	ss << output << std::endl;
	std::cout << ss.str() << std::endl;

}