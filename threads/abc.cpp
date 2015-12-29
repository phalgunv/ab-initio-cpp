#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<csignal>
#include <sys/syscall.h>
using namespace std;

class digital
{
	int s,m,h;
	public:
	digital():s(0),m(0),h(0)
	{
	}
	digital(int hour, int min, int sec):s(sec),m(min),h(hour)
	{
	}	
	void H()
	{
		h %= 24;
		h++;
	}

	void M()
	{
		if ( m == 59)
		H();
		m %= 60;
		m++;
	}

	void S()
	{
		while(1)
		{
		s %= 60;
		if(s == 59)
		M();
        getValues();
		s++;
		}
	}
    
    void getValues(){
        cout<<" h = "<<h<<"m = "<<m<<"s = "<<s<<endl;
        sleep(1);
    }

};
	static int sid4;
	digital *obj = new digital(0,0,0);
	digital *obj1 = new digital(12,34,56);
    pthread_t  p_thread, p_thread2, t3, t4;       /* thread's structure                     */
void*
do_loop(void* data)
{
    digital*  obj = ((digital *)data);     /* thread identifying number */
    /* terminate the thread */
	//cout << " "
	obj->S();
}

void sighandler(int signum)
{
//	cout << "received sigint.." << signum <<  endl;
    static int count;
   // cout<<"Before assigning values"<<endl;
   // obj1->getValues();
    if(count)
    {
        obj1 = obj;
 //   cout<<"After assigning values"<<endl;
    obj1->getValues();
    pthread_kill(t4, );
//    int id4 = pthread_create(&t4, NULL, do_loop, (void*)obj1);
  //  sleep(5);
    }
    if (count == 0) 
    count++;
//	sleep(5);
}

    
int main()
{
	signal(SIGINT,sighandler);	   
    pause();
    int  thr_id, thr_id2, id3, id4;         /* thread ID for the newly created thread */
    int t2;
    pthread_t p_thread4;

    /* create a new thread that will execute 'do_loop()' */
    thr_id = pthread_create(&p_thread, NULL, do_loop, (void*)obj);
    id4 = pthread_create(&t4, NULL, do_loop, (void*)obj1);
    sid4 = id4;
//	pid_t tid = (pid_t) syscall (SYS_gettid);
//	pid_t tid2 = (pid_t) ;
	
//	cout << tid << endl;
	 pthread_exit(NULL);
	//d.S();
}
