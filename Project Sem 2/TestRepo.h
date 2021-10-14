#pragma once
#include "Product.h"
#include <vector>

class TestRepo {
private:
	vector<Product*> products;

	void testGetAll();
	void testGetSize();
	void testGetProduct();
	void testFindProduct();
	void testAddProduct();
	void testUpdateProduct();
	void testDeleteProduct();
public:
	TestRepo();
	~TestRepo();
	void runAllTests();
};