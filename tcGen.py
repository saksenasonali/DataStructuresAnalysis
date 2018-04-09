# A Test Case Generator to write desired test cases in Python

import random
from random import randint 
from random import shuffle

n = 10000

print n/2, n, n/2

l = []

for i in range(n):
	x = randint(1, 10000000)
	while x in l:
		x = randint(1, 10000000)
	l.append(x)

arr = []

for i in range(n/2):
	arr.append(l[i])
	print l[i],

shuffle(l)

print " "

for i in range(n):
	print l[i], 

shuffle(arr)

print " "

for i in range(n/2):
	print arr[i],