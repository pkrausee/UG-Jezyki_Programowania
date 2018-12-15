#Zadanie 1
def dec_to_bin(a):
    return int(bin(a)[2:])
def dec_to_binTab(a):
    return list(bin(a)[2:])

x=123
print("Zadanie 1: ")
text = 'Dana jest liczba ' + repr(x)
print(text)
text = 'Utworzona lista: ' + repr(dec_to_binTab(x))
print(text)
text = repr(x)+'=('+repr(dec_to_bin(x))+')'
print(text)

#Zadanie 2
import random
print("Zadanie 2: ")
text = 'Wylosowane liczby: '+repr(sorted(random.sample(range(0,50),6)))
print(text)

#Zadanie 3
dict1 = {
"student1": {"nazwisko": "Kowalski", "imie": "Jan", "nr albumu":"12345"},
"student2": {"nazwisko": "Adamski", "imie": "Adam", "nr albumu": "12346"},
"student3": {"nazwisko": "Beacka", "imie": "Beata", "nr albumu": "12347"}
}
def printDict(dict):
    tab = []
    for k, student in dict.items():
        tab.append(" ".join(student.values()))
    return(sorted(tab))

print("Zadanie 3: ")
print(printDict(dict1))