// https://atcoder.jp/contests/abc198/tasks/abc198_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> S(3);
    vector<char> v;
    for (int i = 0; i < 3; i++) {
        cin >> S[i];
        for (char c : S[i]) v.push_back(c);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if ((ll)v.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return;
    }
    while ((ll)v.size() < 10) v.push_back('~');

    do {
        vector<ll> N(3, 0);
        
        bool is_ok = true;
        for (int i = 0; i < 3; i++) {
            ll x = 1;
            for (int j = S[i].size()-1; j >= 0; j--) {
                ll y = (ll)distance(v.begin(), find(v.begin(), v.end(), S[i][j]));
                N[i] += x*y;
                if (j == 0 && y == 0) is_ok = false;
                x *= 10;
            }
        }

        if (is_ok && N[0]+N[1]==N[2]) {
            for (int k = 0; k < 3; k++) cout << N[k] << "\n";
            return;
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << "UNSOLVABLE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
