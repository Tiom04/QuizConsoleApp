#include "Guest.h"
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

Guest::Guest()
{
	LogPass.first = "no data";
	LogPass.second = "no data";
	Name.first.first = "no data";
	Name.first.second = "no data";
	Name.second = "no data";
	AdressPhone.first = "no data";
	AdressPhone.second = "no data";
#ifdef DEBUG
	cout << "\nConstructor of Guest\n";
#endif // DEBUG
}
Guest::Guest(string lg, string pw, string nm, string srnm, string patr, string adr, string ph)
{
	LogPass.first = lg;
	LogPass.second = pw;
	Name.first.first = nm;
	Name.first.second = srnm;
	Name.second = patr;
	AdressPhone.first = adr;
	AdressPhone.second = ph;
#ifdef DEBUG
	cout << "\nConstructor of Guest\n";
#endif // DEBUG
}

void Guest::Register()
{
	cout << "\nCreate password:   ";
	getline(cin, LogPass.second);
	cout << "\nYour first name:   ";
	getline(cin, Name.first.first);
	cout << "\nYour middle name:  "; 
	getline(cin, Name.second);
	cout << "\nYour last name:    "; 
	getline(cin, Name.first.second);
	cout << "\nYour home adress:  ";
	getline(cin, AdressPhone.first);
	cout << "\nYour phone number: ";
	getline(cin, AdressPhone.second);
}

void Guest::Login()
{
	string TmpPass;
	bool TmpVar = 1;
	do {
		cout << "\nPassword: ";
		getline(cin, TmpPass);
		if (TmpPass != LogPass.second)
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
	} while (!(TmpVar));
	if(!TmpVar) cout << "\nSuccessful login!\n";

}

void Guest::ReSetLogin(string lg)
{
	string TmpPass;
	bool TmpVar = 1;
	do {
		cout << "\nEnter password to set new login: ";
		cin.get();
		getline(cin, TmpPass);
		if (TmpPass != LogPass.second)
		{
			cout << "\nWrong password!";
			TmpVar = 0;
		}
		else
		{
			LogPass.first = lg;
			cout << "\nSuccessful login reset!\n";
			Sleep(400);
			TmpVar = 1;
			continue;
		}
	} while (!(TmpVar));
}

void Guest::SetPassword(string pw)
{
	string TmpPass;
	bool TmpVar = 1;
	do {
		cout << "\nEnter old password: ";
		cin.get();
		getline(cin, TmpPass);
		if (TmpPass != LogPass.second)
		{
			cout << "\nWrong password!";
			TmpVar = 0;
		}
		else
		{
			LogPass.second = pw;
			cout << "\nSuccessful password reset!\n";
			Sleep(400);
			TmpVar = 1;
			continue;
		}
	} while (!(TmpVar));
}

ofstream& operator << (ofstream& out, const Guest& gu)
{
	out << gu.LogPass.first << gu.LogPass.second
		<< gu.Name.first.first << gu.Name.first.second 
		<< gu.Name.second << gu.AdressPhone.first << gu.AdressPhone.second;
	return out;
}

ifstream& operator >> (ifstream& in, Guest& gu)
{
	in >> gu.LogPass.first >> gu.LogPass.second
		>> gu.Name.first.first >> gu.Name.first.second
		>> gu.Name.second >> gu.AdressPhone.first >> gu.AdressPhone.second;
	return in;
}

Guest::~Guest()
{
#ifdef DEBUG
	cout << "\nDestructor of Admin\n";
#endif // DEBUG
}
