import numpy as np
#a = np.arange(3*4*5*6).reshape((3,4,5,6))
a = np.arange(3*4*5*6)
b = np.reshape(a,(12,30))
print('a \n= ',a)
print('b \n= ',b)
print('a shape:', a.shape)
print('b shape:', b.shape)
c = np.arange(5)
print('c array: \n',c)
d = c*2
print('d array: \n',d)
e = c**2
print('e array: \n',e)