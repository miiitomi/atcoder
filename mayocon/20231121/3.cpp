// https://atcoder.jp/contests/abc252/tasks/abc252_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    int ans = 1e+9;

    for (char c = '0'; c <= '9'; c++) {
        set<int> st;
        for (int i = 0; i < N; i++) {
            int j = S[i].find(c);
            while (st.count(j)) j += 10;
            st.insert(j);
        }
        ans = min(ans, *st.rbegin());
    }
    cout << ans << endl;
}
