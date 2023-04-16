import sys
import numpy as np

__outdir = './time/input'

# Para cada quantidade indicada na lista Q, serão gerados
# R arquivos diferentes, que possuem uma lista de pontos gerados
# aleatoriamente e formatados de acordo com a especificação do trabalho

lim = int(sys.argv[1])
hop = int(sys.argv[2])
R = int(sys.argv[3])
Q = np.arange(hop, lim + hop, hop)

# Os valores das coordenadas x e y dos pontos estarão entre -valueBound e valueBound

valueBound = 10000

j = 1

for n in Q:
	for i in range(0, R):
		# Vetores com as coordenadas geradas aleatoriamente

		x = np.random.randint(-valueBound, valueBound, n)
		y = np.random.randint(-valueBound, valueBound, n)

		# Abcissas (também aleatórias) das âncoras 

		Xa = np.random.randint(-valueBound,valueBound)
		Xb = np.random.randint(Xa+1,valueBound)

		# Abertura e escrita das informações no arquivo de saída

		filePath = f"{__outdir}/{j}.txt"
		outputFile = open(filePath, "w")

		outputFile.write(f'{n} {Xa} {Xb}\n')
		for p in range(0, n):
			outputFile.write(f'{x[p]} {y[p]}\n')

		outputFile.close()
		
		j += 1
			
			
