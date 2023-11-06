// https://atcoder.jp/contests/abc166/tasks/abc166_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    vector<bool> v(N, true);


    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (H[a] <= H[b]) v[a] = false;
        if (H[b] <= H[a]) v[b] = false;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans += v[i];
    
    cout << ans << endl;
}
