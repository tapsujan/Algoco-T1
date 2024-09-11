import random

#Todas las matrices son cuadradas, sus elementos son aleatorios y son de lado potencia de 2,
#Esto es así para que sean admisibles por el algoritmo de Strassen.
#Datasets A: Matrices de lado 2
#Datasets A: Matrices de lado 8
#Datasets A: Matrices de lado 32
#Datasets A: Matrices de lado 128
#Datasets A: Matrices de lado 256
#Datasets 0: Matrices diagonales
#Datasets 1-9: Matrices llenas

size = {"A":2, "B":8, "C":32, "D":128, "E":256}
MAXNUM = 1000

#CODE - DATASET GENERATOR -

for k in size:
    for f in range(10):
        file = open("dataset{0}{1}.txt".format(k,f), "w")
        for t in range(2):
            for i in range(size[k]):
                for j in range(size[k]):
                    if(f == 0):
                        if(i == j):
                            file.write("{} ".format(random.randrange(MAXNUM)))
                            continue
                        file.write("0 ")
                        continue
                    file.write("{} ".format(random.randrange(MAXNUM)))
                file.write("\n")