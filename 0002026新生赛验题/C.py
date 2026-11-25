def check(n, val):
    threshold = (n * n + 1) // 2
    cnt = 0

    for i in range(1, n + 1):
        cnt += min(n, val // i)

    return cnt < threshold

def solve():
    n = int(input())
    l, r = 1, n * n
    while (l <= r):
        mid = (l + r) // 2
        if (check(n, mid)):
            l = mid + 1
        else:
            r = mid - 1

    print(l)

t = int(input())
for i in range(t):
    solve()

