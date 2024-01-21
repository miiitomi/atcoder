#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> cnt(N, 0), C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
        cnt[C[i]]++;
    }
    for (int i = 0; i < N; i++) C.push_back(C[i]);

    vector<int> b(N, 0);
    int r = -1, ans = 0, m = 0;
    for (int l = 0; l < N; l++) {
        while (r+1 < l+N && m < M) {
            r++;
            int c = C[r];
            b[c]++;
            if ((b[C[r]] + K-1) % K == 0) {
                int o = min(cnt[c], ((b[c]+K-2)/K)*K);
                int n = min(cnt[c], ((b[c]+K-1)/K)*K);
                ans += n - o;
                m++;
            }
        }
        cout << ans << "\n";

        int c = C[l];
        b[c]--;
        if ((b[c] + K) % K == 0) {
            int o = min(cnt[c], ((b[c]+K)/K)*K);
            int n = min(cnt[c], ((b[c]+K-1)/K)*K);
            ans += n - o;
            m--;
        }
    }
}
