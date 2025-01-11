// https://atcoder.jp/contests/past19-open/tasks/past19_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Team {
    ll a, b, i;
};

void solve() {
    ll N, T;
    cin >> N >> T;
    vector<Team> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].a >> V[i].b;
        V[i].i = i;
    }
    sort(V.begin(), V.end(), [](const Team &l, const Team &r) {
        if (l.a != r.a) return l.a > r.a;
        if (l.b != r.b) return l.b < r.b;
        return l.i < r.i;
    });
    ll A = V[0].a, B = V[0].b;
    sort(V.begin(), V.end(), [](const Team &l, const Team &r) {
        return l.i < r.i;
    });
    for (auto &v : V) {
        ll g = T * (A - v.a) + (v.b - B);
        cout << g << "\n";
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
