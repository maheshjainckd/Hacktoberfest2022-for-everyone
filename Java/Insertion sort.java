import java.util.*;
public class Main {  
public static void main(String[] args) {  
    //declare an array and print the original contents
    int[] numArray = {10,6,15,4,1,45};  
    System.out.println("Original Array:" + Arrays.toString(numArray));
    //apply insertion sort algorithm on the array
    for(int k=1; k<numArray.length-1; k++)   {  
        int temp = numArray[k];  
        int j= k-1;  
        while(j>=0 && temp <= numArray[j])   {  
            numArray[j+1] = numArray[j];   
            j = j-1;  
        }  
        numArray[j+1] = temp;  
    }  
    //print the sorted array
    System.out.println("Sorted Array:" + Arrays.toString(numArray));
}  
}  
