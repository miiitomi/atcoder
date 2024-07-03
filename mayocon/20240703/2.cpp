// https://atcoder.jp/contests/abc066/tasks/abc066_b
#include <bits/stdc++.h>
using namespace std;

bool is_even(string S) {
    int N = S.size();
    if (N%2 == 1) return false;
    string T;
    while ((int)S.size() > N/2) {
        T.push_back(S.back());
        S.pop_back();
    }
    reverse(T.begin(), T.end());
    return S == T;
}

void solve() {
    string S;
    cin >> S;
    S.pop_back();
    while (!is_even(S)) S.pop_back();
    cout << S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
