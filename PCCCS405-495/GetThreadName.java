class ThreadExample extends Thread {
    public void run() { System.out.println("Thread name: " + this.getName()); }

    public static void main(String[] args) {
        ThreadExample thread = new ThreadExample();
        thread.start();
    }
}
