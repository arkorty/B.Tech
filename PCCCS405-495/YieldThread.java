class ThreadExample extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Thread is running...");
            Thread.yield();
        }
    }

    public static void main(String[] args) {
        ThreadExample thread = new ThreadExample();
        thread.start();
    }
}
