// https://atcoder.jp/contests/abc261/tasks/abc261_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (mp.count(s)) {
            cout << s << "(" << mp[s] << ")\n";
        } else {
            cout << s << "\n";
        }
        mp[s]++;
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
