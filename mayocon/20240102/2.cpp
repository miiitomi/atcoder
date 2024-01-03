// https://atcoder.jp/contests/abc333/tasks/abc333_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> V;
    for (ll a = 1; a <= 1e+15; a = a*10+1) {
        for (ll b = 1; b <= 1e+15; b = b*10+1) {
            for (ll c = 1; c <= 1e+15; c = c*10+1) {
                V.push_back(a+b+c);
            }
        }
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    int N;
    cin >> N;
    cout << V[N-1] << endl;
}
