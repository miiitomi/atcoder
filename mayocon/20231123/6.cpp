// https://atcoder.jp/contests/abc326/tasks/abc326_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(vector<ll> &A, ll X, vector<bool> &v) {

    if (A.size() == 0) {
        return X == 0;
    }

    v.resize((int)A.size(), false);
    int N = A.size();
    int m = (A.size()) / 2;
    map<ll, ll> mp;
    for (ll b = 0; b < (1 << m); b++) {
        ll tmp = 0;
        for (int i = 0; i < m; i++) {
            if (b & (1 << i)) {
                tmp += A[i];
            } else {
                tmp -= A[i];
            }
        }
        mp[tmp] = b;
    }

    if (m == 0) mp[0] = 0;

    for (ll c = 0; c < (1 << (N-m)); c++) {
        ll y = 0;
        for (int i = 0; i < (N-m); i++) {
            if (c & (1 << i)) {
                y += A[m + i];
            } else {
                y -= A[m + i];
            }
        }

        if (mp.count(X - y)) {
            ll b = mp[X - y];
            for (int i = 0; i < m; i++) {
                if (b & (1 << i)) v[i] = true;
            }
            for (int i = 0; i < N-m; i++) {
                if (c & (1 << i)) v[m+i] = true;
            }
            return true;
        }
    }

    return false;
}

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A, B;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) A.push_back(a);
        else B.push_back(a);
    }

    vector<bool> v, w;
    if ((!f(A, Y, v)) || (!f(B, X, w))) {
        cout << "No" << endl;
        return 0;
    };

    cout << "Yes" << endl;

    int state = 0;  // 0:right, 1:up, 2:left, 3:down
    for (int i = 0; i < (int)v.size(); i++) {
        if (state == 0) {
            if (v[i]) {
                cout << "L";
                state = 1;
            } else {
                cout << "R";
                state = 3;
            }
        } else {
            if (v[i]) {
                cout << "R";
                state = 1;
            } else {
                cout << "L";
                state = 3;
            }
        }

        if (i >= (int)w.size()) break;

        if (state == 1) {
            if (w[i]) {
                cout << "R";
                state = 0;
            } else {
                cout << "L";
                state = 2;
            }
        } else {
            if (w[i]) {
                cout << "L";
                state = 0;
            } else {
                cout << "R";
                state = 2;
            }
        }
    }

    cout << endl;
    return 0;
}
