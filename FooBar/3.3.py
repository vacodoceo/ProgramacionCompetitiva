from fractions import Fraction
from functools import reduce

from fractions import Fraction


def solution(m):
    def gcd(a, b):
        while(b):
            a, b = b, a % b
        return a

    def simplify(x, y):
        g = gcd(x, y)
        return Fraction(long(x/g), long(y/g))

    def lcm(x, y):
        return long(x*y/gcd(x, y))

    def transform(mat):
        sum_list = list(map(sum, mat))
        bool_indices = list(map(lambda x: x == 0, sum_list))
        indices = set([i for i, x in enumerate(bool_indices) if x])
        new_mat = []
        for i in range(len(mat)):
            new_mat.append(list(map(lambda x: Fraction(0, 1) if(
                sum_list[i] == 0) else simplify(x, sum_list[i]), mat[i])))
        transform_mat = []
        zeros_mat = []
        for i in range(len(new_mat)):
            if i not in indices:
                transform_mat.append(new_mat[i])
            else:
                zeros_mat.append(new_mat[i])
        transform_mat.extend(zeros_mat)
        tmat = []
        for i in range(len(transform_mat)):
            tmat.append([])
            extend_mat = []
            for j in range(len(transform_mat)):
                if j not in indices:
                    tmat[i].append(transform_mat[i][j])
                else:
                    extend_mat.append(transform_mat[i][j])
            tmat[i].extend(extend_mat)
        return [tmat, len(zeros_mat)]

    def copy_mat(mat):
        cmat = []
        for i in range(len(mat)):
            cmat.append([])
            for j in range(len(mat[i])):
                cmat[i].append(
                    Fraction(mat[i][j].numerator, mat[i][j].denominator))
        return cmat

    def gauss_elmination(m, values):
        mat = copy_mat(m)
        for i in range(len(mat)):
            index = -1
            for j in range(i, len(mat)):
                if mat[j][i].numerator != 0:
                    index = j
                    break
            if index == -1:
                raise ValueError('Gauss elimination failed!')
            mat[i], mat[index] = mat[index], mat[j]
            values[i], values[index] = values[index], values[i]
            for j in range(i+1, len(mat)):
                if mat[j][i].numerator == 0:
                    continue
                ratio = -mat[j][i]/mat[i][i]
                for k in range(i, len(mat)):
                    mat[j][k] += ratio * mat[i][k]
                values[j] += ratio * values[i]
        res = [0 for i in range(len(mat))]
        for i in range(len(mat)):
            index = len(mat) - 1 - i
            end = len(mat) - 1
            while end > index:
                values[index] -= mat[index][end] * res[end]
                end -= 1
            res[index] = values[index]/mat[index][index]
        return res

    def transpose(mat):
        tmat = []
        for i in range(len(mat)):
            for j in range(len(mat)):
                if i == 0:
                    tmat.append([])
                tmat[j].append(mat[i][j])
        return tmat

    def inverse(mat):
        tmat = transpose(mat)
        mat_inv = []
        for i in range(len(tmat)):
            values = [Fraction(int(i == j), 1) for j in range(len(mat))]
            mat_inv.append(gauss_elmination(tmat, values))
        return mat_inv

    def mat_mult(mat1, mat2):
        res = []
        for i in range(len(mat1)):
            res.append([])
            for j in range(len(mat2[0])):
                res[i].append(Fraction(0, 1))
                for k in range(len(mat1[0])):
                    res[i][j] += mat1[i][k] * mat2[k][j]
        return res

    def splitQR(mat, lengthR):
        lengthQ = len(mat) - lengthR
        Q = []
        R = []
        for i in range(lengthQ):
            Q.append([int(i == j)-mat[i][j] for j in range(lengthQ)])
            R.append(mat[i][lengthQ:])
        return [Q, R]

    res = transform(m)
    if res[1] == len(m):
        return [1, 1]
    Q, R = splitQR(*res)
    inv = inverse(Q)
    res = mat_mult(inv, R)
    row = res[0]
    l = 1
    for item in row:
        l = lcm(l, item.denominator)
    res = list(map(lambda x: long(x.numerator*l/x.denominator), row))
    res.append(l)
    return res


# Theory from https://en.wikipedia.org/wiki/Absorbing_Markov_chain#Examples


def solution2(m):
    # BEGIN https://surajshetiya.github.io/Google-foobar/

    def copy_mat(mat):
        cmat = []
        for i in range(len(mat)):
            cmat.append([])
            for j in range(len(mat[i])):
                cmat[i].append(
                    Fraction(mat[i][j].numerator, mat[i][j].denominator))
        return cmat

    def gauss_elmination(m, values):
        mat = copy_mat(m)
        for i in range(len(mat)):
            index = -1
            for j in range(i, len(mat)):
                if mat[j][i].numerator != 0:
                    index = j
                    break
            if index == -1:
                raise ValueError('Gauss elimination failed!')
            mat[i], mat[index] = mat[index], mat[j]
            values[i], values[index] = values[index], values[i]
            for j in range(i+1, len(mat)):
                if mat[j][i].numerator == 0:
                    continue
                ratio = -mat[j][i]/mat[i][i]
                for k in range(i, len(mat)):
                    mat[j][k] += ratio * mat[i][k]
                values[j] += ratio * values[i]
        res = [0 for i in range(len(mat))]
        for i in range(len(mat)):
            index = len(mat) - 1 - i
            end = len(mat) - 1
            while end > index:
                values[index] -= mat[index][end] * res[end]
                end -= 1
            res[index] = values[index]/mat[index][index]
        return res

    def transpose(mat):
        tmat = []
        for i in range(len(mat)):
            for j in range(len(mat)):
                if i == 0:
                    tmat.append([])
                tmat[j].append(mat[i][j])
        return tmat

    def inverse(mat):
        tmat = transpose(mat)
        mat_inv = []
        for i in range(len(tmat)):
            values = [Fraction(int(i == j), 1) for j in range(len(mat))]
            mat_inv.append(gauss_elmination(tmat, values))
        return mat_inv

    # END https://surajshetiya.github.io/Google-foobar/

    def gcd(a, b):
        while(b):
            a, b = b, a % b
        return a

    def pond(m):
        P = [[Fraction()]*len(m) for i in range(len(m))]
        for i, row in enumerate(m):
            s = sum(row)
            if s:
                for j, val in enumerate(row):
                    P[i][j] = Fraction(val, s)

        return P

    def matrix_sub(A, B):
        C = [[None]*len(A) for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A)):
                C[i][j] = A[i][j] - B[i][j]

        return C

    def getQ(P):
        terminals = filter((lambda x: sum(m[x]) == 0), range(len(P)))
        Q = []
        indexes = []

        for i, row in enumerate(P):
            if i not in terminals:
                indexes.append(i)
                Q.append([])
                for j, val in enumerate(row):
                    if j not in terminals:
                        Q[-1].append(val)

        return Q, indexes, terminals

    def getI(n):
        I = [[0]*n for i in range(n)]
        for i in range(n):
            I[i][i] = 1

        return I

    def getN(Q):
        I = getI(len(Q))
        subs = matrix_sub(I, Q)
        return inverse(subs)

    def normalize(ans):
        string_ans = []

        denominators = [f.denominator for f in ans]

        lcm = reduce((lambda x, y: long(x*y/gcd(x, y))), denominators)

        string_ans = list(
            map(lambda x: long(x.numerator*lcm/x.denominator), ans))
        string_ans.append(lcm)

        return string_ans

    P = pond(m)
    Q, indexes, terminals = getQ(P)
    if (len(terminals) == 1):
        return [1, 1]

    N = getN(Q)

    ans = []
    for t in terminals:
        s = Fraction()
        for idx, n in enumerate(N[0]):
            true_idx = indexes[idx]
            s += n*P[true_idx][t]
        ans.append(s)

    string_ans = normalize(ans)

    return string_ans


m = [[0, 0], [1, 0]]


print(solution(m))
print(solution2(m))
