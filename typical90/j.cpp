#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N+1, 0LL),B(N+1, 0LL);
    for (int i = 0; i < N; i++) {
        int c, p;
        cin >> c >> p;
        if (c == 1) {
            A[i+1] = A[i] + p;
            B[i+1] = B[i];
        } else {
            A[i+1] = A[i];
            B[i+1] = B[i] + p;
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << A[r] - A[l-1] << " " << B[r] - B[l-1] << endl;
    }
}
