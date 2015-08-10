// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0], res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min_price = min(min_price, prices[i]);
            res = max(res, prices[i] - min_price);
        }
        return res;
    }
};
