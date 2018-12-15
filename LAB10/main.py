import samochody

class AutoHandel:
    def __init__(self):
        self.auta = []
    def dodaj(self, a):
        self.auta.append(a)
    def usun(self, a):
        self.auta.remove(a)
    def __str__(self):
        out = "Oferta: \n"
        for a in self.auta:
            out += str(a)
        return out


s = samochody.Samochod("Mercedes", 2010, 5000, "czarny", 5)
m = samochody.Maluch(20, False, 1980, 100000, "zielony", "Gdansk", True)
p = samochody.Porsche(10, 2012, 100, "czerwony", 3)

komis = AutoHandel()

komis.dodaj(s)
komis.dodaj(m)
komis.dodaj(p)

print(komis)