#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Abonent {

	public:
		string imie;
		string nazwisko;
		string numerTelefonu;

		Abonent() {};

		Abonent(string i, string n, string nrT)
		{
			imie = i;
			nazwisko = n;
			numerTelefonu = nrT;
		}

		~Abonent() {};

		bool dobryNumer()
		{
			int dlug = numerTelefonu.length();
			return dlug >= 6 && dlug <= 12;
		}
};

istream& operator >> (istream& in, Abonent &osoba) {
	cout << "Podaj imie: ";
	in >> osoba.imie;
	cout << "Podaj nazwisko: ";
	in >> osoba.nazwisko;
	cout << "Podaj nr Telefonu: ";
	in >> osoba.numerTelefonu;
	while (!osoba.dobryNumer())
	{
		cout << "Bledny numer" << endl;
		cout << "Podaj nr Telefonu: ";
		in >> osoba.numerTelefonu;
	}
	return in;
}

ifstream& operator >> (ifstream& in, Abonent &osoba) {
	in >> osoba.imie;
	in >> osoba.nazwisko;
	in >> osoba.numerTelefonu;
	return in;
}

ostream& operator << (ostream& out, Abonent &osoba) {
	out << osoba.imie << endl << osoba.nazwisko << endl << osoba.numerTelefonu << endl;
	return out;
}

int main()
{
	Abonent klient1;
	Abonent klient2;
	Abonent klient3;
	Abonent klient4;

	cin >> klient1;
	cin >> klient2;

	string plikWy = "ksiazkaTel.txt";
	ofstream plik1;
	plik1.open(plikWy);
	if (!plik1)
		cerr << "Error plik1" << endl;
	else
		plik1 << klient1 << klient2;
	plik1.close();

	string plikWe = "ksiazkaTel.txt";
	ifstream plik2;
	plik2.open(plikWe);
	if (!plik2)
		cerr << "Error plik2" << endl;
	else
		plik2 >> klient3 >> klient4;
	plik2.close();

	cout << klient3 << klient4;

	system("pause");
}