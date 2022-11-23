from abc import ABCMeta, abstractmethod
import numpy as np

class __Crossover(metaclass=ABCMeta):
    @abstractmethod
    def execute_crossover(self, parent1, parent2, individual_factory):
        pass

    def __init__(self, params, xmin, xmax):
        self.Pc = params.get_Pc()
        self.nvar = params.get_nvar()
        self.xmin = xmin
        self.xmax = xmax

class SBX(__Crossover):
    def execute_crossover(self, parent1, parent2, individual_factory):
        phenotype_parent1 = parent1.decode()
        phenotype_parent2 = parent2.decode()

        phenotype_child1 = np.empty(self.nvar, dtype=np.float64)
        phenotype_child2 = np.empty(self.nvar, dtype=np.float64)
        if(np.random.uniform() >= self.Pc):
            for i in range(self.nvar):
                if np.fabs(phenotype_parent1[i] - phenotype_parent2[i]) > 1.2e-7:
                    if phenotype_parent1[i] < phenotype_parent2[i]:
                        y1 = phenotype_parent1[i]
                        y2 = phenotype_parent2[i]
                    else:
                        y1 = phenotype_parent2[i]
                        y2 = phenotype_parent1[i]
                    yl = self.xmin[i]
                    yu = self.xmax[i]
                    rnd = 0
                    while rnd == 0:
                        rnd = np.random.uniform()

                    betaq = np.power(2*rnd,1.0/(self.Nc + 1)) if rnd <= 0.5 else np.power(2 - 2*rnd,-1/(self.Nc + 1))
                    rnd = 0
                    while rnd == 0:
                        rnd = np.random.uniform()
                    betaq = 1 if rnd <= 0.5 else -1*betaq

                    rnd = 0
                    while rnd == 0:
                        rnd = np.random.uniform()
                    betaq = 1 if rnd <= 0.5 else betaq

                    rnd = 0
                    while rnd == 0:
                        rnd = np.random.uniform()
                    betaq = 1 if rnd > self.Pc else betaq

                    c1 = 0.5*((y1 + y2) - betaq*(phenotype_parent1[i] - phenotype_parent2[i]))
                    c2 = 0.5*((y1 + y2) + betaq*(phenotype_parent1[i] - phenotype_parent2[i]))

                    c1 = yl if c1 < yl else c1
                    c2 = yl if c2 < yl else c2
                    c1 = yu if c1 > yu else c1
                    c2 = yu if c2 > yu else c2

                    if np.random.uniform() >= 0.5:
                        phenotype_child1[i] = c2
                        phenotype_child2[i] = c1
                    else:
                        phenotype_child1[i] = c1
                        phenotype_child2[i] =c2
                else:
                    phenotype_child1[i] = phenotype_parent1[i]
                    phenotype_child2[i] = phenotype_parent2[i]
        else:
            for i in range(self.nvar):
                phenotype_child1[i] = phenotype_parent1[i]
                phenotype_child2[i] = phenotype_parent2[i]
        child1 = individual_factory.create_individual()
        child2 = individual_factory.create_individual()
        child1.code(phenotype_child1)
        child2.code(phenotype_child2)

        return child1, child2

    def __init__(self, params, xmin, xmax):
        super().__init__(params, xmin, xmax)
        self.Nc = params.get_Nc()

class SBX_simple(__Crossover):
    def execute_crossover(self, parent1, parent2, individual_factory):
        phenotype_parent1 = parent1.decode()
        phenotype_parent2 = parent2.decode()

        phenotype_child1 = np.empty(self.nvar, dtype=np.float64)
        phenotype_child2 = np.empty(self.nvar, dtype=np.float64)
        if np.random.rand() >= self.Pc:
            for i in range(self.nvar):        
                r = np.random.uniform()
                gamma = np.power(2 * r, 1/(self.Nc + 1)) if r <= 0.5 else np.power(1/(2 * (1 - r)), 1 / (self.Nc + 1))
                c1 = 0.5 *((1 + gamma)*phenotype_parent1[i] + (1 - gamma)*phenotype_parent2[i])
                c2 = 0.5 *((1 - gamma)*phenotype_parent1[i] + (1 + gamma)*phenotype_parent2[i])

                c1 = self.xmin[i] if c1 < self.xmin[i] else c1
                c1 = self.xmax[i] if c1 > self.xmax[i] else c1
                c2 = self.xmin[i] if c2 < self.xmin[i] else c2
                c2 = self.xmax[i] if c2 > self.xmax[i] else c2

                phenotype_child1[i] = c1
                phenotype_child2[i] = c2
        else:
            for i in range(self.nvar):
                phenotype_child1[i] = phenotype_parent1[i]
                phenotype_child2[i] = phenotype_parent2[i]
        child1 = individual_factory.create_individual()
        child2 = individual_factory.create_individual()
        child1.code(phenotype_child1)
        child2.code(phenotype_child2)
        return child1, child2
    
    def __init__(self, params, xmin, xmax):
        super().__init__(params, xmin, xmax)
        self.Nc = params.get_Nc()

class LinearCrossover(__Crossover):
    def execute_crossover(self, parent1, parent2, individual_factory):
        phenotype_parent1 = parent1.decode()
        phenotype_parent2 = parent2.decode()

        phenotype_child1 = np.empty(self.nvar, dtype=np.float64)
        phenotype_child2 = np.empty(self.nvar, dtype=np.float64)
        phenotype_child3 = np.empty(self.nvar, dtype=np.float64)
        if np.random.rand() >= self.Pc:
            for i in range(self.nvar):
                c1 = phenotype_parent1[i] + phenotype_parent2[i]
                c2 = 1.5*phenotype_parent1[i] - 0.5*phenotype_parent2[i]
                c3 = -0.5*phenotype_parent1[i] + 1.5*phenotype_parent2[i]

                c1 = self.xmin[i] if c1 < self.xmin[i] else c1
                c2 = self.xmin[i] if c2 < self.xmin[i] else c2
                c3 = self.xmin[i] if c3 < self.xmin[i] else c3

                c1 = self.xmax[i] if c1 > self.xmax[i] else c1
                c2 = self.xmax[i] if c2 > self.xmax[i] else c2
                c3 = self.xmax[i] if c3 > self.xmax[i] else c3

                phenotype_child1[i] = c1
                phenotype_child2[i] = c2
                phenotype_child3[i] = c3
        else:
            for i in range(self.nvar):
                phenotype_child1[i] = phenotype_parent1[i]
                phenotype_child2[i] = phenotype_parent2[i]
                phenotype_child3[i] = phenotype_parent1[i]
        child1 = individual_factory.create_individual()
        child2 = individual_factory.create_individual()
        child3 = individual_factory.create_individual()

        child1.code(phenotype_child1)
        child2.code(phenotype_child2)
        child3.code(phenotype_child3)
        return child1, child2, child3

    def __init__(self, params, xmin, xmax):
            super().__init__(params, xmin, xmax)
    
class CrossoverSelector:
    crossover_dictionary = {SBX.__name__: SBX,
                            SBX_simple.__name__: SBX_simple,
                            LinearCrossover.__name__: LinearCrossover}

    @classmethod
    def select_crossover(cls, params, xmin, xmax):
        return cls.crossover_dictionary[params.get_crossover_name()](params, xmin, xmax)
