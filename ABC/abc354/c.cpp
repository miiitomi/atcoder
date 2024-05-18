#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> X(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> X[i][0] >> X[i][1];
        X[i][2] = i+1;
    }
    sort(X.begin(), X.end());
    set<pair<int,int>> S;
    for (int i = 0; i < N; i++) {
        int c = X[i][1];
        while (!S.empty() && S.rbegin()->first > c) {
            auto iter = S.end();
            iter--;
            S.erase(iter);
        }
        S.insert(make_pair(c, X[i][2]));
    }
    vector<int> v;
    for (auto p : S) v.push_back(p.second);
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i : v) cout << i << " ";
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
