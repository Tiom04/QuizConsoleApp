#include "Result.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <string>
#include "Test.h"
#include <fstream>
using namespace std;

int Result::Mark(int tot, int corr)
{
	return mark = 0.12 * tot / corr * 100;
}

ofstream& operator << (ofstream& out, const Result& res)
{
	out << res.login << res.testcat << res.mark;

	return out;
}

ifstream& operator >> (ifstream& in, Result& res)
{
	in >> res.login >> res.testcat >> res.mark;

	return in;
}