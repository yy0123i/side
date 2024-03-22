#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[300001];
int b[300001];
typedef long long ll; //sum 必须开 longlong 否则会溢出
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
int main()
{
int t;
cin >> t;
while(t -- )
{
solve();
}
}
