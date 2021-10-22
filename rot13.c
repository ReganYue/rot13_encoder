#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
bool input_key() {
	char *input;
	char *key = "rot13";
	scanf("%s",input);
	if(!strcmp(key,input)) {
		return true;
	} else {
		return false;
	}
}

char ch_to_rot13 ( char ch ) {
	char rot13;
	/*
	[0:4] -> [5:9]
	*/
	if ( '0' <= ch && ch <= '4' ) {
		rot13 = ch + 5;
	}
	/*
	[5:9] -> [0:4]
	*/
	else if ( '5' <= ch && ch <= '9' ) {
		rot13 = ch - 5;
	}
	/*
	[A:M] -> [N:Z]
	*/
	else if ( 'A' <= ch && ch <= 'M' ) {
		rot13 = ch + 13;
	}
	/*
	[N:Z] -> [A:M]
	*/
	else if ( 'N' <= ch && ch <= 'Z' ) {
		rot13 = ch - 13;
	}
	/*
	[a:m] -> [n:z]
	*/
	else if ( 'a' <= ch && ch <= 'm' ) {
		rot13 = ch + 13;
	}
	/*
	[n:z] -> [a:m]
	*/
	else if ( 'n' <= ch && ch <= 'z' ) {
		rot13 = ch - 13;
	} else {
		rot13 = ch;
	}

	return rot13;
}

char *s_to_rot13 ( char *s1 ) {
	int s_len;
	char *s2;
	char *c2;

	s_len = strlen ( s1 );

	s2 = ( char * ) malloc ( ( s_len + 1 ) * sizeof ( char ) );
	c2 = s2;

	while ( *s1 != 0 ) {
		*c2 = ch_to_rot13 ( *s1 );
		s1++;
		c2++;
	}
	*c2 = '\0';

	return s2;
}

void handle ( char *input_filename, char *output_filename ) {
	FILE *input;
	FILE *output;

	input = fopen ( input_filename, "rt" );
	if ( !input ) {
		printf ( "\n" );
		printf ( "ROT13::HANDLE - Fatal error!\n" );
		printf ( "  Cannot open the input file \"%s\".\n", input_filename );
		return;
	}

	output = fopen ( output_filename, "wt" );
	if ( !output ) {
		printf ( "\n" );
		printf ( "ROT13::HANDLE - Fatal error!\n" );
		printf ( "  Cannot open the output file \"%s\".\n", output_filename );
		return;
	}

	while ( true ) {
		char c1 = getc ( input );
		if ( c1 == EOF ) {
			break;
		}
		char c2 = ch_to_rot13 ( c1 );
		putc ( c2, output );
	}
}

int main() {

	char input_filename[512];
	char *output_filename;
	printf("Please input the filename you want to encrypt:\n");

	printf("Please input key:");
	if(input_key()) {
		printf("Please input the encrypted filename:");
	} else {
		printf("Error!");
		return 0;
	}

	scanf ( "%s", input_filename );
	output_filename = s_to_rot13 ( input_filename );
	handle ( input_filename, output_filename );

}
