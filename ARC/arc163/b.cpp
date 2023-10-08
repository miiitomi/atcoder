#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(2);
    vector<int> A(N-2);
    cin >> X[0] >> X[1];
    for (int i = 0; i < N-2; i++) cin >> A[i];

    sort(A.begin(), A.end());
    ll ans = 1e+18;

    for (int i = 0; i + M-1 <= N-3; i++) {
        ll tmp = 0;
        if (X[0] > A[i]) tmp = X[0] - A[i];

        ll b = A[i+M-1];
        if (X[1] < b) tmp += b - X[1];

        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
