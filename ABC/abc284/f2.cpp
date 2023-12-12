// by Z-algorithm
#include <bits/stdc++.h>
#include <atcoder/string>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    string T, U;
    cin >> N >> T;
    U = T;
    reverse(U.begin(), U.end());

    string F = T+U, G = U+T;

    vector<int> x = z_algorithm(F), y = z_algorithm(G);
    for (int i = 0; i <= N; i++) {
        if (x[2*N+N-i] >= i && y[2*N+i] >= N-i) {
            for (int j = 0; j < N; j++) {
                cout << G[N-i+j];
            }
            cout << "\n" << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
