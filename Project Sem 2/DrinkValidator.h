#ifndef DRINKVALIDATOR_H
#define DRINKVALIDATOR_H

#include "ValidationExeption.h"
#include "Drink.h"
#include <vector>

class DrinkValidator {
public:
	DrinkValidator() {}
	~DrinkValidator() {}
	void validate(string product) throw(ValidationExeption) {
		string errors;
		vector<string> categories = { "none", "coffee", "hot_chocolate", "soft_drink",
			"juice", "milkshake", "water", "alcoholic_beverage" };
		int pos;
		pos = product.find(":");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid drink format");
		string name = product.substr(0, pos);
		product = product.erase(0, pos + 2);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid drink format");
		string category = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid drink format");
		string price = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid drink format");
		string stock = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid drink format");
		string orders = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		string liters = product;

		int ok = 0;
		for (int i = 0; i < categories.size() && ok == 0; i++) {
			if (category == categories[i])
				ok = 1;
		}
		if (ok == 0) {
			if (errors == "") {
				errors += "invalid category for drink";
			}
			else {
				errors += "; invalid category for drink";
			}
		}

		int commas = 0;
		ok = 1;
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

		commas = 0;
		ok = 1;
		for (int i = 0; i < liters.size() && ok == 1; i++) {
			if (liters[i] == '.')
				commas++;
			else if (!isdigit(liters[i])) {
				ok = 0;
			}
		}
		if (commas > 1 || ok == 0) {
			if (errors == "") {
				errors += "liters should be a decimal number";
			}
			else {
				errors += "; liters should be a decimal number";
			}
		}

		if (errors != "") {
			throw ValidationExeption(errors);
		}
	}
};
#endif // !DRINKVALIDATOR_H
