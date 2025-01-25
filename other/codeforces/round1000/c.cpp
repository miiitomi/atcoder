#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> cnt(N, 0);
    vector<pair<int,int>> P(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> P[i].first >> P[i].second;
        P[i].first--;
        P[i].second--;
        if (P[i].second < P[i].first) swap(P[i].first, P[i].second);
        cnt[P[i].first]++;
        cnt[P[i].second]++;
    }

    if (N == 2) {
        cout << 0 << "\n";
        return;
    }

    sort(P.begin(), P.end());
    int f = -1, s = -1;
    vector<int> F;
    for (int i = 0; i < N; i++) f = max(f, cnt[i]);
    for (int i = 0; i < N; i++) {
        if (cnt[i] != f) s = max(s, cnt[i]);
        else F.push_back(i);
    }

    if (F.size() >= 3) {
        cout << 2*f - 1 << "\n";
        return;
    }
    if (F.size() == 2) {
        auto iter = lower_bound(P.begin(), P.end(), make_pair(F[0], F[1]));
        if (iter != P.end() && *iter == make_pair(F[0], F[1])) cout << 2*f-2 << "\n";
        else cout << 2*f - 1 << "\n";
        return;
    }
    int ans = f-1 + s-1;
    int i = F[0];
    for (int j = 0; j < N; j++) {
        if (cnt[j] != s) continue;
        auto iter = lower_bound(P.begin(), P.end(), make_pair(min(i, j), max(i, j)));
        if (iter == P.end() || *iter != make_pair(min(i, j), max(i, j))) {
            ans = f + s - 1;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
