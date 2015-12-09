#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<csignal>
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
		cout << h << ":" << m << ":" << s << endl;sleep(2);
		if(s == 59)
		M();
		s++;
		}
	}

};

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
	cout << "received sigint.." << signum <<  endl;
//	sleep(5);
}
int main()
{
	signal(SIGINT,sighandler);	   
	digital *obj = new digital();
	digital *obj1 = new digital(12,34,56);
    int  thr_id, thr_id2, id3, id4;         /* thread ID for the newly created thread */
    pthread_t  p_thread, p_thread2, t3, t4;       /* thread's structure                     */

    /* create a new thread that will execute 'do_loop()' */
    thr_id = pthread_create(&p_thread, NULL, do_loop, (void*)obj);
    id4 = pthread_create(&t4, NULL, do_loop, (void*)obj1);
    pthread_exit(NULL);
	//d.S();
}
