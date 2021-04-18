f = open("liczby.txt", 'w')
for i in range(100):
    f.write(str(i+1) + '\n')
f.close()
