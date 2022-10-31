import java.util.Scanner;
class quadraticEq{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a=0,b=0,c=0,x1=0, x2=0;
        System.out.println("Enter the value of a :");
        a= sc.nextDouble();
        System.out.println("Enter the value of b :");
        b= sc.nextDouble();
        System.out.println("Enter the value of c :");
        c= sc.nextInt();
        x1=(0-b + Math.sqrt(Math.pow(b, 2) - 4*a*c))/2*a;
        x2=(0-b - Math.sqrt(Math.pow(b, 2) - 4*a*c))/2*a;
        System.out.println("Quadratic equation : "+a+"x2 + "+b+"x + "+c+" = 0");
        System.out.println("Roots : \nx = "+x1+"\nx="+x2);
    }
}

/**********************************************
 * @INFO
 * Author = programmer-offbeat
 * @ INFO
 * Discord = Astrexx.jar#4035
 *********************************************/
