#pragma once
#ifndef ORDER_H

#include "Product.h"
#include <string.h>

class Order {
private:
	Product* product;
	int noProducts;
public:
	Order();
	Order(Product* p);
	Order(Product* p, int noProducts);
	Order(const Order& o);
	~Order();

	Product* getProduct();
	int getNoProducts();
	void setProduct(Product* p);
	void setNoProducts(int noProducts);

	Order* clone();
	Order& operator=(const Order& o);
	Order& operator++(int);
	bool operator==(const Order& o);
	bool operator!=(const Order& o);

	string toString();
	friend ostream& operator<<(ostream& os, Order& o);
};
#endif // !ORDER_H
