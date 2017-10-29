#Copyright 2017 Wu Sun sunw5@bu.edu

Table = "{:<6} {:<22} {:<22} {:<22}"

print(Table.format('Bytes','Largest Unsigned Int','Minimum Signed Int','Maximum Signed Int'))

for i in range(1,9):
	print (Table.format(i,2**(i*8)-1,-1*2**((i*8)-1),2**((i*8)-1)-1))