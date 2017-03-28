#include<iostream>
#include<omp.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>


using namespace std;


int main(void) {

int threadid;

#pragma omp parallel num_threads(8) private(threadid)
	{
		threadid = omp_get_thread_num();
	    printf("Hello from thread %d\n", threadid);
	    // Only the master thread executes this:
	    #pragma omp master
		    {
		    	printf("Master Thread %d executing single block \n", threadid);
		    }
	    printf("Past the master block on thread %d\n", threadid);

}
	return 0;
}