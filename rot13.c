#include<stdio.h>
#include<stdbool.h>
bool input_key(){
	char *input;
	char *key = "rot13"; 
	scanf("%s",input);
	if(!strcmp(key,input)){
		return true;
	} else {
		return false;
	}
}

int main(){

	char input_filename[512];
	char output_filename[512];
	printf("Please input the filename you want to encrypt:")
	scanf ( "%s", input_filename );
	
	printf("Please input key:");
	if(input_key()){
		printf("Please input the encrypted filename:");
	} else {
		printf("Error!");
		return 0;
	}
	
	scanf ( "%s", input_filename );
	output_filename = s_to_rot13 ( input_filename );
}