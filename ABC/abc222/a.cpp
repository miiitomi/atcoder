#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    cin >> N;
    while ((int)N.size() < 4) {
        N = '0' + N;
    }
    cout << N << endl;
}
