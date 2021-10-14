#include "Drink.h"

Drink::Drink() :Product()
{
	this->liters = 0.0;
}

Drink::Drink(string name, string category, double price, int stock, int orders, double liters)
	:Product(name, category, price, stock, orders)
{
	this->liters = liters;

}

Drink::Drink(const Drink& drink):Product(drink)
{
	this->liters = drink.liters;
}

Drink::~Drink()
{
}

double Drink::getLiters()
{
	return this->liters;
}

void Drink::setLiters(double liters)
{
	this->liters = liters;
}

Drink* Drink::clone()
{
	Drink* newDrink = new Drink(this->name, this->category, this->price, this->stock, this->orders, this->liters);
	/*newDrink->setName(this->getName());
	newDrink->setCategory(this->getCategory());
	newDrink->setPrice(this->getPrice());
	newDrink->setStock(this->getStock());
	newDrink->setOrders(this->getOrders());
	newDrink->setLiters(this->getLiters());*/
	return newDrink;
}

Drink& Drink::operator=(const Drink& drink)
{
	if (this != &drink) {
		Product::operator=(drink);
		this->liters = drink.liters;
	}
	return *this;
}

bool Drink::operator==(const Drink& drink)
{
	return Product::operator==(drink) && this->liters == drink.liters;
}

bool Drink::operator!=(const Drink& drink)
{
	return Product::operator!=(drink) || this->liters != drink.liters;
}

string Drink::toStringUI()
{
	string drink;
	string doubleNum;

	if (this->name == "")
		drink += "none";
	else
		drink += this->name;
	drink += "   ";

	doubleNum = to_string(this->liters);
	drink += doubleNum.substr(0, doubleNum.find(".") + 3);
	drink += "L";

	for (int i = drink.size(); i < 46; i++)
		drink += " ";

	doubleNum = to_string(this->price);
	drink += doubleNum.substr(0, doubleNum.find(".") + 3);
	drink += " RON";
	return drink;
}

string Drink::toString()
{
	string drink;
	drink += "D ";
	if (this->name == "")
		drink += "none";
	else
		drink += this->name;
	drink += ": ";
	if (this->category == "")
		drink += "none";
	else
		drink += this->category;
	drink += " ";
	drink += to_string(this->price);
	drink += " ";
	drink += to_string(this->stock);
	drink += " ";
	drink += to_string(this->orders);
	drink += " ";
	drink += to_string(this->liters);
	return drink;
}

ostream& operator<<(ostream& os, Drink& drink)
{
	os << (Product&)drink << " " << drink.liters;
	return os;
}
