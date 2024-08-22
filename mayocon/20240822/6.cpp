// https://atcoder.jp/contests/abc167/tasks/abc167_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool cmp(const pair<ll,ll> &l, const pair<ll,ll> &r) {
    ll L = l.second-l.first, R =r.second-r.first;
    if (L >= 0 && R < 0) return true;
    if (L < 0 && R >= 0) return false;
    if (L >= 0 && R >= 0) return l.first < r.first;
    else return l.second > r.second;
}

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> V;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        string q = "";
        for (char &c : s) {
            if (!q.empty() && q.back() == '(' && c == ')') q.pop_back();
            else q.push_back(c);
        }
        ll a = 0, b = 0;
        for (char &c : q) {
            if (c == ')') a++;
            else b++;
        }
        V.push_back({a, b});
    }
    sort(V.begin(), V.end(), cmp);
    ll tmp = 0;
    for (auto &p : V) {
        tmp -= p.first;
        if (tmp < 0) {
            cout << "No\n";
            return;
        }
        tmp += p.second;
    }
    if (tmp == 0) cout << "Yes\n";
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
