#include <iostream>
using namespace std;

const int N = 10;
bool st[N];
int path[N];
int n;

void dfs(int u)
{
    if (u > n) {
        for (int i = 1; i <= n; i ++)
            cout << path[i] << ' ';
        puts("");
        return;
    }
    
    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 2);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);//从第一个位置开始选
    return 0;
}
