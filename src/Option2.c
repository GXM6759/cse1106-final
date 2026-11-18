#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>

#define PIN 17

int main(void)
{
	int count = 0;
	int max = 5;
	int input;
	
	gpioInitialise();
	gpioSetMode(PIN, PI_OUTPUT);
	gpioWrite(PIN, 0);
	
	while (1)
	{
		
		printf("Are you entering or leaving?\n1 for entering or 2 for leaving: ");
		scanf("%d", &input);
		
		if (input == 1 && count < max)
		{
			count++;
		}
		else if (input == 2 && count > 0)
		{
			count--;
		}
		
		if (count == max)
		{
		gpioWrite(PIN,1);
		}
		else if (count < max)
		{
		gpioWrite(PIN,0);
		}
		
		printf("\ncurrent number of students: %d\n", count);
		printf("enter 3 to exit program\n\n");
	
		if (input == 3)
		{
		return 0;
		}

}
	gpioTerminate();

	return 0;
}
