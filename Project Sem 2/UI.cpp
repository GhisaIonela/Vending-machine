#include "UI.h"
#include "Food.h"
#include "Drink.h"
#include <windows.h> 
#include <iostream>
#include <stdlib.h>
using namespace std;

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

string setcolor(unsigned short color) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	return "";
}

void UI::populateProducts()
{
	Food
		* f1 = new Food("Pizza Margherita", "fast_food", 17.60, 20, 10, 550, "Aluat de pizza, sos pizza, mozzarella 100% lapte, ciuperci"),
		* f2 = new Food("Pizza Prosciutto", "fast_food", 19.20, 20, 13, 550, "Aluat de pizza, sos pizza, mozzarella 100% lapte, sunca"),
		* f3 = new Food("Pizza Funghi", "fast_food", 19.20, 20, 13, 550, "Aluat de pizza, sos pizza, mozzarella 100% lapte, ciuperci"),
		* f4 = new Food("Pizza Prosciutto e funghi", "fast_food", 20, 25, 14, 550, "Aluat de pizza, sos pizza, mozzarella 100% lapte, sunca, ciuperci"),
		* f5 = new Food("Pizza Quattro stagioni", "fast_food", 23.20, 19, 15, 550, "Aluat de pizza, sos pizza, mozzarella 100% lapte, sunca, ciuperci, salam, ardei, masline"),
		* f6 = new Food("Pizza Quattro formaggi", "fast_food", 22.40, 19, 15, 550, "Aluat de pizza, sos pizza, mozzarella 100% lapte, cascaval, parmezan, gorgonzola"),
		* f7 = new Food("Salata Caesar", "salad", 23.99, 22, 17, 420, "Ou, Mix salata, Pui grill, Castravete , Include crutoane, Mozzarella"),
		* f8 = new Food("Salata Tuna", "salad", 25.49, 22, 17, 420, "Ton, Mix salata, Morcov, Ceapa rosie, Masline negre, Porumb, Lamaie"),
		* f9 = new Food("Salata Athena", "salad", 25.49, 22, 17, 420, "Double Cream, Mix salata, Castravete , Ceapa rosie , Masline negre, Rosii"),
		* f10 = new Food("Salata Dakota (cu ciuperci crude)", "salad", 26.99, 22, 16, 420, "Mix salata, Castravete , Ciuperci crude , Ardei copt, Ananas, Double Cream, Vita grill"),
		* f11 = new Food("Salata Dakota (cu ciuperci fierte)", "salad", 26.99, 21, 12, 420, "Vita grill, Mix salata, Ardei copt, Ananas, Double Cream, Castravete , Ciuperci fierte"),
		* f12 = new Food("Gyros de puisor", "fast_food", 18.50, 30, 19, 460, "lipie pita, carne rotisata de pui, sos de usturoi, salata varza, rosii, ceapa proaspata, castraveciori murati, cartofi prajiti, sos dulce acrisor, sos masline, sos legume, salata verde"),
		* f13 = new Food("Cheeseburger", "fast_food", 4.20, 25, 15, 110, "Carne vita tocata, branza Cheddar, sos, castraveti, ceapa, chifla"),
		* f14 = new Food("McPuisor", "fast_food", 4.20, 25, 15, 110, "Carne de pui, sos McPuisor, castraveti murati, chifla"),
		* f15 = new Food("Carbonara", "pasta", 24.0, 20, 10, 200, "Paste, ou, smantana si bacon"),
		* f16 = new Food("Bolognese", "pasta", 25.0, 20, 10, 200, "Sos de rosii, carne tocata, ceapa"),
		* f17 = new Food("Lasagna", "pasta", 25.0, 20, 10, 250, "Pasta fresca, carne tocata, sos de rosii, parmezan, sos besciamella"),
		* f18 = new Food("Rigatoni Quattro Formaggi", "pasta", 24.0, 20, 10, 200, "Gorgonzola, smantana, branza brie"),
		* f19 = new Food("Piept de pui în sos tarhon", "hot_meal", 27.0, 20, 10, 350, "Piept de pui, sos tarhon, cartofi copti, parmesan, rosii cherry"),
		* f20 = new Food("Philadelphia cheese steak", "hot_meal", 29.0, 20, 10, 350, "Bagheta pufoasa, vita gatita domol, branza cheddar, ardei gras, ceapa calita, sos, cartofi copti"),
		* f21 = new Food("Mic dejun englezesc", "hot_meal", 20.0, 20, 10, 250, "Oua, fasole, bacon, rosii cherry, carnariori, cartofi prajiti, paine prajita"),
		* f22 = new Food("Omleta cu ciuperci si cascaval", "hot_meal", 15.0, 20, 10, 250, "Oua, ciuperci, ceapa, cheddar, parmezan, mix salata, paine prajita"),
		* f23 = new Food("Curry de legume", "hot_meal", 19.0, 20, 10, 300, "Orez basmati, ceapa, usturoi, zuchinni, ciuperci, lapte de cocos, curry"),
		* f24 = new Food("Ciorba de burta", "soup", 12.0, 20, 10, 320, ""),
		* f25 = new Food("Ciorba radauteana", "soup", 10.0, 20, 10, 300, ""),
		* f26 = new Food("Ciorba taraneasca de porc", "soup", 10.0, 20, 10, 300, ""),
		* f27 = new Food("Supa crema de legume", "soup", 9.0, 20, 10, 300, ""),
		* f28 = new Food("Supa crema de ciuperci", "soup", 12.0, 20, 10, 300, "");
	Drink
		* d1 = new Drink("Cafe latte", "coffee", 3.5, 30, 20, 0.3),
		* d2 = new Drink("Cappuccino", "coffee", 6.5, 30, 20, 0.3),
		* d3 = new Drink("Cafe americano", "coffee", 6, 30, 20, 0.3),
		* d4 = new Drink("Espresso macchiato", "coffee", 6.5, 30, 20, 0.3),
		* d5 = new Drink("Espresso italian", "coffee", 4.0, 30, 20, 0.3),
		* d6 = new Drink("Ciocolata calda", "hot_chocolate", 3, 30, 20, 0.3),
		* d7 = new Drink("Ciocolata alba", "hot_chocolate", 3, 30, 20, 0.3),
		* d8 = new Drink("Ciocolata neagra", "hot_chocolate", 3, 30, 20, 0.3),
		* d9 = new Drink("Coca-Cola", "soft_drink", 5, 30, 20, 0.5),
		* d10 = new Drink("Fanta", "soft_drink", 5, 30, 20, 0.5),
		* d11 = new Drink("Sprite", "soft_drink", 5, 30, 20, 0.5),
		* d12 = new Drink("Limonada", "juice", 5, 30, 20, 0.5),
		* d13 = new Drink("Cappy portocale", "juice", 5, 30, 20, 0.5),
		* d14 = new Drink("Cappy piersici", "juice", 5, 30, 20, 0.5),
		* d15 = new Drink("Cappy grapefruit", "juice", 5, 30, 20, 0.5),
		* d16 = new Drink("Tymbark portocale", "juice", 5, 30, 20, 0.5),
		* d17 = new Drink("Tymbark mere", "juice", 5, 30, 20, 0.5),
		* d18 = new Drink("Tymbark piersici", "juice", 5, 30, 20, 0.5),
		* d19 = new Drink("Milkshake de ciocolata", "milkshake", 10, 30, 20, 0.3),
		* d20 = new Drink("Milkshake de capsuni", "milkshake", 10, 30, 20, 0.3),
		* d21 = new Drink("Milkshake de banane", "milkshake", 10, 30, 20, 0.3),
		* d22 = new Drink("Milkshake Oreo", "milkshake", 10, 30, 20, 0.3),
		* d23 = new Drink("Apa plata Dorna", "water", 2.5, 30, 20, 0.5),
		* d24 = new Drink("Apa carbogazoasa Dorna", "water", 2.5, 30, 20, 0.5),
		* d25 = new Drink("Apa plata Aqua Carpatica", "water", 2.5, 30, 20, 0.5),
		* d26 = new Drink("Apa carbogazoasa Aqua Carpatica", "water", 2.5, 30, 20, 0.5),
		* d27 = new Drink("Bere Staropramen ", "alcoholic_beverage", 5, 30, 20, 0.5),
		* d28 = new Drink("Bere Tuborg ", "alcoholic_beverage", 3, 30, 20, 0.5),
		* d29 = new Drink("Bere Ursus ", "alcoholic_beverage", 3, 30, 20, 0.5),
		* d30 = new Drink("Vin alb Cotnari ", "alcoholic_beverage", 35.25, 30, 20, 0.75),
		* d31 = new Drink("Vin rosu Cotnari ", "alcoholic_beverage", 35.5, 30, 20, 0.75);

	this->service.addProduct(f1); this->service.addProduct(f2); this->service.addProduct(f3); this->service.addProduct(f4); this->service.addProduct(f5); this->service.addProduct(f6);
	this->service.addProduct(f7); this->service.addProduct(f8); this->service.addProduct(f9); this->service.addProduct(f10); this->service.addProduct(f11); this->service.addProduct(f12);
	this->service.addProduct(f13); this->service.addProduct(f14); this->service.addProduct(f15); this->service.addProduct(f16); this->service.addProduct(f17); this->service.addProduct(f18);
	this->service.addProduct(f19); this->service.addProduct(f20); this->service.addProduct(f21); this->service.addProduct(f22); this->service.addProduct(f23); this->service.addProduct(f24);
	this->service.addProduct(f25); this->service.addProduct(f26); this->service.addProduct(f27); this->service.addProduct(f28);

	this->service.addProduct(d1); this->service.addProduct(d2); this->service.addProduct(d3); this->service.addProduct(d4); this->service.addProduct(d5); this->service.addProduct(d6);
	this->service.addProduct(d7); this->service.addProduct(d8); this->service.addProduct(d9); this->service.addProduct(d10); this->service.addProduct(d11); this->service.addProduct(d12);
	this->service.addProduct(d13); this->service.addProduct(d14); this->service.addProduct(d15); this->service.addProduct(d16); this->service.addProduct(d17); this->service.addProduct(d18);
	this->service.addProduct(d19); this->service.addProduct(d20); this->service.addProduct(d21); this->service.addProduct(d22); this->service.addProduct(d23); this->service.addProduct(d24);
	this->service.addProduct(d25); this->service.addProduct(d26); this->service.addProduct(d27); this->service.addProduct(d28); this->service.addProduct(d29); this->service.addProduct(d30);
	this->service.addProduct(d31);
}

void UI::runMenu() throw(ValidationExeption)
{
	service.loadProductsFromFile(this->productsFileNameIn);
	//this->populateProducts();
	bool shouldRun = true;
	do {
		try {
			showKeyPad();
			switch (this->commandUI())
			{
			case 0:
				this->productsUI("salad");
				break;
			case 1:
				this->productsUI("fast_food");
				break;
			case 2:
				this->productsUI("pasta");
				break;
			case 3:
				this->productsUI("hot_meal");
				break;
			case 4:
				this->productsUI("soup");
				break;
			case 5:
				this->productsUI("coffee/hot_chocolate");
				break;
			case 6:
				this->productsUI("juice/soft_drink");
				break;
			case 7:
				this->productsUI("milkshake");
				break;
			case 8:
				this->productsUI("water");
				break;
			case 9:
				this->productsUI("alcoholic_beverage");
				break;
			case -1:
				shouldRun = false;
				break;
			case -2:
				this->ordersUI();
				break;
			default:
				throw ValidationExeption("invalid command");
				break;
			}
			system("CLS");
		}
		catch (ValidationExeption& e) { this->showException(e.what()); }
		catch (RepoException& e) { this->showException(e.what()); }
		catch (ServiceException& e) { this->showException(e.what()); }
	} while (shouldRun);
}

void UI::showKeyPad()
{
	char c = char(92);
	/*for (int i = 0; i < 256; i++)
	{
		setcolor(i);
		if (i % 10 == 0)
			cout << endl;
		cout << "|" << i << "|";
	}
	cout << endl;*/

	setcolor(1);
	cout << "|______________________________________________________________________\n";
	cout << "|                             |  _  |                            |  _  |\n";
	cout << "|    SALADS                   | | | |    COFFEE                  | |_  |\n";
	cout << "|                             | |_| |    HOT CHOCOLATE           |  _| |\n";
	cout << "|_____________________________|_____|____________________________|_____|\n";
	cout << "|                             |     |                            |  _  |\n";
	cout << "|    FAST FOOD                |  |  |    JUICE                   | |_  |\n";
	cout << "|                             |  |  |    SOFT DRINKS             | |_| |\n";
	cout << "|_____________________________|_____|____________________________|_____|\n";
	cout << "|                             |  _  |                            | __  |\n";
	cout << "|    PASTA                    |  _| |    MILKSHAKES              |   | |\n";
	cout << "|                             | |_  |                            |   | |\n";
	cout << "|_____________________________|_____|____________________________|_____|\n";
	cout << "|                             |  _  |                            |  _  |\n";
	cout << "|    HOT MEALS                |  _| |    WATER                   | |_| |\n";
	cout << "|                             |  _| |                            | |_| |\n";
	cout << "|_____________________________|_____|____________________________|_____|\n";
	cout << "|                             |     |                            |  _  |\n";
	cout << "|    SOUPS                    | |_| |    ALCOHOLIC               | |_| |\n";
	cout << "|                             |   | |    BEVERAGES               |  _| |\n";
	cout << "|_____________________________|_____|____________________________|_____|\n";
	cout << "|                             |  _  |                            |     |\n";
	cout << "|    MY CART                  | |   |    SHUT DOWN               | " << c << "_/ |\n";
	cout << "|                             | |_  |                            | / " << c << " |\n";
	cout << "|_____________________________|_____|____________________________|_____|\n";
}

int UI::commandUI() throw(ValidationExeption)
{
	cout << "|\n";
	cout << "|COMMAND: ";
	string option;
	char o;
	getline(cin, option);
	system("CLS");
	if (option.size() == 0)
		throw ValidationExeption("invalid command");
	else if (option == "x" || option == "X")
		return -1;
	else if (option == "c" || option == "C")
		return -2;
	else if (option == "p" || option == "P")
		return -3;
	else if (option == "n" || option == "N")
		return -4;
	else if (option == "b" || option == "B")
		return -5;
	for (int i = 0; i < option.size(); i++)
		if (!isdigit(option[i]))
			throw ValidationExeption("invalid command");
	return stoi(option);
}

void UI::showException(string e)
{
	setcolor(4);
	cout << "|----------------------------------------------------------------------\n";
	cout << "|Error: " << e << endl;
	cout << "|----------------------------------------------------------------------\n";
}

void UI::showProducts(vector<Product*> products)
{
	setcolor(1);
	if (products.size() == 0)
	{
		cout << "|----------------------------------------------------------------------\n";
		cout << "|There are no products\n";
		cout << "|----------------------------------------------------------------------\n";
	}
	else {
		setcolor(1);
		cout << "|_______________________________PRODUCTS_______________________________|\n";
		cout << "|______________________________________________________________________|\n";
		cout << "|No|                   Name                      |        Price        |\n";
		cout << "|--|---------------------------------------------|---------------------|\n";
		for (int i = 0; i < products.size(); i++)
		{
			if (!(products[i]->getOrders() < products[i]->getStock()))
				setcolor(8);
			else 
				setcolor(3);
			cout << "|" << i << ". " << products[i]->toStringUI() << "\n";
		}
	}
}

void UI::showProductsOptions()
{
	setcolor(1);
	if (this->service.getProductsSize() > 0)
	{
		cout << "|______________________________________________________________________\n";
		cout << "| Add To Cart: No | Sort By Price: P | Sort By Name: N |    Back: X    |\n";
		cout << "|_________________|__________________|_________________|_______________|\n";
	}
	else
	{
		cout << "|_______________\n";
		cout << "|    Back: X    |\n";
		cout << "|_______________|\n";
	}
}

void UI::productsUI(string category) throw(ValidationExeption)
{
	vector<Product*> products = this->service.getAllByCategory(this->service.getAllProducts(), category);
	this->showProducts(products);

	int option;
	bool shouldRun = true;
	do {
		try {
			this->showProductsOptions();
			option = this->commandUI();
			if (0 <= option && option < products.size())
			{
				this->showProducts(products);
				this->service.addOrder(products[option]);
				setcolor(10);
				cout << "|----------------------------------------------------------------------\n";
				cout << "| " << products[option]->getName() << " x1 has been added to your cart\n";
				cout << "|----------------------------------------------------------------------\n";
				setcolor(1);
			}
			else if (option == -1)
			{
				shouldRun = false;
			}
			else if (products.size() > 0)
			{
				if (option == -3)
				{
					products = this->service.sortByPrice(products);
					this->showProducts(products);
				}
				else if (option == -4)
				{
					products = this->service.sortByName(products);
					this->showProducts(products);
				}
				else
				{
					throw ValidationExeption("invalid command");
				}
			}
			else
			{
				throw ValidationExeption("invalid command");
			}
		}
		catch (ValidationExeption& e) { this->showException(e.what()); }
		catch (RepoException& e) { this->showException(e.what()); }
		catch (ServiceException& e) { this->showException(e.what()); }
	} while (shouldRun);
}

void UI::showOrders(vector<Order*> orders)
{
	setcolor(1);
	if (orders.size() == 0)
	{
		cout << "|----------------------------------------------------------------------\n";
		cout << "|There are no products\n";
		cout << "|----------------------------------------------------------------------\n";
	}
	else {
		setcolor(1);
		cout << "|_______________________________MY CART________________________________|\n"; 
		cout << "|______________________________________________________________________|\n";
		cout << "|No|                   Name                      |        Price        |\n";
		cout << "|--|---------------------------------------------|---------------------|\n";
		setcolor(3);
		for (int i = 0; i < orders.size(); i++)
		{
			cout << "|" << i << ". " << orders[i]->toString() << "\n";
		}
		setcolor(1);
		cout << "|------------------------------------------------|---------------------|\n|"; setcolor(7);
		cout << "   Total                                         " << this->service.getTotal() << "\n"; setcolor(1);
		cout << "|------------------------------------------------|---------------------|\n";
	}
}

void UI::showOrdersOptions()
{
	setcolor(1);
	if (this->service.getOrdersSize() > 0)
	{
		cout << "|______________________________________________________________________\n";
		cout << "|   Buy: B   | Filter By Price: P | Filter By Category: C |   Back: X  |\n";
		cout << "|____________|____________________|_______________________|____________|\n";
	}
	else
	{
		cout << "|_______________\n";
		cout << "|    Back: X    |\n";
		cout << "|_______________|\n";
	}
}

void UI::ordersUI() throw(ValidationExeption)
{
	setcolor(1);
	this->showOrders(this->service.getAllOrders());

	int option;
	bool shouldRun = true;
	do {
		try {
			this->showOrdersOptions();
			option = this->commandUI();
			if (option == -1)
			{
				shouldRun = false;
			}
			else if (this->service.getOrdersSize() > 0)
			{
				if (option == -5)
				{
					this->service.purchaseProducts();
					setcolor(10);
					cout << "|----------------------------------------------------------------------\n";
					cout << "| All products have been purchased\n";
					cout << "|----------------------------------------------------------------------\n";
					setcolor(1);
				}
				else if (option == -3)
				{
					this->filterByPriceUI();
					this->showOrders(this->service.getAllOrders());
				}
				else if (option == -2)
				{
					this->filterByCategoryUI();
					this->showOrders(this->service.getAllOrders());
				}
				else
				{
					throw ValidationExeption("invalid command");
				}
			}
			else {
				throw ValidationExeption("invalid command");
			}
		}
		catch (ValidationExeption& e) { this->showException(e.what()); }
		catch (RepoException& e) { this->showException(e.what()); }
		catch (ServiceException& e) { this->showException(e.what()); }
	} while (shouldRun);
}

void UI::filterByCategoryUI() throw(ValidationExeption)
{
	setcolor(1);
	cout << "|----------------------------------------------------------------------\n";
	cout << "|  Choose the category you want to keep:\n|\n";
	cout << "|0. SALADS\n";
	cout << "|1. FAST FOOD\n";
	cout << "|2. PASTA\n";
	cout << "|3. HOT MEALS\n";
	cout << "|4. SOUPS\n";
	cout << "|5. COFFEE/HOT CHOCOLATE\n";
	cout << "|6. JUICE/SOFT DRINKS\n";
	cout << "|7. MILKSHAKES\n";
	cout << "|8. WATER\n";
	cout << "|9. ALCOHOOLIC BEVERAGES\n";
	cout << "|\n";
	cout << "|x. Cancel filtering\n";

	setcolor(1);
	int command = this->commandUI();
	setcolor(10);
	switch (command)
	{
	case 0:
		this->service.filterByCategory("salad");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 1:
		this->service.filterByCategory("fast_food");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 2:
		this->service.filterByCategory("pasta");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 3:
		this->service.filterByCategory("hot_meal");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 4:
		this->service.filterByCategory("soup");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 5:
		this->service.filterByCategory("coffee/hot_chocolate");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 6:
		this->service.filterByCategory("juice/soft_drink");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 7:
		this->service.filterByCategory("milkshake");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 8:
		this->service.filterByCategory("water");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case 9:
		this->service.filterByCategory("alcoholic_beverage");
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n";
		break;
	case -1:
		break;
	default:
		throw ValidationExeption("invalid command");
		break;
	}
}

void UI::filterByPriceUI() throw(ValidationExeption)
{
	setcolor(1);
	cout << "|----------------------------------------------------------------------\n";
	cout << "|0. Insert the price you wish to filter your orders by \n";
	cout << "|   (product price <= inserted price)\n";
	cout << "|\n";
	cout << "|x. Cancel filtering\n";
	
	switch (this->commandUI())
	{
	case 0:
		this->service.filterByPrice(this->getPrice());
		setcolor(10);
		cout << "|----------------------------------------------------------------------\n";
		cout << "| The orders have been filtered\n";
		cout << "|----------------------------------------------------------------------\n"; setcolor(1);
		break;
	case -1:
		break;
	default:
		throw ValidationExeption("invalid command");
		break;
	}
}

double UI::getPrice() throw(ValidationExeption)
{
	setcolor(1);
	cout << "|\n";
	cout << "|----------------------------------------------------------------------\n";
	cout << "|PRICE: ";
	string option;
	char o;
	getline(cin, option);
	if (option.size() == 0)
		throw ValidationExeption("invalid command");
	for (int i = 0; i < option.size(); i++)
		if (!isdigit(option[i]) && option[i] != '.')
			throw ValidationExeption("invalid command");
	return stod(option);
}
