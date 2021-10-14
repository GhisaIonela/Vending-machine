#pragma once
#ifndef DRINK_H
#define DRINK_H

#include "Product.h"

class Drink :public Product {
private:
	double liters;
public:
	Drink();
	Drink(string name, string category, double price, int stock, int orders, double liters);
	Drink(const Drink& drink);
	~Drink();

	double getLiters();
	void setLiters(double liters);

	Drink* clone();
	Drink& operator=(const Drink& drink);

	bool operator==(const Drink& drink);
	bool operator!=(const Drink& drink);

	string toStringUI();
	string toString();
	friend ostream& operator<<(ostream& os, Drink& drink);
};
#endif // !DRINK_H
