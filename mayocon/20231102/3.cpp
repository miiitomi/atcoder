// https://atcoder.jp/contests/abc286/tasks/abc286_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, A, B;

ll f(string S) {
    ll tmp = 0;
    for (int i = 0; i < N/2; i++) {
        if (S[i] != S[N-1-i]) tmp += B;
    }
    return tmp;
}

int main() {
    cin >> N >> A >> B;
    string S;
    cin >> S;

    ll ans = 1e+18;
    for (int i = 0; i < N; i++) {
        ans = min(ans, A*i + f(S));
        string T;
        for (int i = 1; i < N; i++) T.push_back(S[i]);
        T.push_back(S[0]);
        S = T;
    }

    cout << ans << endl;
}
