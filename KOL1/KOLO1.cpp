#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

class Skladnik {
public:
	std::string nazwa;
	float liczba;
	std::string jednostka;

	Skladnik() {};

	Skladnik(std::string n, int l, std::string j)
	{
		this->nazwa = n;
		this->liczba = l;
		this->jednostka = j;
	}

	friend std::ostream& operator << (std::ostream& out, Skladnik & s);
};

class Ciasto {
public:
	std::string nazwaCiasta;
	int liczbaSkladnikow;
	Skladnik **skladniki = new Skladnik*[100];

	Ciasto(std::string nazwa) {
		this->nazwaCiasta = nazwa;
		liczbaSkladnikow = 0;
	}

	void dodajSkladnik(Skladnik *s) {
		skladniki[liczbaSkladnikow] = s;
		liczbaSkladnikow++;
	}

	friend std::ostream& operator << (std::ostream& out, Ciasto & c) {
		out << c.nazwaCiasta << std::endl;
		int i;
		for (i = 0; i < c.liczbaSkladnikow; i++) {
			out << *c.skladniki[i];
		}
		return out;
	}
};

std::ostream& operator << (std::ostream& out, Skladnik & s) {
	out << s.nazwa << " " << s.liczba << " " << s.jednostka << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Skladnik &s) {
	in >> s.nazwa;
	in >> s.liczba;
	in >> s.jednostka;
	return in;
}


int main()
{
	Ciasto c1("Makowiec");

	std::string we = "ciacho.txt";
	std::ifstream plik;
	plik.open(we);
	if (!plik)
		std::cout << "Blad" << std::endl;
	else
		while (!plik.eof())
		{
			Skladnik s;
			plik >> s.nazwa;
			plik >> s.liczba;
			plik >> s.jednostka;
			//std::cout << s;
			c1.dodajSkladnik(&s);
		}
	plik.close();

	std::cout << c1;

	system("pause");
	return 0;
}

