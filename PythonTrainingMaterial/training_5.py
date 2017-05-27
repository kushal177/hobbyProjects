# This has a  ML application to separate IRIS dataset based on four
# features, Petal lenght, petal width, sepal length and sepal width
# This program separates setosa flower with non-setosa flowers
# Reference book: Build Maching learning Systems with Python, Richert Coelho
# Chapter 2.

import matplotlib.pyplot as plt
import sklearn.datasets as dataset
import numpy as np

# We load the data with load_iris from sklearn

data = dataset.load_iris()
print("data type:", type(data) )
features = data['data']
feature_names = data['feature_names']
target = data['target']
target_names = data['target_names']

print('Dimensions: ', features.shape)
slength = features[:,0]
swidth = features[:,1]
plength = features[:,2]
pwidth = features[:,3]
print('Feature names : ', feature_names)
for t, marker,c in zip(np.arange(3), ">ox", "rgb"):
    # we plot each class on it own to get different 
    # colored markers
    plt.scatter(features[target==t,2],
                features[target==t,3],
                marker=marker, c=c)



labels = target_names[target]
# use numpy operastion to get setosa features
is_setosa = (labels =='setosa')

print('feature_names:', labels.shape)

max_setosa = plength[is_setosa].max()
min_non_setosa = plength[~is_setosa].min()

print('Maximum of setosa:', (max_setosa))
print('Minimum of others:', (min_non_setosa))


#if features [:,2]<2: print ('Setosa')
#if (plength < 2): print ('Setosa')
pred = (plength<2)

# count the number of Setosa labels
setosa_count = np.count_nonzero(pred)
print ('Number of setosa: ', setosa_count)
sz = np.size(pred)-setosa_count
print('Number of non-setosa: ',  (np.size(pred)-setosa_count))


    