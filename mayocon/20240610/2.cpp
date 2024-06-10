// https://atcoder.jp/contests/abc187/tasks/abc187_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    set<string> S;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        string t = '!' + s;
        if (S.count(t)) {
            cout << s << endl;
            return;
        }
        t = "";
        if (s[0] == '!') {
            for (int j = 1; j < (int)s.size(); j++) t.push_back(s[j]);
            if (S.count(t)) {
                cout << t << endl;
                return;
            }
        }
        S.insert(s);
    }
    cout << "satisfiable\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
