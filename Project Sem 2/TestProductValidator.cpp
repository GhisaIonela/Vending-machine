#include "TestProductValidator.h"
#include <assert.h>

TestProductValidator::TestProductValidator()
{

}

TestProductValidator::~TestProductValidator()
{
}

void TestProductValidator::runAllTests()
{
	try {
		this->productValidator.validate("cd  sas 0.00c.0 a v");
	}
	catch (ValidationExeption& exe) {}
	catch (...) {
		assert(false);
	}

	try {
		this->productValidator.validate("P acadele: dulciuri 6.500.000 2s6 2s5");
	}
	catch (ValidationExeption& exe) {}
	catch (...) {
		assert(false);
	}

	try {
		this->productValidator.validate("F saasa asda: asdsa 0.00da.0000 0a 0cc 0.000ca.0000 asjdan");
	}
	catch (ValidationExeption& exe) {}
	catch (...) {
		assert(false);
	}

	try {
		this->productValidator.validate("D cappy de portocale: juicdsadae 6.75das.0000 2.2 2.2 0.75as0.000");
	}
	catch (ValidationExeption& exe) {}
	catch (...) {
		assert(false);
	}
	/*ofstream file("testInvalidProducts.txt");
	string line = "cd  sas 0.00c.0 a v";
	file << line;
	file.close();
	try {
		RepoFile repoFile = RepoFile("testInvalidProducts.txt");
	}
	catch (ValidationExeption& ex) {
		cout << "exception test: " << ex.what() << endl;
	}


	file.open("testInvalidProducts.txt");
	line = "P acadele: dulciuri 6.500.000 2s6 2s5";
	file << line;
	try {
		RepoFile repoFile = RepoFile("testInvalidProducts.txt");
	}
	catch (ValidationExeption& ex) {
		cout << "exception test: " << ex.what() << endl;
	}
	file.close();


	file.open("testInvalidProducts.txt");
	line = "F saasa asda: asdsa 0.00da.0000 0a 0cc 0.000ca.0000 asjdan";
	file << line;
	try {
		RepoFile repoFile = RepoFile("testInvalidProducts.txt");
	}
	catch (ValidationExeption& ex) {
		cout << "exception test: " << ex.what() << endl;
	}
	file.close();


	file.open("testInvalidProducts.txt");
	line = "D cappy de portocale: juicdsadae 6.75das.0000 2.2 2.2 0.75as0.000";
	file << line;
	try {
		RepoFile repoFile = RepoFile("testInvalidProducts.txt");
	}
	catch (ValidationExeption& ex) {
		cout << "exception test: " << ex.what() << endl;
	}
	file.close();*/
}
