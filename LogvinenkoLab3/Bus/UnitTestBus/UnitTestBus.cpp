#include "pch.h"
#include "CppUnitTest.h"
#include "../Bus/Bus.h"
#include "../Bus/Bus.cpp"
#include "../Bus/BusInfo.h"
#include "../Bus/BusInfo.cpp"
#include "../Bus/HandleException.h"
#include "../Bus/HandleException.cpp"
#include "../Bus/Validator.h"
#include "../Bus/Validator.cpp"
#include "../Bus/Month.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBus
{
	TEST_CLASS(UnitTestBus)
	{
	public:
		//VALIDATOR ISYEARVALID()
		TEST_METHOD(TestValidatorYearPositive) {
			Validator val;
			bool actual = val.isYearValid(1);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestValidatorYearMaxPositive) {
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			int currentYear = newtime.tm_year + 1900;

			Validator val;
			bool actual = val.isYearValid(currentYear);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestValidatorYearMinPositive) {
			Validator val;
			bool actual = val.isYearValid(0);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestValidatorYearFail) {
			Validator val;
			bool actual = val.isYearValid(-1);
			bool expected = false;
			Assert::AreEqual(actual, expected);
		}


		//VALIDATOR ISNUMBERVALID()
		TEST_METHOD(TestValidatorNumberMaxPositive) {
			Validator val;
			bool actual = val.isNumberValid(MAX_NUMBER, MAX_NUMBER);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(TestValidatorNumberMinPositive) {
			Validator val;
			bool actual = val.isNumberValid(0, MAX_NUMBER);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestValidatorNumberPositive) {
			Validator val;
			bool actual = val.isNumberValid(1, MAX_NUMBER);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestValidatorNumberFail) {
			Validator val;
			bool actual = val.isNumberValid(-1,MAX_NUMBER);
			bool expected = false;
			Assert::AreEqual(actual, expected);
		}

		//BUSINFO BUSINFO()
		TEST_METHOD(TestBusInfoConstructorPositive)
		{
			try {
				BusInfo info;
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoConstructorArgsPositive)
		{
			try {
				BusInfo info=BusInfo(1,"d",2000,1);

			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoConstructorArgsFail)
		{
			auto func = [] { BusInfo info=BusInfo(-1,"",1,1); };
			Assert::ExpectException<HandleException>(func);
		}

		//BUSINFO AREEQUAL()
		TEST_METHOD(TestBusInfoAreEqualPositive)
		{
			BusInfo info1, info2;
			bool actual = info1.areEqual(info2);
			bool expected = true;
			Assert::AreEqual(actual,expected);
		}

		TEST_METHOD(TestBusInfoAreEqualArgsPositive)
		{
			BusInfo info1 = BusInfo(1, "f", 2, 4);
			BusInfo info2 = BusInfo(1, "f", 2, 4);
			bool actual = info1.areEqual(info2);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestBusInfoAreEqualArgsNegative)
		{
			BusInfo info1 = BusInfo(1, "d", 2, 1);
			BusInfo info2 = BusInfo(1, "f", 2, 4);
			bool actual = info1.areEqual(info2);
			bool expected = false;
			Assert::AreEqual(actual, expected);
		}

		//BUSINFO SETNUMBER()
		TEST_METHOD(TestBusInfoNumberMaxPositive)
		{
			try {
				BusInfo info; info.setNumber(99999);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoNumberMinPositive)
		{
			try {
				BusInfo info; info.setNumber(0);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoNumberPositive)
		{
			try {
				BusInfo info; info.setNumber(1);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoNumberFail)
		{
			auto func = [] { BusInfo info; info.setNumber(-1); };
			Assert::ExpectException<HandleException>(func);
		}
		TEST_METHOD(TestBusInfoNumberFailMessage)
		{
			try {
				BusInfo info; info.setNumber(-1);
			}
			catch (HandleException& e) {
				Assert::AreEqual(e.what(), "The number of bus isn't valid!");
			}
		}

		//BUSINFO SETBRAND()
		TEST_METHOD(TestBusInfoBrandPositive)
		{
			try {
				BusInfo info; info.setBrand("Great");
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoBrandMinPositive)
		{
			try {
				BusInfo info; info.setBrand("");
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoBrandFail)
		{
			auto func = [] { BusInfo info; info.setBrand("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"); };
			Assert::ExpectException<HandleException>(func);
		}
		TEST_METHOD(TestBusInfoBrandFailMessage)
		{
			try {
				BusInfo info; info.setBrand("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
			}
			catch (HandleException& e) {
				Assert::AreEqual(e.what(), "The brand isn't valid!");
			}
		}


		//BUSINFO SETYEAR()
		TEST_METHOD(TestBusInfoYearMaxPositive)
		{
			try {
				struct tm newtime;
				time_t now = time(0);
				localtime_s(&newtime, &now);
				int currentYear = newtime.tm_year + 1900;
				BusInfo info; info.setYear(currentYear);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoYearMinPositive)
		{
			try {
				BusInfo info; info.setYear(0);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoYearPositive)
		{
			try {
				BusInfo info; info.setYear(1);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoYearFail)
		{
			auto func = [] { BusInfo info; info.setYear(2023); };
			Assert::ExpectException<HandleException>(func);
		}
		TEST_METHOD(TestBusInfoYearFailMessage)
		{
			try {
				BusInfo info; info.setYear(3000);
			}
			catch (HandleException& e) {
				Assert::AreEqual(e.what(), "The year of exploitation isn't valid!");
			}
		}

		//BUSINFO SETMILEAGE()
		TEST_METHOD(TestBusInfoMileageMaxPositive)
		{
			try {
				BusInfo info; info.setMileage(1000000);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoMileageMinPositive)
		{
			try {
				BusInfo info; info.setMileage(0);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoMileagePositive)
		{
			try {
				BusInfo info; info.setMileage(1);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusInfoMileageFail)
		{
			auto func = [] { BusInfo info; info.setMileage(-1); };
			Assert::ExpectException<HandleException>(func);
		}
		TEST_METHOD(TestBusInfoMileageFailMessage)
		{
			try {
				BusInfo info; info.setMileage(-1);
			}
			catch (HandleException& e) {
				Assert::AreEqual(e.what(), "The mileage isn't valid!");
			}
		}

		//BUS BUS()

		TEST_METHOD(TestBusConstructorPositive)
		{
			try {
				Bus info;
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusConstructorArgsPositive)
		{
			try {
				Bus info = Bus("f", 1,1, "d", 2000, 1);

			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusConstructorArgsBusInfoPositive)
		{
			try {
				BusInfo info;
				Bus bus = Bus("f", 1, info);

			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusConstructorArgsFail)
		{
			auto func = [] { Bus info = Bus("f", -1, 1, "d", 2000, 1); };
			Assert::ExpectException<HandleException>(func);
		}

		//BUS AREEQUAL()
		TEST_METHOD(TestBusAreEqualPositive)
		{
			Bus bus1, bus2;
			bool actual = bus1.areEqual(bus2);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestBusAreEqualArgsPositive)
		{
			Bus bus1 = Bus("a",3,1, "f", 2, 4);
			Bus bus2 = Bus("a",3,1, "f", 2, 4);
			bool actual = bus1.areEqual(bus2);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestBusAreEqualArgsBusInfoPositive)
		{
			BusInfo info1, info2;
			Bus bus1 = Bus("a", 3, info1);
			Bus bus2 = Bus("a", 3,info2);
			bool actual = bus1.areEqual(bus2);
			bool expected = true;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestBusAreEqualArgsNegative)
		{
			Bus bus1 = Bus("b", 3, 1, "f", 2, 4);
			Bus bus2 = Bus("a", 3, 1, "f", 2, 4);
			bool actual = bus1.areEqual(bus2);
			bool expected = false;
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(TestBusAreEqualArgsBusInfoNegative)
		{
			BusInfo info1, info2;
			Bus bus1 = Bus("a", 1, info1);
			Bus bus2 = Bus("a", 3, info2);
			bool actual = bus1.areEqual(bus2);
			bool expected = false;
			Assert::AreEqual(actual, expected);
		}

		//BUS SETNAME()
		TEST_METHOD(TestBusNameFail)
		{
			auto func = [] { Bus info; info.setName("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"); };
			Assert::ExpectException<HandleException>(func);
		}
		TEST_METHOD(TestBusNameFailMessage)
		{
			try {
				Bus info; info.setName("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
			}
			catch (HandleException& e) {
				Assert::AreEqual(e.what(), "The name isn't valid!");
			}
		}

		//BUS SETROUTE()
		TEST_METHOD(TestBusRouteMaxPositive)
		{
			try {
				Bus info; info.setNumberRoute(99999);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusRouteMinPositive)
		{
			try {
				Bus info; info.setNumberRoute(0);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusRoutePositive)
		{
			try {
				Bus info; info.setNumberRoute(1);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusRouteFail)
		{
			auto func = [] { Bus info; info.setNumberRoute(-1); };
			Assert::ExpectException<HandleException>(func);
		}
		TEST_METHOD(TestBusRouteFailMessage)
		{
			try {
				Bus info; info.setNumberRoute(-1);
			}
			catch (HandleException& e) {
				Assert::AreEqual(e.what(), "The number of route isn't valid!");
			}
		}

		//BUS SETBUSINFO()
		TEST_METHOD(TestBusBusInfoArgsPositive)
		{
			try {
				Bus info; info.setBusInfo(1,"f",2,1);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestBusBusInfoPositive)
		{
			try {
				BusInfo info;
				Bus bus; bus.setBusInfo(info);
			}
			catch (HandleException& e) {
				Assert::Fail();
			}
		}

	};
}
