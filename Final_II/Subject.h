#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
class Subject
{
	string question;
	vector<pair<string, bool>> answers;
public:
	Subject();
	Subject(string quest, vector<pair<string, bool>>ans);
	void SetQuestion();
	void ShowQuestionTmp();

	friend ofstream& operator << (ofstream& out, const Subject& sub);
	friend ifstream& operator >> (ifstream& in, Subject& sub);

	string CorrectAnswer();

	~Subject();
};

