#include "input.h"
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
	if (input == "h" || input == "help") {
		cout << "Help message:\n\tHelp message format: (\"Command\" [abbreviation] - Help message)\n";
		cout << "\t\"Encrypt\" [e] - Encrypt a text input by providing a keyword and the plaintext to be encrypted.\n";
		cout << "\t\"Decrypt\" [d] - Decrypt a text input by providing a keyword and the plaintext to be decrypted.\n";
		cout << "\t\"Quit\" [q] - Quit the program.";
		cout << "\n";
	}
	else if (input == "e" || input == "encrypt") {
		encrypt();
	}
	else if (input == "d" || input == "decrypt") {
		decrypt();
	}
	else if (input == "q" || input == "quit") {
		exit(0);
	}
	else {
		cout << "Error, command not found.\n";
	}
}

//Brutish method to turn all alphabetical characters to lower case
string bruteForceToLower(string input) {
	string capitals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lowers = "abcdefghijklmnopqrstuvwxyz";
	string output = "";
	bool used = 0;
	for (int i = 0; i < input.size(); i++) {
		for (int o = 0; o < capitals.size(); o++) {
			if (input[i] == capitals[o]) {
				output = output + lowers[o];
				used = 1;
			}
			else if (input[i] == lowers[o]) {
				output = output + input[i];
				used = 1;
			}
		}
		if (used != 1) {
			output = output + input[i];
		}
	}
	return output;
}