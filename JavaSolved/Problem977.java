package Done;
public class Problem977 {
    static int[] sortedSquares(int[] nums) {
        int[] sol=new int[nums.length];
        int l=0, u=nums.length-1,i=u;
        while(l<=u){
            if (Math.abs(nums[l])>Math.abs(nums[u])) {
                sol[i]=nums[l]*nums[l];
                i--;
                l++;
            }else{
                sol[i]=nums[u]*nums[u];
                i--;
                u--;
            }
        }
        return sol;
    }

    public static void main(String[] args) {
        int[] nums={-4,-1,0,3,10};
        int[] sol=sortedSquares(nums);
        for(int num:sol){
            System.out.println(num);
        }
    }
}
