// https://atcoder.jp/contests/typical90/tasks/typical90_ah
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    vector<int> v = a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int &x : a) x = distance(v.begin(), lower_bound(v.begin(), v.end(), x));

    vector<int> cnt(v.size(), 0);
    int tmp = 0, r = 0, ans = -1;
    for (int l = 0; l < N; l++) {
        while (r < N) {
            if (tmp == K && cnt[a[r]]==0) break;
            cnt[a[r]]++;
            if (cnt[a[r]] == 1) tmp++;
            r++;
        }
        ans = max(ans, r-l);
        cnt[a[l]]--;
        if (cnt[a[l]]==0) tmp--;
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
