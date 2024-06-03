// https://atcoder.jp/contests/abc140/tasks/abc140_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> S(1<<N, 0);
    for (int i = 0; i < (1<<N); i++) cin >> S[i];
    sort(S.begin(), S.end());

    vector<int> A;
    A.push_back(S.back());
    S.pop_back();
    multiset<int> st;
    while (!S.empty()) {
        st.insert(S.back());
        S.pop_back();
    }

    for (int x = 1; x <= N; x++) {
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        int a_size = A.size();
        for (int i = 0; i < a_size; i++) {
            int a = A[i];
            auto iter = st.lower_bound(a);
            if (iter == st.begin()) {
                cout << "No\n";
                return;
            }
            iter--;
            A.push_back(*iter);
            st.erase(iter);
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
