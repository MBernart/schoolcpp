# Zachłanny algorytm wydawania reszty

T = [50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1]

def wydawanieReszty(kwota, wGroszach = False):
    if not wGroszach:
        kwota *= 100
    doWydania = [0 for _ in range(len(T))]
    for index, i in enumerate(T):
        doWydania[index] += int(kwota / i)
        kwota %= i
    return doWydania

if __name__ == '__main__':
    print(wydawanieReszty(73))