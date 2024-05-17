// https://atcoder.jp/contests/abc307/tasks/abc307_b
#include <bits/stdc++.h>
using namespace std;

bool is_kaibun(string S) {
    string T = S;
    reverse(T.begin(), T.end());
    return S == T;
}

void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (is_kaibun(S[i] + S[j])) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
