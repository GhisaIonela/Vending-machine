#include "Product.h"
#include <stdlib.h>

Product::Product()
{
	this->name = "";
	this->category = "";
	this->price = 0.0;
	this->stock = 0;
	this->orders = 0;
}

Product::Product(string name, string category, double price, int stock, int orders)
{
	this->name = name;
	this->category = category;
	this->price = price;
	this->stock = stock;
	this->orders = orders;
}

Product::Product(const Product& p)
{
	this->name = p.name;
	this->category = p.category;
	this->price = p.price;
	this->stock = p.stock;
	this->orders = p.orders;
}

Product::~Product()
{
}

string Product::getName()
{
	return this->name;
}

string Product::getCategory()
{
	return this->category;
}

double Product::getPrice()
{
	return this->price;
}

int Product::getStock()
{
	return this->stock;
}

int Product::getOrders()
{
	return this->orders;
}

void Product::setName(string name)
{
	this->name = name;
}

void Product::setCategory(string category)
{
	this->category = category;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setStock(int stock)
{
	this->stock = stock;
}

void Product::setOrders(int orders)
{
	this->orders = orders;
}

Product* Product::clone()
{
	Product* newProduct = new Product(this->name, this->category, this->price, this->stock, this->orders);
	/*newProduct->setName(this->name);
	newProduct->setCategory(this->category);
	newProduct->setPrice(this->price);
	newProduct->setStock(this->stock);
	newProduct->setOrders(this->orders);*/
	return newProduct;;
}

Product& Product::operator=(const Product& p)
{
	if (this != &p) {
		this->setName(p.name);
		this->setCategory(p.category);
		this->setPrice(p.price);
		this->setStock(p.stock);
		this->setOrders(p.orders);
	}
	return *this;
}

bool Product::operator==(const Product& p)
{
	return this->name == p.name && this->category == p.category && this->price == p.price && this->stock == p.stock && this->orders == p.orders;
}

bool Product::operator!=(const Product& p)
{
	return this->name != p.name || this->category != p.category || this->price != p.price || this->stock != p.stock || this->orders != p.orders;
}

string Product::toStringUI()
{
	string product;
	string doubleNum;

	if (this->name == "")
		product += "none";
	else
		product += this->name;

	for (int i = product.size(); i < 46; i++)
		product += " ";

	doubleNum = to_string(this->price);
	product += doubleNum.substr(0, doubleNum.find(".") + 3);
	product += " RON";
	return product;
}

string Product::toString()
{
	string product;
	product += "P ";
	if (this->name == "")
		product += "none";
	else
		product += this->name;
	product += ": ";
	if (this->category == "")
		product += "none";
	else
		product += this->category;
	product += " ";
	product += to_string(this->price);
	product += " ";
	product += to_string(this->stock);
	product += " ";
	product += to_string(this->orders);
	return product;
}

ostream& operator<<(ostream& os, Product& p)
{
	os << p.name << ": " << p.category << " " << p.price << " " << p.stock << " " << p.orders;
	return os;
}
