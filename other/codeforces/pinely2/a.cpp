#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;

    vector<int> g(q+1, 0);
    g[0] = a;

    string S;
    cin >> S;

    for (int t = 0; t < q; t++) {
        char c = S[t];
        if (c == '-') {
            g[t+1] = g[t] - 1;
        } else {
            g[t+1] = g[t] + 1;
            a++;
        }
    }

    int m = *max_element(g.begin(), g.end());

    if (m >= n) cout << "YES" << endl;
    else if (a >= n) cout << "MAYBE" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
