package Done;

class P1550 {
    static boolean todo(int[] nums) {
        int i=0;
        for(int n:nums){
            System.out.println(n);
            if(n%2==1)
                i++;
            else    
                i=0;    
            if(i==3)
                return true;    
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums ={0,1,2};
        System.out.println(todo(nums));
    }
}