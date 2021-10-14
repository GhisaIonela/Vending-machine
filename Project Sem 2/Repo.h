#pragma once
#include "Product.h"
#include "ProductValidator.h"
#include "RepoException.h"
#include <vector>

class Repo {
protected:
	vector<Product*> products;
	ProductValidator productValidator;
public:
	Repo();
	~Repo();

	vector<Product*> getAll();
	int getSize();
	Product* getProduct(int index) throw(RepoException);

	int findProduct(Product* p);
	void addProduct(Product* p) throw(RepoException);
	void updateProduct(Product* oldP, Product* newP) throw(RepoException);
	void deleteProduct(Product* p) throw(RepoException);

	void empty();
};