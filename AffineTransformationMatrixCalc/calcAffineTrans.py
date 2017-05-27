import numpy as np
#from affineMatFromPoints import affine_matrix_from_points
from loadPts import load_points
from matplotlib import pyplot as plt

# read the points 
pts_file1 = 'MatchedPointsAll_1'
Hl_1 = 'Hl_1'
pts = load_points(pts_file1)
#print('pts: \n', pts)
x1_y1 = pts[:,[0,1]]
#print('(X1,Y1) pts: \n', x1_y1)
x2_y2 = pts[:,[2,3]]
#
#Hl_mat = affine_matrix_from_points(*x1_y1,*x2_y2)
#trans = np.dot(np.linalg.inv(*x1_y1),*x2_y2)

primary = x1_y1

'''np.array([[40., 1160., 0.],
                    [40., 40., 0.],
                    [260., 40., 0.],
                    [260., 1160., 0.]])
'''

secondary = x2_y2
''' np.array([[610., 560., 0.],
                      [610., -560., 0.],
                      [390., -560., 0.],
                      [390., 560., 0.]])
'''

# Get transformation matrix

# Pad the data with ones, so that our transformation can do translations too
n = primary.shape[0]
pad = lambda x: np.hstack([x, np.ones((x.shape[0], 1))])
unpad = lambda x: x[:,:-1]
X = pad(primary)
Y = pad(secondary)

# Solve the least squares problem X * A = Y
# to find our transformation matrix A
A, res, rank, s = np.linalg.lstsq(X, Y)
print ('transform matrix(padded)\n: ', A)
transform = lambda x: unpad(np.dot(pad(x), A))
print ('transform matrix\n: ', A)

#print ('Target: ', secondary)
res = transform(primary)
#print ('Result: ', res)
print ('Max error:', np.abs(secondary - res).max())  

plt.title('Primary and secondary points plot')
plt.scatter(primary[:,0],primary[:,1],marker='x', c='b', s=30)
plt.scatter(res[:,0],res[:,1],marker='x', c='r', s=30)
plt.show()

err = np.abs(primary[:,1] - res[:,1])
print('size of arr array :\n', err.shape)
arr = np.arange(err.shape[0])
#print('arr :\n', arr)
plt.title('Error plot')
plt.scatter(arr,err,marker='x', c='r', s=30)
plt.show()
