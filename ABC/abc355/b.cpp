#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> C;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        C.push_back({a, 0});
    }
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        C.push_back({a, 1});
    }
    sort(C.begin(), C.end());

    for (int i = 0; i < (int)C.size()-1; i++) {
        if (C[i].second == 0 && C[i+1].second == 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
