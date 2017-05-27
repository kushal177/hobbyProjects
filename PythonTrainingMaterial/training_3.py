# This has a small ML application to fit a model: 
# Reference book: Build Maching learning Systems with Python, Richert Coelho
# Chapter 1: 19.

import scipy as sp
import matplotlib.pyplot as plt

#definition for calculating error
def error (f,x,y):
    return sp.sum((f(x)-y)**2)

# read the data from tsv file.
filename = "D:\study\MachineLearning\ml-with-python\data\BuildingMachineLearningSystemsWithPython-master\ch01\data\web_traffic.tsv"
data = sp.genfromtxt(filename, delimiter='\t')
#print('data: \n', data)
print ('dimesions: ', data.shape)
# pre-processing and cleaning the data
x = data[:,0]
y = data[:,1]
#print('x = ',x)
#print('y = ',y)
total_nan = sp.sum(sp.isnan(y))
print('NAN numbers: \n', total_nan)
# elimination all NANs
x = x[~sp.isnan(y)]
y = y[~sp.isnan(y)]
# plot the initial data
plt.scatter(x,y,s=3.5)
#plt.plot(x,y)
plt.title("Web traffic over the last one month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*25 for w in range(10)], 
           ['week %i'%w for w in range (10)])
plt.autoscale(tight=True)
plt.grid()
#plt.show()

# Intially fit a straight line
fp1,res,rand,sv,rcond = sp.polyfit(x,y,5,full=True)
print('Model params: ', fp1)
print('res: ',res)
f1=sp.poly1d(fp1)
print(error(f1,x,y))

# plot the calculated polynomial
fx = sp.linspace(0,x[-1],1000)# generate X-values for plotting
plt.plot(fx,f1(fx),linewidth=4,color="green")
plt.legend(["d=%i" % f1.order],loc="upper left")
#plt.show()





