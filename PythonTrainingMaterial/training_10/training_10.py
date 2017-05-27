# This is a Machine learning application that finds the affinity of a 
# test post with that of stored posts. it use bag of word approach. it uses
# SK lean library and NLP tooliit.

import numpy as np
import scipy as sp

from matplotlib import pyplot as plt
import os 

DIR = 'D:/study/MachineLearning/ml-with-python/codes/training_10/posts/';

#posts = [open(os.path.join(DIR,f)).read() for f in os.listdir(DIR)]
posts = []
for f in os.listdir(DIR):
    fileH = open(os.path.join(DIR,f))
    posts.append(fileH.read())
    print("file path = ", os.path.join(DIR,f))
print("file contents = ", posts)

from sklearn.feature_extraction.text import CountVectorizer
vect = CountVectorizer(min_df=1)
X_train = vect.fit_transform(posts)

print ("feature names:\n ",vect.get_feature_names())
print ("train data:\n ",X_train.toarray())

new_post  = "Imaging Databases contains data"
new_post_vec = vect.transform([new_post])
print ("new post array:\n ",new_post_vec.toarray())

import scipy as sp
def dist_row(v1,v2):
    delta = v1-v2
    return sp.linalg.norm(delta.toarray())
