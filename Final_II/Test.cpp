#include "Test.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <string>
#include "Subject.h"
#include <fstream>
//#define DEBUG

Test::Test()
{
	category = "no category";
#ifdef DEBUG
	cout << "\nDefault construcor of Test\n";
#endif // DEBUG
}
Test::Test(string cat, list<Subject> subj)
{
	category = cat;
	subjects = subj;
#ifdef DEBUG
	cout << "\nConstructor of Test\n";
#endif // DEBUG
}

void Test::SetTest()
{
	cout << "\nCategoryÿ: ";
	getline(cin, category);
	cout << "\nQuestions: ";
	bool flag = 1;
	while (flag)
	{
		Subject tmp_subj;
		tmp_subj.SetQuestion();
		subjects.push_back(tmp_subj);
		cout << "\nContinue adding questions? [0/1]: ";
		cin >> flag;
	}
}

void Test::ShowTest()
{
	cout << "\nCategory: " << category
		<< "\nQuestions: "; 
	for (auto val : subjects)
		val.ShowQuestionTmp();
}

void Test::RunTest(int &Total, int &Correct)
{
	Correct = 0;
	Total = 0;
	for (auto val : subjects)
	{
		val.ShowQuestionTmp();
		cout << "\nChoice: ";
		string tmp_var1;
		cin >> tmp_var1;
		if (tmp_var1 == val.CorrectAnswer())
			Correct++;
		Total++;
	}
}

ofstream& operator << (ofstream& out, const Test& tes)
{
	out << tes.category << tes.subjects.size();
	for (auto val : tes.subjects)
		out << val;

	return out;
}

ifstream& operator >> (ifstream& in, Test& tes)
{
	in >> tes.category;
	int s;
	in >> s;
	tes.subjects.resize(s);
	for (auto val : tes.subjects)
		in >> val;

	return in;
}


Test::~Test()
{
#ifdef DEBUG
	cout << "Destructor of Test\n";
#endif // DEBUG
}