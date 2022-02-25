def jestPotegaLiczby3(n: int) -> bool:
    if n < 1:
        return False
    if n == 1:
        return True
    else:
        return jestPotegaLiczby3(n/3)


def silnia(n):
    silnia = 1
    for i in range(1, n + 1):
        silnia *= i
    return silnia


def sumaSilniCyfrJestRownaLiczbie(n):
    liczba = str(n)
    suma = 0
    for i in liczba:
        suma += silnia(int(i))
    return n == suma


def nwd(a, b):
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a
    return a


def podciagLiczbZeWspolnymDzielnikiem(tab):
    licznik = 0
    wspolnyDzielnik = 0
    indeksPierwszego = 0
    wspolnyDzielnikTymczasowy = 0
    for i in range(len(tab) - 1):
        licznikTymczasowy = 0
        wspolnyDzielnikTymczasowy = tab[i]
        for j in range(i, len(tab)):
            dzielnikDlaIteracji = wspolnyDzielnikTymczasowy
            wspolnyDzielnikTymczasowy = nwd(wspolnyDzielnikTymczasowy, tab[j])
            if wspolnyDzielnikTymczasowy != 1:
                licznikTymczasowy += 1
            else:
                if licznik < licznikTymczasowy:
                    wspolnyDzielnik = dzielnikDlaIteracji
                    licznik = licznikTymczasowy
                    indeksPierwszego = i
    return tab[indeksPierwszego], licznik, wspolnyDzielnik


with open('liczby.txt') as f:
    linie = list(map(int, f.readlines()))


z4_1 = len(list(filter(jestPotegaLiczby3, linie)))
print(z4_1)
z4_2 = list(filter(sumaSilniCyfrJestRownaLiczbie, linie))
print(z4_2)
print(podciagLiczbZeWspolnymDzielnikiem(linie))
