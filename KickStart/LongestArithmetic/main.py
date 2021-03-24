T = int(input(''))
for t in range(T):
    N = int(input(''))
    arr = [int(i) for i in input('').split(' ')]

    ans = 0
    curr = 1
    diff = 0
    for i in range(1, N):
        if arr[i] - arr[i-1] == diff:
            curr += 1
        else:
            diff = arr[i] - arr[i-1]
            curr = 2

        ans = max(ans, curr)

    print(f'Case #{t+1}: {ans}')
