node, vertex, start = map(int, input().split())
matrix, DFS_queue, BFS_queue = ([] for _ in range(3)) 
for i in range(node + 1):
    matrix.append([0 for _ in range(node + 1)])
print(matrix)
for i in range(vertex):
    x, y = map(int, input().split())
    matrix[x][y] = matrix[y][x] = 1

DFS_queue.append(start)
dfs_start = start
while len(DFS_queue) != node:
    next_nodes = [i for i, val  in enumerate(matrix[dfs_start]) if i not in DFS_queue and val != 0]
    print(DFS_queue, next_nodes)
    if len(next_nodes) > 0:
        dfs_start = next_nodes[0]
        DFS_queue.append(dfs_start)
    else:
        dfs_start_index = DFS_queue.index(dfs_start)
        if dfs_start_index - 1 == 0:
            break
        start = DFS_queue[dfs_start_index - 1]
print(*DFS_queue, sep=" ")

BFS_queue.append(start)
find_list = [start]
while len(BFS_queue) != node:
    tmp_find_list = []    
    for next_node in find_list:
        next_nodes = [i for i, val in enumerate(matrix[next_node]) if i not in BFS_queue and val != 0]
        BFS_queue += next_nodes
        tmp_find_list += next_nodes
    find_list = tmp_find_list

print(*BFS_queue, sep=" ")
