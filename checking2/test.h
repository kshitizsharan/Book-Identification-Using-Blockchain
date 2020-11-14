#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED



#endif // TEST_H_INCLUDE
/*
	A demo of reading the entire contents of a file. Other than
	"echoing" the contents of the file to the console this program
	does do anything useful.

	The program assumes we have a file called test.dat in the same
	directory as the executible.

	M. Kesson
	4.12.03
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void)
{
/* declare a file pointer */
FILE    *infile;
char    *buffer;
long    numbytes;

/* open an existing file for reading */
infile = fopen("anything.txt", "r");

/* quit if the file does not exist */
if(infile == NULL)
    return 1;

/* Get the number of bytes */
fseek(infile, 0L, SEEK_END);
numbytes = ftell(infile);

/* reset the file position indicator to
the beginning of the file */
fseek(infile, 0L, SEEK_SET);

/* grab sufficient memory for the
buffer to hold the text */
buffer = (char*)calloc(numbytes, sizeof(char));

/* memory error */
if(buffer == NULL)
    return 1;

/* copy all the text into the buffer */
fread(buffer, sizeof(char), numbytes, infile);
fclose(infile);

/* confirm we have read the file by
outputing it to the console */
printf("The file called test.dat contains this text\n\n%s", buffer);

/* free the memory we used for the buffer */
free(buffer);

return 0;
}
