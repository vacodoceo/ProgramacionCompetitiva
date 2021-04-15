def solution(m):
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    def fraction_mult(a, b):
        ret = (a[0]*b[0], a[1]*b[1])
        div = gcd(ret[0], ret[1])
        return (ret[0]/div, ret[1]/div)

    def fraction_sum(a, b):
        new_den = a[1]*b[1]
        ret = (a[0]*b[1] + b[0]*a[1], new_den)
        div = gcd(ret[0], ret[1])
        return (ret[0]/div, ret[1]/div)

    M = len(m)
    records = [sum(i) for i in m]
    terminals = filter((lambda x: sum(m[x]) == 0), range(len(m)))
    probs = [(0, 1) for i in range(M)]

    def dfs(i, frac):
        visited.add(i)

        if (i in terminals):
            probs[i] = fraction_sum(probs[i], frac)
            return

        # new_r = 0
        # for j, times in enumerate(m[i]):
        #     if j not in visited:
        #         new_r += times

        for j, times in enumerate(m[i]):
            if j not in visited and times:
                dfs(j, fraction_mult(frac, (times, records[i])))

    for idx, i in enumerate(m[0]):
        if (i):
            visited = set([0])
            dfs(idx, (i, records[0]))

    total = (0, 1)
    for i in terminals:
        total = fraction_sum(total, probs[i])
    pond = (total[1], total[0])

    ans_probs = [fraction_mult(pond, probs[i]) for i in terminals]

    max_div = max([prob[1] for prob in ans_probs])
    ans = [prob[0]*max_div/prob[1] for prob in ans_probs]
    ans.append(max_div)

    return ans


m = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
     [4, 0, 0, 3, 2, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0]]


print(solution(m))
