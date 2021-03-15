import matplotlib.pyplot as plt
import numpy as np

# 不能有空行


f=open("./static.txt")

x = []
y = []

for line in f:
    dataline = line.split()
    xx = float(dataline[0]) #split 后, 依然是字符, 所以要转成数字
    yy = float(dataline[1]) #split 后, 依然是字符, 所以要转成数字
    x.append(xx)
    y.append(yy)

f.close()

x = np.array(x)
y = np.array(y)

fig, ax0 = plt.subplots(figsize=(12, 4))
ax0.plot(x,y)

ax0.set_title('test')

plt.xlabel("x")
plt.ylim(0)
plt.show()

