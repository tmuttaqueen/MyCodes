package threadlearning;

import java.util.LinkedList;
import java.util.Queue;
import java.util.logging.Level;
import java.util.logging.Logger;

//class Producer implements Runnable
//{
//    Queue<Integer> myq;
//    int max;
//    public Thread t;
//    
//    Producer( Queue<Integer> my, int ma )
//    {
//        myq = my;
//        max = ma;
//        t = new Thread(this);
//        t.start();
//    }
//    
//    public void run()
//    {
//        while(true)
//        {
//            synchronized(myq)
//            {
//                while( myq.size() >= max )
//                {
//                    try
//                    {
//                        myq.wait();
//                    }catch( InterruptedException e )
//                    {
//                        System.out.println(e);
//                    }
//                }
//                System.out.println("Producing: 10");
//                myq.add(10);
//                myq.notify();
//            }
//        }
//    }
//    
//}
//
//class Consumer implements Runnable
//{
//    Queue<Integer> myq;
//    int max;
//    public Thread t;
//    
//    Consumer( Queue<Integer> my, int ma )
//    {
//        myq = my;
//        max = ma;
//        t = new Thread(this);
//        t.start();
//    }
//    
//    public void run()
//    {
//        while(true)
//        {
//            synchronized(myq)
//            {
//                while( myq.size() <= 0 )
//                {
//                    try
//                    {
//                        myq.wait();
//                    }catch( InterruptedException e )
//                    {
//                        System.out.println(e);
//                    }
//                }
//                
//                System.out.println( "Consuming: " + myq.remove());
//                myq.notify();
//            }
//        }
//    }
//    
//}

class MyThread implements Runnable
{
    hold t;
    Integer s;
    Thread h;
    
    MyThread( hold x, int ss )
    {
        t = x;
        s = ss;
        h = new Thread(this);
        h.start();
    }
   
    public void run()
    {
        Integer sum = 0;
        for( Integer i = s+1; i <= s+250; i++ )
        {
            sum += i;
        }
        t.add(sum);
    }
    
}

class hold
{
    int t;
    hold()
    {
        t = 0;
    }
    synchronized void add(int x)
    {
        t += x;
    }
    void show()
    {
        System.out.println(t);
    }
}

public class ThreadLearning
{
    public static void main(String[] args)
    {
        hold t = new hold();
        MyThread m1 = new MyThread(t, 0);
         MyThread m2 = new MyThread(t, 250);
          MyThread m3 = new MyThread(t, 500);
           MyThread m4 = new MyThread(t, 750);
        try
        {
            m1.h.join();
            m2.h.join();
            m3.h.join();
            m4.h.join();
        } catch (InterruptedException ex)
        {
            Logger.getLogger(ThreadLearning.class.getName()).log(Level.SEVERE, null, ex);
        }
        t.show();
    }
}