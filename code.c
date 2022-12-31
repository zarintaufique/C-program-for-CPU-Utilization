#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// main starts here
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
	
		//now converting all the variables
		int vars[7];
		int u = 0;
		for(u = 0;u < 7;u++){
			vars[u] = atoi(word[u]);
			
		}
		//calculating total
		double total = 0;
		int t = 0;
		for(t = 0;t < 7;t++){
			total = total + vars[t];
			
		}
		//calculating without idle time
		double idl = 0.00;
		idl = total - vars[3];
		idl = idl - vars[4];
		
		
		double prc = 0.0f;
		prc = idl/total;
		
		
		sleep(1);
		//////////////////////////////////////////////////////////////////
		
			
		FILE* fp1;
		fp1 = fopen("/proc/stat", "r");
		if (fp1 == NULL) {
			printf("File can't be opened.\n");
		}
		else {
		//read upto first line
			while ((ch = fgetc(fp1)) != '\n') {
				sentence[index] = ch;
				ch = fgetc(fp1);
				index++;
				sentence[index] = ch;
				index++;
			}
			sentence[index++] = '\0';
			fclose(fp1);
		}

	
		int ind2 = 0;
		//to ignore the words like cpu and spaces
		while(sentence[ind2] < 48 || sentence[ind2] > 57){
			ind2++;
		}
		int length2 = strlen(sentence);
		char word2[7][100];
		j = 0,k = 0;
		for(j = 0;j < 7;j++){
			for(k = 0;sentence[ind2] != ' ';k++){
				if(sentence[ind2] > 47 && sentence[ind2] < 58){
					word2[j][k] = sentence[ind2]; 
				}
				ind2++;
			}
				ind2++;	
		}
	//now converting all the variables
		int vars2[7];
		int u2 = 0;
		for(u2 = 0;u2 < 7;u2++){
			vars2[u2] = atoi(word2[u2]);
		}
		//calculating total
		double total2 = 0;
		int t2 = 0;
		for(t2 = 0;t2 < 7;t2++){
			total2 = total2 + vars2[t2];
		}
		
		//calculating without idle time
		double idl2 = 0;
		idl2 = total2 - vars2[3];
		idl2 = idl2 - vars2[4];
	
		double prc2 = 0;
		prc2 = idl2/total2;
		//printf("%d\n", vars[u]);
	
		//calculating average
		double avg = prc + prc2;
		avg = avg/2;
		
		printf("%f\n", avg);
	}
	
	return 0;
}

