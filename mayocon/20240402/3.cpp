// https://atcoder.jp/contests/abc254/tasks/abc254_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<vector<int>> b(K);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i % K].push_back(a[i]);
    }
    sort(a.begin(), a.end());
    vector<int> c(N);
    for (int k = 0; k < K; k++) {
        sort(b[k].begin(), b[k].end());
        int idx = k;
        for (int x : b[k]) {
            c[idx] = x;
            idx += K;
        }
    }

    if (a == c) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
