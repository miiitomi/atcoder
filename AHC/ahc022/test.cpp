#include <bits/stdc++.h>
using namespace std;

int P;
int L = 50;
random_device seed_gen;
mt19937 engine(seed_gen());
uniform_int_distribution<> dist_l(1, L);

pair<int,int> solve() {
    set<pair<int,int>> X;
    for (int i = 0; i < P;) {
        pair<int,int> p;
        p.first = dist_l(engine);
        p.second = dist_l(engine);
        if (!X.count(p)) {
            X.insert(p);
            i++;
        }
    }

    pair<int,int> q;
    int x=1e+9, y=1e+9;
    for (auto p : X) {
        int i=p.first, j=p.second;
        int a = dist_l(engine);
        int b = dist_l(engine);
        int tmp_x, tmp_y;
        tmp_x = (i-a+L)%L;
        tmp_y = (j-b+L)%L;
        if (abs((a-i+L)%L) < abs(tmp_x)) tmp_x = -((a-i+L)%L);
        if (abs((b-j+L)%L) < abs(tmp_y)) tmp_y = -((b-j+L)%L);

        if (abs(tmp_x)<abs(x)) x = tmp_x;
        if (abs(tmp_y)<abs(y)) y = tmp_y;
    }

    return make_pair(x, y);
}

int main() {
    P = 4;
    int N = 1e+6;
    double x=0, y=0;
    for (int i = 0; i < N; i++) {
        auto p = solve();
        x += abs(p.first);
        y += abs(p.second);
    }
    x /= N;
    y /= N;

    cout << fixed << setprecision(10) << x << " " << y << endl;
}
