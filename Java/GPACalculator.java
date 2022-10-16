import java.util.Scanner;
import java.text.DecimalFormat;
public class GpaCalculator {
 
    public static void main(String[] args) {
        
                String lettergrd;
		        double credit;
                double caltimes = 0;
                double totalcal = 0;
                double totalcredit = 0;
                double finalgpa = 0;
		        final double A = 4.0;
		        final double AMINUS = 3.67;
		        final double BPLUS = 3.33;
		        final double B = 3.0;
		        final double BMINUS = 2.67;
		        final double CPLUS = 2.33;
		        final double C = 2.0;
                final double CMINUS = 1.67;
                final double D = 1.00;
                final double F = 0.0;
                DecimalFormat df = new  DecimalFormat("0.##");
		        Scanner grd = new Scanner(System.in);
                
                for(int i = 0; i < 10; i++)
                {
                    
                System.out.println("Enter the  grade: ");
		        lettergrd = grd.next();
                
		        System.out.println("Enter the  credit: ");
		        credit = grd.nextDouble();
                
                switch(lettergrd)
                {
                  case "A": caltimes = credit * A;
                  case "a": caltimes = credit * A;
                    break;
                    case "A-": caltimes = credit * AMINUS;
                    case "a-": caltimes = credit * AMINUS;
                    break;
                    case "B+": caltimes = credit * BPLUS;
                    case "b+": caltimes = credit * BPLUS;
                    break;
                    case "B": caltimes = credit * B;
                    case "b": caltimes = credit * B;
                    break;   
                    case "B-": caltimes = credit * BMINUS;
                    case "b-": caltimes = credit * BMINUS;
                    break;
                    case "C+": caltimes = credit * CPLUS;
                    case "c+": caltimes = credit * CPLUS;
                    break; 
                    case "C": caltimes = credit * C;
                    case "c": caltimes = credit * C;
                    break;
                    case "C-": caltimes = credit * CMINUS;
                    case "c-": caltimes = credit * CMINUS;
                    break;   
                    case "D": caltimes = credit * D;
                    case "d": caltimes = credit * D;
                    break;
                    case "F": caltimes = credit * F;
                    case "f": caltimes = credit * F;
                    break;
                        
                }
                 
                totalcredit = totalcredit + credit;
                totalcal = totalcal + caltimes;
                
                }
                
                finalgpa = totalcal/totalcredit;
                System.out.println("Final GPA: " + df.format(finalgpa));
    }
    
}
