import java.util.LinkedHashMap;
import java.util.Map;

public class longestSubstring {
    public static void main(String[] args) {
        String S = "rohilla";
        int length = 0;
        String longest = null;
        Map <Character , Integer> map = new LinkedHashMap<Character , Integer>(50);
        char[] ch = S.toCharArray();
        for (int i = 0; i < ch.length; i++) {
            char chr = ch[i];
            if(!map.containsKey(chr)){
                map.put(chr, i);
            }else{
                i = map.get(chr);
                map.clear();
            }
            if(map.size()>length){
                length = map.size();
              longest =  map.keySet().toString();
            }
           // System.out.println(map.keySet().toString());
        }
        System.out.println(longest);
        System.out.println(length);
    }
}
