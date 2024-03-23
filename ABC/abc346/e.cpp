#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll H, W, M;
    cin >> H >> W >> M;
    vector<ll> T(M), A(M), X(M);
    for (int i = 0; i < M; i++) cin >> T[i] >> A[i] >> X[i];

    vector<ll> cnt(*max_element(X.begin(), X.end()) + 1, 0);
    cnt[0] = H*W;

    set<int> R, C;

    for (int i = M-1; i >= 0; i--) {
        if (T[i] == 1) {
            if (R.count(A[i])) continue;
            ll x = W - (ll)C.size();
            cnt[X[i]] += x;
            cnt[0] -= x;
            R.insert(A[i]);
        } else {
            if (C.count(A[i])) continue;
            ll x = H - (ll)R.size();
            cnt[X[i]] += x;
            cnt[0] -= x;
            C.insert(A[i]);
        }
    }

    vector<pair<int,ll>> v;

    for (int i = 0; i < (int)cnt.size(); i++) if (cnt[i] > 0) v.push_back(make_pair(i, cnt[i]));

    cout << (int)v.size() << "\n";
    for (auto &p : v) cout << p.first << " " << p.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
