from collections import deque


def solution(entrances, exits, path):
    MAX_BUNNIES = 2000000

    neighbors = [set() for n in range(len(path))]
    visited = deque()
    ans = 0

    for i, row in enumerate(path):
        for j, val in enumerate(row):
            if val:
                neighbors[i].add(j)

    def dfs(n, val):
        visited.append(n)
        if n in exits:
            return val

        for i in neighbors[n]:
            if i not in visited:
                cost = path[n][i]
                p_val = dfs(i, min(val, cost))
                if p_val:
                    return p_val

        visited.pop()
        return 0

    def reduce_path(val, visited):
        for i in range(len(visited)-1):
            a = visited[i]
            b = visited[i+1]
            path[a][b] -= val
            if not path[a][b]:
                neighbors[a].remove(b)

    for e in entrances:
        while True:
            visited.clear()
            p_val = dfs(e, MAX_BUNNIES)
            if not p_val:
                break
            else:
                ans += p_val
                reduce_path(p_val, visited)

    return ans


en, ex, pa = [0, 1], [4, 5], [[0, 0, 4, 6, 0, 0], [0, 0, 5, 2, 0, 0], [
    0, 0, 0, 0, 4, 4], [0, 0, 0, 0, 6, 6], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
print(solution(en, ex, pa))
