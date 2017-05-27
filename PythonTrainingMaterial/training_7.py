from matplotlib import pyplot as plt
from sklearn.datasets import load_iris
import numpy as np

def fit_model(features,labels):
    '''learn a simple threshold model'''
    best_acc = -1.0
    #loop over all the features
    for fi in range(features.shape[1]):
        thresh = features[:,fi].copy()
        thresh.sort()
        for t in thresh:
            pred = (features[:,fi]>t)
            # measure the accuracy
            acc = (pred == labels).mean()
            #acc = (pred).mean()
            rev_acc = (pred==~labels).mean()
            #rev_acc = (pred).mean()
            if rev_acc>acc:
                acc = rev_acc
                reverse = True
            else:
                reverse = False
            if acc>best_acc:
                best_acc = acc
                best_fi = fi
                best_t = t
                best_reverse = reverse
    return best_t, best_fi, best_reverse , best_acc
                    
def predict (model, features):
    '''Apply a learned model'''
    t, fi, reverse, acc= model
    
    if reverse:
        return features[:,fi]<=t
    else:
        return features[:,fi]>t

data = load_iris()
features = data.data
feature_names = data.feature_names
target = data.target
target_names = data.target_names

correct = 0.0
labels = target_names[target]
#labels = np.array(target_names[target])
is_virginica = (labels == 'virginica')
print('feature length: ', len(features))
for ei in range (len(features)):
    # select all but the one at position 'ei':
    training = np.ones(len(features),bool)
    training[ei] = False
    testing = ~training
    model = fit_model(features[training],is_virginica[training])
    print('iteration: ', ei)
    print('trained model: ', model)
    predictions = predict(model, features[testing])
    correct +=np.sum(predictions==is_virginica[testing])
acc = correct/float(len(features))
print('Accuracy: {0:.1%}'.format(acc))




