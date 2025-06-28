package Done.Strings;
class P14 {
    static String longestCommonPrefix(String[] strs) {
        int k = strs[0].length(), count = 0;
        for (int i = 1; i < strs.length; i++) {
            count = 0;
            System.out.println(strs[i]);
            k = Math.min(k, strs[i].length());
            for (int j = 0; j < k; j++) {
                if (strs[0].charAt(j) == strs[i].charAt(j)) {
                    count++;
                }else{
                    break;
                }
            }
            System.out.println(count);
            k = count;
        }
        return strs[0].substring(0, k);
    }

    public static void main(String[] args) {
        String[] strs = { "cir","car"};
        System.out.println(longestCommonPrefix(strs));
    }
}