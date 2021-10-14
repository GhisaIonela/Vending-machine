#pragma once
#ifndef TESTORDER_H
#define TESTORDER_H

#include "Order.h"
#include "Product.h"
#include "Food.h"
#include "Drink.h"

class TestOrder {
private:
	void testConstructors();
	void testSetters();
	void testClone();
	void testBoolOperators();
	void testAssignmentOperator();
	void testIncrementOperator();
	void testToString();
	void testIOstream();
public:
	void runAllTests();
};
#endif // !TESTORDER_H