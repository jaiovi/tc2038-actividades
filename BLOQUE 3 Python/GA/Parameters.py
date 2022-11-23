class Parameters:
    def __init__(self, params_file):
        file = open(params_file, "rt")
        for line in file.readlines():
            fragments = line.split("=")
            if fragments[0] == "number_parents":
                self.number_parents = int(fragments[1])
            elif fragments[0] == "number_children":
                self.number_children = int(fragments[1])
            elif fragments[0] == "Pc":
                self.Pc = float(fragments[1])
            elif fragments[0] == "Nc":
                self.Nc = int(fragments[1])
            elif fragments[0] == "Pm":
                self.Pm = float(fragments[1])
            elif fragments[0] == "Nm":
                self.Nm = int(fragments[1])
            elif fragments[0] == "nvar":
                self.nvar = int(fragments[1])
            elif fragments[0] == "Gmax":
                self.Gmax = int(fragments[1])
            elif fragments[0] == "crossover_name":
                self.crossover_name = fragments[1].strip()
            elif fragments[0] == "mutation_name":
                self.mutation_name = fragments[1].strip()
            elif fragments[0] == "representation":
                self.representation = fragments[1].strip()
            elif fragments[0] == "number_alleles":
                self.number_alleles = int(fragments[1])
            
        if self.Pm == -1:
            self.Pm = 1 / self.nvar


    def get_nvar(self):
        return self.nvar 

    def get_number_parents(self):
        return self.number_parents
    
    def get_number_children(self):
        return self.number_children    
  
    def get_Pc(self):
        return self.Pc

    def get_Nc(self):
        return self.Nc

    def get_Pm(self):
        return self.Pm

    def get_Nm(self):
        return self.Nm

    def get_Gmax(self):
        return self.Gmax

    def get_crossover_name(self):
        return self.crossover_name
    
    def get_mutation_name(self):
        return self.mutation_name
    
    def get_representation(self):
        return self.representation

    def get_number_alleles(self):
        return self.number_alleles
