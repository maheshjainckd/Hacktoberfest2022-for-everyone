public class ReverseString {
    public static void main(String[] args) {
        String myString = "Hello darkness, my old friend";
        System.out.println("String before swap:" + myString);
        myString = reverseString(myString);
        System.out.println("String after swap:" + myString);
    }

    private static String reverseString(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length/2; i++) {
            swap(chars, i, chars.length-1-i);
        }
        return new String(chars);
    }

    private static void swap(char[] chars, int posA, int posB) {
        char tmp = chars[posA];
        chars[posA] = chars[posB];
        chars[posB] = tmp;
    }
}
