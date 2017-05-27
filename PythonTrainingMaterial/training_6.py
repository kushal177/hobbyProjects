# This has a  ML application to separate IRIS dataset based on four
# features, Petal lenght, petal width, sepal length and sepal width
# This program separates setosa, virginica and  versicolor
# Reference book: Build Maching learning Systems with Python, Richert Coelho
# Chapter 2.

#import matplotlib.pyplot as plt
from matplotlib import pyplot as plt
import sklearn.datasets as dataset
import numpy as np

# load Iris dataset
data = dataset.load_iris()
features = data['data']
feature_names = data['feature_names']
target = data['target']
target_names = data['target_names']

# visualize the data
for t in range(3):
    if (t==0):
        c='r' 
        marker = '>'
    elif (t==1):
        c = 'g' 
        marker = 'o'
    if (t==2):
        c='b' 
        marker = 'x'
    
    plt.scatter(features[t==target, 3], features[t==target, 2], 
            marker=marker, c=c)

 # use NumPy indexing to get array of strings.
 # converting list to numpy array
#labels = target_names[target]# get the array of strings
labels = np.array(target_names[target])
print('label dimensions: \n', labels.shape)

# get all values under petal length
plength = features[:,2]

# build an array fo booleans
is_setosa = (labels=='setosa')
print('is_setosa:', is_setosa.shape)
max_setosa = features[is_setosa].max()
min_non_setosa = features[~is_setosa].min()
print('Maximum of setosa: {0}.'.format(max_setosa))
print('Minimum of others: {0}.'.format(min_non_setosa))

# get the "non setosa " features
features = features[~is_setosa]
labels = labels[~is_setosa]

is_virginica = (labels == 'virginica')

best_acc = -1.0
print('features.shape[1]: ', features.shape[1])

for fi in range (features.shape[1]):# this returns 4
    # we are going to test all possible thresholds
    thresh = features[:,fi]# get all the values corresponding to features[:,fi]
    print('feature number: \n', fi)
    
    for t in thresh:
        features_i = features[:,fi]
        pred = (features_i > t)# build an array of boolean values
        acc = (pred == is_virginica).mean()
        print('acc: \n', acc)
        rev_acc = (pred == ~is_virginica).mean()
        print('rev_acc: \n', rev_acc)
        if rev_acc>acc:
            reverse = True
            acc=rev_acc
        else:
            reverse=False
        
        if acc>best_acc:
            best_acc = acc
            best_fi = fi
            best_t = t
            best_reverse = reverse
            
print(best_fi, best_t, best_reverse, best_acc)

def is_virginica_test(fi, t, reverse, example):
    'Apply threshold model to a new example'
    test = example[fi] > t
    if reverse:
        test = not test
    return test
from threshold import fit_model, predict

correct = 0.0
for ei in range(len(features)):
    # select all but the one at position `ei`:
    training = np.ones(len(features), bool)
    training[ei] = False
    testing = ~training
    model = fit_model(features[training], is_virginica[training])
    predictions = predict(model, features[testing])
    correct += np.sum(predictions == is_virginica[testing])
acc = correct/float(len(features))
print('Accuracy: {0:.1%}'.format(acc))
    

