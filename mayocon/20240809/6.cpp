// https://atcoder.jp/contests/abc249/tasks/abc249_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> t(N), y(N);
    multiset<ll> U, L;
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> y[i];
        if (t[i] == 2) {
            if (y[i] >= 0) {
                U.insert(y[i]);
                tmp += y[i];
            } else {
                L.insert(y[i]);
            }
        }
    }
    ll ans = -INF;
    if (L.size()+U.size() >= N-K) {
        while (U.size() < N-K) {
            auto iter = L.end();
            iter--;
            tmp += *iter;
            U.insert(*iter);
            L.erase(iter);
        }
        ans = max(ans, tmp);
    }
    for (int i = 0; i < N; i++) {
        if (t[i] == 1) {
            if (U.size()+L.size() >= N-K-i-1) {
                if (U.size() >= N-K-i-1) {
                    while (U.size() > N-K-i-1 && *U.begin() < 0) {
                        auto iter = U.begin();
                        tmp -= *iter;
                        L.insert(*iter);
                        U.erase(iter);
                    }
                } else {
                    while (U.size() < N-K-i-1) {
                        auto iter = L.end();
                        iter--;
                        tmp += *iter;
                        U.insert(*iter);
                        L.erase(iter);
                    }
                }
                ans = max(ans, y[i] + tmp);
            }
        } else {
            if (U.contains(y[i])) {
                tmp -= y[i];
                U.erase(U.find(y[i]));
            } else {
                L.erase(L.find(y[i]));
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
