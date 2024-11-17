#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<pair<char, ll>> V;
    for (char c : S) {
        if (V.empty() || V.back().first != c) V.push_back({c, 1});
        else V.back().second++;
    }
    int cnt = 0, i = -1;
    for (int j = 0; j < (int)V.size(); j++) {
        if (V[j].first == '1') cnt++;

        if (cnt == K) {
            i = j;
            break;
        }
    }
    swap(V[i], V[i-1]);
    for (auto &e : V) {
        cout << string(e.second, e.first);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
