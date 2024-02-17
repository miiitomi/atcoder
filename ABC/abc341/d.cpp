#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, K, L;

bool f(ll x) {
    ll a = x / N;
    ll b = x / M;
    ll c = x / L;
    if (a+b-2*c >= K) return true;
    else return false;
}

void solve() {
    cin >> N >> M >> K;
    L = lcm(N, M);

    ll left = 0, right = 9e+18;
    while (right - left > 1) {
        ll x = (right + left) / 2;
        if (f(x)) right = x;
        else left = x;
    }

    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
