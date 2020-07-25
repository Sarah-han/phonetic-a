#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>


using namespace std;

// namespace for find function
namespace phonetic{
    string find (string text, string word);
};

// util function fo find
vector<string> split(string s, string delimiter);

bool isPhonetic(string w1, string w2);

bool typoCheck(char c1, char c2);

void removeSpace(string& s);


