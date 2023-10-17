// https://atcoder.jp/contests/abc251/tasks/abc251_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int W;
    cin >> W;
    vector<int> V;
    V.reserve(300);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= 99; j++) {
            int x = j;
            for (int s = 0; s < i; s++) x *= 100;
            V.push_back(x);
        }
    }
    V.push_back(1000000);

    cout << (int)V.size() << endl;
    for (int v : V) cout << v << " ";
    cout << endl;
}
