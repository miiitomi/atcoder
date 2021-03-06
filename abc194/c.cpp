#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A.at(i);
    }

    vector<int64_t> S(N+1, 0);
    for (int i = 1; i <= N; i++) {
        S.at(i) = S.at(i-1) + A.at(i);
    }

    int64_t ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (N - 1LL) * A.at(i) * A.at(i);
        if (i == 1) {
            continue;
        }
        ans -= 2LL * A.at(i) * S.at(i-1);
    }

    cout << ans << endl;
}