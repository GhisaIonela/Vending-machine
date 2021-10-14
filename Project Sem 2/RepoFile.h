#pragma once
#include "Repo.h"

class RepoFile : public Repo {
private:
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();

	string getFileName();
	void setFileName(string fileName);

	void addProduct(Product* p);
	void updateProduct(Product* oldP, Product* newP);
	void deleteProduct(Product* p);

	void loadFromFile();
	void saveToFile();

	void empty();
};