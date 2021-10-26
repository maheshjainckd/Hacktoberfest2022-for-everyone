import java.util.*;

public class BinarySearch{
  public static boolean binarySearch(int[] arr, int t){
    int leftIndex=0;
    int rightIndex=arr.length-1;
    while(leftIndex<=rightIndex){
      int middleIndex=(leftIndex+rightIndex)/2;
      if(arr[middleIndex]==t){
        return true;
      }
      if(t>arr[middleIndex]){
        leftIndex=middleIndex+1;
      }
      else{
        rightIndex=middleIndex-1;
      }
    }
    return false;
  }
}
