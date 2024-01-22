// https://atcoder.jp/contests/abc168/tasks/abc168_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int K;
    string S;
    cin >> K >> S;
    if (S.size() <= K) cout << S << endl;
    else {
        while (S.size() > K) S.pop_back();
        cout << S << "...\n";
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
