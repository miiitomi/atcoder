// https://atcoder.jp/contests/abc273/tasks/abc273_e
#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int par;
    int x;

    Vertex(int _par, int _x) {
        par = _par;
        x = _x;
    }
};

int main() {
    int Q;
    cin >> Q;

    vector<int> X(Q);

    vector<Vertex> V;
    V.reserve(Q);

    map<int, int> M;

    V.push_back(Vertex(0, -1));
    int now = 0;

    for (int q = 0; q < Q; q++) {
        string s;
        int x = -1;
        cin >> s;
        if (s != "DELETE") cin >> x;

        if (s == "ADD") {
            V.push_back(Vertex(now, x));
            now = (int)V.size() - 1;
        } else if (s == "DELETE") {
            now = V[now].par;
        } else if (s == "SAVE") {
            M[x] = now;
        } else {
            if (M.count(x)) now = M[x];
            else now = 0;
        }

        X[q] = V[now].x;
    }

    for (int x : X) cout << x << " ";
    cout << endl;
}
