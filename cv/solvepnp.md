
First, forget about translation vector, because it is not related with rotation: translation moves things around, rotation changes their orientation.

Rodrigues parameters are also called axis-angle rotation. They are formed by 4 numbers [theta, x, y, z], which means that you have to rotate an angle "theta" around the axis described by unit vector v=[x, y, z]. Looking at cv::Rodrigues function reference, it seems that OpenCV uses a "compact" representation of Rodrigues notation as vector with 3 elements rod2=[a, b, c], where:

Angle to rotate theta is the module of input vector theta = sqrt(a^2 + b^2 + c^2)
Rotation axis v is the normalized input vector: v = rod2/theta = [a/theta, b/theta, c/theta]
So, Rodrigues vector from solvePnP is not even slightly related with Euler angles notation, which represent three consecutive rotations around a combination of X, Y and Z axes.

How to compare both rotations? This is a good question. Both Euler- and Rodrigues- representations have singularities and other problems. For instance, if you compare two Euler terns, or two Rodrigues parameters, they can look completely different but actually represent almost the same rotation. If you just need to check if both rotations are the same (or approx.), you can follow the next approach:

Transform both rotations to matrix notation (quaternions are also valid)
OpenCV Rodrigues vector can be transformed to matrix using cv::Rodrigues function
For transforming Euler to matrix, I suggest you to take a look to conversions section of euclideanspace.com
