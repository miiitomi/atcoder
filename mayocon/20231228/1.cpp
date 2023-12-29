// https://atcoder.jp/contests/abc159/tasks/abc159_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int ans = N*(N-1)/2 + M*(M-1)/2;
    cout << ans << endl;
}
