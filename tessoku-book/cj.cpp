#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        auto iter = lower_bound(A.begin(), A.end(), x);
        cout << distance(A.begin(), iter) << endl;
    }
}
