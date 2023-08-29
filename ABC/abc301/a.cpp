#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int t=0, a=0;
    for (int s : S) {
        if (s == 'T') t++;
        else a++;
    }

    if (t != a) {
        if (t > a) cout << "T" <<endl;
        else cout << "A" << endl;
    } else {
        if (S[N-1] == 'T') cout << "A" << endl;
        else cout << "T" << endl;
    }
}
