#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (1 <= N && N <= 125) cout << 4 << endl;
    else if (N <= 211) cout << 6 << endl;
    else cout << 8 << endl;
}
