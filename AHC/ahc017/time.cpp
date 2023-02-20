#include <bits/stdc++.h>
using namespace std;

int main() {
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
    int t;

    while (t <= 5000) {
        end = chrono::system_clock::now();
        t = (int)chrono::duration_cast<chrono::milliseconds>(end-start).count();
    }
    cout << t << endl;
}
