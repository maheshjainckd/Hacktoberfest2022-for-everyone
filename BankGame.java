//Password: 4758
import java.util.*;
import java.util.Random;
public class Bank
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        Random rd= new Random();  
        System.out.println("---WELCOME TO ELIX BANKING SERVICES---");
        System.out.println("");
        System.out.println("________________________");
        System.out.println("Enter your name: ");
        String name=sc.nextLine();
        //I am inserting do loop to make the program run forever under correct inputs.
        System.out.println("Hi, "+name+"\bWelcome to my program!");
        System.out.println("____________________________");
        System.out.println("Do you want to start/repeat the program?");
        System.out.println("Enter Y for Yes and N for No: ");
        char temp= sc.next().charAt(0);
        int pass=4758;
        int bal=10000;
        int leftbal;
        System.out.println("If you don't know the password refer the first line of the program");
        System.out.println("Please enter the password: ");;
        // Condition when the statement goes true i.e.- temp equals 1
        do
        {      
            if(temp=='Y'|| temp=='y')
            {
                if (pass== 4758)
                {
                    System.out.println("");
                    System.out.println("Your initial account balance is Rs. 10000");

                    //Using for statement to perform 5 operation on each login
                    for (int x=0; x<=6; x++)
                    {
                        System.out.println("0. Exit");
                        System.out.println("1. Deposit");
                        System.out.println("2. Withdraw");
                        System.out.println("3. Change passcode");
                        System.out.println("4. Check balance");
                        System.out.println("5. Customer care");
                        System.out.println("Enter the serial no. of your choice");
                        int choice= sc.nextInt();
                        System.out.println("Enter captha to verify that you are not a robot.");
                        int captha= rd.nextInt(10000);
                        System.out.println(captha);
                        System.out.println("Enter the number shown above: ");
                        int verify= sc.nextInt();
                        if (verify==captha)
                        {
                            //If captha gets matched, then these switch statements are executed.
                            switch(choice)
                            {
                                case 0:
                                {
                                    System.out.println("BYE!......"+name+" HAVE A NICE DAY!");
                                    System.out.println("__________________________");
                                    System.out.println("CREDITS: ");
                                    System.out.println("---------");
                                    System.out.println("Dcoder IDE");
                                    System.out.println("Pearson Education Limited");
                                    System.out.println("__________________________");
                                    System.out.println("@author>[@yash197911]");
                                    System.out.println("Please comment here if you have any queries or suggestions!");
                                    System.out.println("--OR--");
                                    System.out.println("You can e-mail me on - yash197911@gmail.com");
                                    System.out.println("I will rightly see and reply to your messages ans suggestions!");
                                    System.out.println("Just keep the title as #Dcoder");
                                    System.out.println("");
                                    System.out.println("HAPPY CODING!:-)");
                                    System.exit(3);
                                }
                                break;
                                case 1:
                                {
                                    System.out.println("You have chosen to deposit.");
                                    System.out.println("Enter the amount to deposit : ");
                                    int deposit=sc.nextInt();
                                    bal=bal+deposit;
                                    System.out.println(deposit+" has been deposited to your account.");
                                    System.out.println("Left balance is "+bal);
                                }
                                break;
                                case 2:
                                {
                                    System.out.println("You have chosen to withdraw.");
                                    System.out.println("Enter the amount to be withdrawn");
                                    int withdraw=sc.nextInt();
                                    System.out.println(+withdraw+" has been withdrawn from your account.");
                                    bal=bal-withdraw;
                                    System.out.println("Check the cash printer.");
                                    System.out.println("Left balance is "+bal);
                                }
                                break;
                                case 3:
                                {
                                    System.out.println("You have chosen to change passcode.");
                                    System.out.println("Enter the current passcode: ");
                                    int check= sc.nextInt();
                                    if(check== pass)
                                    {
                                        System.out.println("Enter the new passcode");
                                        int newP=sc.nextInt();
                                        pass=newP;
                                        System.out.println("Your new password is "+newP);
                                    }
                                    else
                                    {
                                        System.out.println("Wrong passcode!");
                                    }
                                }
                                break;
                                case 4:
                                {                      
                                    System.out.println("You have chosen to check balanace.");
                                    System.out.println("Your current account balance is "+bal);
                                }
                                break;
                                case 5:
                                {
                                    System.out.println("You have chosen for customer care.");
                                    System.out.println("Contact us at:");
                                    System.out.println("          Email: yash197911@gmail.com");
                                }
                                break;
                                default:
                                System.out.println("Wrong choice!!! Choose again...!");
                            }
                        }
                        // Condition if captha mismatches.
                        else
                        {
                            System.out.println("×CAPTHA NOT CORRECT×");
                        }
                    }       
                    // Using continue for prompting again to start/ restart
                }
                continue;
            }
            else if (temp=='N' || temp=='n')
            {
                System.out.println("BYE!......"+name+" HAVE A NICE DAY!");
                System.out.println("__________________________");
                System.out.println("@author>[@programmer-offbeat]");
                System.out.println("Please comment here if you have any queries or suggestions!");
                System.out.println("--OR--");
                System.out.println("You can e-mail me on - me@theyash.dev");
                System.out.println("I will rightly see and reply to your messages and suggestions!");
                System.out.println();
                System.out.println("HAPPY CODING!:-)");
                System.exit(5);
            }
            //Condition if any other character is accepted instead of Y or N.
            else
            {
                System.out.println("Err!..... You have entered a wrong choice!");
                System.out.println("Try again....!");
            }
            // Comdition if password mismatches.
            if(pass!= 4758)
            {
                System.out.println("You have entered wrong password.....Try again!");
            }
        }while(temp<100);
    }
}

/**********************************************
 * @INFO
 * Author = programmer-offbeat
 * @ INFO
 * Discord = Astrexx.jar#4035
 *********************************************/
