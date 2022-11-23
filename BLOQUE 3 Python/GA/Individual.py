import numpy as np
from Representation import GenomeFactory

class Individual:    
    def __init__(self, genome_factory, obj_func_singleton):
        self.__genotype = genome_factory.create_genome()
        self.__obj_func_singleton = obj_func_singleton
        self.__objective_value = np.infty

    def code(self, x):
        self.__genotype.code(x)        
        self.__objective_value = self.__obj_func_singleton.evaluate(x)
        self.__phenotype = x

    def decode(self):        
        self.__phenotype = self.__genotype.decode()
        return self.__phenotype

    def get_objective_value(self):
        return self.__objective_value
        
    def randomly_initialize(self):       
        x = np.empty(self.__obj_func_singleton.get_nvar())
        xmin = self.__obj_func_singleton.get_xmin()
        xmax = self.__obj_func_singleton.get_xmax()
        for i in range(self.__obj_func_singleton.get_nvar()):
            x[i] = xmin[i] + np.random.rand() * (xmax[i] - xmin[i])
        self.code(x)    
     
    def print_genotype(self):
        self.__genotype.print()

    def print_phenotype(self):
        if(self.__phenotype == None):
            self.decode()
        print(self.__phenotype)
    
class IndividualFactory:
    def __init__(self, params, obj_func_singleton):
        self.__genome_factory = GenomeFactory(params)
        self.__obj_func_singleton = obj_func_singleton

    def create_individual(self):
        return Individual(self.__genome_factory, self.__obj_func_singleton)