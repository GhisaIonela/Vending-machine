#include "TestOrder.h"
#include <assert.h>

void TestOrder::testConstructors()
{
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "pizza", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 22, 0.75);
	
	Order o;
	assert(o.getProduct() == NULL);
	assert(o.getNoProducts() == 0);
	
	Order o1(p1), o2(p2, 3), o3(o1), o4(o2);
	assert(*o1.getProduct() == *p1);
	assert(*o2.getProduct() == *p2);
	assert(*o3.getProduct() == *p1);
	assert(*o4.getProduct() == *p2);
	assert(o1.getNoProducts() == 1);
	assert(o2.getNoProducts() == 3);
	assert(o3.getNoProducts() == 1);
	assert(o4.getNoProducts() == 3);

	Order o5(f1), o6(f2, 4), o7(o5), o8(o6);
	assert(*o5.getProduct() == *f1);
	assert(*o6.getProduct() == *f2);
	assert(*o7.getProduct() == *f1);
	assert(*o8.getProduct() == *f2);
	assert(o5.getNoProducts() == 1);
	assert(o6.getNoProducts() == 4);
	assert(o7.getNoProducts() == 1);
	assert(o8.getNoProducts() == 4);


	Order o9(d1), o10(d2, 2), o11(o9), o12(o10);
	assert(*o9.getProduct() == *d1);
	assert(*o10.getProduct() == *d2);
	assert(*o11.getProduct() == *d1);
	assert(*o12.getProduct() == *d2);
	assert(o9.getNoProducts() == 1);
	assert(o10.getNoProducts() == 2);
	assert(o11.getNoProducts() == 1);
	assert(o12.getNoProducts() == 2);
}

void TestOrder::testSetters()
{
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "pizza", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 22, 0.75);

	Order o;
	o.setNoProducts(2);
	assert(o.getNoProducts() == 2);
	o.setProduct(p1);
	assert(*o.getProduct() == *p1);
	o.setProduct(p2);
	assert(*o.getProduct() == *p2);
	o.setProduct(f1);
	assert(*o.getProduct() == *f1);
	o.setProduct(f2);
	assert(*o.getProduct() == *f2);
	o.setProduct(d1);
	assert(*o.getProduct() == *d1);
	o.setProduct(d2);
	assert(*o.getProduct() == *d2);
}

void TestOrder::testClone()
{
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "pizza", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 22, 0.75);

	Order o1, o2(d2), o3(f1, 2), o4(o2);

	Order* o1Clone = (Order*)o1.clone(),
		* o2Clone = (Order*)o2.clone(), 
		* o3Clone = (Order*)o3.clone(), 
		* o4Clone = (Order*)o4.clone();

	assert(o1 == *o1Clone);
	assert(&o1 != o1Clone);
	

	assert(o2 == *o2Clone);
	assert(&o2 != o2Clone);

	assert(o3 == *o3Clone);
	assert(&o3 != o3Clone);

	assert(o4 == *o4Clone);
	assert(&o4 != o4Clone);
}

void TestOrder::testBoolOperators()
{
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "pizza", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 22, 0.75);

	Order o,
		o1(p1), o2(p2, 3), o3(o1), o4(o2),
		o5(f1), o6(f2, 4), o7(o5), o8(o6),
		o9(d1), o10(d2, 2), o11(o9), o12(o10);

	assert(o != o1); assert(o != o2); assert(o != o3); assert(o != o4); 
	assert(o != o5); assert(o != o6); assert(o != o7); assert(o != o8);
	assert(o != o9); assert(o != o10); assert(o != o11); assert(o != o12);

	assert(o1 == o3); assert(o2 == o4); 
	assert(o5 == o7); assert(o6 == o8);
	assert(o9 == o11); assert(o10 == o12);
}

void TestOrder::testAssignmentOperator()
{
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "pizza", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 22, 0.75);

	Order o, 
		o1(p1), o2(p2, 3), o3(o1), o4(o2), 
		o5(f1), o6(f2, 4), o7(o5), o8(o6),
		o9(d1), o10(d2, 2), o11(o9), o12(o10);

	o = o1; assert(o == o1);
	o = o2; assert(o == o2);
	o = o3; assert(o == o3);
	o = o4; assert(o == o4);
	o = o5; assert(o == o5);
	o = o6; assert(o == o6);
	o = o7; assert(o == o7);
	o = o8; assert(o == o8);
	o = o9; assert(o == o9);
	o = o10; assert(o == o10);
	o = o11; assert(o == o11);
	o = o12; assert(o == o12);
}

void TestOrder::testIncrementOperator()
{
	Product
		* p1 = new Product(),
		* p2 = new Product("acadele", "dulciuri", 6.5, 26, 25);
	Food
		* f1 = new Food(),
		* f2 = new Food("pizza Quattro Formaggi", "pizza", 24.55, 22, 12, 360.50,
			"blat crocant, salsa di pomodoro, mozzarella, caşcaval, gorgonzola, parmezan");
	Drink
		* d1 = new Drink(),
		* d2 = new Drink("cappy de portocale", "juice", 6.75, 22, 22, 0.75);

	Order o,
		o1(p1), o2(p2, 3), o3(o1), o4(o2),
		o5(f1), o6(f2, 4), o7(o5), o8(o6),
		o9(d1), o10(d2, 2), o11(o9), o12(o10);

	o++; o1++; o2++; o3++; o4++; o5++; o6++; 
	o7++; o8++; o9++; o10++; o11++; o12++;

	assert(o.getNoProducts() == 1);
	assert(o1.getNoProducts() == 2);
	assert(o2.getNoProducts() == 4);
	assert(o3.getNoProducts() == 2);
	assert(o4.getNoProducts() == 4);
	assert(o5.getNoProducts() == 2);
	assert(o6.getNoProducts() == 5);
	assert(o7.getNoProducts() == 2);
	assert(o8.getNoProducts() == 5);
	assert(o9.getNoProducts() == 2);
	assert(o10.getNoProducts() == 3);
	assert(o11.getNoProducts() == 2);
	assert(o12.getNoProducts() == 3);
}

void TestOrder::testToString()
{
	Food* f = new Food("food", "food_category", 15.25, 12, 2, 50, "");
	Order o1, o2(f), o3(f, 5);

	assert(o1.toString() == "none x0                                       0.00 RON");
	assert(o2.toString() == "food x1                                       15.25 RON");
	assert(o3.toString() == "food x5                                       76.25 RON");
	o2++;
	assert(o2.toString() == "food x2                                       30.50 RON");
}

void TestOrder::testIOstream()
{
	Order o;
	cout << o << endl;

	string order = o.toString();
	cout << order << endl;
}

void TestOrder::runAllTests()
{
	this->testConstructors();
	this->testSetters();
	this->testClone();
	this->testBoolOperators();
	this->testAssignmentOperator();
	this->testIncrementOperator();
	this->testToString();
	//this->testIOstream();
}
