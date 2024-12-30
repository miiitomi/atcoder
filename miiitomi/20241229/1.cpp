// https://atcoder.jp/contests/abc277/tasks/abc277_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    set<string> st;
    set<char> st1{'H', 'D', 'C', 'S'}, st2{'A', '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (!st1.contains(s[0]) || !st2.contains(s[1]) || st.contains(s)) {
            cout << "No\n";
            return;
        }
        st.insert(s);
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
