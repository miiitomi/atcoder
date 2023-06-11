#include <bits/stdc++.h>
using namespace std;

map<string, int> M = {
    {"A", 0},
    {"B", 3},
    {"C", 4},
    {"D", 8},
    {"E", 9},
    {"F", 14},
    {"G", 23}
};

int main() {
    string p, q;
    cin >> p >> q;

    cout << abs(M[p] - M[q]) << endl;
}
