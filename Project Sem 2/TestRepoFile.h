#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
    string fileNameIn = "testProductsIn.txt";
    string fileNameOut = "testProductsOut.txt";
    vector<Product*> products;

    void testGetSetFilename();
    void testFindProduct();
    void testAddProduct();
    void testUpdateProduct();
    void testDeleteProduct();

    void testLoadFromFile();
    void testSaveToFile();

    void testEmpty();
public:
    TestRepoFile();
    ~TestRepoFile();
    void runAllTests();
};