#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[300001];
int b[300001];
typedef long long ll; //sum 必须开 longlong 否则会溢出
// 贪心算法
// 在一个数组里，找到两两配对 , ai + aj >=k 的最大数量。 双指针, 贪心算法. 对 a 排序,先 an – a0 比较如何不行, 移动 i 指针, 那么 ai 就变大, i++直到符合. 接着 an-1 和 ai 之后的元素
// 结合, 不可能再和 i 指针前面元素的结合, 因为 an 不能和前面的结合>k 那么 an-1 比 an 小，
// 肯定和 i 之后的元素结合才能>k.
void solve()
{
int n, k;
cin >> n >> k;
ll sum = 0;
for(int i = 1; i <= n ; i ++ )
{
cin >> a[i];
sum += a[i] / k;
b[i] = a[i] % k;
//只考虑余数，任意两个余数不会 > 2k;
//那么只需要考虑结合>k 的种数,利用双指针匹配贪心,可以完成这一步. }
sort(b+1,b+1+n);
for(int i = 1, j = n; i < j ;)
{
if(b[i] + b[j] < k)
{
i ++ ;
continue;
}
sum += 1;
i ++;
j --;
}
cout << sum << endl;
}
}
int main()
{
int t;
cin >> t;
while(t -- )
{
solve();
}
}
