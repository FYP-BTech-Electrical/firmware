#include <stdio.h>      // for printf()
#include <unistd.h>     // for sleep()
#include <stdlib.h>

#define SECONDS 1000000	
// 1 sec = 1000000 usec

int main() {
	unsigned long int reading_count = 0;
	FILE *fp_temp, *fp_adc, *fp_write;
	char buff[8];

	while(1) {
		++reading_count;
		fp_adc = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");    // voltageP9_39 -> /sys/bus/iio/devices/iio:device0/in_voltage0_raw
		fscanf(fp_adc, "%s", buff);
		printf("\n{--reading: %ld--}\nvalue : %s\n", reading_count, buff );
		fp_write = fopen("bat_read1.txt", "aw");

		/* Write data to file */
		fprintf(fp_write, "\n{--reading: %ld--}\n{voltage : %s}", reading_count, buff );
		/* Close file to save file data */
		fclose(fp_write);

		fp_temp = fopen("/sys/class/hwmon/hwmon0/temp1_input", "r");
		fscanf(fp_temp, "%s", buff);
		printf("temperature = %s\n", buff );

		fp_write = fopen("bat_read1.txt", "aw");

		/* Write data to file */
		fprintf(fp_write, "\n{temperature: %s}\n", buff);
		/* Close file to save file data */
		fclose(fp_write);
		
		usleep(1.5*SECONDS);
		fclose(fp_temp);
		fclose(fp_adc);
	}
	return EXIT_SUCCESS;
}
