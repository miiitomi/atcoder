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
    for (int k = 0; k < 2; k++) S.push_back('.');
    for (int k = 0; k < 2; k++) T.push_back('.');
    if (S == T) {
        cout << 0 << endl;
        return;
    }
    map<string, ll> d;
    d[S] = 0;
    queue<string> Q;
    Q.push(S);
    while (!Q.empty()) {
        string s = Q.front();
        Q.pop();
        int i = -1;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == '.') {
                i = j;
                break;
            }
        }
        for (int j = 0; j < (int)s.size()-1; j++) {
            if (s[j] != '.' && s[j+1] != '.') {
                string t = s;
                swap(t[j], t[i]);
                swap(t[j+1], t[i+1]);
                if (d.count(t)) continue;
                d[t] = d[s] + 1;
                if (t == T) {
                    cout << d[t] << endl;
                    return;
                }
                Q.push(t);
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
