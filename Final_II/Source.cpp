#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include "Subject.h"
#include "Test.h"
#include "objects to file.h"
#include "Admin.h"
#include "Guest.h"
#include "Result.h"
#include <iterator>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	list<Guest> GuestList;
	vector <pair<string, bool>> tmp_vect, tmp_vect2;
	pair<string, bool> tmp_pair("1", 0);
	tmp_vect.push_back(tmp_pair);
	tmp_pair.first = "2";
	tmp_pair.second = 0;
	tmp_vect.push_back(tmp_pair);
	tmp_pair.first = "3";
	tmp_pair.second = 1;
	tmp_vect.push_back(tmp_pair);
	tmp_pair.first = "18";
	tmp_pair.second = 0;
	tmp_vect2.push_back(tmp_pair);
	tmp_pair.first = "16";
	tmp_pair.second = 0;
	tmp_vect2.push_back(tmp_pair);
	tmp_pair.first = "17";
	tmp_pair.second = 1;
	tmp_vect2.push_back(tmp_pair);

	Subject tmp_sub("whats my age", tmp_vect2)
		, tmp_sub2("guess the number", tmp_vect);

	list<Subject> SubjList;

	SubjList.push_back(tmp_sub);
	SubjList.push_back(tmp_sub2);

	list<Test> TestList;
	Test TmpTest("Mathematics", SubjList);
	TestList.push_back(TmpTest);

	ofstream WriteTests("Tests", ios::binary);
	if (WriteTests)
	{
		WriteTests << TestList;
		WriteTests.close();
	}

	list<Result> ResultList;
	Result TmpRes;

	int Opt; Start:
	cout << "Hello. Welcome to my testing program. Please, choose an option\n1.Admin\n2.Guest\nChoice: ";
	do { cin >> Opt; } while (Opt < 1 || Opt >2);
	switch (Opt)
	{
	case 1:
	{
		cout << "\n\t\t*Sign in or register*\nLogin: ";
		string TmpLog;
		cin.get();
		getline(cin, TmpLog);
		Admin TmpAdm;
		ifstream FileRead;
		FileRead.open("Admin", ios::binary);
		if (FileRead)
		{
			FileRead >> TmpAdm;
			if (TmpAdm.GetLogin() == TmpLog)
				TmpAdm.Login();
			else {
				system("cls");
				cout << "\tWrong admin login!\n";
				Sleep(900);
				system("cls"); 
				goto Start;
			}
			FileRead.close();
		}
		else
		{
			TmpAdm.SetLogin(TmpLog);
			TmpAdm.Register();
		}
		//login passed
		int VarMenu;
		system("cls");
		cout << "Welcome, " << TmpAdm.GetLogin() << "!\n\tMenu:\n1.   My profile\n2.   Manage users\n3.   View results\n4.   Manage testing"
			<< "\nChoice: ";
		do { cin >> VarMenu; } while (VarMenu < 1 || VarMenu > 4);
		switch (VarMenu)
		{
		case 1:
		{
			bool Var1Adm;
			cout << "\nMenu:\n0. Change login\n1. Change password\nChoice: ";
			do { cin >> Var1Adm; } while (Var1Adm < 0 || Var1Adm > 1);
			if (Var1Adm) 
			{
				string Var1Pass;
				cout << "\nEnter new password: ";
				cin >> Var1Pass;
				TmpAdm.ReSetPassword(Var1Pass);
			}
			else
			{
				string Var1Log;
				cout << "\nEnter new login: ";
				cin >> Var1Log;
				TmpAdm.ReSetLogin(Var1Log);
			}
			ofstream FileWrite("Admin", ios::binary, ios::trunc);
			if (FileWrite)
			{
				FileWrite << TmpAdm;
				FileWrite.close();
			}
		}break;
		case 2:
		{
			cout << "\n\tMenu:\n1.   Create guest profile\n2.   Change guest profile parameters\nChoice: ";
			do { cin >> VarMenu; } while (VarMenu < 1 || VarMenu > 2);
			switch (VarMenu)
			{
			case 1:
			{
				string log1, pass1, nm1, snm1, lnm1, adr1, ph1;
				cout << "\nEnter new guest's login: ";
				cin >> log1;
				cout << "\nEnter new guest's password: ";
				cin >> pass1;
				cout << "\nEnter new guest's name: ";
				cin >> nm1;
				cout << "\nEnter new guest's second name: ";
				cin >> snm1;
				cout << "\nEnter new guest's last name: ";
				cin >> lnm1;
				cout << "\nEnter new guest's adress: ";
				cin >> adr1;
				cout << "\nEnter new guest's phone: ";
				cin >> ph1;
				GuestList.push_back(TmpAdm.CreateGuest());
				ofstream FileWrite("Guests", ios::binary);
				if (FileWrite)
				{
					FileWrite << GuestList;
					FileWrite.close();
					cout << "\n\tNew guest added!";
				}
			}break;
			case 2:
			{
				string TmpC2;
				cout << "\nEnter login of the guest you are looking for: ";
				cin >> TmpC2;
				bool flag1 = 0;
				ifstream FileRead("Guests", ios::binary);
				if (FileRead)
				{
					FileRead >> GuestList;
					for (auto& val : GuestList)
					{
						if (val.GetLogin() == TmpC2)
						{
							bool ExFlag = 0;
							do {
								flag1 = 1;
								cout << "\n\tChange:\n1.  Login\n2.  Password\n3.  Name\n4.  Middle name\n5.  Last name\n6.  Adress\n7.  Phone\nChoice: ";
								do { cin >> VarMenu; }
								while (VarMenu < 1 || VarMenu > 7);
								switch (VarMenu)
								{
								case 1:
								{
									cout << "\nNew login: ";
									cin >> TmpC2;
									val.AdmLog(TmpC2);
								}break;
								case 2:
								{
									cout << "\nNew password: ";
									cin >> TmpC2;
									val.AdmPass(TmpC2);
								}break;
								case 3:
								{
									cout << "\nNew name: ";
									cin >> TmpC2;
									val.AdmNm(TmpC2);
								}break;
								case 4:
								{
									cout << "\nNew middle name: ";
									cin >> TmpC2;
									val.AdmSnm(TmpC2);
								}break;
								case 5:
								{
									cout << "\nNew last name: "; 
									cin >> TmpC2;
									val.AdmLnm(TmpC2);
								}break;
								case 6:
								{
									cout << "\nNew adress: ";
									cin >> TmpC2;
									val.AdmAdr(TmpC2);
								}break;
								case 7:
								{
									cout << "\nNew phone: "; 
									cin >> TmpC2;
									val.AdmPh(TmpC2);
								}break;
								}
								cout << endl << val.GetLogin() << "'s profile parameters changed!";
								cout << "\nContinue changing = 1; Exit = 0\n  Choice: ";
								cin >> ExFlag;
							} while (ExFlag);
							break;
						}
					}
					if (flag1 == 0)
						cout << "\nGuest not found!";
					FileRead.close();
				}
			}break;
			}
		}break;
		case 3:
		{
			cout << "\n\tResults:\n1.  By category\n2.  By login\nChoice: ";
			do { cin >> VarMenu; } while (VarMenu < 1 || VarMenu > 3);
			string TmpCase3;
			switch (VarMenu)
			{
			case 1:
			{
				cout << "\nEnter category to search: ";
				cin >> TmpCase3;
				ifstream infile("Results", ios::binary);
				if (infile)
				{
					bool FlCase3 = 0;
					list<Result> TmpResList;
					infile >> TmpResList;
					for (auto val : TmpResList)
					{
						if (val.GetTestCat() == TmpCase3)
						{
							cout << "\nLogin: " << val.GetLog()
								<< "\nTest category: " << val.GetTestCat()
								<< "\nMark: " << val.GetMark();
							FlCase3 = 1;
						}
						cout << endl;
					}
					if (FlCase3 == 0) cout << "\nCategory not found";
					infile.close();
				}
			}break;
			case 2:
			{
				cout << "\nEnter login to search: ";
				cin >> TmpCase3;
				ifstream infile("Results", ios::binary);
				if (infile)
				{
					bool FlCase3 = 0;
					list<Result> TmpResList;
					infile >> TmpResList;
					for (auto val : TmpResList)
					{
						if (val.GetLog() == TmpCase3)
						{
							cout << "\nLogin: " << val.GetLog()
								<< "\nTest category: " << val.GetTestCat()
								<< "\nMark: " << val.GetMark();
							FlCase3 = 1;
						}
						cout << endl;
					}
					if (FlCase3 == 0) cout << "\nLogin not found";
					infile.close();
				}
			}break;
			}
			ofstream outfile("Results", ios::binary);
			if (outfile)
			{
				outfile << ResultList;
				outfile.close();
			}
		}break;
		case 4:
		{
			cout << "\n\tTests:\n1.  Add new test\n2.  Add questions to existing test\nChoice: ";
			do { cin >> VarMenu; } while (VarMenu < 1 || VarMenu > 2);
			switch (VarMenu)
			{
			case 1:
			{
				Test TmpTest;
				TmpTest.SetTest();
				TestList.push_back(TmpTest);
				ofstream WriteTests("Tests", ios::binary);
				if (WriteTests)
				{
					WriteTests << TestList;
					WriteTests.close();
				}
				cout << "\nTest added!";
			}break;
			case 2:
			{
				string TmpCat;
				cout << "\nEnter needed test category: ";
				cin >> TmpCat;
				for (auto& val : TestList)
				{
					if (val.GetCat() == TmpCat)
					{
						bool TmpFlag0;
						do {
							val.SetQuestion();
							cout << "\nContinue adding questions? [0/1]";
							cin >> TmpFlag0;
						} while (TmpFlag0);
						break;
					}
				}
				ofstream WriteTests("Tests", ios::binary);
				if (WriteTests)
				{
					WriteTests << TestList;
					WriteTests.close();
				}
			}break;
			}
		}break;
		}
		ofstream FileWrite("Guests", ios::binary);
		if (FileWrite)
		{
			FileWrite << GuestList;
			cout << "\nAll data saved to file";
			FileWrite.close();
		}
	}break;
	case 2:
	{
		cout << "\n\t\t*Sign in or register*\nLogin: ";
		string TmpLog;
		cin.get();
		getline(cin, TmpLog);
		Guest TmpGuest;
		ifstream FileRead;
		FileRead.open("Guests", ios::binary);
		if (FileRead)
		{
			list<Guest> TmpGuestList;
			FileRead >> TmpGuestList;

			bool Con = 0;
			for (auto &val : TmpGuestList)
			{
				if (val.GetLogin() == TmpLog)
				{
					Con = 1;
					TmpGuest = val;
					break;
				}
			}
			if(!Con)
				goto RegisterUser;
			else {
				TmpGuest.Login();
			}
			FileRead.close();
		}
		else
		{
			RegisterUser:
			TmpGuest.SetLogin(TmpLog);
			TmpGuest.Register();
			GuestList.push_back(TmpGuest);
		}
		//login passed

		int VarMenu;
		system("cls");
		cout << "Welcome, " << TmpGuest.GetLogin() << "!\n\tMenu:\n1.   My previous results\n2.   New test\n3.   My profile"
			<< "\nChoice: "; 
		do { cin >> VarMenu; } while (VarMenu < 1 || VarMenu > 4);
		switch (VarMenu)
		{
		case 1:
		{
			ifstream infile("Results", ios::binary);
			if (infile)
			{
				list<Result> TmpResList;
				infile >> TmpResList;
				for (auto val : TmpResList)
				{
					if (val.GetLog() == TmpGuest.GetLogin())
					{
						cout << "\nLogin: " << val.GetLog()
							<< "\nTest category: " << val.GetTestCat()
							<< "\nMark: " << val.GetMark();
					}
					cout << endl;
				}
				infile.close();
			}
		}break; 
		case 2:
		{
			int TotAnswers, CorrAnswers;
			for (auto val : TestList)
			{
				cout << "\nCategory: " << val.GetCat();
				val.RunTest(TotAnswers, CorrAnswers);
				
				cout << "\nResult: " << TmpRes.Mark(TotAnswers, CorrAnswers);
				TmpRes.SetLog(TmpLog);
				TmpRes.SetCat(val.GetCat());

				ResultList.push_back(TmpRes);

				ofstream outfile("Results", ios::binary);
				if (outfile)
				{
					outfile << ResultList;
					outfile.close();
				}
				cout << "\n0 = exit; 1 = continue\nOption:	";
				bool var01; cin >> var01;
				if (!var01) break;
			}
		}break;
		case 3:
		{
			cout << "\nProfile menu:\n1.Show my profile\n2.Change login\n3.Change password\nChoice: ";
			int Case4Tmp;
			do { cin >> Case4Tmp; } while (Case4Tmp < 1 || Case4Tmp > 3);
			switch (Case4Tmp)
			{
			case 1:
			{
				TmpGuest.ShowGuest();
			}break;
			case 2:
			{
				string Case2Log, Case2Tmp;
				cout << "\nEnter new login: ";
				cin >> Case2Log;
				Case2Tmp = TmpGuest.GetLogin();
				cout << Case2Tmp;
				TmpGuest.ReSetLogin(Case2Log);
				Case4Tmp = 0;
				for (auto& val : GuestList)
				{
					Case4Tmp++;
					if (val.GetLogin() == Case2Tmp)
					{
						GuestList.assign(Case4Tmp, TmpGuest);
					}
				}
			}break;
			case 3:
			{
				string Var3Pass, Var3Tmp;
				cout << "\nEnter new password: ";
				cin >> Var3Pass;
				Var3Tmp = TmpGuest.GetPassword();
				TmpGuest.SetPassword(Var3Pass);
				Case4Tmp = 0;
				for (auto& val : GuestList)
				{
					Case4Tmp++;
					if (val.GetPassword() == Var3Tmp)
					{
						GuestList.assign(Case4Tmp, TmpGuest);
					}
				}
			}break;
			}
		}break;
		}

		ofstream FileWrite("Guests", ios::binary);
		if (FileWrite)
		{
			FileWrite << GuestList;
			cout << "\nAll data saved to file";
			FileWrite.close();
		}
	}break;
	}

	_getch();
	return 0;
}