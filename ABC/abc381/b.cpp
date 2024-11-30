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
    int N = S.size();
    if (N % 2 == 1) {
        cout << "No\n";
        return;
    }
    vector<int> cnt(26, 0);
    for (int i = 0; i < N; i++) {
        cnt[S[i] - 'a']++;
        if (i % 2 == 0) {
            if (S[i] != S[i+1]) {
                cout << "No\n";
                return;
            }
        }
    }
    set<int> st;
    for (int a : cnt) st.insert(a);
    if (st == set<int>{0, 2} || st == set<int>{2}) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
