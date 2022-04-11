#include <stdio.h>      // for printf()
#include <unistd.h>     // for sleep()
#include <stdlib.h>
#include<string.h>
#include <time.h>

#define SECONDS 1000000
// 1 sec = 1000000 usec

int main() {
        time_t local_time;
        unsigned long int reading_count = 0;
        FILE *fp_temp, *fp_adc, *fp_write;
        char buff[8];

        while(1) {
                time(&local_time);
                char *t = ctime(&local_time);
                if (t[strlen(t)-1] == '\n') t[strlen(t)-1] = '\0';
                ++reading_count;
                fp_adc = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");    // voltageP9_39 -> /sys/bus/iio/devices/iio:device0/in_voltage0_raw
                fscanf(fp_adc, "%s", buff);
                // printf("\n---\nTime:%s", ctime(&local_time));
                //printf("%s\t", ctime(&local_time));
                //printf("\n{--reading: %ld--}\nvoltage : %s\n", reading_count, buff );
                printf("%s\t%ld\t%s\t",t, reading_count, buff );
                //fp_write = fopen("28Mar-bat_read2.txt", "aw");

                /* Write data to file */
                //fprintf(fp_write, "\n---\nTime:%s\n{--reading: %ld--}\n{voltage : %s}", ctime(&local_time), reading_count, buff );
                /* Close file to save file data */
                //fclose(fp_write);

                fp_temp = fopen("/sys/class/hwmon/hwmon0/temp1_input", "r");
                fscanf(fp_temp, "%s", buff);
                printf("%s\n", buff );

                //fp_write = fopen("4NOV-bat_read2.txt", "aw");

                /* Write data to file */
                //fprintf(fp_write, "\n{temperature: %s}\n", buff);
                 /* Close file to save file data */
                //fclose(fp_write);

                usleep(1*SECONDS);
                fclose(fp_temp);
                fclose(fp_adc);
        }
        return EXIT_SUCCESS;
}
