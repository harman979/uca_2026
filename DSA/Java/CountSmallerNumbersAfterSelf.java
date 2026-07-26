import java.util.*;

public class CountSmallerNumbersAfterSelf {
    static class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    static int[] ans;

    static void mergeSort(Pair[] arr, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    static void merge(Pair[] arr, int low, int mid, int high) {
        ArrayList<Pair> temp = new ArrayList<>();

        int left = low;
        int right = mid + 1;
        int rightCount = 0;

        while (left <= mid && right <= high) {
            if (arr[left].value > arr[right].value) {
                rightCount++;
                temp.add(arr[right++]);
            } else {
                ans[arr[left].index] += rightCount;
                temp.add(arr[left++]);
            }
        }

        while (left <= mid) {
            ans[arr[left].index] += rightCount;
            temp.add(arr[left++]);
        }

        while (right <= high) {
            temp.add(arr[right++]);
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp.get(i - low);
        }
    }

    static int[] countSmaller(int[] nums) {
        int n = nums.length;
        ans = new int[n];

        Pair[] arr = new Pair[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        mergeSort(arr, 0, n - 1);

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();

        while (sc.hasNextInt()) {
            list.add(sc.nextInt());
        }

        int[] nums = new int[list.size()];

        for (int i = 0; i < list.size(); i++) {
            nums[i] = list.get(i);
        }

        int[] result = countSmaller(nums);

        for (int x : result) {
            System.out.print(x + " ");
        }
    }
}
