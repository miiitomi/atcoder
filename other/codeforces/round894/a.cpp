#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    string vika = "vika";
    int x = 0;
    for (int k = 0; k < M; k++) {
        for (int j = 0; j < N; j++) {
            if (S[j][k] == vika[x]) {
                x++;
                break;
            }
        }
        if (x == 4) break;
    }

    if (x == 4) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
