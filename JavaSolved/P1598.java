package Done;
class P1598 {
    static int minOperations(String[] logs) {
        int count = 0;
        for (String s : logs) {
            if (s.equals("../"))
                count = Math.max(0, count - 1);
            else if (s.equals("./"))
                ;
            else
                count++;
        }
        return count;
    }

    public static void main(String[] args) {
        String[] arr = { "d1/", "../", "../", "../" };
        System.out.println(minOperations(arr));
    }
}