#include <assert.h>
#include "TestRepoFile.h"
#include "Repo.h"
#include "Food.h"
#include "Drink.h"
#include "ValidationExeption.h"
#include "RepoException.h"

void TestRepoFile::testGetSetFilename()
{
	RepoFile repofile;
	repofile.setFileName(this->fileNameOut);
	assert(repofile.getFileName() == this->fileNameOut);
}

void TestRepoFile::testFindProduct()
{
	RepoFile repoFile = RepoFile(this->fileNameIn);
	Food* f = new Food("food 1", "hot_meal", 55.75, 20, 18, 360.65, "capsuni");
	Drink* d = new Drink("drink 1", "hot_chocolate", 10.25, 12, 5, 1.5);
	assert(repoFile.findProduct(f) == 0);
	assert(repoFile.findProduct(d) == 1);
}

void TestRepoFile::testAddProduct()
{
	RepoFile repoFile = RepoFile(this->fileNameIn);
	repoFile.setFileName(this->fileNameOut);
	Food* f = new Food("food 12", "salad", 55.75, 20, 18, 360.65, "pere");
	repoFile.addProduct(f);
	assert(repoFile.getSize() == this->products.size() + 1);
	assert(*repoFile.getProduct(repoFile.getSize() - 1) == *f);
}

void TestRepoFile::testUpdateProduct()
{
	RepoFile repoFile = RepoFile(this->fileNameIn);
	repoFile.setFileName(this->fileNameOut);
	Food* newF1 = new Food("food 1", "salad", 25.0, 40, 23, 15.25, "mere");
	Food* newF2 = new Food("food 2", "fast_food", 15.20, 32, 17, 5.5, "capsuni");
	repoFile.updateProduct(this->products[1], newF1);
	assert(*repoFile.getProduct(0) == *this->products[0]);
	assert(*repoFile.getProduct(1) == *newF1);
}

void TestRepoFile::testDeleteProduct()
{
	RepoFile repoFile = RepoFile(this->fileNameIn);
	repoFile.setFileName(this->fileNameOut);
	repoFile.deleteProduct(this->products[0]);
	assert(repoFile.getSize() == 1);
	assert(*repoFile.getProduct(0) == *this->products[1]);
	Food* f = new Food("food 1", "hot_meal", 55.75, 20, 18, 360.65, "capsuni");
	try {
		repoFile.deleteProduct(f);
	}
	catch (RepoException& exe) {}
	catch (...) { assert(false); }
	assert(repoFile.getSize() == 1);
	assert(*repoFile.getProduct(0) == *this->products[1]);
}

void TestRepoFile::testLoadFromFile()
{
	RepoFile repoFile = RepoFile(this->fileNameIn);
	assert(repoFile.getSize() == this->products.size());
	for (int i = 0; i < this->products.size(); i++)
	{
		assert(*repoFile.getProduct(i) == *this->products[i]);
	}
}

void TestRepoFile::testSaveToFile()
{
	RepoFile repoFile = RepoFile(this->fileNameIn);;
	repoFile.setFileName(this->fileNameOut);
	Product* newProduct = new Product("bomboane cu capsuni" , "dulciuri", 20.25, 500, 300);
	repoFile.addProduct(newProduct);
	repoFile.saveToFile();
	repoFile.loadFromFile();
	assert(repoFile.getSize() == this->products.size() + 1);
	vector<Product*> products = repoFile.getAll();
	for (int i = 0; i < repoFile.getSize() - 1; i++)
	{
		assert(*products[i] == *this->products[i]);
	}
	assert(*products[products.size() - 1] == *newProduct);
}

void TestRepoFile::testEmpty()
{
	RepoFile repo(fileNameOut);
	repo.empty();
	assert(repo.getSize() == 0);
	repo.loadFromFile();
	assert(repo.getSize() == 0);
}

TestRepoFile::TestRepoFile()
{
	Food* f = new Food("food 1", "hot_meal", 55.75, 20, 18, 360.65, "capsuni");
	Drink* d = new Drink("drink 1", "hot_chocolate", 10.25, 12, 5, 1.5);
	this->products.push_back(f);
	this->products.push_back(d);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::runAllTests()
{
	this->testGetSetFilename();
	this->testFindProduct();
	this->testAddProduct();
	this->testUpdateProduct();
	this->testDeleteProduct();
	this->testLoadFromFile();
	this->testSaveToFile();
	this->testEmpty();
}
