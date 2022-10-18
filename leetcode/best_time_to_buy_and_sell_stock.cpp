class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], max_profit = 0;
        for (auto price: prices) {
            if (price < min_price)
                min_price = price;
            else if (price - min_price > max_profit)
                max_profit = price - min_price;
        }
        return max_profit;
    }
};
