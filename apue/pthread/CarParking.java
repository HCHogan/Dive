import java.util.Random;
import java.util.concurrent.Semaphore;

public class CarParking {
	private static Semaphore semaphore = new Semaphore(10);

	public static void main(String[] args) {

		for(int i = 1; i <= 100; i++) {
			Thread thread = new Thread(new Runnable() {
				@Override
				public void run() {
					System.out.println("hehe" + Thread.currentThread().getName() + "nmsl");
					if(semaphore.availablePermits() == 0) {
						System.out.println("gun");
					}
					try {
						semaphore.acquire();
						System.out.println(Thread.currentThread().getName() + "sibusi");
						// Thread.sleep(new Random().nextInt(10000));
						System.out.println(Thread.currentThread().getName() + "gunned");
						semaphore.release();
					} catch(InterruptedException e) {
						e.printStackTrace();
					}
				}
			}, i + "hao");
	
			thread.start();
		}
	}
}
