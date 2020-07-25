#include "PhoneticFinder.hpp"

using namespace std;

string phonetic::find(string text, string word) {
    // remove all whitespaces 
    removeSpace(word);

    // check for empty strings
    if (text == " " || word == " " || text.empty() || word.empty()) {
        throw std::logic_error("ERR: searched word can't be empty");
    }

    //split the text to words
    vector<string> res = split(text, " ");

    //iterate over words in prash;
    for (int i = 0; i < res.size(); i++) {
        if(isPhonetic(res[i],word)){
            return res[i];
        }
    }

    throw std::runtime_error("ERR: searched word: " + word + ", is not in text");
}

// The string split() method breaks a given string around matches of the given delimiter.
// cpoy from stackoverflaw
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        removeSpace(token);
        res.push_back (token);
    }
    token = s.substr (pos_start);
    removeSpace(token);
    res.push_back (token);
    return res;
}

bool isPhonetic(string w1, string w2){
    //cout<<w1 + ',' + w2<<endl;
    if(w1.length() != w2.length()){ return false;}
    for(int i=0; i<w1.length();i++){
        if(!typoCheck(w1[i],w2[i]))
            return false;
    }
    return true;
}

bool typoCheck(char c1, char c2){
    
    char char1 = toupper(c1);
    char char2 = toupper(c2);


    if(char1 == char2){ return true; }

    switch (char1) {
    case 'V':
        if (char2 == 'W') { return true;}
        break;

    case 'W':
        if (char2 == 'V') { return true;}
        break;

    case 'G':
        if (char2 == 'J') { return true;}
        break;
    
    case 'J':
        if (char2 == 'G') { return true;}
        break;
    
    case 'S':
        if (char2 == 'Z') { return true;}
        break;
    
    case 'Z':
        if (char2 == 'S') { return true;}
        break;

    case 'D':
        if (char2 == 'T') { return true;}
        break;

    case 'T':
        if (char2 == 'D') { return true;}
        break;
    
    case 'O':
        if (char2 == 'U') { return true;}
        break;

    case 'U':
        if (char2 == 'O') { return true;}
        break;
    
    case 'I':
        if (char2 == 'Y') { return true;}
        break;
    
    case 'Y':
        if (char2 == 'I') { return true;}
        break;

    case 'B':
        if(char2 == 'F' || char2 == 'P'){ return true; }
        break;
    
    case 'F':
        if(char2 == 'B' || char2 == 'P'){ return true; }
        break;

    case 'P':
        if(char2 == 'B' || char2 == 'F'){ return true; }
        break;  

    case 'Q':
        if(char2 == 'C' || char2 == 'K'){ return true; }
        break;
    
    case 'C':
        if(char2 == 'K' || char2 == 'Q'){ return true; }
        break;

    case 'K':
        if(char2 == 'C' || char2 == 'Q'){ return true; }
        break;  
    }

    return false;
}

// Given a string refrerance remove all whithspaces from it
void removeSpace(string& s){
    string ans = "";
    for (int i = 0; i < s.length() ; ++i) {
        if(s[i] != ' ') ans = ans +s[i];
    }
    s = ans;
}






