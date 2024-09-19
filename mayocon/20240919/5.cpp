// https://atcoder.jp/contests/abc122/tasks/abc122_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_ok(string S) {
    if (S.substr(0, 3) == "AGC" || S.substr(1, 4) == "AGC") return false;
    for (int i = 0; i < 3; i++) {
        int j = i+1;
        string T = S;
        swap(T[i], T[j]);
        if (T.substr(0, 3) == "AGC" || T.substr(1, 4) == "AGC") return false;
    }
    return true;
}

void solve() {
    ll N;
    cin >> N;
    if (N == 3) {
        cout << 61 << endl;
        return;
    }
    N -= 4;
    string ACGT = "ACGT";
    map<string, mint> dp;
    for (char a : ACGT) {
        for (char b : ACGT) {
            for (char c : ACGT) {
                for (char d : ACGT) {
                    string S = {a, b, c, d};
                    if (is_ok(S)) dp[S] = 1;
                }
            }
        }
    }
    while (N--) {
        map<string, mint> ndp;
        for (auto iter = dp.begin(); iter != dp.end(); iter++) {
            string S = iter->first;
            mint tmp = iter->second;
            for (char c : ACGT) {
                string T = S.substr(1, 4) + c;
                if (is_ok(T)) ndp[T] += tmp;
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    for (auto iter = dp.begin(); iter != dp.end(); iter++) ans += iter->second;
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
