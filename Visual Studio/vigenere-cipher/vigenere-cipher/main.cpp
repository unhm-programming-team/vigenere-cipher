#include <iostream>
#include <string>
#include "input.h"
using namespace std;

int main() {
	bool loop = 1;
	string input;
	cout << "Welcome to the Vigenere Cipher System! Please type \"h\" or \"help\" to read the command list.\n";
	while (loop == 1) {
		//User input to be used for commmands
		input = userInput();
		//Central commands system connecting input strings to command arguments
		inputReply(input);
	}
}