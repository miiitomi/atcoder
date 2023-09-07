#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> C(201, 1e+9);
    for (int i = 0; i < N; i++) {
        int d, s;
        cin >> d >> s;
        d--;
        C[d] = min(C[d], s);
    }

    int k = 1;
    while (true) {
        for (int p = 0; p <= min(200, k); p++) {
            if (2*(k-p) >= C[p]) {
                cout << k << endl;
                return;
            }
        }
        k++;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
