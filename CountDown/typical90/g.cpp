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

    for (int q = 0; q < Q; q++) {
        int b;
        cin >> b;
        auto iter = lower_bound(A.begin(), A.end(), b);
        int ans = abs(*iter - b);
        if (iter != A.begin()) {
            iter--;
            ans = min(ans, abs(*iter - b));
        }
        cout << ans << endl;
    }
}
