#include <iostream>
#include "main.h"

using namespace std;

bool zawieraLitere(const string& slowo, const char& litera)
{
	for (int i = 0; i < slowo.length() + 1; i++)
	{
		if (slowo[i] == litera)
		{
			return true;
		}
	}
	return false;
}

string usunDuplikaty(const string& slowo)
{
	string wykorzystane_litery{ "" },
		slowo_bez_duplikatow{ "" };

	for (const char& litera : slowo)
	{
		if (!zawieraLitere(wykorzystane_litery, litera) && litera != ' ')
		{
			slowo_bez_duplikatow += litera;
			wykorzystane_litery += litera;
		}
	}
	return slowo_bez_duplikatow;
}

string stworzAlfabetZDanymKluczem(const string& key)
{
	string alfabet{ usunDuplikaty(key) };
	for (int i = 'A'; i < 'Z' + 1; i++)
	{
		char litera = char(i);
		if (!zawieraLitere(alfabet, litera))
		{
			alfabet += litera;
		}
	}
	return alfabet;
}

int indeksLiteryWAlfabecie(const char& litera)
{
	int i{ 0 };
	for (i = 'A'; i < 'Z' + 1; i++)
	{
		if (litera == char(i))
		{
			return i % 'A';
		}
	}
}

string przypisz_odpowiadajace_litery(const string& alfabet, const string& slowo)
{
	string zaszyfrowane_slowo{ "" };
	for (const char& litera : slowo)
	{
		if (litera != ' ')
		{
			zaszyfrowane_slowo += alfabet[indeksLiteryWAlfabecie(litera)];
		}
		else
		{
			zaszyfrowane_slowo += ' ';
		}
	}
	return zaszyfrowane_slowo;
}

string zaszyfrujMonoalfabetycznie(const string& tekst, const string& klucz)
{
	string alfabet{ stworzAlfabetZDanymKluczem(klucz) };
	return przypisz_odpowiadajace_litery(alfabet, tekst);
}

int main(void)
{
	string tekst{ "PEWNEGO PRZYJACIELA POZNAJE SIE W NIEPEWNEJ SYTUACJI" };
	string klucz{ "KRYPTOGRAFIA I KRYPTOANALIZA" };
	cout << zaszyfrujMonoalfabetycznie(tekst, klucz);

	return 0;
}