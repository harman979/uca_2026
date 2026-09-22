public class IntersectionSortedLists {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Find intersection and create a new linked list
    static Node intersection(Node head1, Node head2) {
        Node dummy = new Node(0);
        Node tail = dummy;

        Node p1 = head1;
        Node p2 = head2;

        while (p1 != null && p2 != null) {

            if (p1.data == p2.data) {
                // Create a NEW node
                tail.next = new Node(p1.data);
                tail = tail.next;

                p1 = p1.next;
                p2 = p2.next;
            }
            else if (p1.data < p2.data) {
                p1 = p1.next;
            }
            else {
                p2 = p2.next;
            }
        }

        return dummy.next;
    }

    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data);

            if (head.next != null) {
                System.out.print(" -> ");
            }

            head = head.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // First list:
        // 1 -> 2 -> 2 -> 4 -> 6 -> 8
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(4);
        head1.next.next.next.next = new Node(6);
        head1.next.next.next.next.next = new Node(8);

        // Second list:
        // 2 -> 2 -> 3 -> 4 -> 6 -> 6
        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(3);
        head2.next.next.next = new Node(4);
        head2.next.next.next.next = new Node(6);
        head2.next.next.next.next.next = new Node(6);

        System.out.println("List 1:");
        printList(head1);

        System.out.println("List 2:");
        printList(head2);

        Node result = intersection(head1, head2);

        System.out.println("Intersection:");
        printList(result);
    }
}
