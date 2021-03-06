#include "convert.h"

//Prompts the user for an input, if keyword isn't purely alphabetical, loops until an all alphabetical keyword is provided.
//"inputMethod" expects prompts 0, 1, or 2, being the plaintext, keyword, and encrypted text prompts respectively.
string customInput(int inputMethod) {
	//"loop" variable, mainly used for inputMethod 1, the keyword prompt.
	bool loop = 0;
	if (inputMethod == 1) {
		loop = 1;
	}
	//Empty "output" string variable to be appended to.
	string output = "";
	//Since the loop evaluates on a per-character basis, this bool keeps the error message from repeating more than once per response.
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

//Function to encrypt the text provided by the user.
void encrypt() {
	string keyword, plaintext;
	keyword = customInput(1);
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

//Function to decrypt the text provided by the user.
void decrypt() {
	string keyword, encrypted;
	keyword = customInput(1);
	encrypted = customInput(2);
	string lowers = "abcdefghijklmnopqrstuvwxyz";
	string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string output = "";
	int encryptedData = 0;
	int keywordData = 0;
	int keywordPos = 0;
	int specialData = 0;
	for (int i = 0; i < encrypted.size(); i++) {
		if (isalpha(encrypted[i])) {
			if (isupper(encrypted[i])) {
				encryptedData = uppers.find(encrypted[i]);
			}
			else if (islower(encrypted[i])) {
				encryptedData = lowers.find(encrypted[i]);
			}
			if (isupper(keyword[keywordPos])) {
				keywordData = uppers.find(keyword[keywordPos]);
			}
			else if (islower(keyword[keywordPos])) {
				keywordData = lowers.find(keyword[keywordPos]);
			}
			if (isupper(encrypted[i])) {
				specialData = encryptedData - keywordData;
				if (specialData < 0) {
					specialData = specialData + 26;
				}
				output = output + uppers[specialData % 26];
			}
			else if (islower(encrypted[i])) {
				specialData = encryptedData - keywordData;
				if (specialData < 0) {
					specialData = specialData + 26;
				}
				output = output + lowers[specialData % 26];
			}
		}
		else {
			output = output + encrypted[i];
		}
		if (isalpha(encrypted[i])) {
			keywordPos = keywordPos + 1;
		}
		if (keywordPos >= keyword.size()) {
			keywordPos = 0;
		}
	}
	cout << output << endl;
}