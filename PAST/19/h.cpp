// https://atcoder.jp/contests/past19-open/tasks/past19_h
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, S;
    cin >> N >> S;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    do {
        for (int s = 0; s < (1 << (N-1)); s++) {
            __int128_t cnt = 0, tmp = a[0];
            for (int i = 0; i < (N-1) && cnt <= (__int128_t)S && tmp <= (__int128_t)S; i++) {
                if (s & (1 << i)) tmp *= a[i+1];
                else {
                    cnt += tmp;
                    tmp = a[i+1];
                }
            }
            cnt += tmp;
            if (cnt == (__int128_t)S) {
                cout << "Yes\n";
                for (int i = 0; i < N; i++) {
                    cout << a[i];
                    if (i < N-1 && (s & (1 << i))) cout << "x";
                    else if (i < N-1) cout << "+";
                }
                cout << "\n";
                return;
            }
        }

    } while (next_permutation(a.begin(), a.end()));

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
