#include "input.h"
#include "randConvert.h"
#include "convert.h"

string bruteForceToLower(string input);

//Collecting a string input from the user and converting its alphabetical characters to lower case
string userInput() {
	//Take the input from the user
	cout << "Input: ";
	string text = "";
	getline(cin, text);
	//Converts the text to lower case
	text = bruteForceToLower(text);
	return text;
}

//Central system that manages responses to user inputs
void inputReply(string input) {
	//Help response string.
	if (input == "h" || input == "help") {
		cout << "Help message:\n\tHelp message format: (\"Command\" [abbreviation] - Help message)\n";
		cout << "\t\"Encrypt\" [e] - Encrypt a text input by providing a keyword and the plaintext to be encrypted.\n";
		cout << "\t\"Decrypt\" [d] - Decrypt a text input by providing a keyword and the plaintext to be decrypted.\n";
		cout << "\t\"Random Encrypt\" [r] - Encrypt a plaintext input with a randomly generated keyword.\n";
		cout << "\t\"Quit\" [q] - Quit the program.";
		cout << "\n";
	}
	//Encrypt function, leads to convert.cpp
	else if (input == "e" || input == "encrypt") {
		encrypt();
	}
	//Decrypt function, leads to convert.cpp
	else if (input == "d" || input == "decrypt") {
		decrypt();
	}
	//Random Encrypt function, leads to randConvert.cpp
	else if (input == "r" || input == "random encrypt") {
		randEncrypt();
	}
	//Quit command.
	else if (input == "q" || input == "quit") {
		exit(0);
	}
	//If none of the above inputs are found, return error message.
	else {
		cout << "Error, command not found.\n";
	}
}

//Brutish method to turn all alphabetical characters to lower case
string bruteForceToLower(string input) {
	//Delcaration of alphabet strings and output string.
	string capitals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lowers = "abcdefghijklmnopqrstuvwxyz";
	//"output" string will be appended to as characters are evaluated.
	string output = "";
	/*
	* "used" boolean used in check to make sure that character is alphabetical. 
	* If a character is found in the alphabets above, it will be set to true.
	* If it is false, the character from the original string will be passed on with no changes.
	*/
	bool used = 0;
	//Checks for the length of the string for capitalized alphabetical characters.
	for (int i = 0; i < input.size(); i++) {
		//For each character, it is compared to all alphabetical characters.
		for (int o = 0; o < capitals.size(); o++) {
			/*
			* If a character is capitalized and matches a character from the upper case alphabet, the corresponding letter from
			* the lower case alphabet is used and appended to the output.
			*/
			if (input[i] == capitals[o]) {
				output = output + lowers[o];
				used = 1;
			}
			/*
			* If a character is lower case and matches a character from the lower case alphabet, the letter from the
			* input is passed on with no changes.
			*/
			else if (input[i] == lowers[o]) {
				output = output + input[i];
				used = 1;
			}
		}
		//If the used boolean was never set to true during its checks, the character from the original string is passed on.
		if (used != 1) {
			output = output + input[i];
		}
	}
	return output;
}