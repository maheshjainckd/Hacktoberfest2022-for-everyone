/* . write a java program to accept a number from the user, if number is zero then throw
user defined exception "number is 0" otherwise calculate the sum of first and last digit of a
 given number(use static keyword) */

import java.util.Scanner;
class MyException extends Exception
{
	MyException()
	{
		super();
	}MyException(String str)
	{
		super(str);
	}
	public String getMessage()
	{
		return("number is 0");
	}
}

class SumDigit
{
	static void calc(int n)
	{
		int first=0,last;
		if(n<10)
			System.out.println("Sum of first and last digit is"+n);
		else
		{
			last=n%10;
			while(n>0)
			{
				first=n%10;
				n=n/10;
			}
			System.out.println("Sum of first and last digit is"+(first+last));
		}
	}
	public static void main(String args[])
	{
		int n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a no");
		n=sc.nextInt();
		try
		{
			if(n==0)
				throw new MyException("Null");
			else
				calc(n);
		}
		catch(MyException e)
		{
			System.out.println("am in Exception \n"+e.getMessage());
		}
		finally
		{
			System.out.println("\n goodbye...");
		}
	}
}
		
			
		
		
