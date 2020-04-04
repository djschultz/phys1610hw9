import numpy as np
import matplotlib.pyplot as plt


cores = np.linspace(1,32,32)
times = np.loadtxt("diffusion1d/times.dat")
a = 600
b = 60

plt.plot(cores, times)
plt.xlabel("number of cores")
plt.ylabel("runtime (seconds)")
plt.savefig("runtimes.pdf")
