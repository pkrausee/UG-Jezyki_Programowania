#include <iostream>
#include <string>

namespace Pojazd
{
	class Samochod
	{
	protected:
		std::string marka;
		int rokProdukcji;
		int przebieg;
		std::string kolor;
		int liczbaDrzwi;

	public:
		void setPrzebieg(int przebieg)
		{
			this->przebieg = przebieg;
		}
		Samochod(std::string marka, int rokProdukcji, std::string kolor, int liczbaDrzwi)
		{
			this->marka = marka;
			this->przebieg = 0;
			this->rokProdukcji = rokProdukcji;
			this->kolor = kolor;
			this->liczbaDrzwi = liczbaDrzwi;
		}
		friend std::ostream& operator << (std::ostream& out, Samochod & s) {
			out << "Dane samochodu: " << std::endl;
			out << "Marka: " << s.marka << std::endl;
			out << "Rok Produkcji: " << s.rokProdukcji << std::endl;
			out << "Przebieg: " << s.przebieg << "km" << std::endl;
			out << "Kolor: " << s.kolor << std::endl;
			out << "Liczba Drzwi: " << s.liczbaDrzwi << std::endl;
			return out;
		}
	};

	class Maluch : public Samochod
	{
	private:
		int liczbaDrzwi = 2;
		int glosnosc;
		bool czyJezdzi;

	public:
		void setCzyJezdzi(bool czyJezdzi)
		{
			this->czyJezdzi = czyJezdzi;
		}
		Maluch(int rokProdukcji, int przebieg, std::string kolor, int glosnosc,
			bool czyJezdzi) :
			Samochod("Fiat", rokProdukcji, kolor, 2) {
			this->setPrzebieg(przebieg);
			this->glosnosc = glosnosc;
			this->czyJezdzi = czyJezdzi;
		}
		Maluch nowyMaluch(std::string kolor)
		{
			Maluch s = *this;
			s.kolor = kolor;
			s.przebieg = 15;
			s.czyJezdzi = true;
			return s;
		}

		friend std::ostream& operator << (std::ostream& out, Maluch & s) {
			Samochod a = s;
			out << a;
			out << "Glosnosc: " << s.glosnosc << "dB" << std::endl;
			if (s.czyJezdzi)
				out << "Jezdzi" << std::endl;
			else
				out << "Nie jezdzi" << std::endl;
			return out;
		}
	};
}


int main()
{
	Pojazd::Samochod s1("Seat",1997,"zielony", 4);
	s1.setPrzebieg(35000);

	Pojazd::Maluch m1(1980, 10000, "czerwony", 20, false);
	m1.setCzyJezdzi(true);
	Pojazd::Maluch m2(1980, 150000, "niebieski", 30, false);
	Pojazd::Maluch m3 = m2.nowyMaluch("czerwony");

	std::cout << s1 << std::endl;
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl << "Nowy maluch:" << std::endl << m3;

	system("pause");
	return 0;
}