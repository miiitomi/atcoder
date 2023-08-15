#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<> dist_x(0, 10);
    pair<int,int> p = make_pair(dist_x(engine), dist_x(engine));
    cout << p.first << " " << p.second << endl;
}