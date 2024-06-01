// https://atcoder.jp/contests/abc324/tasks/abc324_c
#include <bits/stdc++.h>
using namespace std;

bool could_be(string &S, string &T) {
    if (abs((int)S.size() - (int)T.size()) >= 2) return false;
    else if (S.size() == T.size()) {
        if (S == T) return true;
        int cnt = 0;
        for (int i = 0; i < (int)S.size(); i++) {
            if (S[i] != T[i]) cnt++;
        }
        return (cnt <= 1);
    }
    else if (S.size() > T.size()) {
        int b = 0, c = 0;
        for (int i = 0; i < (int)T.size(); i++) {
            if (S[i] != T[i]) break;
            else b++;
        }
        for (int i = T.size()-1; i >= 0; i--) {
            if (S[i+1] != T[i]) break;
            else c++;
        }
        return ((b+c) >= (int)T.size());
    } else {
        int b = 0, c = 0;
        for (int i = 0; i < (int)S.size(); i++) {
            if (S[i] != T[i]) break;
            else b++;
        }
        for (int i = S.size()-1; i >= 0; i--) {
            if (S[i] != T[i+1]) break;
            else c++;
        }
        return ((b+c) >= (int)S.size());
    }
}

void solve() {
    int N;
    string T_;
    cin >> N >> T_;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        if (could_be(s, T_)) v.push_back(i);
    }

    cout << v.size() << "\n";
    for (int i : v) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
