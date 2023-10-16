// https://atcoder.jp/contests/abc173/tasks/abc173_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    priority_queue<ll> Q;
    Q.push(A[0]);

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ll x = Q.top();
        Q.pop();
        ans += x;
        for (int k = 0; k < 2; k++) Q.push(A[i]);
    }
    
    cout << ans << endl;
}
