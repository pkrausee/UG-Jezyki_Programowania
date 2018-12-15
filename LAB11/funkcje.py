def czynnikiPierwsze(x):
    tab = []
    dziel = 2
    while x > 1:
        while x % dziel == 0:
            tab.append(dziel)
            x = x/dziel
        dziel +=1
    return tab

def liczbaIWykladnik(tab):
    rtab = []
    for i in tab:
        if tab[0] != tab[i]:
            return False
    rtab.append(tab[0])
    rtab.append(len(tab))
    return rtab