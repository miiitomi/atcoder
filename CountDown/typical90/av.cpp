#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    priority_queue<int> Q;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        Q.push(b);
        Q.push(a - b);
    }

    ll ans = 0;
    while (K--) {
        ans += Q.top();
        Q.pop();
    }

    cout << ans << endl;
}
