#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    vector<int> X(M, 0);
    while (N--) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            X[j] += x;
        }
    }

    bool is_ok = true;
    for (int j = 0; j < M; j++) {
        if (X[j] < A[j]) is_ok = false;
    }

    if (is_ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
