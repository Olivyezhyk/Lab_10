#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(const char* fname) {
    ofstream fout(fname);
    string s;
    char ch;
    do {
        cout << "Enter line: ";
        getline(cin, s);
        fout << s << endl;
        cout << "Continue? (y/n): "; cin >> ch;
        cin.ignore();
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}

void PrintTXT(const char* fname) {
    ifstream fin(fname);
    string s;
    while (getline(fin, s)) {
        cout << s << endl;
    }
    cout << endl;
}

void CalculateStats(const char* fname, int& lineCount, int& maxLineLength, int& emptyLineCount) {
    ifstream fin(fname);
    string s;

    lineCount = 0;
    maxLineLength = 0;
    emptyLineCount = 0;

    while (getline(fin, s)) {
        lineCount++;

        if (s.length() > maxLineLength) {
            maxLineLength = s.length();
        }

        if (s.empty()) {
            emptyLineCount++;
        }
    }
}

string FindStartEndString(const char* fname, char startChar, char endChar) {
    ifstream fin(fname);
    string s;
    string startEndString;

    while (getline(fin, s)) {
        size_t start = s.find_first_not_of(' ');
        size_t end = s.find_last_not_of(' ');

        if (start != -1 && end != -1) {
            s = s.substr(start, end - start + 1);
        }

        if (!s.empty() && s.front() == startChar && s.back() == endChar) {
            startEndString = s;
            break;
        }
    }

    return startEndString;
}


void SaveStats(const char* statsFile, int lineCount, int maxLineLength, int emptyLineCount, const string& startEndString, char startChar, char endChar) {
    ofstream fout(statsFile);

    fout << "Line count: " << lineCount << endl;
    fout << "Max line length: " << maxLineLength << endl;
    fout << "Empty line count: " << emptyLineCount << endl;

    if (!startEndString.empty()) {
        fout << "String that starts with '" << startChar << "' and ends with '" << endChar << "': " << startEndString << endl;
    }
    else {
        fout << "No string found that starts with '" << startChar << "' and ends with '" << endChar << "'." << endl;
    }

    cout << "Statistics saved to " << statsFile << endl;
}

int main() {
    char fname[100];
    cout << "Enter the first file name: ";
    cin >> fname;
    cin.ignore();

    CreateTXT(fname);
    PrintTXT(fname);

    char statsFile[100];
    cout << "Enter the name for the statistics file: ";
    cin >> statsFile;

    int lineCount, maxLineLength, emptyLineCount;
    CalculateStats(fname, lineCount, maxLineLength, emptyLineCount);

    char startChar, endChar;
    cout << "Enter the starting character: ";
    cin >> startChar;
    cout << "Enter the ending character: ";
    cin >> endChar;

    string startEndString = FindStartEndString(fname, startChar, endChar);
    SaveStats(statsFile, lineCount, maxLineLength, emptyLineCount, startEndString, startChar, endChar);

    return 0;
}
