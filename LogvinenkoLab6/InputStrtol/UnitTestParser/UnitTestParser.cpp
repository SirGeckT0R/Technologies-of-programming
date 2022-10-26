#include "pch.h"
#include "CppUnitTest.h"
#include "../InputStrtol/Parser.h"
#include "../InputStrtol/Parser.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestParser
{
	TEST_CLASS(UnitTestParser)
	{
	public:
		//IntFromString
		TEST_METHOD(TestIntFromStringPositive)
		{
			int actual = Parser::ParseIntString("1234");
			int expected = 1234;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestIntFromStringNotNumber)
		{
			int actual = Parser::ParseIntString("f1234");
			int expected = 0;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestIntFromStringNotNumberInMiddle)
		{
			int actual = Parser::ParseIntString("12f34");
			int expected = 12;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestIntFromStringNotNumberEnd)
		{
			int actual = Parser::ParseIntString("1234g");
			int expected = 1234;
			Assert::AreEqual(actual, expected);
		}

		//DoubleFromString
		TEST_METHOD(TestDoubleFromStringPositive)
		{
			double actual = Parser::ParseDoubleString("1234.4321");
			double expected = 1234.4321;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestDoubleFromStringNotNumber)
		{
			double actual = Parser::ParseDoubleString("f1234.4321");
			double expected = 0;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestDoubleFromStringNotNumberEnd)
		{
			double actual = Parser::ParseDoubleString("1234.4321f");
			double expected = 1234.4321;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestDoubleFromStringNotNumberInMiddle)
		{
			double actual = Parser::ParseDoubleString("1234.43f21");
			double expected = 1234.43;
			Assert::AreEqual(actual, expected);
		}



		//IntFromFile
		TEST_METHOD(TestIntFromFilePositive)
		{
			int actual = Parser::ParseIntFile("../UnitTestParser/int.txt");
			int expected = 12345;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestIntFromFileNotNumber)
		{
			int actual = Parser::ParseIntFile("./IntNotNum.txt");
			int expected = 0;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestIntFromFileNotNumberInMiddle)
		{
			int actual = Parser::ParseIntFile("./IntNotNumMiddle.txt");
			int expected = 123;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestIntFromFileNotNumberEnd)
		{
			int actual = Parser::ParseIntFile("./IntNotNumEnd.txt");
			int expected = 12345;
			Assert::AreEqual(actual, expected);
		}
	};
}
