// https://atcoder.jp/contests/abc076/tasks/abc076_c
#include <bits/stdc++.h>
using namespace std;

string f(string s, string t, int i) {
    for (int j = 0; j < (int)t.size(); j++) {
        if (i+j >= (int)s.size()) return "";
        if (s[i+j] != '?' && s[i+j] != t[j]) return "";
        else if (s[i+j] == '?') s[i+j] = t[j];
    }

    for (int j = 0; j < s.size(); j++) if (s[j] == '?') s[j] = 'a';
    return s;
}

void solve() {
    string s, t;
    cin >> s >> t;
    priority_queue<string, vector<string>, greater<string>> Q;
    for (int i = 0; i < s.size(); i++) {
        string x = f(s, t, i);
        if (x != "") Q.push(x);
    }

    if (!Q.empty()) {
        cout << Q.top() << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
