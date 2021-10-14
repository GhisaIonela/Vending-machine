#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
protected:
	string name;
	string category;
	double price;
	int stock;
	int orders;
public:
	Product();
	Product(string name, string category, double price, int stock, int orders);
	Product(const Product& p);
	virtual ~Product();

	string getName();
	string getCategory();
	double getPrice();
	int getStock();
	int getOrders();

	void setName(string name);
	void setCategory(string category);
	void setPrice(double price);
	void setStock(int stock);
	void setOrders(int orders);

	virtual Product* clone();
	virtual Product& operator=(const Product& p);

	bool operator==(const Product& p);
	bool operator!=(const Product& p);

	virtual string toStringUI();
	virtual string toString();
	friend ostream& operator<<(ostream& os, Product& p);
};
#endif // !PRODUCT_H