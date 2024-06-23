// https://atcoder.jp/contests/abc352/tasks/abc352_d
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
    set<int> S;
    for (int i = 0; i < K; i++) {
        S.insert(Q[i]);
    }
    int ans = *S.rbegin() - *S.begin();
    for (int i = K; i < N; i++) {
        S.erase(Q[i-K]);
        S.insert(Q[i]);
        ans = min(ans, *S.rbegin() - *S.begin());
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
