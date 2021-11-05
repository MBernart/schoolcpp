from szyfr_cezara import *

f = open('dane_6_3.txt')

dane = f.readlines()

dane = "".join(dane).split('\n')[:-1]

print(dane)


f = open("wyniki_6_3.txt", 'w')

for i in dane:
    temp = i.split(" ")
    if not encodedSuccessfully(temp[0], temp[1]):
        f.write(temp[0] + "\n")

f.close()

print(cesarCipherDecode("LQWHUSUHWRZDQLH", 107))