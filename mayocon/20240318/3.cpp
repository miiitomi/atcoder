// https://atcoder.jp/contests/abc307/tasks/abc307_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string T;
    vector<int> left, right;
    for (int i = 0; i < N; i++) {
        if (S[i] == ')' && !left.empty() && (right.empty() || right.back() < left.back())) {
            while (T.back() != '(') T.pop_back();
            T.pop_back();
            left.pop_back();
        } else {
            T.push_back(S[i]);
            if (T.back() == '(') left.push_back(i);
            else if (T.back() == ')') right.push_back(i);
        }
    }

    cout << T << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
