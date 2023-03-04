#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void solve() {
    ll N, D, K;
    cin >> N >> D >> K;
    K--;
    D = D % N;

    if (D == 0) {
        cout << K << endl;
        return;
    }

    ll M = lcm(N, D);
    ll c = M / D;

    cout << ((K / c) % N + ((K % c) * D) % N) % N << endl;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}
