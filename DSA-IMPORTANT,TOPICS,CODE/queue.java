import java.util.Queue;

public class queue {
    static class Queue {
        static int arr[]; // IMPLEMENT QUEUE YSUNG ARRAY
        static int size;
        static int rear = -1;

        Queue(int n) {
            arr = new int[n];
            this.size = n;
        }

        public static boolean isEmpty() {
            return rear == -1;
        }

        // add or enqueue
        public static void add(int data) {
            if (rear == size - 1) {
                System.out.println("Full queue");
                return;
            }
            rear++;
            arr[rear] = data;
        }

        // dequeue or remove
        public static int remove() {
            if (isEmpty()) {
                System.out.println("Empty dequeue");
                return -1;
            }
            int front = arr[0];
            for (int i = 0; i < rear; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
            return front;

        }

        // peek
        public static int peek() {
            if (isEmpty()) {
                System.out.println("Empty dequeue");
                return -1;
            }
            return arr[0];
        }
    }

    public static void main(String[] args) {
        queue q = new queue();
        q.add(1);
        q.add(2);
        q.add(3);
        // 1,2,3
        while (!q.isEmpty()) {
            System.out.println(q.peek());
            q.remove();
        }

    }

    private void add(int i) {
    }

    private void remove() {
    }

    private char[] peek() {
        return null;
    }

    private boolean isEmpty() {
        return false;
    }

}
