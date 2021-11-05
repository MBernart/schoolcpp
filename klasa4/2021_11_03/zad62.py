from szyfr_cezara import *

f = open('dane_6_3.txt')

dane = f.readlines()

f.close()

print(dane)

# f = open('wyniki_6_2.txt', 'w')

# for i in dane:
#     if i[1]:
#         f.write(cesarCipherDecode(i[0], int(i[1])) + '\n')
#     else:
#         f.write('\n')

# f.close()