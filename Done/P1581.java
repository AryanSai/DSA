package Done;
class P1581 {
    public static int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        while(numBottles >= numExchange){
            sum+=(numBottles / numExchange); 
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return sum;
    }
    public static void main(String[] args) {
        System.out.println(numWaterBottles(15,4));
    }
}