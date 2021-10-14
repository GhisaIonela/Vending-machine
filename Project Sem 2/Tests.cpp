#include "Tests.h"
#include "TestProducts.h"
#include "TestProductValidator.h"
#include "TestOrder.h"
#include "TestRepo.h"
#include "TestRepoFile.h"
#include "TestService.h"

void runAllTests()
{
	TestProducts testProducts;
	TestProductValidator testProductValidator;
	TestOrder testOrder;
	TestRepo testRepo; 
	TestRepoFile testRepoFile; 
	TestService testService;
	//cout << "test products\n";
	testProducts.runAllTests();
	//cout << "test product_validator\n";
	testProductValidator.runAllTests();
	//cout << "test order\n";
	testOrder.runAllTests();
	//cout << "test repo\n";
	testRepo.runAllTests();
	//cout << "test repo_file\n";
	testRepoFile.runAllTests();
	//cout << "test service\n";
	testService.runAllTests();
}