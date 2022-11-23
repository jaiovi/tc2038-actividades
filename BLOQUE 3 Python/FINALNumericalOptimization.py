import numpy as np
from numpy.linalg import inv
import sys
import matplotlib.pyplot as plt

# def f(x):
#     sum = 0
#     n = x.shape[0]
#     for i in range(n):
#         sum += x[i]**2
#     return sum

# def df(x):
#     n = x.shape[0]
#     gradient = np.empty(n)
#     for i in range(n):
#         gradient[i] = 2*x[i]
#     return gradient

def f(x):
    A = 10
    n = x.shape[0]
    result = A*n
    for i in range(n):
        result += x[i]**2 - A * np.cos(2*np.pi*x[i])
    return result

def df(x):
    A = 10
    n = x.shape[0]
    gradient = np.empty(n)
    for i in range(n):
        gradient[i] = 2*x[i] + 2*A*np.pi*np.sin(2*np.pi*x[i])
    return gradient

# def f(x):
#     return 100 * np.power(x[1] - x[0]**2, 2) + np.power(1- x[0], 2)

# def df(x):
#     gradient = np.empty(2)
#     gradient[0] = 400*np.power(x[0], 3) - 400*x[0]*x[1] + 2*x[0] - 2
#     gradient[1] = 200*(x[1] - np.power(x[0], 2))
#     return gradient
    
# def ddf(x):
#     hessian = np.empty([2, 2])
#     hessian[0][0] = 1200*np.power(x[0], 2) - 400*x[1] + 2
#     hessian[0][1] = -400*x[0]
#     hessian[1][0] = -400*x[0]
#     hessian[1][1] = 200
#     return hessian

def newton(n, min, max):
    sequence = list()
    x = np.empty(n)
    for i in range(n):
        x[i] = min + (max  - min)*np.random.rand()
    sequence.append(x)
    norm = np.infty
    while norm >= 1e-4:
        gradient = df(x)
        hessian = ddf(x)
        x = x  - inv(hessian).dot(gradient)
        norm = np.linalg.norm(gradient)
        sequence.append(x)
    return sequence, x

def gradient_descent(alpha, n, min, max):
    sequence = list()
    x = np.empty(n)
    for i in range(n):
        x[i] = min + (max  - min)*np.random.rand()
    sequence.append(x)
    norm = np.infty
    while f(x) > 1e-1:
        gradient = df(x)
        x = x - alpha*gradient
        #print("x= {0}  f(x) = {1}".format(x, f(x)))
        norm = np.linalg.norm(gradient)
        sequence.append(x)
    return sequence, x

def ES(n, min, max, Gmax):
    sequence = list()
    x = np.empty(n)
    normal = np.empty(n)
    for i in range(n):
        x[i] = min + (max  - min)*np.random.rand()
    f_new = 0
    f_old = f(x)
    sequence.append(x)
    t = 0
    while t < Gmax:
        normal = np.random.normal(0, 1, size=(n))
        # Heurística de generación
        x_new = x + normal
        for i in range(n):
            if x_new[i] < min:
                x_new[i] = min
            if x_new[i] > max:
                x_new[i] = max
        f_new = f(x_new)
        # Heuristica de selección
        if f_new < f_old:
            x = x_new
            f_old = f_new
            sequence.append(x)
        t = t + 1
    return sequence, x


def plot(sequence, min, max):
    x = np.linspace(min, max, 1000)
    y = np.linspace(min, max, 1000)
    Z = np.empty((x.shape[0], y.shape[0]))
    for i in range(x.shape[0]):
        for j in range(y.shape[0]):
            w = np.array([x[i], y[j]])
            Z[i, j] = f(w)
    X, Y = np.meshgrid(x, y)
    plt.contour(X, Y, Z)
    x1 = np.empty(len(sequence))
    x2 = np.empty(len(sequence))
    for i in range(len(sequence)):
        x1[i] = sequence[i][0]
        x2[i] = (sequence[i])[1]
    plt.plot(x1, x2, marker='o')
    plt.show()


alpha = float(sys.argv[1])
n = int(sys.argv[2])
min = float(sys.argv[3])
max = float(sys.argv[4])

# sequence, x_opt = gradient_descent(alpha, n, min, max)
# print("El óptimo está en ", x_opt, " y f = ", f(x_opt))
# plot(sequence, min, max)

# sequence, x_opt = newton(n, min, max)
# print("El óptimo está en ", x_opt, " y f = ", f(x_opt))
# plot(sequence, min, max)

sequence, x_opt = ES(n, min, max, 1000)
print("El óptimo está en ", x_opt, " y f = ", f(x_opt))
plot(sequence, min, max)