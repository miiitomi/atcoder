#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string T = "Takahashi";
    int ans = 0;
    while (N--) {
        string s;
        cin >> s;
        if (T == s) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
