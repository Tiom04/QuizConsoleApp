#include "Subject.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
//#define DEBUG

Subject::Subject()
{
	question = "no question";
#ifdef DEBUG
	cout << "\nDefault constructor of Subject\n";
#endif // DEBUG
}

Subject::Subject(string quest, vector<pair<string, bool>>ans)
{
	question = quest;
	answers = ans;
#ifdef DEBUG
	cout << "\nConstructor of Subject\n";
#endif // DEBUG
}

void Subject::SetQuestion()
{
	cout << "\nQuestion: ";
	getline(cin, question);
	cout << "\nNumber of answers: ";
	int szf_ans; 
	cin >> szf_ans; 
	cin.get();
	pair<string, bool> tmp;
	cout << "\nAnswers:\n";
	for (int i = 0; i < szf_ans; i++)
	{
		cout << endl << i + 1 << ": ";
		getline(cin, tmp.first);
		cout << "False/True [0/1]: ";
		cin >> tmp.second;
		cin.get();
		answers.push_back(tmp);
	}
}

void Subject::ShowQuestionTmp()
{
	cout << "\nQuestion: " << question;
	cout << "\nAnswers:\n";
	for (auto val : answers)
	{ 
#ifdef DEBUG
		cout << val.first << " " << val.second << endl;
#endif // DEBUG
		cout << val.first << endl;
	}
}

string Subject::CorrectAnswer()
{
	for (auto val : answers)
	{
		if (val.second == 1)
			return val.first;
	}
}

ofstream& operator << (ofstream& out, const Subject& sub)
{
	out << sub.question;
	out << sub.answers.size();
	for (auto val : sub.answers)
	{
		out << val.first << val.second;
	}
	return out;
}

ifstream& operator >> (ifstream& in, Subject& sub)
{
	in >> sub.question;
	int s;
	in >> s;
	sub.answers.resize(s);
	for (auto val : sub.answers)
	{
		in >> val.first >> val.second;
	}
	return in;
}

Subject::~Subject()
{
#ifdef DEBUG
	cout << "\nDestructor of Subject\n";
#endif // DEBUG
}