package dsa.array;

public class BestTimeToBuyAndSellStock {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = { 3, 1, 4, 8, 7, 2, 5 };
		
		System.out.println(maxProfit(a));
	}

	public static int maxProfit(int[] prices) {
        int maxProfit = 0;
        int minSoFar = prices[0];
        
        for(int i = 0; i < prices.length; i++) {
        	if(prices[i] < minSoFar)
        		minSoFar = prices[i];
        	int profit = prices[i] - minSoFar;
        	if(profit > maxProfit)
        		maxProfit = profit;
        }
        
        return maxProfit;
    }
}
