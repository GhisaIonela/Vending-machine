#pragma once
#ifndef UI_H
#define UI_H

#include "Service.h"
#include "ValidationExeption.h"
#include "RepoException.h"
#include "ServiceException.h"

class UI {
private:
	string productsFileNameIn = "productsIn.txt";
	Service service;

	void populateProducts();

	void showKeyPad();
	int commandUI() throw(ValidationExeption);
	void showException(string e);

	void showProducts(vector<Product*> products);
	void showProductsOptions();
	void productsUI(string category);

	void showOrders(vector<Order*> orders);
	void showOrdersOptions();
	void ordersUI();
	void filterByCategoryUI();
	void filterByPriceUI();
	double getPrice();
public:
	void runMenu() throw(ValidationExeption);
};
#endif // !UI_H
