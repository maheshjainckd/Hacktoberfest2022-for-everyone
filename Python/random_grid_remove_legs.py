import networkx as nx
import random
from matplotlib import pyplot as plt

# Variables
side = 5
remove = 16

if side < 2:
    raise ValueError("Side length must be atleast 1")

max_remove = 2 ** (side - 1)
if remove > max_remove:
    raise ValueError(f"Remove amount can't be more than {max_remove}")

G = nx.grid_2d_graph(side, side)

nodes = G.nodes()

while remove > 0:
    randnode = random.choice(list(nodes))
    direction = random.randrange(0, 3)
    node_x, node_y = randnode[0], randnode[1]
    
    sidenode_x = node_x if (direction % 2 == 1) else (node_x + 1 if direction == 0 else node_x - 1)
    sidenode_y = node_y if (direction % 2 == 0) else (node_y + 1 if direction == 1 else node_y + 1)
    if G.has_edge((sidenode_x, sidenode_y), (node_x, node_y)):
        G.remove_edge((sidenode_x, sidenode_y), (node_x, node_y))
        if not nx.is_connected(G):
            G.add_edge((sidenode_x, sidenode_y), (node_x, node_y))
        remove -= 1

plt.figure(figsize=(3,3))
pos = {(x,y):(y,-x) for x,y in G.nodes()}
nx.draw(G, pos=pos, 
        node_color='black',
        node_size=20)