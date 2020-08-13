from collections import deque


def solution(map):
    m = len(map)
    n = len(map[0])
    target = m*n-1
    matrix = {i: set() for i in range(m*n)}
    walls = []

    def connect(a, b):
        offsets = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for o in offsets:
            (o_a, o_b) = o
            new_a = a + o_a
            new_b = b + o_b
            if 0 <= new_a < m and 0 <= new_b < n and not map[new_a][new_b]:
                c_node = a*n + b
                n_node = new_a*n + new_b
                matrix[c_node].add(n_node)
                matrix[n_node].add(c_node)

    def disconnect(a, b):
        offsets = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for o in offsets:
            (o_a, o_b) = o
            new_a = a + o_a
            new_b = b + o_b
            if 0 <= new_a < m and 0 <= new_b < n and not map[new_a][new_b]:
                c_node = a*n + b
                n_node = new_a*n + new_b
                matrix[c_node].remove(n_node)
                matrix[n_node].remove(c_node)

    for a, i in enumerate(map):
        for b, w in enumerate(i):
            if not w:
                connect(a, b)
            else:
                walls.append((a, b))

    print(matrix)

    def BFS(a, b):
        connect(a, b)
        visited = set([0])
        queue = deque([(0, 0)])

        min_steps = -1
        while queue:
            if min_steps > 0:
                break
            (c_id, steps) = queue.pop()
            steps += 1

            for id in matrix[c_id]:
                if id == target:
                    min_steps = steps + 1
                    break
                if id not in visited:
                    visited.add(id)
                    queue.appendleft((id, steps))
        disconnect(a, b)
        return min_steps

    steps = [BFS(a, b) for (a, b) in walls]
    valid_steps = [s for s in steps if s > 0]
    return min(valid_steps)


m = [[0, 1, 1, 0, 1, 0],
     [0, 1, 1, 0, 1, 0],
     [0, 1, 1, 0, 1, 0],
     [0, 1, 1, 0, 1, 0],
     [0, 0, 0, 0, 1, 0],
     [0, 0, 0, 0, 1, 0],
     [0, 0, 0, 0, 1, 0]]


print(solution(m))
