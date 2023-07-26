#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), odds, evens;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 1) odds.push_back(A[i]);
        else evens.push_back(A[i]);
    }
    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    int idx_o = 0;
    int idx_e = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 1) {
            A[i] = odds[idx_o];
            idx_o++;
        } else {
            A[i] = evens[idx_e];
            idx_e++;
        }
    }
    for (int i = 1; i < N; i++) {
        if (A[i-1] > A[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
