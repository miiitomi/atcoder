#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        R[P[i]] = i;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (R[a] > R[b]) swap(a, b);
        cout << a + 1 << endl;
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
