#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    set<int> AB, AA, BB, BA;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A' && T[i] == 'A') AA.insert(i);
        if (S[i] == 'A' && T[i] == 'B') AB.insert(i);
        if (S[i] == 'B' && T[i] == 'B') BB.insert(i);
        if (S[i] == 'B' && T[i] == 'A') BA.insert(i);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == T[i]) continue;
        if (S[i] == 'B') {
            if (!AB.empty()) {
                auto iter = AB.lower_bound(i);
                if (iter != AB.end()) {
                    int j = *iter;
                    AB.erase(j);
                    S[j] = 'B';
                    BB.insert(j);
                    S[i] = 'A';
                    BA.erase(i);
                    AA.insert(i);
                    cnt++;
                    continue;
                }
            }
            auto iter = BB.lower_bound(i);
            if (iter == BB.end()) {
                cout << -1 << endl;
                return;
            } else {
                BA.erase(i);
                S[i] = 'A';
                AA.insert(i);
                cnt++;
            }
        } else {
            auto iter = AA.lower_bound(i);
            if (iter == AA.begin()) {
                cout << -1 << endl;
                return;
            } else {
                S[i] = 'B';
                BB.insert(i);
                AB.erase(i);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
