# FAILED uwu

def clean_losts(R_lost, C_lost, B_lost):
    n_cleared = 0

    for r in R_lost:
        if len(r) == 1:
            n_cleared += 1
            cleared = r.pop()
            C_lost[cleared[2]].remove(cleared)
            del B_lost[cleared]

    for c in C_lost:
        if len(c) == 1:
            n_cleared += 1
            cleared = c.pop()
            R_lost[cleared[1]].remove(cleared)
            del B_lost[cleared]

    if n_cleared:
        clean_losts(R_lost, C_lost, B_lost)

    return


T = int(input())

for t in range(T):
    N = int(input())

    A = []
    for n in range(N):
        A.append(list(map(int, input().split())))

    B = []
    for n in range(N):
        B.append(list(map(int, input().split())))

    R = list(map(int, input().split()))
    C = list(map(int, input().split()))

    R_lost = [set() for i in range(N)]
    C_lost = [set() for i in range(N)]
    B_lost = {}

    for i in range(N):
        for j in range(N):
            if B[i][j]:
                R_lost[i].add((B[i][j], i, j))
                C_lost[j].add((B[i][j], i, j))
                B_lost[(B[i][j], i, j)] = 0

    clean_losts(R_lost, C_lost, B_lost)

    time = 0
    while B_lost:
        payed = sorted(B_lost)[0]
        time += payed[0]

        R_lost[payed[1]].remove(payed)
        C_lost[payed[2]].remove(payed)
        del B_lost[payed]
        clean_losts(R_lost, C_lost, B_lost)

    print(f"Case #{t+1}: {time}")
