// https://atcoder.jp/contests/abc281/tasks/abc281_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll sum = 0;
    multiset<ll> U, L;
    for (int i = 0; i < M; i++) {
        sum += A[i];
        L.insert(A[i]);
        if ((ll)L.size() > K) {
            ll x = *L.rbegin();
            sum -= x;
            U.insert(x);
            L.erase(L.find(x));
        }
    }

    cout << sum << " ";
    for (int r = M; r < N; r++) {
        int l = r-M;
        ll x = A[l];
        auto iter = L.lower_bound(x);
        if (iter != L.end() && *iter == x) {
            sum -= x;
            L.erase(iter);
            if (!U.empty()) {
                x = *U.begin();
                sum += x;
                U.erase(U.find(x));
                L.insert(x);
            }
        } else {
            U.erase(U.find(x));
        }

        x = A[r];
        sum += x;
        L.insert(x);
        if ((ll)L.size() > K) {
            x = *L.rbegin();
            sum -= x;
            L.erase(L.find(x));
            U.insert(x);
        }

        cout << sum << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
