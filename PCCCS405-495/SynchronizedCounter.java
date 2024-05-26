
class SharedCounter {
    private int count = 0;

    public synchronized void increment() {
        System.out.println(count + " .. " + ++count);
    }

    public synchronized void decrement() {
        System.out.println(count + " .. " + --count);
    }
}

class Runner extends Thread {
    private SharedCounter counter;

    public Runner(SharedCounter counter) { this.counter = counter; }

    public void run() {
        try {
            synchronized (counter) {
                counter.increment();
                // Simulate some processing time
                Thread.sleep(1000);
                counter.decrement();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class SynchronizedExample {
    public static void main(String[] args) {
        SharedCounter counter = new SharedCounter();
        Runner r1 = new Runner(counter);
        Runner r2 = new Runner(counter);
        Runner r3 = new Runner(counter);

        r1.start();
        r2.start();
        r3.start();
    }
}
