#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int k = 0; k < 1000; k++) {
        int l = 1;
        for (int t = 0; t < k; t++) l *= 2;
        if (l-1 > N-1) break;
        for (int i = l; i+1 < 2*l; i++) {
            if (i+1 > N-1) break;
            if (A[i] > A[i+1]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
