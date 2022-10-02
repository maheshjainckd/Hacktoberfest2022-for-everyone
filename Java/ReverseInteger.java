import java.util.*;

class ReverseInteger {
    public int reverse(int x) {
        ArrayList<Integer> list = new ArrayList<Integer>();
            while(Math.abs(x) > 0){
                int digit = x%10;
                list.add(digit);
                x = x/10;
            }
            int result = 0;
            int index = list.size();
            for(int i = 0; i < list.size(); i++){
                result += list.get(i) * Math.pow(10, index-1);
                index--;
            }
        
        if(result >=  Integer.MAX_VALUE || result <= Integer.MIN_VALUE)
            return 0;
        else
            return result;  
    }
}
