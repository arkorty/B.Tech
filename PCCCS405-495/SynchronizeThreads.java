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

    public static void main(String[] args) {
        Counter counter = new Counter();
        ThreadExample thread1 = new ThreadExample(counter);
        ThreadExample thread2 = new ThreadExample(counter);
        thread1.start();
        thread2.start();
        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Counter value: " + counter.getCount());
    }
}
