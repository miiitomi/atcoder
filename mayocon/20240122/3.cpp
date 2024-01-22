// https://atcoder.jp/contests/abc143/tasks/abc143_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int x = L[i] + L[j];
            auto iter = lower_bound(L.begin(), L.end(), x);
            if (iter != L.begin()) {
                iter--;
                int k = distance(L.begin(), iter);
                if (j < k) {
                    ans += k - (j+1) + 1;
                }
            }
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
