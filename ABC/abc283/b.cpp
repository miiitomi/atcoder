#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int Q;
    cin >> Q;
    for (int t = 0; t < Q; t++) {
        int l, k;
        cin >> l >> k;
        k--;
        if (l == 1) {
            int x;
            cin >> x;
            A[k] = x;
        } else {
            cout << A[k] << endl;
        }
    }
}
