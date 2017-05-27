####################################################################
######### This file contains code for loading a TSV file############
####################################################################

import numpy as np

def load_points(dataset_name):
    '''
    data, labels = load_dataset(dataset_name)
    
    Load a given dataset
    
    Returns
    -------
    data : numpy ndarray
    labels : list of str
    '''
    data = []
    
    with open('{0}.txt'.format(dataset_name)) as ifile:
        for line in ifile:
            tokens = line.strip().split(',')
            #print('tokens: \n', tokens)
            data.append([float(tk) for tk in tokens[:]])
           
            #labels.append(tokens[-1])
    #print('data b4: \n', data)
    data = np.array(data)
    #print('data: \n', data)
    return data
        
