#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    string T = "";
    for (int i = 0; i < (int)S.size(); i++) {
        char c = S[i];
        if (c == 'i') {
            if ((int)T.size() % 2 != 0) T.push_back('o');
            T.push_back('i');
        } else {
            if ((int)T.size() % 2 != 1) T.push_back('i');
            T.push_back('o');
        }
    }
    if (T.size() % 2 != 0) T.push_back('o');
    cout << T.size() - S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
