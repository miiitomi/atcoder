#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    ll cnt = 0;

    for (int i = 0; i < N-1; i++) {
        if (S[i] == '>') cnt++;
        else cnt = 0;
        ans += cnt;
    }
    cout << ans << endl;
}
