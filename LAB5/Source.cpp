#include <iostream>

class ZlaPodstawa{
public:
	ZlaPodstawa() {}

	friend std::ostream& operator << (std::ostream& out, ZlaPodstawa &zp);
};

class ZlyArgument {
public:
	ZlyArgument() {}

	friend std::ostream& operator << (std::ostream& out, ZlyArgument &za);
};

class RoznePodstawy{
public:
	RoznePodstawy() {}

	friend std::ostream& operator << (std::ostream& out, RoznePodstawy &rp);
};

std::ostream& operator << (std::ostream& out, ZlaPodstawa &zu) {
	out << "BLAD: Nie mozna utworzyc logarytmu o podstawie <=0 i !=1" << std::endl;
	return out;
}std::ostream& operator << (std::ostream& out, ZlyArgument &za) {
	out << "BLAD: Nie mozna utworzyc logarytmu o argumencie <=0" << std::endl;
	return out;
}
std::ostream& operator << (std::ostream& out, RoznePodstawy &rp) {
	out << "BLAD: Nie mozna dodac logarytmow o roznych podstawach" << std::endl;
	return out;
}


class Funkcja {
protected:
	double argument;

public:
	Funkcja(double arg)
	{
		this->argument = arg;
	}

	double getArg()
	{
		return this->argument;
	}

	virtual double dodaj(double) = 0;
};


class Logarytm : Funkcja {
private:
	int podstawa;

public:
	Logarytm(int podst, double arg) : Funkcja(arg)
	{
		if (podst <= 0 || podst == 1)
			throw ZlaPodstawa();
		if (arg <= 0)
			throw ZlyArgument();
		this->podstawa = podst;
	}

	double dodaj(double arg) {
		return this->argument * arg;
	}

	Logarytm operator + (Logarytm l) {
		if (this->podstawa != l.podstawa)
			throw RoznePodstawy();
		return Logarytm(this->podstawa,this->dodaj(l.argument));
	}

	friend std::ostream& operator << (std::ostream& out, Logarytm & l);
};

std::ostream& operator << (std::ostream& out, Logarytm & l) {
	out << "log_" << l.podstawa << "_(" << l.argument << ")";
	return out;
}

int main()
{
	//Testowanie zlej podstawy
	try {
		Logarytm l3(0, 3);
	}
	catch (ZlaPodstawa zp) {
		std::cout << zp << std::endl;
	}

	//Testowanie zlego argumentu
	try {
		Logarytm l3(3, 0);
	}
	catch (ZlyArgument za) {
		std::cout << za << std::endl;
	}

	//Testowanie zlego dodawania
	try {
		Logarytm l1(2, 4);
		Logarytm l2(3, 3);

		std::cout << l1 + l2 << std::endl;
	}
	catch (RoznePodstawy rp){
		std::cout << rp << std::endl;
	}


	//Prawidlowe dane
	Logarytm l1(3, 4);
	Logarytm l2(3, 3);
	std::cout << l1 << std::endl;
	std::cout << l2 << std::endl;

	std::cout << l1 + l2 << std::endl;


	system("pause");
	return 0;
}