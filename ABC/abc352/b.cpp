#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;
    vector<int> ans;
    int j = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        while (T[j] != S[i]) j++;
        ans.push_back(j);
        j++;
    }

    for (int x : ans) cout << x+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
