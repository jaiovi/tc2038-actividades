import numpy as np

from abc import ABCMeta, abstractmethod
class ObjectiveFunction(metaclass=ABCMeta):
    def __init__(self, nvar):
        self.nvar = nvar
        self.xmin = np.empty(nvar)
        self.xmax = np.empty(nvar)
        self.set_xmin()
        self.set_xmax()
        
    @abstractmethod
    def evaluate(self, x):
        pass

    @abstractmethod
    def set_xmin(self):
        pass
    
    @abstractmethod
    def set_xmax(self):
        pass

    @abstractmethod
    def get_name(self):
        pass

    def get_nvar(self):
        return self.nvar

    def get_xmin(self):
        return self.xmin
    
    def get_xmax(self):
        return self.xmax
   

class Paraboloid(ObjectiveFunction):        
    def evaluate(self, x):
        result = 0.0
        for i in range(self.nvar):
            result = result + x[i] ** 2
        return result
    
    def set_xmin(self):
        for i in range(self.nvar):
            self.xmin[i] = -5.0

    def set_xmax(self):
        for i in range(self.nvar):
            self.xmax[i] = 5.0
    
    def get_name(self):
        return Paraboloid.__name__
   

class Rastringin(ObjectiveFunction):     
    def evaluate(self, x):
        result = 0.0
        for i in range(self.nvar):
            result = result + x[i]*x[i] - 10*np.cos(2*np.pi*x[i])
        result = result + 10*self.nvar
        return result
    
    def set_xmin(self):
        for i in range(self.nvar):
            self.xmin[i] = -5.12
    
    def set_xmax(self):
        for i in range(self.nvar):
            self.xmax[i] = 5.12
    
    def get_name(self):
        return Rastringin.__name__

class Rosenbrock(ObjectiveFunction):       
    def evaluate(self, x):
        result = 0.0
        for i in range(self.nvar - 1):
            result = result + 100*np.power(x[i + 1] - x[i]*x[i], 2) + np.power(1 - x[i], 2)
        return result
    
    def set_xmin(self):
        for i in range(self.nvar):
            self.xmin[i] = -10.0
    
    def set_xmax(self):
        for i in range(self.nvar):
            self.xmax[i] = 10.0
    
    def get_name(self):
        return Rosenbrock.__name__

class Ackley(ObjectiveFunction):
    def evaluate(self, x):
        a=20
        b=0.2
        c=2*np.pi
        d=3 #dimensiones que hay self.nvar-1
        result1=0.0
        result2=0.0
        for i in range(self.nvar-1):
            result1 = result1 + np.power(x[i], 2)
            result2 = result2 + np.cos(x[i])
        result1 = -1 * b * np.sqrt(result1 / d)
        result2 = result2 / d
        result3 = ( -1 * a * np.exp(result1) ) - np.exp(result2) + a + np.exp(1)
        return result3

    def set_xmin(self):
        for i in range(self.nvar):
            self.xmin[i] = -32.768
    
    def set_xmax(self):
        for i in range(self.nvar):
            self.xmax[i] = 32.768
    
    def get_name(self):
        return Ackley.__name__

class Bukin(ObjectiveFunction):
    def evaluate(self, x ,x2):
        result = 0.0
        for i in range(self.nvar):
            result = result + np.sqrt( np.abs(x2 - .01*x^2 )) + 0.01*np.abs(x+10)
        result = result * 100
        return result
    
    def set_xmin(self):
        for i in range(self.nvar):
            self.xmin[i] = -15.0
    
    def set_xmax(self):
        for i in range(self.nvar):
            self.xmax[i] = -5.0

    def set_x2min(self):
        for i in range(self.nvar):
            self.xmin[i] = -3.0
    
    def set_x2max(self):
        for i in range(self.nvar):
            self.xmax[i] = 3.0
    
    def get_name(self):
        return Bukin.__name__


class FunctionFactory:
    function_dictionary = {Paraboloid.__name__: Paraboloid,
                            Rastringin.__name__: Rastringin,
                            Rosenbrock.__name__: Rosenbrock,
                            Ackley.__name__: Ackley,
                            Bukin.__name__: Bukin}
    @classmethod
    def select_function(cls, function_name, nvar):
        return cls.function_dictionary[function_name](nvar)