import logarytm
import funkcje

l1 = logarytm.Logarytm(8,64)
l2 = logarytm.Logarytm(16,36)
l1.redukuj()
l2.redukuj()
print("Redukcja: "+str(l1))
print("Redukcja: "+str(l2))

l1.oblicz()
l2.oblicz()
print("Oblicz: "+str(l1.oblicz()))
print("Oblicz: "+str(l2.oblicz()))

l3 = logarytm.Logarytm(3,3)
l4 = logarytm.Logarytm(3,4)
l34 = l3 + l4
print("Dodawanie: "+str(l34))


print("Wyjatki: ")
try:
    l5 = logarytm.Logarytm(3, 8)
    l6 = logarytm.Logarytm(4, 9)
    l7 = l5 + l6
except logarytm.RoznePodstawy as error:
    print(error)

try:
    l8 = logarytm.Logarytm(0, 1)
except logarytm.ZlaPodstawa as error:
    print(error)

try:
    l9 = logarytm.Logarytm(2, 0)
except logarytm.ZlyArgument as error:
    print(error)
