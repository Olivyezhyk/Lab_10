#include "pch.h"
#include <CppUnitTest.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include "..\\Lab_10_03\\Lab_10_03.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
    TEST_CLASS(FileHandlingTests)
    {
    public:

        TEST_METHOD(TestAddNotesToFile)
        {
            std::ofstream fout("test.txt");
            fout << "Smith John 1234567890 15 3 1990\n";
            fout << "Doe Jane 0987654321 25 12 1985\n";
            fout.close();

            std::ifstream fin("test.txt");
            std::string line;
            std::string expected = "Smith John 1234567890 15 3 1990\nDoe Jane 0987654321 25 12 1985\n";
            std::string result;
            while (std::getline(fin, line)) {
                result += line + "\n";
            }
            fin.close();

            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestSearchByPhoneInFile)
        {
            std::ofstream fout("test.txt");
            fout << "Smith John 1234567890 15 3 1990\n";
            fout.close();

            bool found = searchByPhoneInFile("test.txt", "1234567890");

            Assert::IsTrue(found);
        }

        TEST_METHOD(TestOverwriteFile)
        {
            std::ofstream fout("test.txt");
            fout << "Brown Charlie 1122334455 1 1 2000\n";
            fout.close();

            std::ifstream fin("test.txt");
            std::string line;
            std::string expected = "Brown Charlie 1122334455 1 1 2000\n";
            std::string result;
            while (std::getline(fin, line)) {
                result += line + "\n";
            }
            fin.close();

            Assert::AreEqual(expected, result);
        }
    };
}
