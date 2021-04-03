#pragma once
#include <iostream>
#include <string>
using namespace std;

string embedEncrypt(string keyword, string plaintext);
string embedDecrypt(string encrypted, string keyword);