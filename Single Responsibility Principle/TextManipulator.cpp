#include<bits/stdc++.h>
using namespace std;

class TextManipulator {
private:
    string text;
public:
    TextManipulator(string text) {
        this->text = text;
    }
    void concatenate(string);
    void replaceChar(char, char);
	// Voilates Single Responsibility Principle
    bool findSubstr(string);
};

void TextManipulator :: concatenate(string addText) {
    this->text = this->text + addText;
}

void TextManipulator :: replaceChar(char existingChar, char newChar) {
    if(text.empty() == false) {
        for(char &currChar: text) {
            if(currChar == existingChar) {
                currChar = newChar;
            }
        }
    }
}

bool TextManipulator :: findSubstr(string searchStr) {
    if(text.size() < searchStr.size()) { return false; }
    int n = text.size(), m = searchStr.size();
    int index = 0;
    while(index < n-m) {
        int textIndex = index, searchStrIndex = 0;
        bool searchStrFound = true;
        while(searchStrIndex < m) {
            if(text[textIndex] == searchStr[searchStrIndex]) {
                textIndex++; searchStrIndex++;
            } else {
                searchStrFound = false;
                break;
            }
        }
        if(searchStrFound == true) {
            return true;
        }
        index++;
    }
    return false;
}

int main() {
    string text; cin >> text;
    TextManipulator textManipulator(text);
    string newText; cin >> newText ;
    textManipulator.concatenate(newText);
    textManipulator.replaceChar('T', 'K');
   if(textManipulator.findSubstr("Kuma") == true) {
       cout << "Substring Found";
   } else {
       cout << "No Substring Found";
   }
}