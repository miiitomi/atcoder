#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, A, B, C;
    cin >> V >> A >> B >> C;

    while (true) {
        if (V < A) {
            cout << "F" << endl;
            return 0;
        }
        V -= A;

        if (V < B) {
            cout << "M" << endl;
            return 0;
        }
        V -= B;

        if (V < C) {
            cout << "T" << endl;
            return 0;
        }
        V -= C;
    }
}
