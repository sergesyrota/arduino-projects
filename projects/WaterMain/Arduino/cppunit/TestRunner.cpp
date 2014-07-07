/*
 * TestRunner.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: Arvind A de Menezes Pereira
 */

#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestWaterMeterCounter.h"

using namespace std;


int main() {
	CppUnit::TextUi::TestRunner runner;

	cout << "Creating Test Suites:" << endl;
	runner.addTest(TestWaterMeterCounter::suite());
	cout<< "Running the unit tests."<<endl;
	runner.run();

	return 0;
}
