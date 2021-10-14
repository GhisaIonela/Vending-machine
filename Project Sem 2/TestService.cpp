#include "TestService.h"
#include "Food.h"
#include "Drink.h"
#include "ValidationExeption.h"
#include <assert.h>

void TestService::testConstructors()
{
	Service s1, s2(this->fileNameIn);
	assert(s1.getProductsSize() == 0);
	assert(s2.getProductsSize() == this->products.getSize());

	for (int i = 0; i < s2.getProductsSize(); i++)
		assert(*s2.getProduct(i) == *this->products.getProduct(i));
}

void TestService::testLoadProductsFromFile()
{
	Service service;
	service.loadProductsFromFile(this->fileNameIn);

	for (int i = 0; i < service.getProductsSize(); i++)
		assert(*service.getProduct(i) == *this->products.getProduct(i));
}

void TestService::testProducts()
{
	//findProduct
	Service service(this->fileNameIn);
	service.setProductsFile(this->fileNameOut);

	for (int i = 0; i < service.getProductsSize(); i++)
		assert(service.findProduct(service.getProduct(i)) == i);

	//addProduct
	Drink* d3 = new Drink("ciocolata calda", "hot_chocolate", 15.5, 25, 23, 0.5);
	service.addProduct(d3);
	assert(service.getProductsSize() == this->products.getSize() + 1);
	assert(*service.getProduct(service.getProductsSize() - 1) == *d3);

	//updateProduct
	Drink* d4 = new Drink("vin", "alcoholic_beverage", 15.5, 25, 23, 1.5), * d5 = new Drink();
	service.updateProduct(this->products.getProduct(1), d4);
	assert(*service.getProduct(1) == *d4);
	try {
		service.updateProduct(this->products.getProduct(1), d5);
		assert(*service.getProduct(1) == *d4);
	}
	catch (RepoException& exe) {}
	catch (...) { assert(false); }

	//deleteProduct
	Drink* d6 = new Drink("cdjsnjcs", "dsadas", 121, 454, 56, 125);
	service.deleteProduct(this->products.getProduct(3));
	assert(service.getProductsSize() == this->products.getSize());
	assert(*service.getProduct(3) == *this->products.getProduct(4));
	try {
		service.deleteProduct(d6);
	}
	catch (RepoException& exe) {}
	catch (...) { assert(false); }
	assert(service.getProductsSize() == this->products.getSize());

	//getAllFromProducts
	vector<Product*> products = service.getAllProducts();
	assert(products.size() == service.getProductsSize());
	for (int i = 0; i < products.size(); i++)
		assert(products[i] == service.getProduct(i));
}

void TestService::testOrders()
{
	Service service(this->fileNameIn);
	service.setProductsFile(this->fileNameOut);
	Product
		* p1 = new Product(), 
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25),
		* p3 = new Product("dasd", "dsffe", 15, 2115, 21115);
	Food
		* f1 = new Food(), 
		* f2 = new Food("pizza Quattro Formaggi", "fast_food", 24.55, 22, 12, 360.50,
		"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan"),
		* f3 = new Food("ada ds c1", "sfsd", 21.02, 23, 1221, 455, "dadsa dasds");
	Drink
		* d1 = new Drink(), 
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 20, 0.75),
		* d3 = new Drink("sACDSC", "DASD", 12.51, 151, 11, 21321.45);
	
	Order
		* o1 = new Order(p1),
		* o2 = new Order(p2),
		* o3 = new Order(p3),
		* o4 = new Order(f1),
		* o5 = new Order(f2),
		* o6 = new Order(f3),
		* o7 = new Order(d1),
		* o8 = new Order(d2),
		* o9 = new Order(d3);

	this->orders.push_back(o1); this->orders.push_back(o2); this->orders.push_back(o3);
	this->orders.push_back(o4); this->orders.push_back(o5); this->orders.push_back(o6);
	this->orders.push_back(o7); this->orders.push_back(o8); this->orders.push_back(o9);

	//addOrder
	for (int i = 0; i < this->orders.size(); i++)
	{
		try {
			service.addOrder(this->orders[i]->getProduct());
		}
		catch (ServiceException& exe) {}
		catch (...) {
			assert(false);
		}
	}

	assert(service.getOrdersSize() == 3);
	assert(*service.getOrder(0) == *o2);
	assert(*service.getOrder(1) == *o5);
	assert(*service.getOrder(2) == *o8);

	//purchaseProducts
	service.purchaseProducts();
	
	p2->setOrders(p2->getOrders() + 1);
	f2->setOrders(f2->getOrders() + 1);
	d2->setOrders(d2->getOrders() + 1);
	
	assert(*service.getProduct(0) == *p1);
	assert(*service.getProduct(1) == *p2);
	assert(*service.getProduct(2) == *f1);
	assert(*service.getProduct(3) == *f2);
	assert(*service.getProduct(4) == *d1);
	assert(*service.getProduct(5) == *d2);
	assert(service.getOrdersSize() == 0);
	assert(service.getAllOrders().empty());
}

void TestService::testGetAllByCategory()
{
	Service service(this->fileNameIn);
	service.setProductsFile(this->fileNameOut);
	vector<Product*> selection;
	selection = service.getAllByCategory(service.getAllProducts(), "");
	assert(selection.size() == 3);
	assert(*selection[0] == *service.getProduct(0));
	assert(*selection[1] == *service.getProduct(2));
	assert(*selection[2] == *service.getProduct(4));

	selection = service.getAllByCategory(service.getAllProducts(), "fast_food");
	assert(selection.size() == 1);
	assert(*selection[0] == *service.getProduct(3));
}

void TestService::testSortProducts()
{
	Service service(this->fileNameIn);
	service.setProductsFile(this->fileNameOut);
	vector<Product*> sorted;
	sorted = service.sortByPrice(service.getAllProducts());
	assert(sorted.size() == service.getProductsSize());
	assert(*sorted[0] == *service.getProduct(4));
	assert(*sorted[1] == *service.getProduct(2));
	assert(*sorted[2] == *service.getProduct(0));
	assert(*sorted[3] == *service.getProduct(1));
	assert(*sorted[4] == *service.getProduct(5));
	assert(*sorted[5] == *service.getProduct(3));

	sorted = service.sortByPrice(service.getAllProducts());
	assert(sorted.size() == service.getProductsSize());
	assert(*sorted[0] == *service.getProduct(0));
	assert(*sorted[1] == *service.getProduct(2));
	assert(*sorted[2] == *service.getProduct(4));
	assert(*sorted[3] == *service.getProduct(1));
	assert(*sorted[4] == *service.getProduct(5));
	assert(*sorted[5] == *service.getProduct(3));
}

void TestService::testFilterOrders()
{
	Service service(this->fileNameIn);
	service.setProductsFile(this->fileNameOut);
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "fast_food", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 20, 0.75);

	Order
		* o1 = new Order(p1),
		* o2 = new Order(p2),
		* o3 = new Order(f1),
		* o4 = new Order(f2),
		* o5 = new Order(d1),
		* o6 = new Order(d2);

	service.addOrder(p2);
	service.addOrder(f2);
	service.addOrder(d2);

	service.filterByCategory("");
	assert(service.getOrdersSize() == 0);

	service.emptyOrders();
	service.addOrder(p2);
	service.addOrder(f2);
	service.addOrder(d2);

	service.filterByCategory("fast_food");
	assert(service.getOrdersSize() == 1);
	assert(*service.getOrder(0) == *o4);

	service.addOrder(p2);
	service.addOrder(f2);
	service.addOrder(d2);

	service.filterByPrice(0);
	assert(service.getOrdersSize() == 0);

	service.emptyOrders();
	service.addOrder(p2);
	service.addOrder(f2);
	service.addOrder(d2);

	service.filterByPrice(6.75);
	assert(service.getOrdersSize() == 2);
	assert(*service.getOrder(0) == *o2);
	assert(*service.getOrder(1) == *o6);
}

TestService::TestService()
{
	this->products.setFileName(this->fileNameIn);
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "fast_food", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 20, 0.75);
	this->products.addProduct(p1);
	this->products.addProduct(p2);
	this->products.addProduct(f1);
	this->products.addProduct(f2);
	this->products.addProduct(d1);
	this->products.addProduct(d2);
}

TestService::~TestService()
{
}

void TestService::runAllTests()
{
	this->testConstructors();
	this->testLoadProductsFromFile();
	this->testProducts();
	this->testOrders();
	this->testGetAllByCategory();
	this->testSortProducts();
	this->testFilterOrders();
}
