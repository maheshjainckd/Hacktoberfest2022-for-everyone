
public class BestTimeToBuyAndSellStockII {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = { 5, 2, 6, 1, 4, 7, 3, 6 };
		
		System.out.println(maxProfit(a));
	}

	public static int maxProfit(int[] prices) {
        int profit = 0;
        for(int i = 1; i < prices.length; i++) {
        	if(prices[i] > prices[i-1])
        		profit += prices[i] - prices[i-1];
        }
        return profit;
    }
}
