#pragma once
#ifndef PRODUCTVALIDATOR_H
#define PRODUCTVALIDATOR_H

#include "ValidationExeption.h"
#include "Product.h"
#include "FoodValidator.h"
#include "DrinkValidator.h"
#include <vector>

class ProductValidator {
public:
	ProductValidator() {}
	~ProductValidator() {}
	void validate(string product) throw(ValidationExeption) {
		string errors = "";
		if (product.empty()){
			throw ValidationExeption("the input is NULL");
		}
		else {
			int pos;
			pos = product.find(" ");
			if (pos < 0 || product.size() <= pos)
				throw ValidationExeption("invalid product format");
			string code = product.substr(0, pos);
			product = product.erase(0, pos + 1);

			if (code == "P") {
				pos = product.find(":");
				if (pos < 0 || product.size() <= pos)
					throw ValidationExeption("invalid product format");
				string name = product.substr(0, pos);
				product = product.erase(0, pos + 2);

				pos = product.find(" ");
				if (pos < 0 || product.size() <= pos)
					throw ValidationExeption("invalid product format");
				string category = product.substr(0, pos);
				product = product.erase(0, pos + 1);

				pos = product.find(" ");
				if (pos < 0 || product.size() <= pos)
					throw ValidationExeption("invalid product format");
				string price = product.substr(0, pos);
				product = product.erase(0, pos + 1);

				pos = product.find(" ");
				if (pos < 0 || product.size() <= pos)
					throw ValidationExeption("invalid product format");
				string stock = product.substr(0, pos);
				product = product.erase(0, pos + 1);

				string orders = product;

				int commas = 0, ok = 1;
				for (int i = 0; i < price.size() && ok == 1; i++) {
					if (price[i] == '.')
						commas++;
					else if (!isdigit(price[i])) {
						ok = 0;
					}
				}
				if (commas > 1 || ok == 0) {
					if (errors == "") {
						errors += "price should be a decimal number";
					}
					else {
						errors += "; price should be a decimal number";
					}
				}

				ok = 1;
				for (int i = 0; i < stock.size() && ok == 1; i++) {
					if (!isdigit(stock[i])) {
						ok = 0;
					}
				}
				if (ok == 0) {
					if (errors == "") {
						errors += "stock should be an integer";
					}
					else {
						errors += "; stock should be an integer";
					}
				}

				ok = 1;
				for (int i = 0; i < orders.size() && ok == 1; i++) {
					if (!isdigit(orders[i])) {
						ok = 0;
					}
				}
				if (ok == 0) {
					if (errors == "") {
						errors += "orders should be an integer";
					}
					else {
						errors += "; orders should be an integer";
					}
				}
			}
			else if (code == "F") {
				FoodValidator foodValidator;
				foodValidator.validate(product);
			}
			else if (code == "D") {
				DrinkValidator drinkValidator;
				drinkValidator.validate(product);
			}
			else throw ValidationExeption("invalid product code");
		}

		if (errors != "") {
			throw ValidationExeption(errors);
		}
	}
};
#endif // !PRODUCTVALIDATOR_H
