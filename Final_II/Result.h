#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <string>
#include "Test.h"
#include <fstream>
using namespace std;

class Result
{
	string login;
	string testcat;
	int mark;

public:
	Result() {
#ifdef DEBUG
		cout << "\nConstructor of result";
#endif // DEBUG
	}
	Result(string login, string test) { this->login = login; this->testcat = test; 
#ifdef DEBUG
	cout << "\nConstructor of result";
#endif // DEBUG
	}

	int Mark(int tot, int corr);

	friend ofstream& operator << (ofstream& out, const Result& res);
	friend ifstream& operator >> (ifstream& in, Result& res);

	void SetLog(string lg) { login = lg; }
	void SetCat(string cat) { testcat = cat; }

	string GetLog() { return login; }
	string GetTestCat() { return testcat; }
	int GetMark() { return mark; }


	~Result() {
#ifdef DEBUG
		cout << "\nDestructor of result";
#endif // DEBUG
	}
};

