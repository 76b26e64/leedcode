int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;
    int lowest_price = INT_MAX;

    for(int day=0; day<pricesSize-1; day++){
        if(lowest_price > prices[day]){
            lowest_price = prices[day];
        }else if(max_profit < prices[day]-lowest_price){
            max_profit = prices[day]-lowest_price;
        }
    }

    return max_profit;
    
}