/*
 * TestLin2dSolver.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: Arvind A de Menezes Pereira
 */

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>

#include "../WaterMeterCounter.h"

using namespace std;

class TestWaterMeterCounter : public CppUnit::TestFixture {
private:
	WaterMeterCounter *testCounter;
public:
	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("Test Counting Logic");

		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("One initial reading should not increment counter",
				&TestWaterMeterCounter::testOneReading ));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("Initial readings going into RISING direction should result in 0",
				&TestWaterMeterCounter::testDefaultRising ));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("Peak only readings test",
				&TestWaterMeterCounter::testPeakOnlyPoints ));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("Bouncing back and forth around the same point should not result in coounter increment",
				&TestWaterMeterCounter::testBouncingInPlace ));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("Nice sequential data reversing direction once should result in 1 counter increment",
				&TestWaterMeterCounter::testNormalSequence ));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("When extremums don't stay in the same point, we need to adapt accordingly",
				&TestWaterMeterCounter::testAdaptableWave ));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestWaterMeterCounter>("Standard sequence shifted.",
				&TestWaterMeterCounter::testNormalSequenceShifted ));

		return suiteOfTests;
	}

	/// Setup method
	void setUp() {
		testCounter = new WaterMeterCounter();
	}

	/// Teardown method
	void tearDown() {
	}

protected:
	void testOneReading() {
		testCounter->reading(505);
		CPPUNIT_ASSERT_EQUAL( 0UL, testCounter->getCounter() );
	}
	void testDefaultRising() {
		testCounter->reading(505);
		testCounter->reading(506);
		testCounter->reading(507);
		testCounter->reading(508);
		CPPUNIT_ASSERT_EQUAL( 0UL, testCounter->getCounter() );
	}
	
	void testNormalSequence() {
		testCounter->reading(505);
		testCounter->reading(506);
		testCounter->reading(507);
		testCounter->reading(508);
		testCounter->reading(509);
		testCounter->reading(508);
		testCounter->reading(507);
		testCounter->reading(506);
		testCounter->reading(505);
		CPPUNIT_ASSERT_EQUAL( 1UL, testCounter->getCounter() );	
	}
	
	void testNormalSequenceShifted() {
		testCounter->reading(405);
		testCounter->reading(406);
		testCounter->reading(407);
		testCounter->reading(408);
		testCounter->reading(409);
		testCounter->reading(408);
		testCounter->reading(407);
		testCounter->reading(406);
		testCounter->reading(405);
		CPPUNIT_ASSERT_EQUAL( 1UL, testCounter->getCounter() );
	}
	
	void testPeakOnlyPoints() {
		// If we read only at peaks, test that we capture each of them
		// We need to observe at least 3 points difference
		testCounter->reading(405);
		testCounter->reading(410);
		testCounter->reading(405);
		CPPUNIT_ASSERT_EQUAL( 1UL, testCounter->getCounter() );
		testCounter->reading(410);
		CPPUNIT_ASSERT_EQUAL( 2UL, testCounter->getCounter() );
		testCounter->reading(405);
		CPPUNIT_ASSERT_EQUAL( 3UL, testCounter->getCounter() );
		testCounter->reading(410);
		CPPUNIT_ASSERT_EQUAL( 4UL, testCounter->getCounter() );
		testCounter->reading(405);
		CPPUNIT_ASSERT_EQUAL( 5UL, testCounter->getCounter() );
	}
	
	void testBouncingInPlace() {
		// We need to observe at least 3 points difference, so this should result in 0 counter
		testCounter->reading(405);
		testCounter->reading(406);
		testCounter->reading(405);
		testCounter->reading(406);
		testCounter->reading(405);
		testCounter->reading(406);
		testCounter->reading(405);
		testCounter->reading(406);
		testCounter->reading(405);
		testCounter->reading(406);
		CPPUNIT_ASSERT_EQUAL( 0UL, testCounter->getCounter() );
	}
	
	void testAdaptableWave() {
		// When extremums shift, we need to be able to still adapt to it, instead of requiring rebuild to set those constants
		testCounter->reading(405);
		testCounter->reading(410); // Still rising, so no increment
		CPPUNIT_ASSERT_EQUAL( 0UL, testCounter->getCounter() );
		testCounter->reading(406);
		CPPUNIT_ASSERT_EQUAL( 1UL, testCounter->getCounter() );
		testCounter->reading(415);
		CPPUNIT_ASSERT_EQUAL( 2UL, testCounter->getCounter() );
		testCounter->reading(410);
		CPPUNIT_ASSERT_EQUAL( 3UL, testCounter->getCounter() );
		testCounter->reading(420);
		CPPUNIT_ASSERT_EQUAL( 4UL, testCounter->getCounter() );
		testCounter->reading(415);
		CPPUNIT_ASSERT_EQUAL( 5UL, testCounter->getCounter() );
		testCounter->reading(423);
		CPPUNIT_ASSERT_EQUAL( 6UL, testCounter->getCounter() );
		testCounter->reading(405);
		CPPUNIT_ASSERT_EQUAL( 7UL, testCounter->getCounter() );
		testCounter->reading(410);
		CPPUNIT_ASSERT_EQUAL( 8UL, testCounter->getCounter() );
	}

};
