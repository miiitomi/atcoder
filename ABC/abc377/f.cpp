#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
bool is_in(int x, int y) {return 0 <= x && x < N && 0 <= y && y < N;}

void solve() {
    cin >> N >> M;
    set<ll> yoko, tate, migiue, migishita;
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        yoko.insert(a);
        tate.insert(b);
        migiue.insert(a+b);
        migishita.insert(a-b);
    }
    vector<ll> cnt(5, 0);
    cnt[0] = N*N;
    cnt[1] = N*yoko.size() + N*tate.size();
    for (ll c : migiue) {
        if (c <= N-1) cnt[1] += c+1;
        else cnt[1] += 2*(N-1)-c+1;
    }
    for (ll d : migishita) {
        if (d >= 0) cnt[1] += N-1-d+1;
        else cnt[1] += N-1+d+1;
    }

    for (ll a : yoko) {
        for (ll b : tate) {
            if (!is_in(a, b)) continue;
            cnt[2]++;
            if (migiue.contains(a+b)) cnt[3]++;
            if (migishita.contains(a-b)) cnt[3]++;
            if (migiue.contains(a+b) && migishita.contains(a-b)) cnt[4]++;
        }
        for (ll c : migiue) {
            ll b = c - a;
            if (!is_in(a, b)) continue;
            cnt[2]++;
            if (migishita.contains(a-b)) cnt[3]++;
        }
        for (ll d : migishita) {
            ll b = a - d;
            if (!is_in(a, b)) continue;
            cnt[2]++;
        }
    }

    for (ll b : tate) {
        for (ll c : migiue) {
            ll a = c - b;
            if (!is_in(a, b)) continue;
            cnt[2]++;
            if (migishita.contains(a-b)) cnt[3]++;
        }
        for (ll d : migishita) {
            ll a = b + d;
            if (!is_in(a, b)) continue;
            cnt[2]++;
        }
    }

    for (ll c : migiue) {
        for (ll d : migishita) {
            if ((c+d)%2 != 0) continue;
            ll a = (c + d) / 2;
            ll b = c - a;
            if (!is_in(a, b)) continue;
            cnt[2]++;
        }
    }

    ll ans = cnt[0] - cnt[1] + cnt[2] - cnt[3] + cnt[4];
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
