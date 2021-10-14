#include "Order.h"

Order::Order()
{
	this->product = NULL;
	this->noProducts = 0;
}

Order::Order(Product* p)
{
	this->product = p->clone();
	this->noProducts = 1;
}

Order::Order(Product* p, int noProducts)
{
	if (p == NULL)
		this->product = NULL;
	else
		this->product = p->clone();
	this->noProducts = noProducts;
}

Order::Order(const Order& o)
{
	this->product = o.product->clone();
	this->noProducts = o.noProducts;
}

Order::~Order()
{
	if (this->product)
	{
		delete this->product;
		this->product = NULL;
	}
}

Product* Order::getProduct()
{
	return this->product;
}

int Order::getNoProducts()
{
	return this->noProducts;
}

void Order::setProduct(Product* p)
{
	this->product = p->clone();
}

void Order::setNoProducts(int noProducts)
{
	this->noProducts = noProducts;
}

Order* Order::clone()
{
	Order* order = new Order(this->product, this->noProducts);
	return order;
}

Order& Order::operator=(const Order& o)
{
	this->product = o.product->clone();
	this->noProducts = o.noProducts;
	return *this;
}

Order& Order::operator++(int)
{
	this->noProducts++;
	return *this;
}

bool Order::operator==(const Order& o)
{
	if (this->product == NULL && o.product != NULL)
	{
		return false;
	}
	else if (this->product != NULL && o.product == NULL)
	{
		return false;
	}
	else if (this->product != NULL && o.product != NULL)
	{
		if (*this->product != *o.product)
			return false;
	}
	return this->noProducts == o.noProducts;
}

bool Order::operator!=(const Order& o)
{
	if (this->product == NULL && o.product != NULL)
	{
		return true;
	}
	else if (this->product != NULL && o.product == NULL)
	{
		return true;
	}
	else if (this->product != NULL && o.product != NULL)
	{
		if (*this->product != *o.product)
			return true;
	}
	return this->noProducts != o.noProducts;
}

string Order::toString()
{
	string order;
	string doubleNum;
	if (this->product == NULL)
	{
		order += "none x";
		order += to_string(this->noProducts);
		for (int i = order.size(); i < 46; i++)
			order += " ";
		order += "0.00 RON";
	}
	else {
		if (this->product->getName() == "")
			order += "none";
		else
			order += this->product->getName();
		order += " x";
		order += to_string(this->noProducts);
		for (int i = order.size(); i < 46; i++)
			order += " ";
		doubleNum = to_string(this->product->getPrice() * this->noProducts);
		order += doubleNum.substr(0, doubleNum.find(".") + 3);
		order += " RON";
	}
	return order;
}

ostream& operator<<(ostream& os, Order& o)
{
	if (o.product == NULL)
		os << "NULL ";
	else
		os << o.product->toString() << " ";
	os<< o.noProducts;
	return os;
}
