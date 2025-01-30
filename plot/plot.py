import matplotlib.pyplot as plt
import numpy as np

sorting_algo = "quicksort"

x = [ 10,20,40,80,160,320,640,1280,2560,5120,10240,20480,40960,81920,163840,327680,655360,1310720,2621440 ]
y = [ 1141,2362,5341,12116,26783,60454,133887,271787,613983,1141787,1806054,2926233,5074287,10520262,22338470,48237487,102054879,215057829,452852295 ]

plt.ticklabel_format(useOffset=False,style='plain')
plt.title("Quicksort")
plt.xlabel("n")
plt.subplots_adjust(bottom=0.15,left=0.2)
plt.ylabel("nanoseconds")
plt.plot(x,y)
plt.savefig(f"./{sorting_algo}",dpi=300)
