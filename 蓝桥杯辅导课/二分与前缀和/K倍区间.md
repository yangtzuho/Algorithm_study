# K倍区间
## 题目描述
给定一个长度为 N 的数列，<img src="https://latex.codecogs.com/svg.image?A_1,A_2,...A_N" title="https://latex.codecogs.com/svg.image?A_1,A_2,...A_N" />，
如果其中一段连续的子序列<img src="https://latex.codecogs.com/svg.image?A_i,A_{i&plus;1},...A_j" title="https://latex.codecogs.com/svg.image?A_i,A_{i+1},...A_j" />
之和是 K 的倍数，我们就称这个区间 [i,j] 是 K 倍区间。

你能求出数列中总共有多少个 K 倍区间吗？

## 输入格式
第一行包含两个整数 N 和 K。

以下 N 行每行包含一个整数<img src="https://latex.codecogs.com/svg.image?A_i" title="https://latex.codecogs.com/svg.image?A_i" />。

## 输出格式
输出一个整数，代表 K 倍区间的数目。

**数据范围**
<img src="https://latex.codecogs.com/svg.image?1\leqslant&space;N,K\leqslant&space;100000,1&space;\leqslant&space;A_i\leqslant&space;100000&space;" title="https://latex.codecogs.com/svg.image?1\leqslant N,K\leqslant 100000,1 \leqslant A_i\leqslant 100000 " />
### 输入样例：
```
5 2
1
2
3
4
5
```
### 输出样例：
```
6
```
## 思路
* 考虑暴力做法，直接枚举起点和终点，然后判断该区间是不是K倍区间，普通求和<img src="https://latex.codecogs.com/svg.image?O(n^{3})" title="https://latex.codecogs.com/svg.image?O(n^{3})" />  
* 求和使用前缀和进行优化，<img src="https://latex.codecogs.com/svg.image?O(n^{2})" title="https://latex.codecogs.com/svg.image?O(n^{2})" />  
* 考虑再优化掉一层循环：当R固定后，在1~R之间找到有多少个L满足(S[R]-S[L-1])%K=0，即有多少个S[R]与S[L]的余数相同
```c++
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100010;
int n, k;

LL s[N], cnt[N];//s是前缀和数组，cnt是每个余数的个数,由于每个数的范围是十万，数的个数也是十万，最坏的情况可能是十万的平方，会爆int，所以用long long

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i ++)
    {
        //每次先读入数，然后计算前缀和
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    
    LL res = 0;
    //余数为0的数已经有一个了，所以置成1
    cnt[0] = 1;
    //枚举右端点
    for (int i = 1; i <= n; i ++)
    {
        res += cnt[s[i] % k];
        cnt[s[i] % k] ++;
    }
    printf("%lld\n", res);
    return 0;
}

```


