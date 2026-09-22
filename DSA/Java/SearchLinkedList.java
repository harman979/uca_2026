public class SearchLinkedList {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Check whether list1 occurs as a contiguous sequence in list2
    static boolean isSubList(Node list1, Node list2) {

        // Empty list1 is considered present
        if (list1 == null) {
            return true;
        }

        Node current = list2;

        while (current != null) {

            // Found a possible starting point
            if (current.data == list1.data) {

                Node p1 = list1;
                Node p2 = current;

                // Check whether the complete sequence matches
                while (p1 != null && p2 != null &&
                       p1.data == p2.data) {
                    p1 = p1.next;
                    p2 = p2.next;
                }

                // All elements of list1 matched
                if (p1 == null) {
                    return true;
                }
            }

            current = current.next;
        }

        return false;
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

        // list1: 3 -> 4 -> 5
        Node list1 = new Node(3);
        list1.next = new Node(4);
        list1.next.next = new Node(5);

        // list2: 1 -> 2 -> 3 -> 4 -> 5 -> 6
        Node list2 = new Node(1);
        list2.next = new Node(2);
        list2.next.next = new Node(3);
        list2.next.next.next = new Node(4);
        list2.next.next.next.next = new Node(5);
        list2.next.next.next.next.next = new Node(6);

        System.out.println("List 1:");
        printList(list1);

        System.out.println("List 2:");
        printList(list2);

        if (isSubList(list1, list2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
