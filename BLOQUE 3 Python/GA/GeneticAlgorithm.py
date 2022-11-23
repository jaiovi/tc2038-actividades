import numpy as np
from Population import Population
from Individual import IndividualFactory
from Crossover import CrossoverSelector
from Mutation import MutationSelector


class GeneticAlgorithm:
    def __init__(self, params, obj_func):
        self.params = params
        self.obj_func = obj_func
        self.crossover = CrossoverSelector.select_crossover(self.params, obj_func.get_xmin(), obj_func.get_xmax())
        self.mutation = MutationSelector.select_mutation(self.params, obj_func.get_xmin(), obj_func.get_xmax())
        self.individual_factory = IndividualFactory(params, self.obj_func)
        self.population = Population(params)
    
    def __generate_offspring(self):     
        indexes = np.random.permutation(self.population.get_number_parents())
        i = 0
        while i < self.population.get_number_children():
            # Random selection of parents
            parent1 = self.population.get_individual_at(indexes[i])
            parent2 = self.population.get_individual_at(indexes[i + 1])  
            # Crossover
            child1, child2 = self.crossover.execute_crossover(parent1, parent2, self.individual_factory)
            # Mutation
            self.mutation.execute_mutation(child1)
            self.mutation.execute_mutation(child2)        
            # Add to the main population
            self.population.add_individual(child1)
            self.population.add_individual(child2)
            i = i + 2

    def __selection(self):
        self.population.sort_population()
        for i in range(self.population.get_number_children()):
            self.population.remove_last()
    
    def run(self, execution, report):
        self.population.clean()
        self.population.initialize_population(self.individual_factory)
        t = 0
        while t < self.params.get_Gmax():
            self.__generate_offspring()
            self.__selection()
            # Add information to report object
            report.add_best_individual_at_generation(t, execution, self.population.get_individual_at(0))
            t = t + 1            
        return self.population.get_individual_at(0)