#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<vector<int>> c(100);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        c[a[i]].push_back(i);
    }

    int cnt = 0;
    for (int x = 0; x < 100; x++) if (c[x].size() >= 2) cnt++;
    if (cnt <= 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> b(N, 1);
    bool done = false;
    for (int x = 0; x < 100; x++) {
        if (c[x].size() <= 1) continue;
        if (!done) {
            done = true;
            b[c[x][0]] = 2;
        } else {
            b[c[x][0]] = 3;
            break;
        }
    }
    for (int x : b) cout << x << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
