#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include "RepoFile.h"
#include "Order.h"
#include "ServiceException.h"
#include <vector>

class Service {
private:
	RepoFile products;
	vector<Order*> orders;
public:
	Service();
	Service(string storageInFile);
	~Service();

	int getProductsSize();
	Product* getProduct(int index);
	vector<Product*> getAllProducts(); 
	void setProductsFile(string productsFile);
	void loadProductsFromFile(string productsInFile);
	int findProduct(Product* p);
	void addProduct(Product* p);
	void deleteProduct(Product* p);
	void updateProduct(Product* oldP, Product* newP);
	void emptyProducts();

	int getOrdersSize();
	Order* getOrder(int index);
	vector<Order*> getAllOrders();
	void addOrder(Product* p);

	vector<Product*> getAllByCategory(vector<Product*> products, string category);
	vector<Product*> sortByPrice(vector<Product*> toSort);
	vector<Product*> sortByName(vector<Product*> toSort);
	void filterByCategory(string category);
	void filterByPrice(double price);
	void purchaseProducts();
	string getTotal();
	void emptyOrders();
};
#endif // !SERVICE_H
