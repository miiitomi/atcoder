#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int S = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }

    if (S % 2 == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();    
}
