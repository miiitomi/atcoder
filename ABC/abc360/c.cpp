#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), W(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> W[i];
    vector<vector<ll>> V(N+1);
    for (int i = 0; i < N; i++) {
        V[A[i]].push_back(W[i]);
    }
    ll ans = 0;
    for (int x = 1; x <= N; x++) {
        if (V[x].size() <= 1) continue;
        sort(V[x].begin(), V[x].end());
        for (int j = 0; j < (int)V[x].size()-1; j++) ans += V[x][j];
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
