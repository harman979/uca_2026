class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int low = 1;
        int high = 0;

        for (int q : quantities) {
            high = Math.max(high, q);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(quantities, n, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    private boolean canDistribute(int[] quantities, int n, int maxLoad) {
        long clinics = 0;

        for (int q : quantities) {
            clinics += (q + (long) maxLoad - 1) / maxLoad;

            if (clinics > n) {
                return false;
            }
        }

        return true;
    }
}
