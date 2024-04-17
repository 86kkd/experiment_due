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
total_vol = []
for i in range(37,48):
    try:
        v = np.mean(eval(f"tp_{i}"),axis=0)
        total_vol.append(eval(f"tp_{i}"))
        print(f"tp_{i}:",v)
        vol.append(v)
    except: 
        pass


# 利用numpy中的polyfit函数进行线性回归
fit_line = np.polyfit(temperatures, vol, 1)
b,k = fit_line[1],fit_line[0]
# 计算每个采样点到拟合曲线的距离
errors = []
for i in range(len(temperatures)):
    fitted_value = fit_line[0] * temperatures[i] + fit_line[1]
    error = vol[i] - fitted_value
    errors.append(error)
# 计算平均误差作为线性度误差
linear_error = np.max(abs(np.array(errors)))/max(abs(np.array(vol)))
# 计算迟滞误差 平均值在各测量点的差值，找出最大值处以max(abs(np.array(vol)))
delay_error = max(np.array([abs(vol[i] - np.mean(vol)) for i in range(len(vol))])/max(abs(np.array(vol))))
# 重复性误差 计算重复性误差正行程和反行程在各点的最大差值
replay_error = max(np.array([abs(total_vol[i][0]-total_vol[i][1]) for i in range(len(vol))]))/max(abs(np.array(vol)))
# 精度
accyracy = np.sqrt(linear_error**2 + delay_error**2 + replay_error**2)
_X = [37, 47] 
_Y = [b + k * x for x in _X]
print('线性度为:', linear_error)
print('迟滞误差为:', delay_error)
print('重复性误差为:', replay_error)
print('精度为:', accyracy)
plt.plot(_X, _Y, 'r')
plt.plot(temperatures,vol)
print(b,k)
print(vol)
plt.show()