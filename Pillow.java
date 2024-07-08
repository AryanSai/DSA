class Pillow {
    static int passThePillow(int n, int time) {
        if(time<n)
            return time + 1;
        int rem = time % (n-1);
        System.out.println(rem);
        if(rem%2==0)
            return 1;
        return rem;
    }

    public static void main(String[] args) {
        System.out.println(passThePillow(8, 9));
    }
}