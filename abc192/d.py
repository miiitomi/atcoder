def f(X, n):
    k = len(X)
    ans = 0
    for i in range(len(X)):
        ans += pow(n, i) * int(X[k-1-i])
    return ans

X = str(input())
M = int(input())

d = 0
for x in X:
    if int(x) > d:
        d = int(x)

if len(X) == 1:
    if int(X) > M:
        print(0)
    else:
        print(1)
else:
    begin = 0
    end = M + 1
    while end - begin > 1:
        half = (begin + end) // 2
        if f(X, half) > M:
            end = half
        else:
            begin = half
    if begin > d:
        print(begin -d)
    else:
        print(0)