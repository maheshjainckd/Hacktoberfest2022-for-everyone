// Program to find the first bad version using Binary Search Algorithm
package Class11;

public class FirstBadVersion {

	private static boolean isBad(char version) {
		// TODO Auto-generated method stub
		if(version == 'B') {
			return true;
		}

		return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		char[] version = {'G', 'G', 'G', 'G', 'B'};
	
		int l = -1, r = version.length - 1;
		
		while(r > l + 1) {
			int mid = (l + r) / 2;
			
			if(isBad(version[mid])) {
				r = mid;
			} else {
				l = mid;
			}
		}
		
		System.out.println(r);
	}

}
