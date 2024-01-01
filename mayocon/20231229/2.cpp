// https://atcoder.jp/contests/abc187/tasks/abc187_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> S;
    while (N--) {
        string s;
        cin >> s;
        S.insert(s);
    }

    for (string s : S) {
        string t = "!";
        for (char c : s) t.push_back(c);

        if (S.count(t)) {
            cout << s << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;
}
