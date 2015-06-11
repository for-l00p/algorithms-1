/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

/*
Hi admin:

I want to pay attention to the rational regarding to problem of  best time to buy. Normally, it is the ratio of selling ratio price to purchasing price instead of difference between selling price and purchasing price. For example, buy at 10 and sell at 100 is equal to buying at 1 and selling at 10. Right?

log each element in this prices array before do the math can fix it.

Thanks
*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int localMin = prices[0];
    int profitCand = 0;
    for(int i = 1; i < prices.size(); i++){
      int profit = prices[i] - localMin;
      if(profit > profitCand) profitCand = profit;
      if(prices[i] < localMin) localMin = prices[i];
    }
    return profitCand;
  }
};
