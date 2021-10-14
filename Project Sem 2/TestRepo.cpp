#include <assert.h>
#include "TestRepo.h"
#include "Product.h"
#include "Food.h"
#include "Drink.h"
#include "Repo.h"
#include "ValidationExeption.h"
#include "RepoException.h"


void TestRepo::testGetAll()
{
    Repo repo;
    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    vector<Product*> products = repo.getAll();
    assert(products.size() == this->products.size());
    for (int i = 0; i < this->products.size(); i++)
    {
        assert(*products[i] == *this->products[i]);
    }
}

void TestRepo::testGetSize()
{
    Repo repo;
    assert(repo.getSize() == 0);

    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    assert(this->products.size() == repo.getSize());
}

void TestRepo::testGetProduct()
{
    Repo repo;
    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    vector<Product*> products = repo.getAll();
    for (int i = 0; i < this->products.size(); i++)
    {
        assert(*repo.getProduct(i) == *this->products[i]);
    }
    try {
        repo.getProduct(-1);
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }

    try {
        repo.getProduct(repo.getSize());
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }
}

void TestRepo::testFindProduct()
{
    Repo repo;
    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    vector<Product*> products = repo.getAll();
    for (int i = 0; i < this->products.size(); i++)
    {
        assert(repo.findProduct(this->products[i]) == i);
    }

    Food* f = new Food("p", "adsa", 120.02, 212, 12, 23.265, "dasd njdsand j, sadm");
    assert(repo.findProduct(f) == -1);
}

void TestRepo::testAddProduct()
{
    Repo repo;
    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    Food* f = new Food("p", "soup", 120.02, 212, 12, 23.265, "dasd njdsand j, sadm");
    Food* f2 = new Food("p", "adsa", 120.02, 212, 12, 23.265, "dasd njdsand j, sadm");
    try {
        repo.addProduct(f);
        repo.addProduct(f2);
    }
    catch (ValidationExeption& exe) {}
    catch (...) { assert(false); }

    assert(repo.getSize() == this->products.size() + 1);
    assert(*repo.getProduct(this->products.size()) == *f);

    try {
        repo.addProduct(f);
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }

    Drink* d = new Drink("p", "juice", 120.02, 212, 12, 23.265);
    Drink* d2 = new Drink("p", "dsada", 120.02, 212, 12, 23.265);

    try {
        repo.addProduct(d);
        repo.addProduct(d2);
    }
    catch (ValidationExeption& exe) {}
    catch (...) { assert(false); }

    assert(repo.getSize() == this->products.size() + 2);
    assert(*repo.getProduct(this->products.size() + 1) == *d);

    try {
        repo.addProduct(d);
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }
}

void TestRepo::testUpdateProduct()
{
    Repo repo;
    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    Food* f1 = new Food("f3", "soup", 11.11, 11, 11, 11.111, "11 11, 1111 1, 1");
    Food* f2 = new Food("f4", "pasta", 22.2, 222, 2, 22.22, "22, 22 22222 222, 2222");

    Food* f = new Food("p", "adsa", 120.02, 212, 12, 23.265, "dasd njdsand j, sadm");
    Drink* d = new Drink("p", "adsa", 120.02, 212, 12, 23.265);
    Drink* d1 = new Drink("p", "juice", 120.02, 212, 12, 23.265);

    try {
        repo.updateProduct(this->products[1], f);
    }
    catch (ValidationExeption& exe) {}
    catch (...) { assert(false); }

    repo.updateProduct(this->products[1], f1);
    assert(repo.findProduct(this->products[1]) == -1);
    assert(repo.findProduct(f1) != -1);

    try {
        repo.updateProduct(this->products[1], f1);
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }

    try {
        repo.updateProduct(this->products[1], d);
    }
    catch (ValidationExeption& exe) {}
    catch (...) { assert(false); }

    try {
        repo.updateProduct(this->products[1], d1);
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }
}

void TestRepo::testDeleteProduct()
{
    Repo repo;
    for (int i = 0; i < this->products.size(); i++)
    {
        repo.addProduct(this->products[i]);
    }

    repo.deleteProduct(this->products[0]);
    assert(repo.getSize() == 1);
    assert(repo.findProduct(this->products[0]));

    Food* f = new Food("f1", "soup", 11.11, 11, 11, 11.111, "11 11, 1111 1, 1");
    
    try {
        repo.deleteProduct(f);
    }
    catch (RepoException& exe) {}
    catch (...) { assert(false); }
    assert(repo.getSize() == 1);
}

TestRepo::TestRepo()
{
    Food* f1 = new Food("f1", "soup", 11.11, 11, 11, 11.111, "11 11, 1111 1, 1");
    Food* f2 = new Food("f2", "pasta", 22.2, 222, 2, 22.22, "22, 22 22222 222, 2222");
    this->products.push_back(f1);
    this->products.push_back(f2);
}

TestRepo::~TestRepo()
{
    for (int i = 0; i < this->products.size(); i++)
    {
        if (this->products[i] != NULL)
        {
            delete this->products[i];
            this->products[i] = NULL;
        }
    }
    this->products.clear();
}

void TestRepo::runAllTests()
{
    this->testGetAll();
    this->testGetSize();
    this->testGetProduct();
    this->testFindProduct();
    this->testAddProduct();
    this->testUpdateProduct();
    this->testDeleteProduct();
}
