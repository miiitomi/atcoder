#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    if (A[0] == A[N-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
