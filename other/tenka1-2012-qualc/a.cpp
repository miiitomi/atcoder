#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<bool> V(N, true);
    V[0] = false;
    if (N > 1) V[1] = false;

    for (int x = 2; x < N; x++) {
        if (!V[x]) continue;
        for (int y = 2*x; y < N; y += x) {
            V[y] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (V[i]) ans++;
    }

    cout << ans << endl;
}
