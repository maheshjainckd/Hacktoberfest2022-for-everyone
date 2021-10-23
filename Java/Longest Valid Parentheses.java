class LongestValid {
    public int longestValidParentheses(String s) {
        if (s == null || s.length() < 2)
            return 0;
        int left=0, right=0, maxLen=0;
        for(char c: s.toCharArray()){
            if (c == '('){
                left++;
            }
            else{
                right++;
                if (left == right)
                    maxLen = Math.max(maxLen,2*right);
                else if (right > left){
                    left=0;
                    right=0;
                }
            }
        }
        left=0;
        right=0;
        for (int i=s.length()-1; i>=0; --i){
            if (s.charAt(i) == ')'){
                right++;
            }
            else{
                left++;
                if (left == right)
                    maxLen = Math.max(maxLen,2*left);
                else if (left > right){
                    left = 0;
                    right = 0;
                }
            }
        }
        return maxLen;
    }
}
