class ThreadExample implements Runnable {
    public void run() {
        System.out.println(
            "Thread created by implementing the Runnable interface.");
    }

    public static void main(String[] args) {
        ThreadExample myRunnable = new ThreadExample();
        Thread thread = new Thread(myRunnable);
        thread.start();
    }
}
