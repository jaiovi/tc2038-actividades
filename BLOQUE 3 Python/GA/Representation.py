from abc import ABCMeta, abstractmethod
import numpy as np

class Chromosome(metaclass=ABCMeta):    
    def __init__(self, params):
        self.number_genes = params.get_nvar()
        self.number_alleles = params.get_number_alleles()
        self.chromosome_length = self.number_genes * self.number_alleles

    @abstractmethod
    def decode(self):
        pass  

    @abstractmethod
    def code(self, decision_vector):
        pass  
        
    @abstractmethod
    def print(self):
        pass

class BinaryChromosome(Chromosome):
    def __init__(self, params):
        super().__init__(params)
        self.genes = np.empty(self.number_genes, dtype=BinaryGene)

class RealChromosome(Chromosome):
    def __init__(self, params):
        super().__init__(params)
        self.genes = np.empty(self.number_genes, dtype=RealGene)
        for i in range(self.number_genes):
            self.genes[i] = RealGene(self.number_alleles)

    def set_allele_value(self, gene_location, allele_location, allele_value):
        self.genes[gene_location].set_allele(allele_location, allele_value)
            
    def decode(self):
        phenotype = np.empty(self.chromosome_length, dtype=np.float64)
        for i in range(self.chromosome_length):
            phenotype[i] = self.genes[i].decode()
        return phenotype

    def code(self, decision_vector):
        for i in range(self.number_genes):
            self.genes[i].code(decision_vector[i])
    
    def print(self):
        for i in range(self.number_genes):
            for j in range(self.number_alleles):
                print(self.genes[i].get_allele_at(j))

class GenomeFactory:
    __chromosome_dictionary = {RealChromosome.__name__: RealChromosome, 
    BinaryChromosome.__name__: BinaryChromosome}
    
    def __init__(self, params):
        self.params = params

    def create_genome(self):
        return self.__chromosome_dictionary[self.params.get_representation()](self.params)      

class Gene(metaclass=ABCMeta):
    def __init__(self, number_alleles):
        self.number_alleles = number_alleles    
    
    def get_allele_at(self, allele_position):
        return self.alleles[allele_position]

    def set_allele(self, allele_position, allele_value):
        self.alleles[allele_position] = allele_value
    
    @abstractmethod
    def decode(self):
        pass

    @abstractmethod
    def code(self, decision_variable):
        pass

class RealGene(Gene):
    def __init__(self, number_alleles):
        super().__init__(number_alleles)
        self.alleles = np.empty(self.number_alleles, dtype=np.float64)
    
    def decode(self):
        return self.alleles[0]
    
    def code(self, decision_variable):
        self.alleles[0] = decision_variable

class BinaryGene(Gene):
    def __init__(self, number_alleles):
        super().__init__(number_alleles)
        self.alleles = np.empty(self.number_alleles, dtype=np.ubyte)

    def decode(self):
        return 0






