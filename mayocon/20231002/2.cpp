#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> S;
    int N;
    cin >> N;

    string ans = "satisfiable";
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s[0] != '!') {
            string T = "!";
            for (char c : s) T.push_back(c);
            if (S.count(T)) ans = s;
            S.insert(s);
        } else {
            string T = "";
            for (char c : s) if (c != '!') T.push_back(c);
            if (S.count(T)) ans = T;
            S.insert(s);
        }
    }

    cout << ans << endl;
}
