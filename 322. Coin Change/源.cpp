#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int coinChange(vector<int>& coins, int amount) 
{

	if (amount == 0)
		return 0;

	int num = coins.size();

	vector<int>list(amount+1,INT_MIN);
	vector<vector<int>>dp(num+1,list);

	for (int i = 0; i <= num; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i <=num; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			if (j < coins[i - 1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				if (dp[i - 1][j] != INT_MIN&&dp[i][j - coins[i - 1]] != INT_MIN)
					dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
				else if (dp[i - 1][j] != INT_MIN)
					dp[i][j] = dp[i - 1][j];
				else if (dp[i][j - coins[i - 1]] != INT_MIN)
				{
					dp[i][j] = dp[i][j - coins[i - 1]] + 1;
				}
			}
			
		}
	}

	if (dp[num][amount]!=INT_MIN)
		return dp[num][amount];
	return -1;

}

int main()
{
	vector<int>data(2,1);
	data[1] = INT_MAX;
	int amount = 2;
	int result = coinChange(data,amount);
	return 0;
}