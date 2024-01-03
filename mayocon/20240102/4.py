def main():
    K = int(input())
    ans = 1
    x = 7
    while x % K != 0 and ans < 1000000:
        x = 10*x + 7
        ans += 1
    
    if ans < 1000000:
        print(ans)
    else:
        print(-1)
    return

if __name__ == '__main__':
    main()
