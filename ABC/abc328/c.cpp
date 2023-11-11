#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> A(N+2, 0);
    for (int i = 1; i < N; i++) {
        if (S[i-1] == S[i]) A[i+1]++;
    }
    for (int i = 0; i < N+1; i++) A[i+1] += A[i];

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << A[r+1] - A[l+1] << endl;
    }
}
