#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<ll> score(5);
    for (int i = 0; i < 5; i++) cin >> score[i];

    vector<pair<ll, string>> V;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    for (int e = 0; e < 2; e++) {
                        ll tmp = 0;
                        string S = "";
                        if (a == 1) {
                            S.push_back('A');
                            tmp += score[0];
                        }
                        if (b == 1) {
                            S.push_back('B');
                            tmp += score[1];
                        }
                        if (c == 1) {
                            S.push_back('C');
                            tmp += score[2];
                        }
                        if (d == 1) {
                            S.push_back('D');
                            tmp += score[3];
                        }
                        if (e == 1) {
                            S.push_back('E');
                            tmp += score[4];
                        }
                        if (!S.empty()) {
                            V.push_back({tmp, S});
                        }
                    }
                }
            }
        }
    }
    sort(V.begin(), V.end(), [](const pair<ll, string> &l, const pair<ll, string> r) {
        if (l.first != r.first) return l.first > r.first;
        return l.second < r.second;
    });

    for (auto &p : V) cout << p.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
