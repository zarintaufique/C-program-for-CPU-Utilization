# C-program-for-CPU-Utilization

C Program to find out the Average CPU Utilization Percentage in Linux System over the entire time your program is executing.
You can read the first line of the file named stat having the path “/proc/stat” to get the string depicting the CPU usage. It will look like this:  cpu %user %nice %system %idle %iowait %irq %softirq  You will then parse the string to extract the relevant information and print it out on the terminal. As this file keeps on getting updated, so you have to keep on reading the file in an infinite loop, process the information and then print the Average CPU utilization percentage on the terminal.
You have to read the two samples with a gap of 1.00 sec and find out the average CPU utilization percentage over these two intervals with this sequence repeating indefinitely.
