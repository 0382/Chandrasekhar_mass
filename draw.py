import matplotlib.pyplot as plt
import numpy as np

length_unit = 1000 # km为单位
mass_unit = 1.9891e30 # 太阳质量为单位

def draw():
    data = np.loadtxt("data.txt", delimiter=',')
    m = data[:,0] / mass_unit
    r = data[:,1] / length_unit
    idx = np.argmax(m)
    plt.figure()
    plt.plot(r, m, '+')
    plt.plot(r[idx], m[idx], 'o', color='red')
    plt.annotate(f"({r[idx]:.1f}, {m[idx]:.2f})",
        xy = (r[idx], m[idx]),  xytext = (500, 1.0),
        arrowprops = dict(arrowstyle="->")
    )
    plt.xlabel(r"$R\mathrm{/km}$")
    plt.ylabel(r"$M/M_{sun}$")
    plt.savefig("result.jpg")

if __name__ == "__main__":
    draw()