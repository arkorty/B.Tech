
public class JoinThread {
    public static void main(String[] args) {
        Thread thread1 = new Thread(new ThreadExample("Thread 1"));
        Thread thread2 = new Thread(new ThreadExample("Thread 2"));

        // Start both threads
        thread1.start();
        thread2.start();

        try {
            // Wait for thread1 to finish
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread exiting.");
    }
}

class ThreadExample implements Runnable {
    private String threadName;

    public ThreadExample(String threadName) { this.threadName = threadName; }

    public void run() {
        System.out.println(threadName + " is running.");
        try {
            // Simulate some processing time
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(threadName + " finished.");
    }
}
