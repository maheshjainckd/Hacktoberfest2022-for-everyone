/*
Input: prices = [7,1,5,3,6,4]
Output: 5
*/

import java.util.*;
public class Buy_Sell_Stock
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int price = sc.nextInt();
        int prices[] = new int[price];
        for(int i=0;i<price;i++)
        {
            prices[i] = sc.nextInt();
        }
        int min_profit = Integer.MAX_VALUE;
        int max_profit = 0;
        for(int i=0;i<price;i++)
        {
            if(prices[i]<min_profit)
            {
                min_profit = prices[i];
            }
            else if(prices[i]-min_profit > max_profit)
            {
                max_profit = prices[i]-min_profit;
            }
        }
        System.out.println(max_profit);
    }
}
