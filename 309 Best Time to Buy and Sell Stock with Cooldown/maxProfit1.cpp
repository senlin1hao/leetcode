#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划，时间复杂度O(n)，空间复杂度O(n)
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2] - prices[i], dp[i - 1][3] - prices[i])); // 买入
            dp[i][1] = dp[i - 1][0] + prices[i];                                                   // 今天卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);                                            // 保持卖出
            dp[i][3] = dp[i - 1][1];                                                               // 冷冻期
        }

        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};
