#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll N, X;
    cin >> N >> X;

    if (N == 1) {
        cout << X << endl;
        return;
    }

    vector<ll> A(N, 0);
    ll nv = 1;
    for (int i = 0; i < N-1; i++) {
        A[i] = nv;
        X -= nv;
        nv++;
    }
    A[N-1] = X;

    if (A[N-2] >= A[N-1]) {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (i < N-1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
