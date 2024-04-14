#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    vector<int> cnt((int)S.size()+1, 0);
    for (char c = 'a'; c <= 'z'; c++) {
        int tmp = 0;
        for (char d : S) {
            if (d == c) tmp++;
        }
        cnt[tmp]++;
    }

    for (int i = 1; i <= (int)S.size(); i++) {
        if (cnt[i] != 0 && cnt[i] != 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
