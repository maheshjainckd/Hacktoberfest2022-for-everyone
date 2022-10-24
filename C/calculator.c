#include <stdio.h>
#include<stdlib.h>

int main() 
{
  char oper;
  double first, second;
  double a = 1;
  printf("Enter an operator (+, -, *, /, ^): ");
  scanf("%c", &oper);
  printf("Enter two operands: ");
  scanf("%lf %lf", &first, &second);

  switch (oper) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
      break;
    case'^':
      for(int j =0; j<second; j++){
        a = first * a;
      }
      printf("%.1lf ^ %.1lf = %.1lf",first,second,a);
      break;
    default:
      printf("Error! operator is not correct");
  }

  return 0;
}
