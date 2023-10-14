// https://atcoder.jp/contests/abc251/tasks/abc251_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int max_score = -1;
    int max_idx = -1;
    unordered_set<string> S;

    for (int i = 1; i <= N; i++) {
        string s;
        int T;
        cin >> s >> T;
        if (!S.count(s)) {
            if (max_score < T) {
                max_score = T;
                max_idx = i;
            }
        }
        S.insert(s);
    }

    cout << max_idx << endl;
}
