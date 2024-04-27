#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), P(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        P[A[i]] = i;
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < N-1; i++) {
        if (A[i] == i) continue;
        int j = P[i];
        int b = A[i];
        ans.push_back(make_pair(i, j));
        swap(P[i], P[b]);
        swap(A[i], A[j]);
    }

    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
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
