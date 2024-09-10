import random

#Datasets A: lista de elementos con 10 elementos
#Datasets B: lista de elementos con 100 elementos
#Datasets C: lista de elementos con 1000 elementos
#Datasets D: lista de elementos con 10000 elementos
#Datasets E: lista de elementos con 100000 elementos
#Datasets 0: lista de elementos con elementos crecientemente ordenados
#Datasets 1-9: lista de elementos con elementos aleatoriamente ordenados

size = {"A":10, "B":100, "C":1000, "D":10000, "E":100000}

#CODE - DATASET GENERATOR -

for j in size:
    for k in range(10):
        file = open("dataset{0}{1}.txt".format(j,k), "w")
        for i in range(size[j]):
            if(k == 0):
                file.write("{} ".format(i))
                continue
            file.write("{} ".format(random.randrange(size[j])))