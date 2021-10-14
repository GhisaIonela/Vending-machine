#pragma once
#ifndef TESTPRODUCTS_H
#define TESTPRODUCTS_H

#include "Product.h"
#include "Food.h"
#include "Drink.h"

class TestProducts {
private:
	void testConstructors();
	void testSetters();
	void testClone();
	void testAssignmentOperator();
	void testToString();
	void testIOstream();
public:
	void runAllTests();
};
#endif // !TESTPRODUCTS_H
