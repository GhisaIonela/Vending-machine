#include "Tests.h"
#include "UI.h"
#include "ValidationExeption.h"
#include <time.h>
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();
    clock_t tStart = clock();

    runAllTests();

    //cout << "\nTime taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;

    UI ui;
    ui.runMenu();
    return 0;
}