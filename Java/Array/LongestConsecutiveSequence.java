
import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {0,3,7,2,5,8,4,6,0,1};
		System.out.println(longestConsecutive(nums));
	}
	
	public static int longestConsecutive(int[] nums) {
		Set<Integer> set = new HashSet<>();
		for(int i : nums) {
			set.add(i);
		}
		int longestStreak = 0;
        for (int i : nums) {
			if(!set.contains(i - 1)) {
				int currentNum = i;
				int currentStreak = 1;
				while(set.contains(currentNum + 1)) {
						currentStreak++;
						currentNum++;
				}
				longestStreak = Math.max(longestStreak, currentStreak);
			}
		}
		return longestStreak;
        
    }

}
