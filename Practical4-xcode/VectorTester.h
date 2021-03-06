/*
 * VectorTester.h
 *
 *  Created on: 15 Oct 2014
 *      Author: np183
 */

#ifndef VECTORTESTER_H_
#define VECTORTESTER_H_

#include <string>

class VectorTester {
public:
	VectorTester();
	~VectorTester();

	void testCtor();
	void testCopyCtor();
	void testPushBack();
	void testOperatorSqBr();
	void testOperatorEq();
	void testSize();
	void testEmpty();
	void testClear();
	void testMemory();
	void testToString();
	void testOSRedir();
	void testISRedir();

private:
	void errorOut_(const std::string& errMsg, unsigned int errBit);
	bool errorSet_(unsigned int mask);
	void passOut_(const std::string& passMsg);

	void CompareWithStringSimple_(const std::string& result,int* arr,int size);
	void CompareWithString_(const std::string& result,int* arr,int size,int length,char fill);

	char error_;
	std::string funcname_;
};

#endif /* VECTORTESTER_H_ */
