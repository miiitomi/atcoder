// https://atcoder.jp/contests/abc333/tasks/abc333_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> v;
    for (ll a = 1; a <= 1e+15; a = 10*a + 1) {
        for (ll b = 1; b <= 1e+15; b = 10*b + 1) {
            for (ll c = 1; c <= 1e+15; c = 10*c + 1) {
                ll s = a+b+c;
                v.push_back(s);
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
