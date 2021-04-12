#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "convert.h"

string randGen() {
	srand(time(NULL));
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	bool fail = 0;
	int count = -1;
	string input = "";
	string output = "";
	do {
		fail = 0;
		cout << "Please enter a value for the length of the random keyword. Value must be an integer between 1 and 20.\nInput:   ";
		//getline to pull in text data
		getline(cin, input);
		/*
		* find_first_not_of returns the index of the first character to not be part of its given string.
		* find_first_not_of returns -1 if all characters are part of its string.
		* Turns the "fail" variable to true if not -1.
		*/
		if (input.find_first_not_of("0123456789") != -1) {
			fail = 1;
		}
		//Converts the string to an integer.
		else {
			count = stoi(input);
		}
		//If the value provided is between 1 and 20, select characters randomly from the alphabet (count) number of times.
		if (count <= 20 && count >= 1) {
			for (int i = 0; i < count; i++) {
				output = output + alphabet[(rand() % 26)];
			}
		}
		//If the count is not between 1 and 20, make the fail boolean true to repeat the loop.
		else {
			fail = 1;
		}
	} while (fail == 1);
	cout << "Your random output: " << output << endl;
	return output;
}

void randEncrypt() {
	string keyword, plaintext;
	keyword = randGen();
	plaintext = customInput(0);
	string lowers = "abcdefghijklmnopqrstuvwxyz";
	string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string output = "";
	int plaintextData = 0;
	int keywordData = 0;
	int keywordPos = 0;
	for (int i = 0; i < plaintext.size(); i++) {
		if (isalpha(plaintext[i])) {
			if (isupper(plaintext[i])) {
				plaintextData = uppers.find(plaintext[i]);
			}
			else if (islower(plaintext[i])) {
				plaintextData = lowers.find(plaintext[i]);
			}
			if (isupper(keyword[keywordPos])) {
				keywordData = uppers.find(keyword[keywordPos]);
			}
			else if (islower(keyword[keywordPos])) {
				keywordData = lowers.find(keyword[keywordPos]);
			}
			if (isupper(plaintext[i])) {
				output = output + uppers[(keywordData + plaintextData) % 26];
			}
			else if (islower(plaintext[i])) {
				output = output + lowers[(keywordData + plaintextData) % 26];
			}
		}
		else {
			output = output + plaintext[i];
		}
		if (isalpha(plaintext[i])) {
			keywordPos = keywordPos + 1;
		}
		if (keywordPos >= keyword.size()) {
			keywordPos = 0;
		}
	}
	cout << output << endl;
}

