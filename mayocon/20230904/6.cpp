// https://atcoder.jp/contests/abc110/tasks/abc110_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int N, M;
vector<mint> factorial;

mint C(int n, int r) {
    return factorial[n] / (factorial[n-r] * factorial[r]);
}

mint H(int n, int r) {
    return C(n+r-1, r);
}

int main() {
    cin >> N >> M;
    factorial.assign(1e+6+1, 1);
    for (int i = 1; i <= (int)1e+6; i++) factorial[i] = i * factorial[i-1];

    map<int, int> primes;
    for (int x = 2; x*x <= M; x++) {
        while (M % x == 0) {
            M /= x;
            primes[x]++;
        }
    }
    if (M != 1) primes[M] = 1;

    mint ans = 1;
    for (auto iter = primes.begin(); iter != primes.end(); iter++) {
        int p = iter->first;
        int r = iter->second;
        ans *= H(N, r);
    }

    cout << ans.val() << endl;
}
