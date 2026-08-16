public class FindingNumbersInArray {

    public static int findNumberRepeatedFourTimes(int[] nums) {
        int result = 0;
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int num : nums) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                result |= (1 << bit);
            }
        }

        return result;
    }

    public static void main(String[] args) {

        int[] nums = {
            1, 2, 3, 4,
            1, 2, 4,
            1, 2, 3, 4,
            3, 3
        };

        System.out.println(findNumberRepeatedFourTimes(nums));
    }
}
