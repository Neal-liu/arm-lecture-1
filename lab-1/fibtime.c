#include <stdio.h>
#include <time.h>

extern int fibonacci(int x);
static int iteration = 1000;
int NanoTime();
void Iteration(int);
//struct timespec {
//	time_t   tv_sec;        /* seconds */
//	long     tv_nsec;       /* nanoseconds */
//};

int main(int argc, char **argv)
{
	int i = 0;
	for(i = 0 ; i<47 ; i++){	
		Iteration(i);
	}

}

void Iteration(number)
{
	int j;
	int result = 0;
	int starttime = 0;
	int endtime = 0;
	float average = 0;
	int total = 0;
	FILE *f = fopen("time", "a+");	// a+ : read and write file without overwriting. 

	if(f == NULL){
		printf("CANNOT OPEN FILE !\n");
		exit(1);
	}

		for(j = 0 ; j<iteration ; j++){
			starttime = NanoTime();
			printf("start time is %d\n", starttime);
			result = fibonacci(number);   
			endtime = NanoTime();
			printf("endtime time is %d\n", endtime);
			if(starttime != 0){
				total += (endtime-starttime);
//				printf("total is %d\n", total);
			}
		}
		average = (float)total/(float)iteration;
		printf("take %f nanoseconds\n", average);
		fprintf(f, "%f\n", average);
		printf("The fibonacci sequence at %d is: %d\n", number, result);
		printf("number is %d\n", number);

	fclose(f);

}

int NanoTime(void)
{
	struct timespec t;
	t.tv_sec = t.tv_nsec = 0;
	clock_gettime(CLOCK_MONOTONIC, &t);
//	return t.tv_nsec;
	return t.tv_sec * 1000000000LL + t.tv_nsec;
}
