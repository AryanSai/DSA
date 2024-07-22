package Done.Sorting;
import java.util.Arrays;

public class P2418 {
    static String[] sortPeople(String[] names, int[] heights) {
        int maxx = 0, id = 0, tempHeight;
        String temp;
        for (int j = 0; j < heights.length; j++) {
            maxx = 0;
            id = 0;
            for (int i = j; i < heights.length; i++) {
                if (heights[i] > maxx) {
                    maxx = heights[i];
                    id = i;
                }
            }
            temp = names[j];
            names[j] = names[id];
            names[id] = temp;
            tempHeight = heights[j];
            heights[j] = heights[id];
            heights[id] = tempHeight;
        }

        System.out.println(maxx + " " + id);
        return names;
    }

    public static void main(String[] args) {
        String[] names = { "IEO", "Sgizfdfrims", "QTASHKQ", "Vk", "RPJOFYZUBFSIYp", "EPCFFt", "VOYGWWNCf", "WSpmqvb" };
        int[] heights = { 17233, 32521, 14087, 42738, 46669, 65662, 43204, 8224 };
        System.out.println(Arrays.toString(sortPeople(names, heights)));
    }
}
