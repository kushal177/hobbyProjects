# This has a small ML application to fit a model: 
# This application splits the data at the inflection point
# and fits the two models
# Reference book: Build Maching learning Systems with Python, Richert Coelho
# Chapter 1: 26.

import scipy as sp;
import matplotlib.pyplot as plt

def error(f,x,y):
    return sp.sum((f(x)-y)**2)
    
# read the data from TSV file
filename = "D:\study\MachineLearning\ml-with-python\data\BuildingMachineLearningSystemsWithPython-master\ch01\data\web_traffic.tsv"
data = sp.genfromtxt(filename, delimiter='\t')
print ('Data dimensions: ', data.shape)
# clean up the data
x = data[:,0]
y = data[:,1]
tot_nan = sp.sum(sp.isnan(y))
print('Total NANs: ', tot_nan)

x = x[~sp.isnan(y)]
y = y[~sp.isnan(y)]
# plot the initial data
plt.scatter(x,y,marker='o', c='b', s=3)# here marker indicates the shape, c indicaltes the color, s indicates the size of the scattered points
# used plot function for connected points.
# scatter function does not connect the points
plt.title("We traffic over the last one month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*25 for w in range(10)], ['week %i' % w for w in range(10)])
plt.autoscale(tight=True)
plt.grid()

# fit two straight lines with separationat inflection point
inflection_pt = 3.5*7*25
xa = x[:inflection_pt]# 0 to inflection point
ya = y[:inflection_pt]# 0 to inflection point
xb = x[inflection_pt:]# inflection point +1 to end
yb = y[inflection_pt:]# inflection point +1 to end
fpa = sp.polyfit(xa,ya,1)
fpb = sp.polyfit(xb,yb,1)

f1 = sp.poly1d(fpa)
f2 = sp.poly1d(fpb)
final_err = error(f1,xa,ya)+error(f2,xb,yb)
print('Total fit error: ', final_err)

# plot the calculated polynomials
xpts=sp.linspace(0,x[-1],1000)
plt.plot(xpts,f1(xpts),linewidth=4,color="green")
plt.plot(xpts,f2(xpts),linewidth=4,color="red")
plt.legend(["d=%i" % f1.order],loc="upper left")
plt.show()

 

