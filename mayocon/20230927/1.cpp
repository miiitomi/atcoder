// https://atcoder.jp/contests/abc124/tasks/abc124_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A < B) swap(A, B);
    int ans = A;
    A--;
    ans += max(A, B);

    cout << ans << endl;
}
