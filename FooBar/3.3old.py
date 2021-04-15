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
    probs = [[()]*M for i in range(M)]
    records = [sum(i) for i in m]
    terminals = filter((lambda x: sum(m[x]) == 0), range(len(m)))

    for i in range(M):
        for j in range(M):
            probs[i][j] = (m[i][j], records[i]) if records[i] else (0, 1)

    for j in range(M):
        for k in range(M):
            mult = fraction_mult(probs[0][j], probs[j][k])
            probs[0][k] = fraction_sum(probs[0][k], mult)

    total = (0, 1)
    for i in terminals:
        total = fraction_sum(total, probs[0][i])
    pond = (total[1], total[0])

    ans_probs = [fraction_mult(pond, probs[0][i]) for i in terminals]

    max_div = max([prob[1] for prob in ans_probs])
    ans = [prob[0]*max_div/prob[1] for prob in ans_probs]
    ans.append(max_div)

    return ans


m = [[0, 1, 1, 0, 0, 0],
     [0, 0, 0, 0, 2, 2],
     [0, 0, 0, 0, 2, 2],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0]]


print(solution(m))
