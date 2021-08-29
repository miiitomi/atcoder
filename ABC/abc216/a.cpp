#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string X, Y;
    for (int i = 0; i < (int)S.size()-2; i++) {
        X = X + S[i];
    }
    Y = S[(int)S.size()-1];
    int y;
    y = stoi(Y);

    if (y <= 2) X = X + '-';
    else if (y >= 7) X = X + '+';

    cout << X << endl;
}
