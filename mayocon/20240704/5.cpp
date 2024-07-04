// https://atcoder.jp/contests/abc242/tasks/abc242_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S;

ll f(ll t, ll k) {
    if (t == 0) {
        return S[k]-'A';
    }
    if (k == 0) {
        return ((S[k]-'A')+t) % 3;
    }
    return (f(t-1, k/2)+1+(k%2)) % 3;
}

void solve() {
    cin >> S;
    int Q;
    cin >> Q;
    string ABC = "ABC";
    while (Q--) {
        ll t, k;
        cin >> t >> k;
        k--;
        ll i = f(t, k);
        cout << ABC[i] << endl;
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
