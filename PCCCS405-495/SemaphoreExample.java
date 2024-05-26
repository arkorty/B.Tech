
import java.util.concurrent.Semaphore;

class SharedCounter {
    private int count = 0;
    private Semaphore semaphore;

    public SharedCounter(int permits) {
        this.semaphore = new Semaphore(permits);
    }

    public void increment() throws InterruptedException {
        semaphore.acquire(); // Acquire a permit
        try {
            System.out.println(count + " .. " + ++count);
        } finally {
            semaphore.release(); // Release the permit
        }
    }

    public void decrement() throws InterruptedException {
        semaphore.acquire(); // Acquire a permit
        try {
            System.out.println(count + " .. " + --count);
        } finally {
            semaphore.release(); // Release the permit
        }
    }
}

class Runner extends Thread {
    private SharedCounter counter;

    public Runner(SharedCounter counter) { this.counter = counter; }

    public void run() {
        try {
            counter.increment();
            // Simulate some processing time
            Thread.sleep(1000);
            counter.decrement();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class SemaphoreExample {
    public static void main(String[] args) {
        SharedCounter counter =
            new SharedCounter(2); // Create semaphore with 2 permits
        Runner r1 = new Runner(counter);
        Runner r2 = new Runner(counter);
        Runner r3 = new Runner(counter);

        r1.start();
        r2.start();
        r3.start();
    }
}
