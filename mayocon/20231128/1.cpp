// https://atcoder.jp/contests/abc130/tasks/abc130_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int cnt = 1, tmp = 0;
    for (int i = 0; i < N; i++) {
        int l;
        cin >> l;
        tmp += l;
        if (tmp <= X) cnt++;
    }

    cout << cnt << endl;
}
