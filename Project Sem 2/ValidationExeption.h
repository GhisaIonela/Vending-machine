#pragma once
#ifndef VALIDATIONEXCEPTION_H
#define VALIDATIONEXCEPTION_H
#include <stdexcept>
using namespace std;

class ValidationExeption : public runtime_error {
private:
	string message;
public:
	ValidationExeption(string msg) : runtime_error(msg) , message(msg){
	}
	string what() {
		return message;
	}
};
#endif // !VALIDATIONEXCEPTION_H
