#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string FindFirstWordStartingWithA(const char* fname)
{
    ifstream file(fname);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return "";
    }

    string str;
    string word;
    while (file >> word) {
        if (word[0] == 'a' || word[0] == 'A') {
            return word;
        }
    }
    return "No word starts with 'a' or 'A'";
}

int main()
{
    char fname[100];
    cout << "Enter file name: ";
    cin >> fname;

    cout << "First word starting with 'A/a': " << FindFirstWordStartingWithA(fname) << endl;

    return 0;
}
