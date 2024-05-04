#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        Q[P[i]] = i;
    }

    int ans = 1e+9;
    set<int> S;
    for (int i = 0; i < N; i++) {
        if (i >= K) {
            S.erase(Q[i-K]);
        }
        S.insert(Q[i]);
        if ((int)S.size() == K) ans = min(ans, *S.rbegin() - *S.begin());
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
