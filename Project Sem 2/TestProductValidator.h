#pragma once
#ifndef TESTPRODUCTVALIDATOR_H
#define TESTPRODUCTVALIDATOR_H

#include "ProductValidator.h"

class TestProductValidator {
private:
	ProductValidator productValidator;
public:
	TestProductValidator();
	~TestProductValidator();
	void runAllTests();
};
#endif // !TESTPRODUCTVALIDATOR_H
