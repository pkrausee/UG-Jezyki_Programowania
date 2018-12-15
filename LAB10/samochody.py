import produkty


class Samochod:
    def __init__(self, marka, rokProdukcji, przebieg, kolor, liczbaDrzwi):
        self.marka = marka
        self.rokProdukcji = rokProdukcji
        self.przebieg = przebieg
        self.kolor = kolor
        self.liczbaDrzwi = liczbaDrzwi
    def __str__(self):
        out = "\n\n" + self.marka+": \n"
        out += "\t Rok produkcji: " + str(self.rokProdukcji) + " rok\n"
        out += "\t Przebieg: " + str(self.przebieg) + "km\n"
        out += "\t Kolor: " + self.kolor + "\n"
        out += "\t Liczba Drzwi: " + str(self.liczbaDrzwi)
        return out


class Maluch(Samochod, produkty.PolskiProdukt):
    def __init__(self, glosnosc, czyJezdzi, rokProdukcji, przebieg, kolor, miastoProdukcji, czyPowypadkowy):
        Samochod.__init__(self, "Maluch", rokProdukcji, przebieg, kolor, 2)
        produkty.PolskiProdukt.__init__(self, miastoProdukcji, "Fiat", czyPowypadkowy)
        self.glosnosc = glosnosc
        self.czyJezdzi = czyJezdzi
    def __str__(self):
        out = Samochod.__str__(self) + "\n"
        out += produkty.PolskiProdukt.__str__(self) + "\n"
        out += "\t Glosnosc: " + str(self.glosnosc) + "db\n"
        if self.czyJezdzi:
            out += "\t W stanie jezdzacym"
        else:
            out += "\t W stanie nie jezdzacym"
        return out


class Porsche(Samochod):
    def __init__(self, ileDoSetki, rokProdukcji, przebieg, kolor, liczbaDrzwi):
        Samochod.__init__(self, "Porsche", rokProdukcji, przebieg, kolor, liczbaDrzwi)
        self.ileDoSetki = ileDoSetki
    def __str__(self):
         out = Samochod.__str__(self) + "\n"
         out += "\t " + str(self.ileDoSetki) + "sec do setki"
         return out