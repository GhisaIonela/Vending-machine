#include "Food.h"

Food::Food():Product()
{
	this->grams = 0.0;
	this->ingredients = "";
}

Food::Food(string name, string category, double price, int stock, int orders, double grams, string ingredients)
	:Product(name, category, price, stock, orders)
{
	this->grams = grams;
	this->ingredients = ingredients;
}

Food::Food(const Food& food):Product(food)
{
	this->grams = food.grams;
	this->ingredients = food.ingredients;
}

Food::~Food()
{
}

double Food::getGrams()
{
	return this->grams;
}

string Food::getIngredients()
{
	return this->ingredients;
}

void Food::setGrams(double grams)
{
	this->grams = grams;
}

void Food::setIngredients(string ingredients)
{
	this->ingredients = ingredients;
}

Food* Food::clone()
{
	Food* newFood = new Food(this->name, this->category, this->price, 
		this->stock, this->orders, this->grams, this->ingredients);
	return newFood;
}

Food& Food::operator=(const Food& food)
{
	if (this != &food) {
		Product::operator=(food);
		this->grams = food.grams;
		this->setIngredients(food.ingredients);
	}
	return *this;
}

bool Food::operator==(const Food& food)
{
	return Product::operator==(food) && this->grams == food.grams 
		&& this->ingredients == food.ingredients;
}

bool Food::operator!=(const Food& food)
{
	return Product::operator!=(food) || this->grams != food.grams || this->ingredients != food.ingredients;
}

string Food::toStringUI()
{
	string food;
	string doubleNum;

	if (this->name == "")
		food += "none";
	else
		food += this->name;
	food += "   ";

	doubleNum = to_string(this->grams);
	food += doubleNum.substr(0, doubleNum.find(".") + 3);
	food += "g ";

	for (int i = food.size(); i < 46; i++)
		food += " ";

	doubleNum = to_string(this->price);
	food += doubleNum.substr(0, doubleNum.find(".") + 3);
	food += " RON";

	if (this->ingredients != "")
	{
		if (this->ingredients.size() < 46)
		{
			food += "\n|   ";
			food += this->ingredients;
		}
		else {
			string line1 = this->ingredients, line2;
			while (line1.size() >= 46)
			{
				food += "\n|   ";
				food += line1.substr(0, 45);
				line1.erase(0, 45);
			}
			food += "\n|   ";
			food += line1;
		}
	}
	return food;
}

string Food::toString()
{
	string food;
	food += "F ";
	if (this->name == "")
		food += "none";
	else
		food += this->name;
	food += ": ";
	if (this->category == "")
		food += "none";
	else
		food += this->category;
	food += " ";
	food += to_string(this->price);
	food += " ";
	food += to_string(this->stock);
	food += " ";
	food += to_string(this->orders);
	food += " ";
	food += to_string(this->grams);
	food += " ";
	if (this->ingredients == "")
		food += "none";
	else
		food += this->ingredients;
	return food;
}

ostream& operator<<(ostream& os, Food& food)
{
	os << (Product&)food << " " << food.grams << " " << food.ingredients;
	return os;
}
