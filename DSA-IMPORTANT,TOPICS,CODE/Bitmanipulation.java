// left shift                       right shift 
// N<<i                             N>>i
// 2<<1                             2>>1
/* get , set , clear. update */
import java.util.*;
public class Bitmanipulatation{
 public static void main(String[] args){
    // getBit : 1>>i .Operation : AND 
   /*  int n = 5; //0101
    int pos = 3;
    int bitMask = 1<<pos;

    if((bitMask & n) ==0){
        System.out.println("Bit was Zero ");
    }else{
        System.out.println("Bit was one");
    }   */
    // setBit : set the second bit position=1 of a number n. (n=0101)
    // bitMask:1<<i Operation:OR
   /*  int n = 5; //0101
    int pos = 1;
    int bitMask = 1<<pos;

    int newNumber = bitMask | n;
    System.out.println(newNumber); */
    // ClearbIT : CLEAR the third bit position=2 of a number n. (n=0101)
    // bitMask 1<<i  Operation : AND with NOT
   /*  int n = 5; //0101
    int pos = 2;
    int bitMask = 1<<pos;
    int notBitMask = ~(bitMask);
    int newNumber = notBitMask & n ;
    System.out.println(newNumber); */

    //  Update Bit :Update the second bit position=1 of a number n. (n=0101)
    // For 1 : bitMask 1<<i  Operation : AND with NOT :clear
    // For 0 : bitMask:1<<i Operation:OR: set
    Scanner s = new Scanner(System.in);
    int operation = s.nextInt();
    //operation = 1 set =0 clear
    int n = 5; //0101 -> 0111 -> dec 7
    int pos = 1;
    int bitMask = 1<<pos;

    // int Operation = 1; // update bit to 1 else update bit to 0
    if(operation ==1){
        // set operation
    int newNumber = bitMask | n;
    System.out.println(newNumber);
    }else{
        // clear
        int newBitMask = ~(bitMask);
        int newNumber = newBitMask & n;
        System.out.println(newNumber);
    }
 }
}