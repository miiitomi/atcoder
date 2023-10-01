#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    for (int i = 1; i <= N; i++) {
        auto iter = lower_bound(A.begin(), A.end(), i);
        cout << *iter - i << endl;
    }
}
