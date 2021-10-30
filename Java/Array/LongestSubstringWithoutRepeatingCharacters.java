
import java.util.HashMap;
import java.util.Map;

public class LongestSubstringWithoutRepeatingCharacters {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "abcabcbb";
		System.out.println(lengthOfLongestSubstring(s));
	}

	public static int lengthOfLongestSubstring(String s) {
		Map<Character, Integer> map = new HashMap<>();
		int left = 0, right = 0, longestStringLength = 0;
		while(right < s.length()) {
			if(map.get(s.charAt(right)) != null) {
				left = Math.max(map.get(s.charAt(right)) + 1, left);
			}
			map.put(s.charAt(right), right);
			longestStringLength = Math.max(longestStringLength, right-left+1);
			right++;
		}
		return longestStringLength;
        
    }

}
