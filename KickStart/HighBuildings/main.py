T = int(input(''))
for t in range(T):
    N, A, B, C = [int(i) for i in input().split(' ')]

    a = A - C
    b = B - C

    if a + b + C > N or a < 0 or b < 0 or (a == b == 0 and C != N) or (a + b == N):
        ans = "IMPOSSIBLE"
    else:
        buildings = []
        for i in range(a):
            buildings.append(str(N-1))
        if (a):
            for i in range(N - C - a - b):
                buildings.append("1")
        for i in range(C):
            buildings.append(str(N))
        if not a:
            for i in range(N - C - a - b):
                buildings.append("1")
        for i in range(b):
            buildings.append(str(N-1))
        ans = " ".join(buildings)

    print("CASE #{}: {}".format(t+1, ans))
