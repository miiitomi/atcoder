MOD = 998244353

def main():
    A, B = map(int, input().split())
    M = dict()
    
    x = 2
    while (x*x <= A):
        cnt = 0
        while (A % x == 0):
            cnt += 1
            A //= x
        if cnt != 0:
            M[x] = cnt
        x += 1

    if A != 1:
        M[A] = 1

    ans = B
    for x in M:
        ans *= B*M[x] + 1
    
    if ans % 2 == 1:
        ans -= 1
    
    ans //= 2
    ans %= MOD

    print(ans)
    return


if __name__ == '__main__':
    main()
