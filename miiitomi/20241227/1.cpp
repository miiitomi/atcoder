// https://atcoder.jp/contests/abc282/tasks/abc282_c
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
    string S;
    cin >> N >> S;
    vector<int> V;
    for (int i = 0; i < N; i++) {
        if (S[i] == '"') V.push_back(i);
    }
    for (char &c : S) if (c == ',') c = '.';
    for (int i = 0; i+1 < (int)V.size(); i+=2) {
        for (int j = V[i]; j < V[i+1]; j++) {
            if (S[j] == '.') S[j] = ',';
        }
    }
    cout << S << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
