#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    set<string> st;
    string T = "ABC000";
    for (int t = 1; t <= 349; t++) {
        if (t == 316) continue;
        int x = t;
        for (int j = 0; j < 3; j++) {
            T[5-j] = (char)((x % 10) + '0');
            x /= 10;
        }
        st.insert(T);
    }
    if (st.count(S)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
