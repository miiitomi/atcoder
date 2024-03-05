// https://atcoder.jp/contests/abc251/tasks/abc251_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    set<string> st;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        string s;
        int t;
        cin >> s >> t;
        if (st.count(s)) continue;
        st.insert(s);
        v.push_back(make_pair(t, -i));
    }
    sort(v.begin(), v.end());
    cout << -v.back().second + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
