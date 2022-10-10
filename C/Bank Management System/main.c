#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct Bank
{
    char name[30],fname[30];
    int DOB_dd, DOB_mm, DOB_yyyy;
    char mobile_no[11],aadhar_no[13],pan_no[11];
    char district[20],state[20],pin[7];
    char account_no[11],costumer_id[6];

}bank;
char a[30]="Ashish Goyal";
char Acc[11]="1234567891";
int TotalAmount =2000;
int Amo;
int Amount;
int trans;
int TotalDeposit =0;
int TotalWithdraw =0;
int TotalTransfered =0;
void login();
void mainMenu();
void acc_open();
void details();
void transfer();
void deposit();
void withdraw();
void last();
void main()
{
   system("cls");
   printf("\n\n\t\t\tWELCOME TO BANKING MANAGEMENT SYSTEM BY ASHISH");
   printf("\n\n\t\t\tPress any key to continue. . .");
   getch();
   login();
}
void login()
{
    char user[15],pass[15];
    system("cls");
    printf("\n\n\t\t\tEnter Username :");
    gets(user);
    printf("\n\n\t\t\tEnter Password :");
    gets(pass);
    if(strcmp(user,"ashish123")==0)
    {
        if(strcmp(pass,"Ashish123")==0)
        {
            printf("\n\n\t\t\tLogin Successful");
            printf("\n\n\t\t\tPress any key to continue. . .");
            getch();
            mainMenu();
        }
        else{
            printf("\n\n\t\t\tInvalid password");
            printf("\n\n\t\t\tPress any key");
        }
    }
    else
        {
          printf("\n\n\t\t\tInvalid username");
          printf("\n\n\t\t\tPress any Key");
          getch();
          return;
        }

}
void mainMenu()
{
    int choice;
    lineno73:
    system("cls");
    printf("\n\n\t\t\t\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2");
    printf("\n\n\t\t\t1.Account opening ");
    printf("\n\n\t\t\t2.Detail of account");
    printf("\n\n\t\t\t3.Transfer money ");
    printf("\n\n\t\t\t4.Deposit");
    printf("\n\n\t\t\t5.Withdraw");
    printf("\n\n\t\t\t6.Exit");
    printf("\n\n\t\t\tYou have entered :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            acc_open();
            getch();
            goto lineno73;
        case 2:
            details();
            getch();
            goto lineno73;
        case 3:
            transfer();
            if(trans<=TotalAmount)
              TotalTransfered +=trans;
            goto lineno73;
        case 4:
            deposit();

            TotalDeposit +=Amount;
            goto lineno73;
        case 5:
            withdraw();
            if(Amo<=TotalAmount)
              TotalWithdraw +=Amo;
            goto lineno73;
        case 6:
            last();
            printf("\n\n\t\t\tThanks for visiting . ");
            printf("\n\n\t\t\tPress any key to exit...");
            getch();
            exit(0);
    default:
        printf("\n\n\t\t\tInvalid selection Please enter choose a valid choice.");
        printf("\n\n\t\t\tPress any key");
        getch();
        goto lineno73;
    }

}


void acc_open()
{
system("cls");
printf("\n\n\t\t\t\xB2\xB2\xB2 Account Opening Form \xB2\xB2\xB2");
printf("\n\n\t\t\tEnter name :");
fflush(stdin);//not skip the line
gets(bank.name);
printf("\n\n\t\t\tEnter father's name :");
fflush(stdin);
gets(bank.fname);
printf("\n\n\t\t\tEnter date of birth  :");
fflush(stdin);
scanf("%d",&bank.DOB_dd);
printf("\n\n\t\t\tEnter date of birth mm :");
fflush(stdin);
scanf("%d",&bank.DOB_mm);
printf("\n\n\t\t\tEnter date of birth yyyy :");
fflush(stdin);
scanf("%d",&bank.DOB_yyyy);
printf("\n\n\t\t\tEnter mobile number :");
fflush(stdin);
gets(bank.mobile_no);
printf("\n\n\t\t\tEnter pan number :");
fflush(stdin);
gets(bank.pan_no);
printf("\n\n\t\t\tEnter aadhar number :");
fflush(stdin);
gets(bank.aadhar_no);
printf("\n\n\t\t\tEnter your district :");
fflush(stdin);
gets(bank.district);
printf("\n\n\t\t\tEnter your state :");
fflush(stdin);
gets(bank.state);
printf("\n\n\t\t\tEnter pin :");
fflush(stdin);
gets(bank.pin);
printf("\n\n\t\t\tEnter account number :");
fflush(stdin);
gets(bank.account_no);
printf("\n\n\t\t\tEnter  customer id :");
fflush(stdin);
gets(bank.costumer_id);
printf("\n\n\t\t\tCONGRATULATIONS YOUR ACCOUNT HAS BEEN CREATED");
}







void deposit()
{
system("cls");
printf("\n\n\t\t\tEnter the amount you want to deposit :");
scanf("%d",&Amount);
TotalAmount +=Amount;
}


void withdraw()
{
system("cls");
printf("\n\n\t\t\tEnter the amount you wish to withdraw :");
scanf("%d",&Amo);
if(Amo<=TotalAmount)
{
    TotalAmount -= Amo;
}
else
   {
       printf("\n\n\t\t\tLess amount withdraw is not possible");
   }
}
void transfer()
{
system("cls");
printf("\n\n\t\t\tEnter the amount you want to transfer");
scanf("%d",&trans);
if(trans<=TotalAmount)
{
    TotalAmount -=trans;
}
else{
    printf("\n\n\t\t\tLess amount transfer is not possible");
}
}

void details()
{
system("cls");
printf("\n\n\t\t\t Total Amount =%d",TotalAmount);
printf("\n\n\t\t\tTotal Deposited amount =%d",TotalDeposit);
printf("\n\n\t\t\tTotal withdraw amount =%d",TotalWithdraw );
printf("\n\n\t\t\tTotal transfered amount =%d",TotalTransfered);

}
void last()
{
    system("cls");
    printf("\n\n\t\t\t**************************************\n");
    printf("\n\n\t\t\t Your Name=%s",a);
    printf("\n\n\t\t\tAccount Number=%d",Acc);
    printf("\n\n\t\t\tTotal Amount=%d",TotalAmount);
    printf("\n\n\t\t\tTotal Deposited amount =%d",TotalDeposit);
    printf("\n\n\t\t\tTotal withdraw amount =%d",TotalWithdraw );
    printf("\n\n\t\t\tTotal transfered amount =%d",TotalTransfered);
}
