#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Test.h"
#include <fstream>
#include "Guest.h"
using namespace std;
class Admin
{
	pair<string, string> logpass;
	pair<string, string> name;

public:
	Admin();
	Admin(string login, string password, string name, string surname);

	void Register();

	void Login();

	friend ofstream& operator << (ofstream& out, const Admin& adm);
	friend ifstream& operator >> (ifstream& in, Admin& adm);

	void SetLogin(string lg) { logpass.first = lg; }

	void ReSetLogin(string lg);

	string GetLogin() { return logpass.first; }

	Guest CreateGuest(string login = "Login", string password = "Password", string fname = "FirstName",
		string sname = "SecondName", string lname = "LastName", string adress = "Adress", string phone = "Phone");

	void SetPassword(string pw);

	void ReSetPassword(string pw);

	void ShowAdm() {
		cout << logpass.first.c_str() << " " << logpass.second.c_str() << endl
			<< name.first.c_str() << " " << name.second.c_str() << endl << endl;
	}

	~Admin();
};

