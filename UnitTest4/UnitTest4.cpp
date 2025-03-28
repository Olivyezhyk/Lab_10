#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "..\\Lab_10_04\\Lab_10_04.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(TestCalculateStats)
		{
			const char* testFile = "test.txt";
			std::ofstream fout(testFile);
			fout << "This is the first line." << std::endl;
			fout << "This is the second line, with more characters." << std::endl;
			fout << "" << std::endl;
			fout << "Final line." << std::endl;
			fout.close();

			int lineCount, maxLineLength, emptyLineCount;
			CalculateStats(testFile, lineCount, maxLineLength, emptyLineCount);

			Assert::AreEqual(lineCount, 4);

			Assert::AreEqual(maxLineLength, 46);

			Assert::AreEqual(emptyLineCount, 1);

			std::remove(testFile);
		}
	};
}
