// https://atcoder.jp/contests/abc328/tasks/abc328_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int ans= 0;
    while (N--) {
        int a;
        cin >> a;
        if (a <= X) ans += a;
    }
    cout << ans << endl;
}
