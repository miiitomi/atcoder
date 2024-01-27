#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    vector<pair<int,int>> V(26, make_pair(0, 0));
    for (int i = 0; i < 26; i++) V[i].second = i;

    for (char c : S) {
        V[c - 'a'].first++;
    }

    sort(V.begin(), V.end(), [](const auto &l, const auto &r) {
        if (l.first != r.first) return l.first > r.first;
        else return l.second < r.second;
    });

    cout << (char)('a' + V[0].second) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
