#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());

    int64_t ans = 1LL;
    int64_t mod = pow(10, 9) + 7;

    for (int i = 0; i < N; i++) {
        ans = (ans * (C[i] - i)) % mod;
    }

    cout << ans << endl;
}
