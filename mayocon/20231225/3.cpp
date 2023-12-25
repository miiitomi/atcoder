// https://atcoder.jp/contests/abc260/tasks/abc260_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> R(11, -1), B(11, -1);
ll N, X, Y;

ll rec(bool is_red, ll x) {
    if (is_red) {
        if (R[x] != -1) return R[x];
        else {
            R[x] = rec(true, x-1) + X * rec(false, x);
            return R[x];
        }
    } else {
        if (B[x] != -1) return B[x];
        else {
            B[x] = rec(true, x-1) + Y * rec(false, x-1);
            return B[x];
        }
    }
}


int main() {
    R[0] = 0;
    R[1] = 0;
    B[0] = 0;
    B[1] = 1;
    cin >> N >> X >> Y;

    cout << rec(true, N) << endl;
}
