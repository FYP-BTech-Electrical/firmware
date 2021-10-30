#include <stdio.h>      // for printf()
#include <unistd.h>     // for sleep()
 
int main() {
 
        FILE *fp;
        char buff[8];
 
        while(1) {
        fp = fopen("/sys/class/hwmon/hwmon0/temp1_input", "r");
        fscanf(fp, "%s", buff);
        printf("temperature = %s\n", buff );
        sleep(2);
        fclose(fp);
        }
        return 0;
}
