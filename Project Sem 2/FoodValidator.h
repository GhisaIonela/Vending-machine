#ifndef FOODVALIDATOR_H
#define FOODVALIDATOR_H

#include "ValidationExeption.h"
#include "Food.h"
#include <vector>

class FoodValidator {
public:
	FoodValidator() {}
	~FoodValidator() {}
	void validate(string product) throw(ValidationExeption) {
		string errors;
		vector<string> categories = { "none", "salad", "fast_food", "pasta", "hot_meal", "soup" };
		int pos;
		pos = product.find(":");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid food format");
		string name = product.substr(0, pos);
		product = product.erase(0, pos + 2);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid food format");
		string category = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid food format");
		string price = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid food format");
		string stock = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid food format");
		string orders = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		pos = product.find(" ");
		if (pos < 0 || product.size() <= pos)
			throw ValidationExeption("invalid food format");
		string grams = product.substr(0, pos);
		product = product.erase(0, pos + 1);

		string ingredients = product;

		int ok = 0;
		for (int i = 0; i < categories.size() && ok == 0; i++) {
			if (category == categories[i])
				ok = 1;
		}
		if (ok == 0) {
			if (errors == "") {
				errors += "invalid category for food";
			}
			else {
				errors += "; invalid category for food";
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
		for (int i = 0; i < grams.size() && ok == 1; i++) {
			if (grams[i] == '.')
				commas++;
			else if (!isdigit(grams[i])) {
				ok = 0;
			}
		}
		if (commas > 1 || ok == 0) {
			if (errors == "") {
				errors += "grams should be a decimal number";
			}
			else {
				errors += "; grams should be a decimal number";
			}
		}

		if (errors != "") {
			throw ValidationExeption(errors);
		}
	}
};
#endif // !FOODVALIDATOR_H
