
class Counter {
    private int count = 0;

    public synchronized void increment() { count++; }

    public synchronized int getCount() { return count; }
}

class ThreadExample extends Thread {
    private Counter counter;

    public ThreadExample(Counter counter) { this.counter = counter; }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }

    public static void main(String args[]) {
        Counter counter = new Counter();
        ThreadExample t1 = new ThreadExample(counter);
        ThreadExample t2 = new ThreadExample(counter);

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Final count: " + counter.getCount());
    }
}
