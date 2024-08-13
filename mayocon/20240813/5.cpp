// https://atcoder.jp/contests/abc361/tasks/abc361_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    S = S + "..";
    T = T + "..";
    if (S == T) {
        cout << 0 << endl;
        return;
    }
    map<string, ll> mp;
    mp[S] = 0;
    queue<string> Q;
    Q.push(S);
    while (!Q.empty()) {
        string V = Q.front();
        Q.pop();
        ll k = distance(V.begin(), find(V.begin(), V.end(), '.'));
        for (int i = 0; i < (int)V.size()-1; i++) {
            if (V[i] == '.' || V[i+1] == '.') continue;
            string U = V;
            swap(U[k], U[i]);
            swap(U[k+1], U[i+1]);
            if (mp.contains(U)) continue;
            else if (U == T) {
                cout << mp[V] + 1 << endl;
                return;
            } else {
                mp[U] = mp[V] + 1;
                Q.push(U);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
