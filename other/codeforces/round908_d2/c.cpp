#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> b(N);
    for (int i = 0; i < N; i++) cin >> b[i];

    vector<int> G(N, -1);

    for (int i = 0; i < N; i++) {
        if (!(1 <= b[i] && b[i] <= N)) continue;
        int s = (i - (b[i]-1) + N) % N;
        int t = (s + b[i] + N) % N;
        G[t] = s;
    }

    vector<bool> reached(N, false);
    reached[0] = true;

    int v = 0;
    int d = 0;
    while (K > 0) {
        if (G[v] == -1) {
            cout << "No" << endl;
            return;
        }
        K--;
        d++;
        v = G[v];
        if (reached[v]) break;
        else reached[v] = true;
    }

    cout << "Yes" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
