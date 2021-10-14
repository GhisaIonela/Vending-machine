#pragma once
#ifndef TESTSERVICE_H
#define TESTSERVICE_H

#include "Service.h"

class TestService {
private:
	string fileNameIn = "testServiceIn.txt";
	string fileNameOut = "testServiceOut.txt";
	RepoFile products;
	vector<Order*> orders;
	void testConstructors();
	void testLoadProductsFromFile();
	void testProducts();
	void testOrders();
	void testGetAllByCategory();
	void testSortProducts();
	void testFilterOrders();
public:
	TestService();
	~TestService();
	void runAllTests();
};
#endif // !TESTSERVICE_H
