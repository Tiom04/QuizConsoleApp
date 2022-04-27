#include "Admin.h"
#include "Subject.h"
#include "Test.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <string>
using namespace std;
#include "objects to file.h"
//#define DEBUG

Admin::Admin()
{
	logpass.first = "login";
	logpass.second = "loginlogin";
	this->name.first = "no data";
	this->name.second = "no data";
#ifdef DEBUG
	cout << "\nConstructor of Admin\n";
#endif // DEBUG
}
Admin::Admin(string login, string password, string name, string surname)
{
	logpass.first = login;
	logpass.second = password;
	this->name.first = name;
	this->name.second = surname;
#ifdef DEBUG
	cout << "\nConstructor of Admin\n";
#endif // DEBUG
}

void Admin::Register()
{
	cout << "\nCreate password: ";
	getline(cin, logpass.second);
	cout << "\nYour name:       ";
	getline(cin, name.first);
	cout << "\nYour surname:    ";
	getline(cin, name.second);
	
	ofstream FileWrite("Admin", ios::binary);
	if (FileWrite)
	{
		FileWrite << *this;
		cout << "\nSuccessful registration!";
		FileWrite.close();
	}
	else cout << "\nError writing to file";

}

void Admin::Login()
{
	string TmpPass;
	bool TmpVar = 1;
	do {
	    cout << "\nPassword: "; 
		getline(cin, TmpPass);
		if (TmpPass != logpass.second)
		{
			cout << "\nWrong password!";
			TmpVar = 0;
		}
		else
		{
			cout << "\nSuccessful login!\n";
			Sleep(400);
			TmpVar = 1;
			continue;
		}
	} while(!(TmpVar));
	
}

void Admin::ReSetLogin(string lg)
{
	string TmpPass;
	bool TmpVar = 1;
	do {
		cout << "\nEnter password to set new login: ";
		cin.get();
		getline(cin, TmpPass);
		if (TmpPass != logpass.second)
		{
			cout << "\nWrong password!";
			TmpVar = 0;
		}
		else
		{
			logpass.first = lg;
			cout << "\nSuccessful login reset!\n";
			Sleep(400);
			TmpVar = 1;
			continue;
		}
	} while (!(TmpVar));
}

void Admin::ReSetPassword(string pw)
{
	string TmpPass;
	bool TmpVar = 1;
	do {
		cout << "\nConfirm old password to set new password: ";
		cin.get();
		getline(cin, TmpPass);
		if (TmpPass != logpass.second)
		{
			cout << "\nWrong password!";
			TmpVar = 0;
		}
		else
		{
			logpass.second = pw;
			cout << "\nSuccessful password reset!\n";
			Sleep(400);
			TmpVar = 1;
			continue;
		}
	} while (!(TmpVar));
}

Guest Admin::CreateGuest(string login, string password, string fname, string sname, string lname, string adress, string phone)
{
	Guest RetGuest(login, password, fname, sname, lname, adress, phone);
	return RetGuest;
}

void Admin::SetPassword(string pw)
{
	string TmpPass;
	bool TmpVar = 1;
	do {
		if (TmpPass != logpass.second)
		{
			cout << "\nWrong password!";
			TmpVar = 0;
		}
		else
		{
			logpass.second = pw;
			cout << "\nSuccessful password reset!\n";
			TmpVar = 1;
			continue;
		}
	} while (!(TmpVar));
}

ofstream& operator << (ofstream& out, const Admin& adm)
{
	out << adm.logpass.first << adm.logpass.second
		<< adm.name.first << adm.name.second;
	return out;
}

ifstream& operator >> (ifstream& in, Admin& adm)
{
	in >> adm.logpass.first >> adm.logpass.second
		>> adm.name.first >> adm.name.second;
	return in;
}

Admin::~Admin()
{
#ifdef DEBUG
	cout << "\nDestructor of Admin\n";
#endif // DEBUG
}
