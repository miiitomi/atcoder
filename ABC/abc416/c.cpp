#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, K, X;
vector<string> S, T;

void rec(vector<int> &v) {
    if ((int)v.size() == K) {
        string s = "";
        for (int &i: v) {
            s += S[i];
        }
        T.push_back(s);
        return;
    }

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        rec(v);
        v.pop_back();
    }
}

void solve() {
    cin >> N >> K >> X;
    S.resize(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<int> v;
    rec(v);
    sort(T.begin(), T.end());
    cout << T[X-1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
