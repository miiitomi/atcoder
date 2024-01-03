// https://atcoder.jp/contests/abc146/tasks/abc146_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> v;
    set<int> st;

    vector<int> dp(N+1, -1);
    dp[N] = 0;
    st.insert(N);

    for (int i = N-1; i >= 0; i--) {
        if (S[i] == '1') continue;
        auto iter = st.lower_bound(i+M+1);
        if (iter == st.begin()) continue;
        iter--;
        if (*iter <= i) continue;
        dp[i] = 1 + dp[*iter];
        st.insert(i);
    }

    if (dp[0] < 0) {
        cout << -1 << endl;
        return 0;
    }

    int tmp = 0, tgt = dp[0]-1;
    while (tmp < N) {
        for (int i = tmp+1; i <= N; i++) {
            if (dp[i] == tgt) {
                cout << i-tmp << " ";
                tmp = i;
                tgt--;
                break;
            }
        }
    }
    cout << "\n";
}
