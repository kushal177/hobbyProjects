import numpy as ns
b = ns.version.full_version 
print('numpy version : ',b)
a = ns.array([0,1,2,3,4,5])
print('a array = ', a)
c = a.reshape((3,2))
print('c array = \n', c)
"""modification in c array will casue modification in a array"""
c[1][0] = 77
print('c array(modified) = \n',c)
print('a array(modified) = \n', a)
"""
to have totally independant copies use:
    c = a.reshape((3,2)).copy()
"""
#d = ns.arange(500)
d = ns.linspace(2.0,20.0,150)
print('d = \n',d)
sum_d = ns.sum(d)
print('sum of d = \n',sum_d)

# creating and using arrays of structured datatypes
x = ns.array(
             [(1,2.,'hello'), (2,3.,"World"), (5, 14.4, "Crowd")],
             dtype=[('foo', 'i4'), ('bar', 'f4'), ('baz', 'S10')]
             )
print('x elements: ', x)

#print the 1st element
print('1st element', x[2])

# access the field by indexing the string that names the field

y = x['foo'].copy()
print('y elements: ', y)

y[:] = y**2
print('modified y elements: ', y)
print('modified x elements: ', x)