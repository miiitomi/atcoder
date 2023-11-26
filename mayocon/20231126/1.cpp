// https://atcoder.jp/contests/abc236/tasks/abc236_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    set<string> T;
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        T.insert(t);
    }

    for (int i = 0; i < N; i++) {
        string s = S[i];
        if (T.count(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
