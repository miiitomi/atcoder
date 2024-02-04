#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int B = 1000;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<pair<ll,ll>>> C;

    vector<int> l, r;
    for (int k = 0; k * B < N; k++) {
        l.push_back(B*k);
        r.push_back(min(N-1, B*(k+1)-1));
        vector<pair<ll, ll>> c;
        for (int i = l[k]; i <= r[k]; i++) c.push_back(make_pair(A[i], 0LL));
        c.push_back(make_pair(0, 0));
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (int i = l[k]; i <= r[k]; i++) lower_bound(c.begin(), c.end(), make_pair(A[i], 0LL))->second += A[i];
        for (int j = 0; j < (int)c.size()-1; j++) c[j+1].second += c[j].second;
        C.push_back(c);
    }
    int Q;
    cin >> Q;
    ll ans = 0;
    while (Q--) {
        ll L, R, X;
        cin >> L >> R >> X;
        L ^= ans;
        R ^= ans;
        L--; R--;
        X ^= ans;
        ans = 0;
        for (int k = 0; k < (int)l.size(); k++) {
            if (L <= l[k] && r[k] <= R) {
                auto iter = lower_bound(C[k].begin(), C[k].end(), make_pair(X, 0LL));
                if (iter == C[k].end() || iter->first != X) iter--;
                ans += iter->second;
            } else {
                for (int i = max((int)L, l[k]); i <= min((int)R, r[k]); i++) {
                    if (A[i] <= X) ans += A[i];
                }
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
