import re
import pracownicy

with open("pracownicy.txt") as file:
    linesList = file.read().splitlines()
file.close()

p = pracownicy.Pracownicy()

for line in linesList:
    splittedLine = line.split(',')
    if re.match(r'.*programista',splittedLine[3], re.I):
        p1 = pracownicy.Programista(splittedLine)
        p.dodaj(p1)
    else:
        s1 = pracownicy.Sprzedawca(splittedLine)
        p.dodaj(s1)

print(p)