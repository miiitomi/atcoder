#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int M = A.back();
    vector<vector<int>> D(M+1);
    for (int i = 0; i < N; i++) {
        int a = A[i];
        for (int x = 1; x*x <= a; x++) {
            if (a % x == 0) {
                D[x].push_back(i);
                if (x != a/x) D[a/x].push_back(i);
            }
        }
    }

    ll ans = 0;
    vector<ll> cnt(M+1, 0);
    for (ll x = M; x >= 1; x--) {
        for (ll i = 0; i < D[x].size(); i++) {
            cnt[x] += i * (N-1-D[x][i]);
        }
        for (ll y = 2*x; y <= M; y += x) cnt[x] -= cnt[y];
        ans += x * cnt[x];
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
