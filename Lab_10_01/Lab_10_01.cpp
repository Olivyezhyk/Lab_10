#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int CountB(const char* fname)
{
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        size_t pos = 0;
        while ((pos = line.find('B', pos)) != string::npos)
        {
            count++;
            pos++;
        }
    }
    return count;
}

int CountA(const char* fname)
{
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        size_t pos = 0;
        while ((pos = line.find('A', pos)) != string::npos)
        {
            count++;
            pos++;
        }
    }
    return count;
}

int CountS(const char* fname)
{
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        size_t pos = 0;
        while ((pos = line.find('S', pos)) != string::npos)
        {
            count++;
            pos++;
        }
    }
    return count;
}

int CountI(const char* fname)
{
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        size_t pos = 0;
        while ((pos = line.find('I', pos)) != string::npos)
        {
            count++;
            pos++;
        }
    }
    return count;
}

int CountC(const char* fname)
{
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        size_t pos = 0;
        while ((pos = line.find('C', pos)) != string::npos)
        {
            count++;
            pos++;
        }
    }
    return count;
}

int main()
{
    char fname[100];
    cout << "Enter file name: ";
    cin >> fname;

    cout << "Character count in file:" << endl;
    cout << "B: " << CountB(fname) << endl;
    cout << "A: " << CountA(fname) << endl;
    cout << "S: " << CountS(fname) << endl;
    cout << "I: " << CountI(fname) << endl;
    cout << "C: " << CountC(fname) << endl;

    return 0;
}
