#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    auto iter = lower_bound(A.begin(), A.end(), A[N-1]);
    int x = distance(iter, A.end());
    int64_t ans = 0;

    while (K > 0) {
        if (x < N) {
            if ((A[N-x]-A[N-x-1])*x <= K) {
                K -= (A[N-x]-A[N-x-1])*x;
                ans += ((A[N-x]+ A[N-x-1]+1)*(A[N-x]-A[N-x-1])/2)*x;
                iter = lower_bound(A.begin(), A.end(), A[N-x-1]);
                x = distance(iter, A.end());
            } else {
                while (K >= x) {
                    ans += max(0LL, (long long)A[N-x])*x;
                    K -= x;
                    A[N-x]--;
                }
                ans += max(0LL, (long long)A[N-x]) * K;
                K = 0;
            }
        } else {
                while (K > N) {
                    ans += max((long long)A[0], 0LL)*N;
                    K -= N;
                    A[0]--;
                }
                ans += max(0LL, (long long)A[0]) * K;
                K = 0;
        }
    }

    cout << ans << endl;
}
