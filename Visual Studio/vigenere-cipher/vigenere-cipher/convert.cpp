#include "convert.h"

string customInput(int inputMethod) {
	bool loop = 0;
	if (inputMethod == 1) {
		loop = 1;
	}
	string output = "";
	
	bool clear = 1;
	do {
		clear = 1;
		if (inputMethod == 0) {
			cout << "Please enter your plaintext: ";
		}
		else if (inputMethod == 1) {
			cout << "Please enter your keyword: ";
		}
		else if (inputMethod == 2) {
			cout << "Please enter your encrypted text: ";
		}
		getline(cin, output);
		for (int i = 0; i < output.size(); i++) {
			if (!isalpha(output[i]) && inputMethod == 1) {
				if (clear == 1) {
					cout << "Error, keyword MUST be purely alphabetical!\n";
				}
				loop = 1;
				clear = 0;
			}
		}
		if (clear == 1) {
			loop = 0;
		}
	} while (loop == 1);
	return output;
}

void encrypt() {
	string keyword, plaintext;
	keyword = customInput(1);
	plaintext = customInput(0);
	string lowers = "abcdefghijklmnopqrstuvwxyz";
	string uppers = "ABCDEFGJIJKLMNOPQRSTUVWXYZ";
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
		keywordPos = keywordPos + 1;
		if (keywordPos >= keyword.size()) {
			keywordPos = 0;
		}
	}
	cout << output << endl;
}

void decrypt() {
	cout << "Not currently implemented.\n";
}