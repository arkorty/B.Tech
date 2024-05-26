class ThreadExample extends Thread {
    boolean suspended = false;

    public synchronized void mySuspend() { suspended = true; }

    public synchronized void myResume() {
        suspended = false;
        notify();
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println("Thread is running... " + i);
                Thread.sleep(1000);
                synchronized (this) {
                    while (suspended) {
                        wait();
                    }
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        ThreadExample thread = new ThreadExample();
        thread.start();
        try {
            Thread.sleep(3000); // Sleep for 3 seconds
            thread.mySuspend();
            Thread.sleep(3000); // Sleep for 3 seconds
            thread.myResume();
            Thread.sleep(3000); // Sleep for 3 seconds
            thread.mySuspend();
            Thread.sleep(3000); // Sleep for 3 seconds
            thread.myResume();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
