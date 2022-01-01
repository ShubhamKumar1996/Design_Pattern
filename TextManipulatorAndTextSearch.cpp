#include<bits/stdc++.h>
using namespace std;

// This class is responsible for manipulating text;
class TextManipulator {
private:
    string text;
public:
    TextManipulator(string text) {
        this->text = text;
    }
    string concatenate(string);
    string replaceChar(char, char);
};

// Responsibility of this class is to perform search operations
class TextSearch {
private:
    string text;
public:
    TextSearch(string text) {
        this->text = text;
    }
    bool isSubstr(string);
    bool isSubsequence(string);
};

int main() {
    string str; cin >> str;
    TextManipulator textManipulator(str);
    string newStr; cin >> newStr ;
    str = textManipulator.concatenate(newStr);
    str = textManipulator.replaceChar('T', 'K');
    TextSearch textSearch(str);
    cout << str << "\n";
   if(textSearch.isSubstr("Kuma") == true) {
       cout << "Substring Found\n";
   } else {
       cout << "No Substring Found\n";
   }
   if(textSearch.isSubsequence("hubKu") == true) {
       cout << "Subsequence Found";
   } else {
       cout << "No Subsequence Found";
   }
}

string TextManipulator :: concatenate(string addText) {
    this->text = this->text + addText;
    return this->text;
}

string TextManipulator :: replaceChar(char existingChar, char newChar) {
    if(text.empty() == false) {
        for(char &currChar: text) {
            if(currChar == existingChar) {
                currChar = newChar;
            }
        }
    }
    return this->text;
}

bool TextSearch :: isSubstr(string searchStr) {
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

bool TextSearch :: isSubsequence(string searchStr) {
    if(text.size() < searchStr.size()) {
        return false;
    }
    int n = text.size(), m = searchStr.size();
    int textIndex = 0, searchIndex = 0;
    while(textIndex < n && searchIndex < m) {
        if(text[textIndex] == searchStr[searchIndex]) {
            searchIndex++;
        }
        textIndex++;
    }
    return (searchIndex == m);
}