#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans = max(A+B, B+C);
    ans = max(ans, C+A);
    cout << ans << endl;
}
