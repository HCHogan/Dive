## Mesa semantic
the signal only indicated that some changes happened, but it won't make sure that situation will last until they were runned by the operating system.
So, always use the while loop.
消费者不应该唤醒消费者,而应该只唤醒生产者,反之亦然
所以有的时候要用多个条件变量

## 提示:对条件变量使用 while(不是 if)
多线程程序在检查条件变量时，使用 while 循环总是对的。if 语句可能会对，这取决于发信号的语义。因此，总是使用 while，代码就会符合预期。对条件变量使用 while 循环，这也解决了假唤醒(spurious wakeup)的情况。某些线程库中，由于实现的细节，有可能出现一个信号唤醒两个线程的情况[L11]。再次检查线程的等待条件，假唤醒是另一 个原因。
