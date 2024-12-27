// https://atcoder.jp/contests/abc287/tasks/abc287_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S, T;
    cin >> S >> T;
    vector<bool> A(T.size()+1, false), B(T.size()+1, false);
    A[0] = true;
    B[0] = true;
    for (int i = 0; i < (int)T.size(); i++) {
        if (S[i] == '?' || T[i] == '?' || S[i] == T[i]) {
            A[i+1] = true;
        } else {
            break;
        }
    }
    for (int i = 0; i < (int)T.size(); i++) {
        char s = S[S.size()-1-i], t = T[T.size()-1-i];
        if (s == '?' || t == '?' || s == t) {
            B[i+1] = true;
        } else {
            break;
        }
    }
    for (int x = 0; x <= (int)T.size(); x++) {
        if (A[x] && B[T.size()-x]) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
