#include <bits/stdc++.h>
using namespace std;

void solve() {
    int Q;
    cin >> Q;
    vector<int> V;
    for (int i = 0; i < Q; i++) {
        int c, x;
        cin >> c >> x;
        if (c == 1) V.push_back(x);
        else cout << V[(int)V.size()-x] << "\n";
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
