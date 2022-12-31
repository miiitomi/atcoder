#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll D, N;
    cin >> D >> N;
    vector<int> A(D, 0);

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        A[l]++;
        A[r]--;
    }

    cout << A[0] << endl;
    for (int i = 1; i < D; i++) {
        A[i] = A[i-1] + A[i];
        cout << A[i] << endl;
    }
}
