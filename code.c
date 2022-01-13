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

	
		int ind = 0;
		//to ignore the words like cpu and spaces
		while(sentence[ind] < 48 || sentence[ind] > 57){
			ind++;
		}
		int length = strlen(sentence);
		char word[7][100];
		int j = 0,k = 0;
		for(j = 0;j < 7;j++){
			for(k = 0;sentence[ind] != ' ';k++){
				if(sentence[ind] > 47 && sentence[ind] < 58){
					word[j][k] = sentence[ind]; 
				}
				ind++;
			}
				ind++;	
		}
	
