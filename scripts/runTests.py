import os
import subprocess as sys

exec = "./TP1"

inputFiles = os.listdir("./time/input/")
for file in inputFiles:
	path = f"./time/input/{file}"
	sys.run([exec, "-i", path, "-o", "./time/output.txt"])
