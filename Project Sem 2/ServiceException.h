#pragma once
#ifndef SERVICEEXCEPTION_H
#define SERVICEEXCEPTION_H
#include <stdexcept>
using namespace std;

class ServiceException : public runtime_error {
private:
	string message;
public:
	ServiceException(string msg) : runtime_error(msg), message(msg) {}
	string what() { return message; }
};
#endif // !SERVICEEXCEPTION_H
