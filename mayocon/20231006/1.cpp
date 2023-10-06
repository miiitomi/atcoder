// https://atcoder.jp/contests/abc248/tasks/abc248_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    int cnt = 0;
    while (A < B) {
        A *= K;
        cnt++;
    }

    cout << cnt << endl;
}
