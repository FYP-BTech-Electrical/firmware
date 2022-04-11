# BBB
## components:
- Resistor Load = 100ohm
- Voltage divider = 6k : 6k
The circuit connections are made as shown in the diagram below:

![](/media/31OCT-BBB-CONN.jpeg)


**current sensor 0 voltage:**
```
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
787
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
795
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
795
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
791
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
792
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
788
debian@beaglebone:~/fyp$ cat /sys/bus/iio/devices/iio:device0/in_voltage1_raw
796
```
