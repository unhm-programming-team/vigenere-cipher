#include "embeddedconvert.h"
string embedEncrypt(string keyword, string plaintext) {
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
	return output;
}

string embedDecrypt(string encrypted, string keyword) {
	string lowers = "abcdefghijklmnopqrstuvwxyz";
	string uppers = "ABCDEFGJIJKLMNOPQRSTUVWXYZ";
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
		keywordPos = keywordPos + 1;
		if (keywordPos >= keyword.size()) {
			keywordPos = 0;
		}
	}
	return output;
}