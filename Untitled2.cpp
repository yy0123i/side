#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[300001];
int b[300001];
typedef long long ll; //sum ���뿪 longlong ��������
// ̰���㷨
// ��һ��������ҵ�������� , ai + aj >=k ����������� ˫ָ��, ̰���㷨. �� a ����,�� an �C a0 �Ƚ���β���, �ƶ� i ָ��, ��ô ai �ͱ��, i++ֱ������. ���� an-1 �� ai ֮���Ԫ��
// ���, �������ٺ� i ָ��ǰ��Ԫ�صĽ��, ��Ϊ an ���ܺ�ǰ��Ľ��>k ��ô an-1 �� an С��
// �϶��� i ֮���Ԫ�ؽ�ϲ���>k.
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
