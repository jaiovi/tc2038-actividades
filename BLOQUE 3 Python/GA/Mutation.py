from abc import ABCMeta, abstractmethod
import numpy as np

class __Mutation(metaclass=ABCMeta):
    @abstractmethod
    def execute_mutation(self, individual):
        pass

    def __init__(self, params, xmin, xmax):
        self.Pm = params.get_Pm()
        self.nvar = params.get_nvar()
        self.xmin = xmin
        self.xmax = xmax

class PBM(__Mutation):
    def execute_mutation(self, individual):
        phenotype_individual = individual.decode()

        for j in range(self.nvar):
            if np.random.rand() >= self.Pm:
                y = phenotype_individual[j]
                yl = self.xmin[j]
                yu = self.xmax[j]
                delta1 = (y - yl)/(yu - yl)
                delta2 = (yu - y)/(yu - yl)
                rnd = 0
                while rnd == 0:
                    rnd = np.random.uniform()
                mut_pow = 1 / (self.Nm + 1)
                if rnd <= 0.5:
                    xy = 1 - delta1
                    val = 2*rnd + (1 - 2*rnd) * np.power(xy, self.Nm + 1)
                    deltaq = np.power(val, mut_pow) - 1
                else:
                    xy = 1 - delta2
                    val = 2*(1 - rnd) + 2*(rnd - 0.5)*np.power(xy, self.Nm + 1)
                    deltaq = 1 - pow(val, mut_pow)
                y = y + deltaq*(yu - yl)
                y = yl if y < yl else y
                y = yu if y > yu else y
                phenotype_individual[j] = y
        individual.code(phenotype_individual)
       

    def __init__(self, params, xmin, xmax):
        super().__init__(params, xmin, xmax)
        self.Nm = params.get_Nm()

    
class MutationSelector:
    mutation_dictionary = {PBM.__name__: PBM}

    @classmethod
    def select_mutation(cls, params, xmin, xmax):
        return cls.mutation_dictionary[params.get_mutation_name()](params, xmin, xmax)
