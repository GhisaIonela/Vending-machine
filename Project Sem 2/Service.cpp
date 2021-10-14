#include "Service.h"
#include "ValidationExeption.h"

Service::Service()
{
}

Service::Service(string productsInFile)
{
	this->products.setFileName(productsInFile);
	this->products.loadFromFile();
}

Service::~Service()
{
}

int Service::getProductsSize()
{
	return this->products.getSize();
}

Product* Service::getProduct(int index)
{
	return this->products.getProduct(index);
}

vector<Product*> Service::getAllProducts()
{
	return this->products.getAll();
}

void Service::setProductsFile(string productsFile)
{
	this->products.setFileName(productsFile);
}

void Service::loadProductsFromFile(string productsInFile)
{
	this->products.setFileName(productsInFile);
	this->products.loadFromFile();
}

int Service::findProduct(Product* p)
{
	return this->products.findProduct(p);
}

void Service::addProduct(Product* p)
{
	this->products.addProduct(p);
}

void Service::deleteProduct(Product* p)
{
	this->products.deleteProduct(p);
}

void Service::updateProduct(Product* oldP, Product* newP)
{
	this->products.updateProduct(oldP, newP);
}

void Service::emptyProducts()
{
	this->products.empty();
}

int Service::getOrdersSize() 
{
	return this->orders.size();
}

Order* Service::getOrder(int index)
{
	return this->orders[index];
}

vector<Order*> Service::getAllOrders()
{
	return this->orders;
}

void Service::addOrder(Product* p) throw(ServiceException)
{
	if (this->findProduct(p) != -1)
	{
		if (!(p->getOrders() < p->getStock()))
			throw ServiceException("the product is out of stock");
		bool newOrder = true;
		for (int i = 0; i < this->orders.size() && newOrder == true; i++)
		{
			if (typeid(*this->orders[i]->getProduct()) == typeid(*p))
			{
				if (*this->orders[i]->getProduct() == *p)
				{
					if (!(this->orders[i]->getNoProducts() + p->getOrders() < p->getStock()))
						throw ServiceException("you can't add more of this product");
					(*this->orders[i])++;
					newOrder = false;
				}
			}
		}
		if (newOrder)
		{
			Order* order = new Order(p);
			this->orders.push_back(order);
		}
	}
}

vector<Product*> Service::getAllByCategory(vector<Product*> products, string category)
{
	vector<Product*> selection;
	for (Product* product:products)
	{
		if (category == "")
		{
			if (product->getCategory() == category)
				selection.push_back(product);
		}
		else if (category != "" && product->getCategory() != "")
		{
			if (0 <= category.find(product->getCategory()) && category.find(product->getCategory()) <= category.size())
				selection.push_back(product);
		}		
	}
	return selection;
}

vector<Product*> Service::sortByPrice(vector<Product*> toSort)
{
	vector<Product*> sorted = toSort;
	for (int i = 0; i < sorted.size() - 1; i++)
	{
		for (int j = i + 1; j < sorted.size(); j++)
		{
			if (sorted[i]->getPrice() > sorted[j]->getPrice())
			{
				swap(sorted[i], sorted[j]);
			}
		}
	}
	return sorted;
}

vector<Product*> Service::sortByName(vector<Product*> toSort)
{
	vector<Product*> sorted = toSort;
	for (int i = 0; i < sorted.size() - 1; i++)
	{
		for (int j = i + 1; j < sorted.size(); j++)
		{
			if (sorted[i]->getName().compare(sorted[j]->getName()) > 0)
			{
				swap(sorted[i], sorted[j]);
			}
		}
	}
	return sorted;
}

void Service::filterByCategory(string category)
{
	vector<Order*> filtered;
	for (Order* order: this->orders)
	{
		if (category == "")
		{
			if (order->getProduct()->getCategory() == category)
				filtered.push_back(order);
		}
		else if (category != "" && order->getProduct()->getCategory() != "")
		{
			if (0 <= category.find(order->getProduct()->getCategory()) 
				&& category.find(order->getProduct()->getCategory()) <= category.size())
				filtered.push_back(order);
		}
	}
	this->orders = filtered;
}

void Service::filterByPrice(double price)
{
	vector<Order*> filtered;
	for (Order* order : this->orders)
	{
		if (order->getProduct()->getPrice()*order->getNoProducts() <= price)
		{
			filtered.push_back(order);
		}
	}
	this->orders = filtered;
}

void Service::purchaseProducts()
{
	int pos;
	for (int i = 0; i < this->orders.size(); i++)
	{
		Product* p = this->orders[i]->getProduct()->clone();
		p->setOrders(this->orders[i]->getProduct()->getOrders() + this->orders[i]->getNoProducts());
		this->products.updateProduct(this->orders[i]->getProduct(), p);
	}
	this->orders.clear();
}

string Service::getTotal()
{
	double sum = 0.0;
	for (int i = 0; i < this->orders.size(); i++)
	{
		sum = sum + this->orders[i]->getProduct()->getPrice() * this->orders[i]->getNoProducts();
	}
	string doubleNum = to_string(sum);
	doubleNum = doubleNum.substr(0, doubleNum.find(".") + 3);
	doubleNum += " RON";
	return doubleNum;
}

void Service::emptyOrders()
{
	this->orders.clear();
}
