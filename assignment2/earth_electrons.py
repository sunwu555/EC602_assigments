#Copyright 2017 Wu Sun sunw5@bu.edu

a = 1086832411937628837875003797140300000000 / 0x3fffffff
b = 8694659295501030703000030377122600000000 / 0x3fffffff
c = (a+b) / 2
c = c * 100000000
b = b * 100000000
a = a * 100000000
print(c)
print(a)
print(b)