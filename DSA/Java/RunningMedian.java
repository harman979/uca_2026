import java.util.*;

class RunningMedian {
    private PriorityQueue<Integer> left;
    private PriorityQueue<Integer> right;

    public RunningMedian() {
        left = new PriorityQueue<>(Collections.reverseOrder());
        right = new PriorityQueue<>();
    }

    public void insert(int num) {
        if (left.isEmpty() || num <= left.peek()) {
            left.offer(num);
        } else {
            right.offer(num);
        }

        if (left.size() > right.size() + 1) {
            right.offer(left.poll());
        } else if (right.size() > left.size()) {
            left.offer(right.poll());
        }
    }

    public float getMedian() {
        if (left.size() == right.size()) {
            return ((float) left.peek() + right.peek()) / 2;
        }

        return left.peek();
    }
}
