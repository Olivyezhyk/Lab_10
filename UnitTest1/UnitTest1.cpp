#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <iostream>
#include <string>
#include "..\\Lab_10_01\\Lab_10_01.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        void WriteTestFile(const char* fname, const std::string& content)
        {
            std::ofstream fout(fname);
            fout << content;
            fout.close();
        }

        TEST_METHOD(CountB_Test)
        {
            const char* fname = "test.txt";
            std::string testContent = "ABBBASIBCS";
            WriteTestFile(fname, testContent);

            int result = CountB(fname);
            Assert::AreEqual(4, result);

            std::remove(fname);
        }

        TEST_METHOD(CountA_Test)
        {
            const char* fname = "test.txt";
            std::string testContent = "ABBBASIBCS";
            WriteTestFile(fname, testContent);

            int result = CountA(fname);
            Assert::AreEqual(2, result);

            std::remove(fname);
        }

        TEST_METHOD(CountS_Test)
        {
            const char* fname = "test.txt";
            std::string testContent = "ABBBASIBCS";
            WriteTestFile(fname, testContent);

            int result = CountS(fname);
            Assert::AreEqual(2, result);

            std::remove(fname);
        }

        TEST_METHOD(CountI_Test)
        {
            const char* fname = "test.txt";
            std::string testContent = "ABBBASIBCS";
            WriteTestFile(fname, testContent);

            int result = CountI(fname);
            Assert::AreEqual(1, result);

            std::remove(fname);
        }

        TEST_METHOD(CountC_Test)
        {
            const char* fname = "test.txt";
            std::string testContent = "ABBBASIBCS";
            WriteTestFile(fname, testContent);

            int result = CountC(fname);
            Assert::AreEqual(1, result);

            std::remove(fname);
        }
    };
}
