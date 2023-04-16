import os
import sys
import subprocess as sub

exec = "./TP1"
output = sys.argv[1]

inputFiles = os.listdir("./time/input/")
for file in inputFiles:
	path = f"./time/input/{file}"
	sub.run([exec, "-i", path, "-o", output])
