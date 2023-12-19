// https://atcoder.jp/contests/abc199/tasks/abc199_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S = "", T = "";
    cin >> S;
    for (int i = 0; i < N; i++) {
        T.push_back(S.back());
        S.pop_back();
    }
    reverse(T.begin(), T.end());
    bool s_first = true;

    int Q;
    cin >> Q;
    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            if (s_first) {
                if (b <= N-1) swap(S[a], S[b]);
                else if (a <= N-1 && b >= N) swap(S[a], T[b - N]);
                else swap(T[a-N], T[b-N]);
            } else {
                if (b <= N-1) swap(T[a], T[b]);
                else if (a <= N-1 && N <= b) swap(T[a], S[b-N]);
                else swap(S[a-N], S[b-N]);
            }
        } else {
            s_first = !s_first;
        }
    }

    if (s_first) cout << S << T << endl;
    else cout << T << S << endl;
}
