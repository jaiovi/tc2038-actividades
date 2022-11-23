from QuickSort import QuickSort
import numpy as np

class Population:
    def __init__(self, params):        
        self.number_parents = params.get_number_parents()
        self.number_children = params.get_number_children()
        self.population_size = self.number_parents + self.number_children       
        self.population = list()

    def get_population_size(self):
        return self.population_size

    def get_number_children(self):
        return self.number_children
    
    def get_number_parents(self):
        return self.number_parents   
    
    def add_individual(self, individual):
        self.population.append(individual)
    
    def get_individual_at(self, index):
        return self.population[index]
    
    def remove_last(self):
        self.population.pop()
    
    def sort_population(self):
        QuickSort.sort(self.population, 0, len(self.population) - 1)   
    
    def initialize_population(self, individual_factory):
        for i in range(self.number_parents):
            individual = individual_factory.create_individual()
            individual.randomly_initialize()
            self.add_individual(individual)
    
    def clean(self):
        self.population.clear()