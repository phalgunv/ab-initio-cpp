#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<csignal>
#include <sys/syscall.h>
using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
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
		s %= 60;
		getValues();
		if(s == 59)
			M();
		s++;
	}

	void getValues(){
		cout<<" h = "<<h<<"m = "<<m<<"s = "<<s<<endl;
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
	while(1){	
		cout <<"Thread id: " <<  (unsigned int)pthread_self()<<"obj pointing to "<<obj <<endl;
		/* terminate the thread */
		obj->S();
		sleep(1);
	}
}

void sighandler(int signum)
{
	cout << "received sigint.." << signum <<  endl;
	static int count;
	cout<<"Before assigning values"<<endl;
	obj1->getValues();
	if(count)
	{
		// *obj1=(*obj);
		obj1->operator=(*obj);
		cout<<"After assigning values"<<endl;
		obj1->getValues();
	}
	if (count == 0) 
		count++;
}


int main()
{
	cout <<"obj  add"<<obj<<endl;
	cout <<"obj 1 add"<<obj1<<endl;
	signal(SIGINT,sighandler);	   
	pause();
	int  thr_id, thr_id2, id3, id4;         /* thread ID for the newly created thread */
	int t2;
	pthread_t p_thread4;
	/* create a new thread that will execute 'do_loop()' */
	thr_id = pthread_create(&p_thread, NULL, do_loop, (void*)obj);
	id4 = pthread_create(&t4, NULL, do_loop, (void*)obj1);
	sid4 = id4;
	pthread_join(p_thread,NULL);
	pthread_join(t4,NULL);
	pthread_exit(NULL);
}
