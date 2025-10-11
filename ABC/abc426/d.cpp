#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<pair<int,int>> V;
    int one = 0, zero = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        int x = (S[i] == '1');
        one += x;
        zero += 1-x;
        if (V.empty() || V.back().first != x) {
            V.push_back({x, 1});
        } else {
            V.back().second++;
        }
    }
    if ((int)V.size() == 1) {
        cout << 0 << "\n";
        return;
    }
    N = V.size();
    int ans = 1e+9;
    for (int i = 0; i < N; i++) {
        if (V[i].first == 0) {
            ans = min(ans, one + 2*(zero - V[i].second));
        } else {
            ans = min(ans, zero + 2*(one - V[i].second));
        }
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
