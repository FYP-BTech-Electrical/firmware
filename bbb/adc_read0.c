#include <stdio.h>      // for printf()
#include <unistd.h>     // for sleep()
 
int main() {
 
        FILE *fp;
        char buff[8];
 
        while(1) {
        fp = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");    // voltageP9_39 -> /sys/bus/iio/devices/iio:device0/in_voltage0_raw
        fscanf(fp, "%s", buff);
        printf("value : %s\n", buff );
        sleep(0.2);
        fclose(fp);
        }
        return 0;
}
