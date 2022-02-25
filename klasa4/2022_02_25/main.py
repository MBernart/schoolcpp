wagi = [4, 2, 1, 3, 7]
wartosci = [8, 3, 1, 2, 1]

waga = 11

def plecakuj(wagi, wartosci, waga):
	wynik = 0
	K = [0 for _ in range(len(wagi))]
	for i in range(len(wagi)):
		K[i] = int(waga/wagi[i])
		waga -= K[i] * wagi[i]
		wynik += wartosci[i] * K[i]

	return wynik, K

print(plecakuj(wagi, wartosci, waga))