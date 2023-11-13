#include <bits/stdc++.h>
using namespace std;

int N, X, Y;
vector<int> A;

map<int,int> g(vector<int> &x) {
    map<int, int> mp;
    int n = x.size();

    if (n == 0) {
        mp[0] = 0;
        return mp;
    }

    for (int s = 0; s < (1 << n); s++) {
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                l += x[i];
            } else {
                l -= x[i];
            }
        }
        mp[l] = s;
    }
    return mp;
}

bool f(vector<int> &v, int X, vector<bool> &positive) {
    if ((int)v.size() == 0) {
        if (X == 0) return true;
        else return false;
    }

    int n = (int)v.size() / 2;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        x.push_back(A[v[i]]);
    }
    map<int,int> ma = g(x);

    vector<int> y;
    for (int i = n; i < (int)v.size(); i++) {
        y.push_back(A[v[i]]);
    }
    map<int,int> mb = g(y);

    vector<int> s, t;
    for (auto iter = ma.begin(); iter != ma.end(); iter++) s.push_back(iter->first);
    for (auto iter = mb.begin(); iter != mb.end(); iter++) t.push_back(iter->first);

    for (int p : s) {
        auto iter = lower_bound(t.begin(), t.end(), X - p);
        if (iter == t.end()) continue;
        int q = *iter;
        if (p + q == X) {
            int c = ma[p];
            for (int i = 0; i < n; i++) {
                if (c & (1 << i)) positive[v[i]] = true;
            }
            c = mb[q];
            for (int i = 0; i < (int)v.size() - n; i++) {
                if (c & (1 << i)) positive[v[n+i]] = true;
            }
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> X >> Y;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> v, w;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) v.push_back(i);
        else w.push_back(i);
    }

    vector<bool> positive(N, false);
    bool done = (f(v, Y, positive) && f(w, X, positive));

    if (!done) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    char s = 'R';
    for (int i = 0; i < N; i++) {
        if (s == 'R' && positive[i]) {
            cout << 'L';
            s = 'U';
        } else if (s == 'R' && !positive[i]) {
            cout << 'R';
            s = 'D';
        } else if (s == 'L' && positive[i]) {
            cout << 'R';
            s = 'U';
        } else if (s == 'L' && !positive[i]) {
            cout << 'L';
            s = 'D';
        } else if (s == 'U' && positive[i]) {
            cout << 'R';
            s = 'R';
        } else if (s == 'U' && !positive[i]) {
            cout << 'L';
            s = 'L';
        } else if (s == 'D' && positive[i]) {
            cout << 'L';
            s = 'R';
        } else if (s == 'D' && !positive[i]) {
            cout << 'R';
            s = 'L';
        }
    }

    cout << endl;
}
