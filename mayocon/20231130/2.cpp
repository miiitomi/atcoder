// https://atcoder.jp/contests/abc313/tasks/abc313_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N, true);
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        p[b] = false;
    }

    int i = -1, cnt=0;
    for (int j = 0; j < N; j++) {
        if (p[j]) {
            cnt++;
            i = j;
        }
    }
    if (cnt >= 2) cout << -1 << endl;
    else cout << i+1 << endl;
}
