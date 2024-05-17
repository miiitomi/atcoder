#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end());
    ll ans = 0;
    for (int i = 0; i < N-1; i++) {
        int K = S[i].size();
        int l = i, r = N;
        for (int k = 0; k < K; k++) {
            char c = S[i][k];
            l = i;
            while (r-l > 1) {
                int m = (r + l) / 2;
                if ((int)S[m].size() <= k || S[m][k] != c) r = m;
                else l = m; 
            }
            ans += l-i;
        }
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
