# 股票买卖 III
原题链接：
[AcWing.1058](https://www.acwing.com/problem/content/1058/)

`动态规划` `前后缀分解`  `LeetCode` `今日头条面试题`
## 题目描述
给定一个长度为 <img src="https://latex.codecogs.com/svg.image?N&space;" title="https://latex.codecogs.com/svg.image?N " /> 的数组，数组中的第 <img src="https://latex.codecogs.com/svg.image?i&space;" title="https://latex.codecogs.com/svg.image?i " /> 个数字表示一个给定股票在第 <img src="https://latex.codecogs.com/svg.image?i&space;" title="https://latex.codecogs.com/svg.image?i " /> 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


## 输入格式
第一行包含整数 <img src="https://latex.codecogs.com/svg.image?N&space;" title="https://latex.codecogs.com/svg.image?N " />，表示数组长度。

第二行包含 <img src="https://latex.codecogs.com/svg.image?N&space;" title="https://latex.codecogs.com/svg.image?N " /> 个不大于 <img src="https://latex.codecogs.com/svg.image?10^9" title="https://latex.codecogs.com/svg.image?10^9" /> 的正整数，表示完整的数组。

## 输出格式
输出一个整数，表示最大利润。

### 数据范围
<img src="https://latex.codecogs.com/svg.image?1\leqslant&space;N\leqslant&space;10^5" title="https://latex.codecogs.com/svg.image?1\leqslant N\leqslant 10^5" />

### 输入样例：
```
8
3 3 5 0 0 3 1 4
```
### 输出样例：
```
6
```

## 思路：
可以枚举在哪一天卖掉股票，思考在哪一天买入可以获得最大收益，很容易想到在前面的区间取一个最小值买入。
例如选择在第 i 天卖出，则需要知道前 i-1天的最小值，收益为 <img src="https://latex.codecogs.com/svg.image?p[i]-minv" title="https://latex.codecogs.com/svg.image?p[i]-minv" />.
以上是只进行1次交易的做法，由于该题可以交易两次，一般有很常见的技巧，就是**枚举分割线**，分割线一旦确定，左右两边就变成了两个子问题。
假设第1笔交易是在前 i 天之内完成的，第2比交易是在第 i 天之后进行的，第一笔交易由上述只进行1次交易的做法可以得出结果，但是第二笔交易如果这么做，每个分割点都需要遍历一次，则时间复杂度为<img src="https://latex.codecogs.com/svg.image?O(n^2)" title="https://latex.codecogs.com/svg.image?O(n^2)" />，思考**如何优化**？
**预处理f(i)数组**：f(i)表示从i~n这段时间中交易一次的最大收益，则：

<img src="https://latex.codecogs.com/svg.image?f[i]&space;=max(f[i&plus;1],&space;maxv-p[i])" title="https://latex.codecogs.com/svg.image?f[i] =max(f[i+1], maxv-p[i])" />

## 代码
```c++
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100010;

//股票价格存到p中，前i天的交易最大值存到g中，第i+1~n天交易的最大值存到f中
int p[N], g[N], f[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    
    //求g[i]:1~i中买卖一次的最大收益
    for (int i = 1, minv = p[1]; i <= n; i ++)
    {
        minv = min(minv, p[i]);
        g[i] = max(p[i] - minv, g[i - 1]);
    }
    
    //求f[i]:i~n中买卖一次的最大收益
    for (int i = n, maxv = p[n]; i >= 1; i --)
    {
        maxv = max(maxv, p[i]);
        
        //要么是不在第i天买入，收益就是f[i+1],要么是在第i天买入，最大收益是maxv-p[i]
        f[i] = max(f[i + 1], maxv - p[i]);
    }
    
    //枚举分界点：第一笔交易最后一天卖出的时间
    int res = 0;
    for (int i = 1; i <=  n; i++) res = max(res, g[i] + f[i + 1]);
    printf("%d", res);
    
    return 0;
}
```


