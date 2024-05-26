class ThreadExample extends Thread {
    public void run() {
        System.out.println("Thread is running...");
        try {
            Thread.sleep(2000); // Sleep for 2 seconds
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        ThreadExample thread = new ThreadExample();
        System.out.println("Is thread alive before start? " + thread.isAlive());
        thread.start();
        System.out.println("Is thread alive after start? " + thread.isAlive());
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Is thread alive after join? " + thread.isAlive());
    }
}
