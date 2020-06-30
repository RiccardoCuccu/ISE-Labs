import os
os.system("gcc -Wall ex2.c -o ex2 -lm")		# the "-lm" option is used to have the library with the mathematical functions included by the linker
os.system("./ex2")
