// https://atcoder.jp/contests/abc168/tasks/abc168_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> p2(1e+6, 1);

void solve() {
    ll N;
    cin >> N;
    map<pair<ll,ll>,ll> mp;
    ll zero = 0;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == 0) {
            if (b == 0) {
                zero++;
                continue;
            }
            mp[{a, 1}]++;
            continue;
        } else if (b == 0) {
            mp[{1, 0}]++;
            continue;
        }
        if (a < 0) {
            a *= -1;
            b *= -1;
        }
        ll g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;
        mp[{a,b}]++;
    }
    mint ans = 1;
    set<pair<ll,ll>> seen;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        auto [a, b] = iter->first;
        if (seen.contains(make_pair(a, b))) continue;
        ll m = iter->second;
        seen.insert(make_pair(a, b));
        ll n = 0;

        auto p = make_pair(b, -a);
        if (a == 0 && b == 1) p = {1, 0};
        else if (a == 1 && b == 0) p = {0, 1};
        if (p.first < 0) {
            p.first *= -1;
            p.second *= -1;
        }

        if (mp.contains(p)) {
            n = mp[p];
            seen.insert(p);
        }
        ans *= (p2[m] + p2[n] - 1);
    }
    ans -= 1;
    ans += zero;
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+6; x++) p2[x] = p2[x-1]*2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
