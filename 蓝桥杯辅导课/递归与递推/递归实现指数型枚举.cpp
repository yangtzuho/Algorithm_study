#include <iostream>
using namespace std;

const int N = 20;
int n;
int st[N]; //记录这个数有没有被选，选的话是1，不选的话是0

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1)
                cout << i << ' ';
        }
            puts("");
         return;
    }
        
        st[u] = 0;//不选当前的数字
        dfs(u + 1);
        
        st[u] = 1;//选当前的数字
        dfs(u + 1);   
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
