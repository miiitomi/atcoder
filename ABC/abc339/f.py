def main():
    N = int(input())
    A = [0 for _ in range(N)]
    D: dict[int, int] = dict()
    for i in range(N):
        A[i] = int(input())
        if A[i] in D:
            D[A[i]] += 1
        else:
            D[A[i]] = 1

    A.sort()
    ans = 0

    for i in range(N):
        for j in range(i, N):
            z = A[i] * A[j]
            if z > A[-1]:
                break
            if z in D:
                if i == j:
                    ans += D[z]
                else:
                    ans += 2*D[z]

    print(ans)


if __name__ == '__main__':
    main()
