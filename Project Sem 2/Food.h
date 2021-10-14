#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "Product.h"

class Food :public Product {
private:
	double grams;
	string ingredients;
public:
	Food();
	Food(string name, string category, double price, int stock, int orders, double grams, string ingredients);
	Food(const Food& food);
	~Food();

	double getGrams();
	string getIngredients();

	void setGrams(double grams);
	void setIngredients(string ingredients);

	Food* clone();
	Food& operator=(const Food& food);

	bool operator==(const Food& food);
	bool operator!=(const Food& food);

	string toStringUI();
	string toString();
	friend ostream& operator<<(ostream& os, Food& food);
};
#endif // !FOOD_H
