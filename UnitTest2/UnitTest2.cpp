#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include <iostream>
#include "..\\Lab_10_02\\Lab_10_02.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    void WriteTestFile(const char* fname, const std::string& content)
    {
        std::ofstream fout(fname);
        fout << content;
        fout.close();
    }

    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(FindFirstWordStartingWithA_Test)
        {
            const char* fname = "test.txt";

            std::string testContent = "apple banana apricot orange";
            WriteTestFile(fname, testContent);
            std::string result = FindFirstWordStartingWithA(fname);
            Assert::AreEqual("apple", result.c_str());

            testContent = "banana orange pear";
            WriteTestFile(fname, testContent);
            result = FindFirstWordStartingWithA(fname);
            Assert::AreEqual("No word starts with 'a' or 'A'", result.c_str());

            testContent = "hello apple";
            WriteTestFile(fname, testContent);
            result = FindFirstWordStartingWithA(fname);
            Assert::AreEqual("apple", result.c_str());

            testContent = "";
            WriteTestFile(fname, testContent);
            result = FindFirstWordStartingWithA(fname);
            Assert::AreEqual("No word starts with 'a' or 'A'", result.c_str());

            std::remove(fname);
        }
    };
}
