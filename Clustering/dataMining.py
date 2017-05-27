#This is a small ML application that performs clustering of the # data 
# presented with different clustering algorithms. 

import scipy as sp;
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv
import sys
import collections
#from sklearn.cluster import KMeans
from scipy.cluster.vq import kmeans,vq

# read the ds2.csv file
def load_csv(filename):
    '''
    data, labels = load_dataset(dataset_name)
    
    Load a given dataset
    
    Returns
    -------
    data : numpy ndarray
    labels : list of str
    '''
    data = []
    labels = []#accidents category
    classes = []# state names
    with open(filename) as ifile:
       reader = csv.reader(ifile)
       row1 = next(reader)
       tokens = ",".join(row1)#convert list to str
       tokens1 = tokens.strip().split(',')# split the str at ','commas
       labels.append(tokens1[2:])# append to a vaiable called labels
       for line in ifile:
            tokens = line.strip().split(',')
            #print(type(line))
            data.append([str(tk) for tk in tokens[2:]])
            classes.append(tokens[1])
    data = np.array(data)
    labels = np.array(labels)
    classes = np.array(classes)
    return classes, data, labels
    
def minDist(arr,c, clArr):
    '''
    minVal, minPos = minDist(arr,c, clArr)
    
    For the input list 'arr', calculate the 
    minumum of all values belonging to cluster c.
    
    Returns
    -------
    minVal : numpy int
    minPos : numpy int
    
    '''
    minD = int(sys.maxsize)
    minPos = []

    for y in range(arr.shape[0]):
        if ((clArr[y]==c) & (arr[y]<minD)):
            minD = arr[y]
            minPos = y
            
    return minD, minPos
    
def maxDist(arr,c, clArr):
    '''
    maxVal, maxPos = maxDist(arr,c, clArr)
    
    For the input list 'arr', calculate the 
    maximum of all values belonging to cluster c.
    
    Returns
    -------
    minVal : numpy int
    minPos : numpy int
    
    '''
    maxD = int(-sys.maxsize)
    maxPos = []

    for y in range(arr.shape[0]):
        if ((clArr[y]==c) & (arr[y]>maxD)):
            maxD = arr[y]
            maxPos = y
            
    return maxD, maxPos
    
    
test_data_filename = r"D:\study\MachineLearning\dataminingproblem\ds2.csv"
classes, data, labels = load_csv(test_data_filename)
print('accidentCategories size',labels.shape)

print('Number of states: ', classes.shape[0])

#visualize each accidents as per states
cls_nos = (np.linspace(0,classes.shape[0], classes.shape[0]))

cls_nos = cls_nos.astype(int)
#print('data: ', data[:,0])
#for y in range(data.shape[1]):
#    plt.scatter(cls_nos,data[:,y],s=50)
#    plt.title('%s' % str(labels[:,y]))
#    plt.xticks(cls_nos*2, classes, rotation='vertical')
#    plt.autoscale(tight=True)
#    plt.grid()
#    plt.show()

centArr = []
Data_idArr = []
minArr = []
maxArr = []
maxPArr = []
minPArr = []
dict_min = collections.defaultdict(list)
dict_max = collections.defaultdict(list)
for y in range(data.shape[1]):
    arr = data[:,y].astype(np.float).copy()
    #print("type of arr = \n", type(arr))
    no_of_clusters = np.ceil( np.std(arr/1000, axis=0)).astype(np.int);  
    print("no_of_clusters", '%i' % no_of_clusters, "for accident type", '%s' % (labels[:,y]).astype(np.str))  
    
    cent, _ = kmeans(arr, no_of_clusters)
    centArr.append(cent);
    Data_id, dist = vq(arr, cent)
    minArr = []
    maxArr = []
    for c in range(no_of_clusters):
        min_dist, min_pos = minDist(arr,c, Data_id)
        max_dist, max_pos = maxDist(arr,c, Data_id)
        minArr.append(min_dist)
        maxArr.append(max_dist)
#        minPArr.append(min_pos)
#        maxPArr.append(max_pos)
    Data_idArr.append(Data_id)
#    print("arr = \n", arr.astype(np.int))
#    print("Data_id = \n", Data_id)
    #print ("minArr: \n", minArr)
#    print ("min_pos: \n", minPArr)
    #print ("maxArr: \n", maxArr)
#    print ("max_pos: \n", maxPArr)
    #dictio['y'] = [minArr,maxArr]
    dict_min[y].append(minArr)
    dict_max[y].append(maxArr)

    #print(Data_id)
    
#print(dict_x)
#Data_idArr = np.array(Data_idArr)
#Data_idArr = np.transpose(Data_idArr)
#print('data size: ', data.shape) 
#print('Data_idArr size: ', Data_idArr.shape) 

#print(Data_idArr)
#print(data)
#cls_nos = cls_nos.astype(int)
#y = data[:, 0]
#plt.scatter(cls_nos,y,s=3.5)
##clsuter_i_mean_x = Data_idArr[0]
#minArr = []
#maxArr = []
##if (minArr[Data_idArr[0]]>
##clus_lo = np.min(Data_idArr[0]);
##clus_hi = np.max(Data_idArr[0]);
##print(clsuter_i_mean_x)
#plt.title('%s clusters' % (labels[:,0]).astype(np.str))
#plt.xticks(cls_nos*2, classes, rotation='vertical')
#plt.autoscale(tight=True)
#plt.grid()
#plt.show()

patterns = ['/', '+', 'x', 'o', 'O', '.', '*']  # more patterns

for y in range(data.shape[1]):
    minArrVar = np.array(dict_min[y])
    maxArrVar = np.array(dict_max[y])
    
    plt.scatter(cls_nos,data[:,y],s=50)
    #plt.scatter(np.arange(0, centArr.shape[0]),)
    plt.title('%s' % str(labels[:,y]))
    plt.xticks(cls_nos*2, classes, rotation='vertical')
    plt.autoscale(tight=True)
    tot_x_val = cls_nos.shape[0]
    ax = plt.gca()
    for c in range(minArrVar.shape[1]):
        y1 = minArrVar[:,c].astype(np.int)
        y2 = maxArrVar[:,c].astype(np.int)
        #plt.plot((-1, tot_x_val), (y1,y1), 'k-', lw=0.5)
        #plt.plot((-1, tot_x_val), (y2,y2), 'k-', lw=0.5)
        r = matplotlib.patches.Rectangle((-1, y1), tot_x_val, y2-y1,hatch=patterns[c], fill=False)
        ax.add_artist(r)
    #plt.grid()
    plt.show()
        
# cluster each feature vector
