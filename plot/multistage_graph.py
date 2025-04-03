import matplotlib.pyplot as plt
import numpy as np


adj_matrix = np.array(
    [
        [0, 10, 2, 0, 0, 2],
        [10, 0, 0, 0, 9, 8],
        [2, 0, 0, 5, 0, 1],
        [0, 0, 5, 0, 7, 6],
        [0, 9, 0, 7, 0, 0],
        [2, 8, 1, 6, 0, 0],
    ]
)

edges = [
    [3, 6],
    [1, 3],
    [4, 3],
    [5, 4],
    [2, 6],
]

# Define node positions manually
positions = {
    0: (0, 2),
    1: (3, 2),
    2: (0, 0),
    3: (3, 0),
    4: (4, 1),
    5: (2, 1),
}

# Draw the graph manually
plt.figure(figsize=(6, 6))
plt.axis("off")

# Draw edges
num_nodes = len(adj_matrix)
for i in range(num_nodes):
    for j in range(i, num_nodes):
        if adj_matrix[i, j] > 0:
            x_values = [positions[i][0], positions[j][0]]
            y_values = [positions[i][1], positions[j][1]]
            # label_x = x_values[0] * 0.7 + x_values[1] * 0.3
            # label_y = y_values[0] * 0.7 + y_values[1] * 0.3  # Near the starting point
            label_x = x_values[0] * 0.5 + x_values[1] * 0.5
            label_y = y_values[0] * 0.5 + y_values[1] * 0.5  # In the middle

            plt.plot(x_values, y_values, "gray")
            # plt.arrow(mid_x2, mid_y2, x_end - mid_x2, y_end - mid_y2,
            #                       head_width=0.05, head_length=0.07, fc='gray', ec='gray', length_includes_head=True)
            plt.text(
                label_x,
                label_y,
                str(adj_matrix[i, j]),
                fontweight="bold",
                fontsize=10,
                color="black",
                ha="center",
                va="center",
            )

# Draw select edges
# for [i,j] in edges:
#     x_values = [positions[i-1][0], positions[j-1][0]]
#     y_values = [positions[i-1][1], positions[j-1][1]]
#     # label_x = x_values[0] * 0.7 + x_values[1] * 0.3
#     # label_y = y_values[0] * 0.7 + y_values[1] * 0.3  # Near the starting point
#     label_x = x_values[0] * 0.5 + x_values[1] * 0.5
#     label_y = y_values[0] * 0.5 + y_values[1] * 0.5  # In the middle
#
#     plt.plot(x_values, y_values, "gray")
#     # plt.arrow(mid_x2, mid_y2, x_end - mid_x2, y_end - mid_y2,
#     #                       head_width=0.05, head_length=0.07, fc='gray', ec='gray', length_includes_head=True)
#     plt.text(
#         label_x,
#         label_y,
#         str(adj_matrix[i-1, j-1]),
#         fontweight="bold",
#         fontsize=10,
#         color="black",
#         ha="center",
#         va="center",
#     )
# Draw nodes
for node, (x, y) in positions.items():
    node = node + 1
    # if node == next_correct:
    #     plt.scatter(x, y, s=500, color="green")
    #     plt.text(
    #         x, y, str(node), fontweight="bold", fontsize=12, ha="center", va="center"
    #     )
    #     next_correct = forward[2][next_correct - 1]
    # else:
    plt.scatter(x, y, s=500, color="lightblue")
    plt.text(x, y, str(node), fontsize=12, ha="center", va="center")

plt.title("Prim's Graph")
# plt.show()
plt.savefig("./graphs/prims_graph", dpi=300)
