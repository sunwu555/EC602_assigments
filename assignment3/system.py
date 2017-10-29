#Copyrights 2017 Wu Sun sunw5@bu.edu

import numpy
x = input().split()
xa = numpy.array(x,dtype = float)
h = input().split()
ha = numpy.array(h,dtype = float)
y = numpy.convolve(xa,ha)
print(*y) 