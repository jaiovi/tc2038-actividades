import numpy as np 
import matplotlib.pyplot as plt

from numpy.linealg import inv

import sys
'''
def f(x):
    sum = 0
    for i in range(x.shape[0]):
        sum += x[i]**2
    #nuestra funcion objetivo de nuestro paraboloide
    return sum
def df(x):
    m=x.shape[0]
    gradient = np.empty(n)
    #recordemos la formula de generar un gradiente ascendente
    for i in range(n):
        gradient[i]=2*x[i]
    return gradient

'''
'''
#RASTRIGIN
def f(x):
    A = 10
    n = x.shape[0]
    sum = A*n
    for i in range(x.shape[0]):
        sum += x[i]**2 - A * np.cos(2*np.pi*x[i])
    return sum

def df(x):
    A = 10
    n=x.shape[0]
    gradient = np.empty(n)
    #recordemos la formula de generar un gradiente ascendente
    for i in range(n):
        gradient[i]=2*x[i] + 2*A* np.pi * np.sin(2*np.pi*x[i])
    return gradient
'''

def f(x):
    return 100 * np.power(x[1] - x[0]**2, 2) + np.power(1- x[0], 2)

def df(x):
    gradient = np.empty(2)
    gradient[0] = 400*np.power(x[0], 3) - 400*x[0]*x[1] + 2*x[0] - 2
    gradient[1] = 200*(x[1] - np.power(x[0], 2))
    return gradient
    
def ddf(x): #matriz hessiana, gradiante cuadrado
    hessian = np.empty([2, 2])
    hessian[0][0] = 1200*np.power(x[0], 2) - 400*x[1] + 2
    hessian[0][1] = -400*x[0]
    hessian[1][0] = -400*x[0]
    hessian[1][1] = 200
    return hessian

def Newton

def gradient_descent(alpha, n,min,max):
    sequence = list()
    x = np.empty(n)
    for i in range (n):
        x[i] = min + (max - min) * np.random.rand()
    sequence.append(x)
    norm = np.infty
    while norm > 1e-4: #el valor de la func objetivo
        gradient = df(x)
        x = x - alpha*gradient
        norm = np.linalg.norm(gradient)
        sequence.append(x)
    return sequence, x
#FIN DE LA RASTRIGIN

#MATPLOTLIB.PYPLOT
def plot(sequence, min, max):
    x = np.linspace(min, max, 1000)
    y = np.linspace(min, max, 1000)
    Z = np.empty((x.shape[0], y.shape[0]))
    for i in range(x.shape[0]):
        for j in range(y.shape[0]):
            w=np.array([ x[i],y[j] ])
            Z[i,j] = f(w)
    X, Y = np.meshgrid(x,y) #creamos espacio pa plotear
    plt.contour(X, Y, Z)
    x1 = np.empty(len(sequence))
    x2 = np.empty(len(sequence))
    for i in range(len(sequence)):
        x1[i]=(sequence[i])[0]
        x2[i]=(sequence[i])[1]
    plt.plot(x1,x2,marker='o')
    plt.show()

alpha = float(sys.argv[1])
n = int(sys.argv[2])
min = float(sys.argv[3])
max = float(sys.argv[4])

sequence, x_opt = gradient_descent(alpha, n, min, max)
print("El optimo esta en ", x_opt," y f = ", f(x_opt))
plot(sequence, min, max)


#Wiliam Strig - creador de shrek, es una pizza, 

'''
NEWTON OPT NO LINEAL
input x : punto inical
outpit loccaly optimal
t=0;
for i in mientras sea distinto a 0

calcular la sig iteracion = xt - gradiente(xt) (gradiente^2 * )
   un gradiente cuadrado es una matriz hessiana

en la funcion de newton original no es

reemplazamos alpha > optimium
caso de prueba. 

ROSENBROCK