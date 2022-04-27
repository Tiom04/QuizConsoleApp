#pragma once
#include <string>
#include <list>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;
class Guest
{
	pair<string, string> LogPass;
	pair<pair<string, string>, string> Name;
	pair<string, string> AdressPhone;

public:
	Guest();
	Guest(string lg, string pw, string nm, string srnm, string patr, string adr, string ph);


	void Register();

	void Login();

	friend ofstream& operator << (ofstream& out, const Guest& gu);
	friend ifstream& operator >> (ifstream& in, Guest& gu);

	void SetLogin(string lg) { LogPass.first = lg; }

	void ReSetLogin(string lg);

	string GetLogin() { return LogPass.first; }
	string GetPassword() { return LogPass.second; }

	void AdmLog(string v) { LogPass.first = v; }
	void AdmPass(string v) { LogPass.second = v; }
	void AdmNm(string v) { Name.first.first = v; }
	void AdmSnm(string v) { Name.first.second = v; }
	void AdmLnm(string v) { Name.second = v; }
	void AdmAdr(string v) { AdressPhone.first = v; }
	void AdmPh(string v) { AdressPhone.second = v; }

	void SetPassword(string pw);

	void ShowGuest() {
		cout << endl << LogPass.first.c_str() << " (" << Name.first.first.c_str() << " " 
			<< Name.first.second.c_str() << " " << Name.second.c_str() << ")" << endl
			<< AdressPhone.first.c_str() << endl << AdressPhone.second.c_str() << endl;
	}

	~Guest();
};

