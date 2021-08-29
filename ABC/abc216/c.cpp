#include <bits/stdc++.h>
using namespace std;

string rec(int64_t X) {
    if (X == 0) return "";

    if (X % 2 == 0) return rec(X / 2) + 'B';
    else return rec(X - 1) + 'A';
}


int main() {
    int64_t N;
    cin >> N;
    cout << rec(N) << endl;
}
