#include "TestProducts.h"
#include <assert.h>

void TestProducts::testConstructors()
{
	Product p1, p2("pizza diavola", "pizza", 24.99, 10, 3), p3(p1), p4(p2);
	assert(p1.getName().empty());
	assert(p1.getCategory().empty());
	assert(p1.getPrice() == 0.0);
	assert(p1.getStock() == 0);
	assert(p1.getOrders() == 0);

	assert(p2.getName() == "pizza diavola");
	assert(p2.getCategory() == "pizza");
	assert(p2.getPrice() == 24.99);
	assert(p2.getStock() == 10);
	assert(p2.getOrders() == 3);

	assert(p3.getName().empty());
	assert(p3.getCategory().empty());
	assert(p3.getPrice() == 0.0);
	assert(p3.getStock() == 0);
	assert(p3.getOrders() == 0);

	assert(p4.getName() == "pizza diavola");
	assert(p4.getCategory() == "pizza");
	assert(p4.getPrice() == 24.99);
	assert(p4.getStock() == 10);
	assert(p4.getOrders() == 3);

	Food f1, f2("pizza diavola", "pizza", 12.0, 20, 12, 360.0, "blat pizza, sos de rosii, mozzarela, sunca"), f3(f1), f4(f2);
	assert(f1.getName().empty());
	assert(f1.getCategory().empty());
	assert(f1.getPrice() == 0.0);
	assert(f1.getStock() == 0);
	assert(f1.getOrders() == 0);
	assert(f1.getGrams() == 0.0);
	assert(f1.getIngredients().empty());

	assert(f2.getName() == "pizza diavola");
	assert(f2.getCategory() == "pizza");
	assert(f2.getPrice() == 12.0);
	assert(f2.getStock() == 20);
	assert(f2.getOrders() == 12);
	assert(f2.getGrams() == 360.0);
	assert(f2.getIngredients() == "blat pizza, sos de rosii, mozzarela, sunca");

	assert(f3.getName().empty());
	assert(f3.getCategory().empty());
	assert(f3.getPrice() == 0.0);
	assert(f3.getStock() == 0);
	assert(f3.getOrders() == 0);
	assert(f3.getGrams() == 0.0);
	assert(f3.getIngredients().empty());

	assert(f4.getName() == "pizza diavola");
	assert(f4.getCategory() == "pizza");
	assert(f4.getPrice() == 12.0);
	assert(f4.getStock() == 20);
	assert(f4.getOrders() == 12);
	assert(f4.getGrams() == 360.0);
	assert(f4.getIngredients() == "blat pizza, sos de rosii, mozzarela, sunca");

	Drink d1, d2("cappy de portocale", "juice", 6.5, 50, 25, 1.5), d3(d1), d4(d2);
	assert(d1.getName().empty());
	assert(d1.getCategory().empty());
	assert(d1.getPrice() == 0.0);
	assert(d1.getStock() == 0);
	assert(d1.getOrders() == 0);
	assert(d1.getLiters() == 0.0);

	assert(d2.getName() == "cappy de portocale");
	assert(d2.getCategory() == "juice");
	assert(d2.getPrice() == 6.5);
	assert(d2.getStock() == 50);
	assert(d2.getOrders() == 25);
	assert(d2.getLiters() == 1.5);

	assert(d3.getName().empty());
	assert(d3.getCategory().empty());
	assert(d3.getPrice() == 0.0);
	assert(d3.getStock() == 0);
	assert(d3.getOrders() == 0);
	assert(d3.getLiters() == 0.0);

	assert(d4.getName() == "cappy de portocale");
	assert(d4.getCategory() == "juice");
	assert(d4.getPrice() == 6.5);
	assert(d4.getStock() == 50);
	assert(d4.getOrders() == 25);
	assert(d4.getLiters() == 1.5);
}

void TestProducts::testSetters()
{
	Product p; Food f; Drink d;
	p.setName("a"); p.setCategory("b"); p.setPrice(10.25); p.setStock(14); p.setOrders(12);
	assert(p.getName() == "a");
	assert(p.getCategory() == "b");
	assert(p.getPrice() == 10.25);
	assert(p.getStock() == 14);
	assert(p.getOrders() == 12);
	p.setName(""); p.setCategory(""); p.setPrice(0); p.setStock(0); p.setOrders(0);
	assert(p.getName().empty());
	assert(p.getCategory().empty());
	assert(p.getPrice() == 0.0);
	assert(p.getStock() == 0);
	assert(p.getOrders() == 0);

	f.setName("a"); f.setCategory("b"); f.setPrice(10.25); f.setStock(14); f.setOrders(12); 
	f.setGrams(11.21); f.setIngredients("ingredient 1, ingredient 2");
	assert(f.getName() == "a");
	assert(f.getCategory() == "b");
	assert(f.getPrice() == 10.25);
	assert(f.getStock() == 14);
	assert(f.getOrders() == 12);
	assert(f.getGrams() == 11.21);
	assert(f.getIngredients() == "ingredient 1, ingredient 2");
	f.setName(""); f.setCategory(""); f.setPrice(0); f.setStock(0); f.setOrders(0);
	f.setGrams(0); f.setIngredients("");
	assert(f.getName().empty());
	assert(f.getCategory().empty());
	assert(f.getPrice() == 0.0);
	assert(f.getStock() == 0);
	assert(f.getOrders() == 0);
	assert(f.getGrams() == 0.0);
	assert(f.getIngredients().empty());

	d.setName("a"); d.setCategory("b"); d.setPrice(10.25); d.setStock(14); d.setOrders(12); d.setLiters(10.02);
	assert(d.getName() == "a");
	assert(d.getCategory() == "b");
	assert(d.getPrice() == 10.25);
	assert(d.getStock() == 14);
	assert(d.getOrders() == 12);
	assert(d.getLiters() == 10.02);
	d.setName(""); d.setCategory(""); d.setPrice(0.0); d.setStock(0); d.setOrders(0); d.setLiters(0);
	assert(d.getName().empty());
	assert(d.getCategory().empty());
	assert(d.getPrice() == 0.0);
	assert(d.getStock() == 0);
	assert(d.getOrders() == 0);
	assert(d.getLiters() == 0.0);
}

void TestProducts::testClone()
{
	Product p1, p2("pizza diavola", "pizza", 24.99, 10, 3);
	Food f1, f2("pizza diavola", "pizza", 12.0, 20, 12, 360.0, "blat pizza, sos de rosii, mozzarela, sunca");
	Drink d1, d2("cappy de portocale", "juice", 6.5, 50, 25, 1.5);

	Product* pClone;
	pClone = (Product*)p1.clone();
	assert(p1 == *pClone);
	assert(&p1 != pClone);
	pClone = (Product*)p2.clone();
	assert(p2 == *pClone);
	assert(&p2 != pClone);

	Food* fClone;
	fClone = (Food*)f1.clone();
	assert(f1 == *fClone);
	assert(&f1 != fClone);
	fClone = (Food*)f2.clone();
	assert(f2 == *fClone);
	assert(&f2 != fClone);

	Drink* dClone;
	dClone = (Drink*)d1.clone();
	assert(d1 == *dClone);
	assert(&d1 != dClone);
	dClone = (Drink*)d2.clone();
	assert(d2 == *dClone);
	assert(&d2 != dClone);
}

void TestProducts::testAssignmentOperator()
{
	Product p, p1, p2("pizza diavola", "pizza", 24.99, 10, 3);
	Food f, f1, f2("pizza diavola", "pizza", 12.0, 20, 12, 360.0, "blat pizza, sos de rosii, mozzarela, sunca");
	Drink d, d1, d2("cappy de portocale", "juice", 6.5, 50, 25, 1.5);
	assert(p != p2);
	p = p1; assert(p == p1);
	p = p2; assert(p == p2);
	assert(p != p1);

	assert(f != f2);
	f = f1; assert(f == f1);
	f = f2; assert(f == f2);
	assert(f != f1);

	assert(d != d2);
	d = d1; assert(d == d1);
	d = d2; assert(d == d2);
	assert(d != d1);
}

void TestProducts::testToString()
{
	Product p1, p2("pizza diavola", "pizza", 24.99, 10, 3);
	Food f1, f2("pizza diavola", "pizza", 12.0, 20, 12, 360.0, "blat pizza, sos de rosii, mozzarela, sunca");
	Drink d1, d2("cappy de portocale", "juice", 6.5, 50, 25, 1.5);

	assert(p1.toString() == "P none: none 0.000000 0 0");
	assert(p2.toString() == "P pizza diavola: pizza 24.990000 10 3");
	assert(f1.toString() == "F none: none 0.000000 0 0 0.000000 none");
	assert(f2.toString() == "F pizza diavola: pizza 12.000000 20 12 360.000000 blat pizza, sos de rosii, mozzarela, sunca");
	assert(d1.toString() == "D none: none 0.000000 0 0 0.000000");
	assert(d2.toString() == "D cappy de portocale: juice 6.500000 50 25 1.500000");
	
	assert(p1.toStringUI() == "none                                          0.00 RON");
	assert(p2.toStringUI() == "pizza diavola                                 24.99 RON");
	assert(f1.toStringUI() == "none   0.00g                                  0.00 RON");
	assert(f2.toStringUI() == "pizza diavola   360.00g                       12.00 RON\n|   blat pizza, sos de rosii, mozzarela, sunca");
	assert(d1.toStringUI() == "none   0.00L                                  0.00 RON");
	assert(d2.toStringUI() == "cappy de portocale   1.50L                    6.50 RON");
}

void TestProducts::testIOstream()
{
	Product product; Food food; Drink drink;
	cout << product << "\n" << food << "\n" << drink << "\n";
}

void TestProducts::runAllTests()
{
	this->testConstructors();
	this->testSetters();
	this->testClone();
	this->testAssignmentOperator();
	this->testToString();
	//this->testIOstream();
}
