int maxProfit(int* prices, int pricesSize) {
    int minimum = prices[0], best = 0;
    for (int i = 1; i < pricesSize; ++i) {
        int profit = prices[i] - minimum;
        if (profit > best) best = profit;
        if (prices[i] < minimum) minimum = prices[i];
    }
    return best;
}
