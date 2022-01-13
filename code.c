#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char ch = '\0';
	char sentence[300];
	int index = 0;
	int i = 0;

	while(1){
		FILE* fp;
		fp = fopen("/proc/stat", "r");
		if (fp == NULL) {
			printf("File can't be opened.\n");
		}
		else {
		//read upto first line
			while ((ch = fgetc(fp)) != '\n') {
				sentence[index] = ch;
				ch = fgetc(fp);
				index++;
				sentence[index] = ch;
				index++;
			}
			sentence[index++] = '\0';
			fclose(fp);
		}
