#include"stdafx.h"
#include "Example.h"

void FindPerson(vector<PersonInfo*>& m_vet, const WCHAR* path)
{
	wfstream m_FIle; m_FIle.open(path);
	WCHAR buf[30] = { '\0' };
	WCHAR* buffer;
	while (m_FIle.getline(buf, sizeof(buf)))
	{
		wstring  s_Name = wcstok_s(buf, _T("|"), &buffer);
		wstring	s_phone = wcstok_s(NULL, _T("|"), &buffer);
		PersonInfo* person = new PersonInfo;
		person->strName = s_Name;
		person->strPhone = s_phone;
		m_vet.push_back(person);

		const WCHAR* ch = s_Name.c_str();
		const WCHAR* ch1 = s_phone.c_str();
	}

	return;
}


void AddPerson(vector<PersonInfo*>& m_vet, const WCHAR* path, const WCHAR* ch, const WCHAR* ch1)
{
	PersonInfo* person = new PersonInfo;
	person->strName = ch;
	person->strPhone = ch1;
	m_vet.push_back(person);

	wofstream infile;
	infile.open(path);

	vector<PersonInfo*>::iterator ite = m_vet.begin();
	while (ite != m_vet.end())
	{
		WCHAR buf[30] = { '\0' };
		wcscpy_s(buf, (*ite)->strName.c_str());
		wcscat_s(buf, _T("|"));
		wcscat_s(buf, (*ite)->strPhone.c_str());
		infile << buf << endl;
		ite++;
	}
	return;
}

void DelPerson(vector<PersonInfo*>& m_vet, const WCHAR* path, const WCHAR* ch, const WCHAR* ch1)
{
	for (int i = 0; i < m_vet.size(); i++)
	{
		if (m_vet[i]->strName == ch && m_vet[i]->strPhone == ch1)
		{
			m_vet[i] = m_vet.back();
			m_vet.pop_back();
			break;
		}
	}

	wofstream infile;
	infile.open(path);

	vector<PersonInfo*>::iterator ite = m_vet.begin();
	while (ite != m_vet.end())
	{
		WCHAR buf[30] = { '\0' };
		wcscpy_s(buf, (*ite)->strName.c_str());
		wcscat_s(buf, _T("|"));
		wcscat_s(buf, (*ite)->strPhone.c_str());
		infile << buf << endl;
		ite++;
	}
	return;
}

void ChangePerson(vector<PersonInfo*>& m_vet, const WCHAR* path, const WCHAR* newphone, const WCHAR* name)/*±à¼­¿òµÄÐÕÃû*/
{
	wofstream infile;
	infile.open(path);
	vector<PersonInfo*>::iterator ite = m_vet.begin();
	while (ite != m_vet.end())
	{
		if ((*ite)->strName == name)
		{
			(*ite)->strPhone = newphone;
		}

		WCHAR buf[30] = { '\0' };
		wcscpy_s(buf, (*ite)->strName.c_str());
		wcscat_s(buf, _T("|"));
		wcscat_s(buf, (*ite)->strPhone.c_str());
		infile << buf << endl;

		ite++;
	}
	return;
}