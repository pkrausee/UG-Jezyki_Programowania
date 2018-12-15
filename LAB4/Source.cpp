#include <iostream>
#include <string>

class PolskiProdukt {
protected:
	std::string miejsceProdukcji;
	std::string wykonawca;
	bool powypadkowy;

public:
	PolskiProdukt(std::string miejsceProdukcji, std::string wykonawca, bool powypadkowy) {
		this->miejsceProdukcji = miejsceProdukcji;
		this->wykonawca = wykonawca;
		this->powypadkowy = powypadkowy;
	}

	friend std::ostream& operator << (std::ostream& out, PolskiProdukt &pp) {
		using std::endl;
		out << "  - miejsce Produkcji: " << pp.miejsceProdukcji << endl;
		out << "  - wykonawca: " << pp.wykonawca << endl;
		if (pp.powypadkowy) out << "  - samochod powypadkowy" << endl;
		else out << "  - nieuszkodzony" << endl;
		return out;
	}
};

namespace Pojazd {
	using std::string;

	class Samochod {
	private:
		string marka;
		int rokProdukcji;
		int liczbaDrzwi;

	protected:
		int przebieg;
		string kolor;

	public:
		Samochod(string marka, int rokProdukcji, string kolor, int liczbaDrzwi) {
			this->marka = marka;
			this->rokProdukcji = rokProdukcji;
			this->kolor = kolor;
			this->liczbaDrzwi = liczbaDrzwi;
			this->przebieg = 0;
		}

		void setPrzebieg(int przebieg) {
			this->przebieg = przebieg;
		}

		friend std::ostream& operator << (std::ostream& out, Samochod &s);
	};

	class Maluch : public Samochod, public PolskiProdukt {
	private:
		float glosnosc;
		bool czyJezdzi;

	public:
		Maluch(int rokProdukcji, string kolor, float glosnosc, 
			std::string miejsceProdukcji, std::string wykonawca, bool powypadkowy) :
			Samochod("Fiat", rokProdukcji, kolor, 2),PolskiProdukt(miejsceProdukcji, wykonawca, powypadkowy){
			this->glosnosc = glosnosc;
			this->czyJezdzi = true;
		}

		void setCzyJezdzi(int czyJezdzi) {
			this->czyJezdzi = czyJezdzi;
		}

		Maluch nowyMaluch(int rokProdukcji, string kolor) {
			Maluch m = *this;
			m.kolor = kolor;
			m.przebieg /= 2;
			m.czyJezdzi = true;
			return m;
		}

		friend std::ostream& operator << (std::ostream& out, Maluch &m);
	};

	class Porshe : public Samochod {
	private:
		double ileDoSetki;

	public:
		Porshe(int rokProdukcji, string kolor,int ileDrzwi, double ileDoSetki) :
			Samochod("Porshe", rokProdukcji, kolor, ileDrzwi) {
			this->ileDoSetki = ileDoSetki;
		}

		friend std::ostream& operator << (std::ostream& out, Porshe &p);
	};


	//overloading of out steram operators
	std::ostream& operator << (std::ostream& out, Samochod &s) {
		using std::endl;
		out << "Samochod marki " << s.marka << " dane: " << endl;
		out << "  - rok produkcji: " << s.rokProdukcji << endl;
		out << "  - aktualny przebieg: " << s.przebieg << endl;
		out << "  - kolor: " << s.kolor << endl;
		out << "  - liczba drzwi: " << s.liczbaDrzwi << endl;
		return out;
	}
	std::ostream& operator << (std::ostream& out, Maluch &m) {
		using std::endl;
		out << static_cast<Samochod &>(m);
		out << static_cast<PolskiProdukt &>(m);
		out << "  - glosnosc: " << m.glosnosc << endl;
		if (m.czyJezdzi) out << "  - samochod jest na chodzie" << endl;
		else out << "  - totalny grat" << endl;
		return out;
	}
	std::ostream& operator << (std::ostream& out, Porshe &p) {
		using std::endl;
		out << static_cast<Samochod &>(p);
		out << "  - czas do 100km/h: " << p.ileDoSetki << "sec" << endl;
		return out;
	}
}

class AutoHandel
{
private:
	std::string nazwa;
	Pojazd::Samochod **listaSamochodow = new Pojazd::Samochod*[100];
	int liczbaSamochodow;

public:
	AutoHandel(std::string nazwa) {
		this->nazwa = nazwa;
		liczbaSamochodow = 0;
	}

	void dodajSamochod(Pojazd::Samochod *s) {
		listaSamochodow[liczbaSamochodow] = s;
		liczbaSamochodow++;
	}

	void usunSamochod(Pojazd::Samochod *s) {
		int i;
		for (i = 0; i < liczbaSamochodow; i++) {
			if (s == listaSamochodow[i] && i == liczbaSamochodow) // sprawdz czy -1 dziala
				listaSamochodow[i] = nullptr;
			else if (s == listaSamochodow[i])
			{
				listaSamochodow[i] = listaSamochodow[liczbaSamochodow]; // sprawdz czy -1 dziala -- liczba samochodow
				liczbaSamochodow--;
			}
		}
	}

	friend std::ostream& operator << (std::ostream& out, AutoHandel & ah) {
		int i;
		for (i = 0; i < ah.liczbaSamochodow; i++) {
			out << *ah.listaSamochodow[i] << std::endl;

			//out << typeid(*ah.listaSamochodow[i]).name() << std::endl;
		}

		return out;
	}
};


int main() {

	Pojazd::Samochod s1("Opel", 2007, "czerwony", 3);
	s1.setPrzebieg(100000);

	Pojazd::Maluch s2(1988, "czarny", 65, "Warszawa", "PolSam", true);
	s2.setPrzebieg(300000);
	s2.setCzyJezdzi(false);

	Pojazd::Porshe s3(2015, "czerwony", 2, 2.5);

	AutoHandel gh("Gdansk Handel");
	gh.dodajSamochod(&s1);
	gh.usunSamochod(&s1);
	gh.dodajSamochod(&s2);
	gh.dodajSamochod(&s3);

	std::cout << gh << std::endl;

	std::cout << s2 << std::endl;
	std::cout << s3;


	system("pause");
	return 0;
}