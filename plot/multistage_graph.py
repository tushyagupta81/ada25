import matplotlib.pyplot as plt
import numpy as np

adj_matrix = np.array([
    [0, 9, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 4, 2, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
])

forward = [
    [ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,],
    [16,  7,  9, 18, 15,  7,  5,  7,  4,  2,  5,  0,],
    [ 2,  7,  6,  8,  8, 10, 10, 10, 12, 12, 12, 12,],
]

backward = [
[ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,],
[16,  7,  9, 18, 15,  7,  5,  7,  4,  2,  5,  0,],
[ 3,  7,  6,  8,  8, 10, 10, 10, 12, 12, 12, 12,],
]

# Define node positions manually
positions = {
    0: (0, 2.5),
    1: (1, 4),
    2: (1, 3),
    3: (1, 2),
    4: (1, 1),
    5: (2, 3.5),
    6: (2, 2.5),
    7: (2, 1.5),
    8: (3, 3.5),
    9: (3, 2.5),
    10: (3, 1.5),
    11: (4, 2.5),
}

# Draw the graph manually
plt.figure(figsize=(6, 6))
plt.axis('off')

# Draw edges
num_nodes = len(adj_matrix)
for i in range(num_nodes):
    for j in range(num_nodes):
        if adj_matrix[i, j] > 0:
            x_values = [positions[i][0], positions[j][0]]
            y_values = [positions[i][1], positions[j][1]]
            label_x = x_values[0] * 0.7 + x_values[1] * 0.3
            label_y = y_values[0] * 0.7 + y_values[1] * 0.3  # Raised slightly
            
            plt.arrow(x_values[0], y_values[0], x_values[1] - x_values[0], y_values[1] - y_values[0],
                      head_width=0.05, head_length=0.1, fc='gray', ec='gray', length_includes_head=True)
            plt.text(label_x, label_y, str(adj_matrix[i, j]),fontweight='bold', fontsize=10, color='black', ha='center', va='center')

# Draw nodes
next_correct = forward[0][0]
for node, (x, y) in positions.items():
    node = node +1
    if node == next_correct:
        plt.scatter(x, y, s=500, color='green')
        plt.text(x, y, str(node),fontweight = 'bold', fontsize=12, ha='center', va='center')
        next_correct = forward[2][next_correct-1]
    else:
        plt.scatter(x, y, s=500, color='lightblue')
        plt.text(x, y, str(node), fontsize=12, ha='center', va='center')

plt.title('Multistage Graph - Forward Method')
# plt.show()
plt.savefig("./graphs/forward_multistage",dpi=300)
