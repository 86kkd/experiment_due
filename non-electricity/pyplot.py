import matplotlib.pyplot as plt
import numpy as np
temperatures = [ 37, 38, 39, 40, 41, 42,43,44,45,46,47]

# tp_30 = [116, 120, 118]
# tp_32 = [152, 160, 158]
# tp_33 = [300, 312, 304]
# tp_34 = [378, 377, 385]
# tp_35 = [409, 409, 409]
# tp_36 = [411, 420, 422, 425, 426]
# tp_37 = [433, 436, 430, 430, 438]
# tp_38 = [438, 441, 443]
# tp_39 = [450, 446, 447]
# tp_40 = [460, 455, 453,458]
# tp_41 = [464, 462, 461, 464, 470, 466]
# tp_42 = [471, 482, 481]

# tp_21 = [495, 496]
# tp_22 = [499,500,504,506]

tp_37 = [1.432,1.425]
tp_38 = [1.438,1.440]
tp_39 = [1.452,1.424]
tp_40 = [1.492,1.460]
tp_41 = [1.525,1.527]
tp_42 = [1.607,1.575]
tp_43 = [1.586,1.604]
tp_44 = [1.772,1.672]
tp_45 = [1.812,1.800]
tp_46 = [1.821,1.818]
tp_47 = [1.871,1.894]

vol = []
for i in range(37,48):
    try:
        v = np.mean(eval(f"tp_{i}"),axis=0)
        print(f"tp_{i}:",v)
        vol.append(v)
    except: 
        pass

def linear_regression(x, y): 
    x = np.array(x)
    y = np.array(y)
    N = len(x)
    sumx = sum(x)
    sumy = sum(y)
    sumx2 = sum(x**2)
    sumxy = sum(x*y)
    A = np.mat([[N, sumx], [sumx, sumx2]])
    b = np.array([sumy, sumxy])
    return np.linalg.solve(A, b)
b,k = linear_regression(temperatures,vol)

_X = [37, 47] 
_Y = [b + k * x for x in _X]
plt.plot(_X, _Y, 'r')
plt.plot(temperatures,vol)
print(b,k)
plt.show()