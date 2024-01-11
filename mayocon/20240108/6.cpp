// https://atcoder.jp/contests/abc258/tasks/abc258_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<bitset<3000>> V(N);
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for (int k = 0; k < N; k++) {
            V[i][k] = (a[k] == '1');
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (V[i][j])  {
                ans += (V[i] & V[j]).count();
            }
        }
    }
    ans /= 3;
    cout << ans << endl;
}
