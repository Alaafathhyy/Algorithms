
#include <bits/stdc++.h>

using namespace std;
const int N = 3e3 + 7;
int dp2[N][N], n, prof[N], price[N];
string names[N];

int solve(int i, int cost) {
    if (cost < 0)return -1e9;
    if (i == n)return 0;
    int &ret = dp2[i][cost];
    if (ret != -1)return ret;
    return ret = max(solve(i + 1, cost - price[i]) + prof[i], solve(i + 1, cost));
}


void path(int i, int cost) {
    if (i == n)return;
    int &ret = dp2[i][cost];

    if (ret == (solve(i + 1, cost - price[i]) + prof[i]))
        cout << names[i] << " ", path(i + 1, cost - price[i]);
    else
        path(i + 1, cost);

}


int main() {
    memset(dp2, -1, sizeof(dp2));
    int cost;
    cin >> n >> cost;
    for (int i = 0; i < n; i++)
        cin >> names[i] >> price[i] >> prof[i];

    cout << solve(0, cost) << endl;


}