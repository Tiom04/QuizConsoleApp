#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include <vector>
#include <list>

using namespace std;


ofstream& operator << (ofstream& out, const string& str);
ifstream& operator >> (ifstream& in, string& str);

template<class T>
ofstream& operator << (ofstream& out, const vector<T>& arr)
{
	int s = arr.size();
	out.write((const char*)&s, sizeof(T));
	out.write((const char*)&arr[0], arr.size() * sizeof(arr[0]));
	return out;
}
template<class T>
ifstream& operator >> (ifstream& in, vector<T>& arr)
{
	int s;
	in.read((char*)&s, sizeof(s));
	arr.resize(s);
	in.read((char*)&arr[0], arr.size() * sizeof(arr[0]));
	return in;
}

template<class T>
ofstream& operator << (ofstream& out, const list<T>& lst)
{
	int s = lst.size();
	out.write((const char*)&s, sizeof(s));
	for (auto v : lst)
	{
		out << v;
	}
	return out;
}
template<class T>
ifstream& operator >> (ifstream& in, list<T>& lst)
{
	int s;
	in.read((char*)&s, sizeof(s));
	T tmp;
	for (int i = 0; i < s; i++)
	{
		in >> tmp;
		lst.push_back(tmp);
	}
	return in;
}
