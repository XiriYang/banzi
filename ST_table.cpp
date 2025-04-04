#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;//dp[i][j]��ʾ��˵�Ϊi������Ϊ2^j������
int query(int l, int r)//��ѯ����
{
	int j = (int)log2(r - l + 1);
	return max(dp[l][j], dp[r - (1 << j) + 1][j]);
}
int main()
{
	vector<int>arr = { 9,3,1,7,5,6,0,8 };
	const int n = 8;
	dp = vector<vector<int>>(n, vector<int>((int)log2(n) + 5.0));
	for (int i = 0;i < n;i++)dp[i][0] = arr[i];
	for (int j = 1;j <= log2(n);j++)
		for (int i = 0;i + (1 << j) < n;i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][i - 1]);//״̬ת�Ʒ���
	int l, r;
	while (cin >> l >> r)
	{
		cout << query(l, r) << endl;
	}
	return 0;
}