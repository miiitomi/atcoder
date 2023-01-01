#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto iter = lower_bound(A.begin(), A.end(), X);
    cout << 1 + distance(A.begin(), iter) << endl;
}
