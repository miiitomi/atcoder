// https://atcoder.jp/contests/abc297/tasks/abc297_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;
    ll cnt = 0;

    while (A != B) {
        if (A < B) swap(A, B);
        ll k = (A - B) / B;
        if ((A - B) % B) k++;
        cnt += k;
        A -= B*k;
    }

    cout << cnt << endl;
}
