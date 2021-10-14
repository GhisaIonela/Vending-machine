#include "RepoFile.h"
#include "Food.h"
#include "Drink.h"
#include "ProductValidator.h"
#include <fstream>

RepoFile::RepoFile()
{
	this->fileName = "";
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
	this->loadFromFile();
}

RepoFile::~RepoFile()
{
}

string RepoFile::getFileName()
{
	return this->fileName;
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

void RepoFile::addProduct(Product* p)
{
	Repo::addProduct(p);
	this->saveToFile();
}

void RepoFile::updateProduct(Product* oldP, Product* newP)
{
	Repo::updateProduct(oldP, newP);
	this->saveToFile();
}

void RepoFile::deleteProduct(Product* p)
{
	Repo::deleteProduct(p);
	this->saveToFile();
}

void RepoFile::loadFromFile()
{
	ifstream file(this->fileName);
	if (file.is_open())
	{
		Repo::empty();
		string line;
		string delim1 = ":";
		string delim2 = " ";
		while (getline(file, line))
		{
			this->productValidator.validate(line);
			string code = line.substr(0, 1);
			if (line.substr(0, 1) == "P")
			{
				line = line.erase(0, 2);

				int pos = line.find(delim1);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 2);

				pos = line.find(delim2);
				string category = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				double price = stod(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				int stock = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				int orders = stoi(line);

				if (name == "none")
					name = "";
				if (category == "none")
					category = "";

				Product* p = new Product(name, category, price, stock, orders);
				this->products.push_back(p);
			}
			else if (line.substr(0, 1) == "F")
			{
				line = line.erase(0, 2);

				int pos = line.find(delim1);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 2);

				pos = line.find(delim2);
				string category = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				double price = stod(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				int stock = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				int orders = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				double grams = stod(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				string ingredients = line;

				if (name == "none")
					name = "";
				if (category == "none")
					category = "";
				if (ingredients == "none")
					ingredients = "";

				Food* f = new Food(name, category, price, stock, orders, grams, ingredients);
				this->products.push_back(f);
			}
			else if (line.substr(0, 1) == "D")
			{
				line = line.erase(0, 2);

				int pos = line.find(delim1);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 2);

				pos = line.find(delim2);
				string category = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				double price = stod(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				int stock = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim2);
				int orders = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				double liters = stod(line);

				if (name == "none")
					name = "";
				if (category == "none")
					category = "";

				Drink* d = new Drink(name, category, price, stock, orders, liters);
				this->products.push_back(d);
			}
		}
		file.close();
	}
}

void RepoFile::saveToFile()
{
	ofstream file(this->fileName);
	if (file.is_open())
	{
		for (Product* produs : this->products)
		{
			file << produs->toString() << endl;
		}
	}
	file.close();
}

void RepoFile::empty()
{
	Repo::empty();
	this->saveToFile();
}
