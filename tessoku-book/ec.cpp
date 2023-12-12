#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e+9 + 7;
const ll base = 100;
vector<ll> p(2e+5, 1), s, t;

ll N, Q;
string S, T;

ll f(int a, int b) {
    return (s[b+1] - s[a] * p[b-a+1] % MOD + MOD) % MOD;
}

ll g(int a, int b) {
    return (t[b+1] - t[a] * p[b-a+1] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i < 2e+5; i++) p[i] = p[i-1] * base % MOD;

    cin >> N >> Q;
    cin >> S;
    T = S;
    reverse(T.begin(), T.end());

    s.assign(N+1, 0);
    t.assign(N+1, 0);
    for (int i = 0; i < N; i++) s[i+1] = (s[i] * base + (S[i] - '0' + 1)) % MOD;
    for (int i = 0; i < N; i++) t[i+1] = (t[i] * base + (T[i] - '0' + 1)) % MOD;

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int x = N-1-r, y = N-1-l;
        if (f(l, r) == g(x, y)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
