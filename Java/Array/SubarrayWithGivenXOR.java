
import java.util.HashMap;
import java.util.Map;

public class SubarrayWithGivenXOR {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] A = {4, 2, 2, 6, 4};
		System.out.println(solve(A,6));
	}
	public static int solve(int[] A, int B) {
		int longestStreak = 0;
		Map<Integer, Integer> frequency = new HashMap<>();
		int currentXOR = 0;
		int count = 0;
		for(int i: A) {
			currentXOR ^= i;
			if(frequency.get(currentXOR ^ B) != null) {
				count += frequency.get(currentXOR ^ B);
			}
			if(currentXOR == B) {
				count++;
			}
			if(frequency.get(currentXOR) != null) {
				frequency.put(currentXOR, frequency.get(currentXOR)+1);
			} else {
				frequency.put(currentXOR, 1);
			}
		}
		
		return count;
		
    }

}
