#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[300001];
int b[300001];
typedef long long ll; //sum ���뿪 longlong ��������
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
//ֻ�������������������������� > 2k;
//��ôֻ��Ҫ���ǽ��>k ������,����˫ָ��ƥ��̰��,���������һ��. }
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
