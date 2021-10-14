#include "Repo.h"
#include "ProductValidator.h"
#include "RepoException.h"
#include <typeinfo>

Repo::Repo()
{
}

Repo::~Repo()
{
    this->empty();
}

vector<Product*> Repo::getAll()
{
    return this->products;
}

int Repo::getSize()
{
    return this->products.size();
}

Product* Repo::getProduct(int index) throw(RepoException)
{
    if (index < 0 || index >= this->products.size())
    {
        throw RepoException("index is out of range");
    }
    return this->products[index];
}

int Repo::findProduct(Product* p)
{
    for (int i = 0; i < this->products.size(); i++)
    {
        if (typeid(*this->products[i]) == typeid(*p))
        {
            if (*this->products[i] == *p)
            {
                return i;
            }
        }   
    }
    return -1;
}

void Repo::addProduct(Product* p) throw(RepoException)
{
    this->productValidator.validate(p->toString());
    if (this->findProduct(p) != -1)
    {
        throw RepoException("the product you want to add already exits");
    }
    this->products.push_back(p->clone());
}

void Repo::updateProduct(Product* oldP, Product* newP) throw(RepoException)
{
    this->productValidator.validate(newP->toString());

    bool found = false;
    for (int i = 0; i < this->products.size(); i++)
    {
        if (typeid(*this->products[i]) == typeid(*oldP))
        {
            if (*this->products[i] == *oldP)
            {
                delete this->products[i];
                this->products[i] = newP->clone();
                found = true;
            }
        }
    }
    if (!found)
    {
        throw RepoException("produsul nu poate fi updatat pentru ca nu exista");
    }
}

void Repo::deleteProduct(Product* p) throw(RepoException)
{
    bool found = false;
    for (int i = 0; i < this->products.size(); i++)
    {
        if (typeid(*this->products[i]) == typeid(*p))
        {
            if (*this->products[i] == *p)
            {
                delete this->products[i];
                this->products.erase(this->products.begin() + i);
                i--;
                found = true;
            }
        }
    }
    if (!found)
    {
        throw RepoException("produsul nu poate fi sters pentru ca nu exista");
    }
}

void Repo::empty()
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
