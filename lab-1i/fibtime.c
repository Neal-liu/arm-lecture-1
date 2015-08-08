#include <stdio.h>
#include <time.h>

extern int fibonacci(int x, int a, int b);
int NanoTime();
void Iteration(int);
static int iteration = 10000;

//struct timespec {
//	time_t   tv_sec;        /* seconds */
//	long     tv_nsec;       /* nanoseconds */
//};

int main(int argc, char **argv)
{
	int i;
	for(i = 0 ; i<47 ; i++)
		Iteration(i);

}

void Iteration(number)
{
	int j;
	int result = 0;
	int starttime = 0;
	int endtime = 0;
	int average = 0;
	int total = 0;
	FILE *f = fopen("time_recursive", "a+");	// a+ : read and write file without overwriting. 

	if(f == NULL){
		printf("CANNOT OPEN FILE !\n");
		exit(1);
	}

		for(j = 0 ; j<iteration ; j++){
			starttime = NanoTime();
			printf("start time is %d\n", starttime);
			result = fibonacci(number, 0, 1);   
			endtime = NanoTime();
			printf("endtime time is %d\n", endtime);
			if(starttime != 0){
				total += (endtime-starttime);
//				printf("total is %d\n", total);
			}
		}
		average = total/iteration;
		printf("take %ld nanoseconds\n", average);
		fprintf(f, "%ld\n", average);
		printf("The fibonacci sequence at %d is: %d\n", number, result);
		printf("number is %d\n", number);

	fclose(f);

}

int NanoTime()
{
	struct timespec t;
	t.tv_sec = t.tv_nsec = 0;
	clock_gettime(CLOCK_REALTIME, &t);
	return t.tv_sec * 1000000000LL + t.tv_nsec;
}
