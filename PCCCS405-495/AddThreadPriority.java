class ThreadExample extends Thread {
    private static int count = 0;

    public void run() {
        for (int i = 0; i < 10; i++) {
            count++;
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Final value of count for priority " +
                           this.getPriority() + ": " + count);
    }

    public static void main(String[] args) {
        ThreadExample thread1 = new ThreadExample();
        thread1.setPriority(1);
        ThreadExample thread2 = new ThreadExample();
        thread2.setPriority(3);
        ThreadExample thread3 = new ThreadExample();
        thread3.setPriority(5);
        ThreadExample thread4 = new ThreadExample();
        thread4.setPriority(7);

        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
    }
}
