#This program attempts to read a CSV file and 
# load the data into a stream and plot & process the data

import numpy as np

def unique_rows(A, return_index=False, return_inverse=False):
    """
    Similar to MATLAB's unique(A, 'rows'), this returns B, I, J
    where B is the unique rows of A and I and J satisfy
    A = B[J,:] and B = A[I,:]

    Returns I if return_index is True
    Returns J if return_inverse is True
    """
    A = np.require(A, requirements='C')
    assert A.ndim == 2, "array must be 2-dim'l"

    B = np.unique(A.view([('', A.dtype)]*A.shape[1]),
               return_index=return_index,
               return_inverse=return_inverse)

    if return_index or return_inverse:
        return (B[0].view(A.dtype).reshape((-1, A.shape[1]), order='C'),) \
            + B[1:]
    else:
        return B.view(A.dtype).reshape((-1, A.shape[1]), order='C')

def load_csv_file(filename):
    ''' loads a gven csv file
    '''
    #data = np.genfromtxt(filename,delimeter=',')
    data = np.loadtxt(filename,dtype='int',delimiter=',')
    return data;
    
pts = load_csv_file('D:/MatchedPoints.txt')
x2_y2_pts = pts[:,[2,3]]
print('Points : ', x2_y2_pts)
uniq_arry = np.zeros(len(x2_y2_pts),bool)

u,ind = unique_rows(x2_y2_pts,return_index=True)
##mark all the numbers that are unique as True
uniq_arry[ind]=True
print('uniq_arry : ', uniq_arry)

x2_y2_filtered = x2_y2_pts[uniq_arry]
print('size of filtered points: ', x2_y2_filtered.shape)