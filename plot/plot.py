import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

sorting_algo = "strassens"
df = pd.read_csv(f"./csvs/{sorting_algo}.csv")
# df_in = pd.read_csv(f"./{sorting_algo}_input.csv")


# plt.scatter(df_in.iloc[:,0],df_in.iloc[:,1], color="blue", label = "input")
# plt.scatter(df.iloc[:,0],df.iloc[:,1], color="red", label="output")
plt.ticklabel_format(useOffset=False,style='plain')
plt.yscale('log')
plt.title(sorting_algo)
plt.xlabel("n")
plt.subplots_adjust(bottom=0.15,left=0.2)
plt.ylabel("nanoseconds")
# plt.plot(df.iloc[:,0],df.iloc[:,1], label = sorting_algo)
plt.plot(df.iloc[:,0],df.iloc[:,1], label = "convensional")
plt.plot(df.iloc[:,0],df.iloc[:,2], label = "strassens")
plt.plot(df.iloc[:,0],df.iloc[:,3],  label = "divide and conquer")
# plt.plot(df.iloc[:,0],df.iloc[:,0],label = "n")
# plt.plot(df.iloc[:,0],[j*np.log(j) for j in df.iloc[:,0]],label = "n*log(n)")
# plt.plot(df.iloc[:,0],[np.log(j) for j in df.iloc[:,0]],label = "log(n)")
# plt.plot(df.iloc[:,0],[j**2 for j in df.iloc[:,0]], color = "blue",label = "n^2")
plt.plot(df.iloc[:,0],[j**2.81 for j in df.iloc[:,0]], color = "green",label = "n^2.81")
plt.plot(df.iloc[:,0],[j**3 for j in df.iloc[:,0]], color = "red",label = "n^3")
plt.legend()
# plt.show()
plt.savefig(f"./graphs/{sorting_algo}",dpi=300)
