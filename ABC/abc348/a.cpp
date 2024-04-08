#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) cout << 'x';
        else cout << 'o';
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
