#pragma once
#ifndef REPOEXCEPTION_H
#define REPOEXCEPTION_H
#include <stdexcept>
using namespace std;

class RepoException : public runtime_error {
private:
	string message;
public:
	RepoException(string msg) : runtime_error(msg), message(msg) {}
	string what() { return message; }
};
#endif // !REPOEXCEPTION_H
