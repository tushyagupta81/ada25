import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

sorting_algo = "knapsack"
df = pd.read_csv(f"./{sorting_algo}.csv")


plt.ticklabel_format(useOffset=False,style='plain')
plt.yscale('log')
plt.title(sorting_algo)
plt.xlabel("n")
plt.subplots_adjust(bottom=0.15,left=0.2)
plt.ylabel("nanoseconds")
plt.plot(df.iloc[:,0],df.iloc[:,1], label = sorting_algo)
# plt.plot(df.iloc[:,0],df.iloc[:,0],label = "n")
plt.plot(df.iloc[:,0],[j*np.log(j) for j in df.iloc[:,0]],label = "n*log(n)")
plt.plot(df.iloc[:,0],[j**2 for j in df.iloc[:,0]],label = "n^2")
# plt.plot(df.iloc[:,0],[j**3 for j in df.iloc[:,0]],label = "n^3")
plt.legend()
# plt.show()
plt.savefig(f"./{sorting_algo}",dpi=300)
