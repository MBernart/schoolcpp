from szyfr_cezara import *

f = open('dane_6_1.txt')

dane = f.readlines()

dane = "".join(dane).split('\n')[:-1]

f = open("wyniki_6_1.txt", 'w')

for i in dane:
    f.write(cesarCipher(i, 107) + "\n")

f.close()

print(cesarCipherDecode("LQWHUSUHWRZDQLH", 107))