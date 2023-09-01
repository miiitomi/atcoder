// https://atcoder.jp/contests/abc315/tasks/abc315_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N, 0);
    vector<int> S(N);

    for (int i = 0; i < N; i++) {
        int f, s;
        cin >> f >> s;
        f--;
        V[f] = max(V[f], s);
        S[i] = s;
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    sort(S.begin(), S.end());
    reverse(S.begin(), S.end());

    int ans = -1;
    ans = max(ans, S[0] + S[1]/2);
    ans = max(ans, V[0] + V[1]);

    cout << ans << endl;
}
