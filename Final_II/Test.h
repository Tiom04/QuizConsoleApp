#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <string>
#include "Subject.h"
#include <fstream>
using namespace std;
class Test : public Subject
{
	string category;
	list<Subject> subjects;

public:
	Test();
	Test(string cat, list<Subject> subj);

	int NumOfQuestions() { return subjects.size(); }

	void SetTest();

	void ShowTest();

	void RunTest(int& Total, int& Correct);

	string GetCat() { return category; }

	friend ofstream& operator << (ofstream& out, const Test& tes);
	friend ifstream& operator >> (ifstream& in, Test& tes);
	
	~Test();
};

