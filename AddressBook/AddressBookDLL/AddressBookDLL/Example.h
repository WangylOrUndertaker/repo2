#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"string"
#include <tchar.h>
using namespace std;

struct PersonInfo
{
	wstring strName;
	wstring strPhone;
};

#define DLLEXAMPLE_EXPORT_API __declspec(dllexport) //tells the compiler which is accessible externally

extern "C" DLLEXAMPLE_EXPORT_API void FindPerson(vector<PersonInfo*>& m_vet, const WCHAR* path);
extern "C" DLLEXAMPLE_EXPORT_API void AddPerson(vector<PersonInfo*>& m_vet, const WCHAR* path, const WCHAR* ch, const WCHAR* ch1);
extern "C" DLLEXAMPLE_EXPORT_API void DelPerson(vector<PersonInfo*>& m_vet, const WCHAR* path, const WCHAR* ch, const WCHAR* ch1);
extern "C" DLLEXAMPLE_EXPORT_API void ChangePerson(vector<PersonInfo*>& m_vet, const WCHAR* path, const WCHAR* ch, const WCHAR* ch1);