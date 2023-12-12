#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = (int)1e+9 + 7;
const ll base = 100;
vector<ll> p(1e+6, 1);

ll N, Q;
string S;
vector<ll> h;

ll f(int a, int b) {
    return (h[b+1] - h[a] * p[b - a + 1] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (ll x = 1; x < 1e+6; x++) p[x] = p[x-1] * base % MOD;

    cin >> N >> Q >> S;
    h.assign(N+1, 0);
    for (int i = 0; i < N; i++) {
        h[i+1] = (h[i] * base % MOD + (S[i] - 'a' + 1)) % MOD;
    }

    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if (f(a, b) == f(c, d)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
