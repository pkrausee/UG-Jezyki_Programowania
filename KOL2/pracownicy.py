class Pracownik:
    def __init__(self,line):
        self.nazwisko = line[0]
        self.imie = line[1]
        self.pesel = line[2]
        self.stanowisko = line[3]
        self.zarobki = line[4]

    def __str__(self):
        return ' Nazwisko: ' + str(self.nazwisko) + '\n Imie: ' + str(self.imie) + '\n Pesel: ' + str(self.pesel) + '\n Stanowisko: ' + str(self.stanowisko) + '\n Zarobki: ' + str(self.zarobki) + '\n'


class Programista(Pracownik):
    def __init__(self,line):
        Pracownik.__init__(self,line)
        self.jezyki = line[5].split(' ')
        if(len(line) > 6):
            self.dodU = line[6]
        else:
            self.dodU = ""

    def __str__(self):
        out = Pracownik.__str__(self)
        if self.dodU != "":
            out += " Dodatkowe umiejetnosci: " + str(self.dodU) + "\n"
        out += " Programista zna nastepujace jezyki programowania: \n"
        for i in self.jezyki:
            out += '\t -' + i + '\n'
        return out


class Sprzedawca(Pracownik):
    def __init__(self,line):
        Pracownik.__init__(self, line)
        self.jezyki = line[5].split(' ')
        self.charP = line[6]
        if (len(line) > 7):
            self.dodU = line[7]
        else:
            self.dodU = ""

    def __str__(self):
        out = Pracownik.__str__(self)
        if self.dodU != "":
            out += " Dodatkowe umiejetnosci: " + str(self.dodU) + "\n"
        out += " Sprzedawca posluguje sie nastepujacymi jezykami: \n"
        for i in self.jezyki:
            out += '\t -' + i + '\n'
        out += " Charakterystyka pracy: " + str(self.charP) + '\n'
        return out


class Pracownicy:
    def __init__(self):
        self.listaPrac = []

    def dodaj(self,p):
        self.listaPrac.append(p)

    def __str__(self):
        out = ""
        for p in self.listaPrac:
            out += str(p) + "\n"
        return out