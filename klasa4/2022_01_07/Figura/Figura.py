import numpy as np


def f(x): return -(x ** 2) / 50
def g(x): return 1 + x ** 2 / 100 - x / 200


p = 0
q = 10
step = 0.0001
area = 0

for x in np.arange(0.0, q + step, step):
    a = abs(f(x) - g(x))
    b = abs(f(x) - g(x))
    area += (a+b) / 2

area *= step

print("a: ", round(area, 2))

distanceBetweenFxAndGx = 0

x = 0.0
step = 0.001

while distanceBetweenFxAndGx <= 26:
    distanceBetweenFxAndGx = abs(f(x) - g(x))
    x += step

print("b: ", np.ceil(x + 100))
