// https://atcoder.jp/contests/abc207/tasks/abc207_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N), l(N), r(N);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t >> l[i] >> r[i];
        l[i] *= 2;
        r[i] *= 2;
        if (t == 2 || t == 4) r[i]--;
        if (t == 3 || t == 4) l[i]++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (r[i] < l[j] || r[j] < l[i]) continue;
            ans++;
        }
    }
    cout << ans << endl;
}
