/**************************************************************************** 
 
                                                                   Your name 
                                                        Course name, quarter 
                                                                Today's date 
                                                            Your cs12x login 
                Assignment One 
 
File Name:  hw1.c 
Description:    This program tests functions to display output strings and  
        numbers.  
****************************************************************************/  
  
#define COUNT ((long) (sizeof (long) << 1 ))  /* number of hex digits to display */  
#define DECIMAL 10  /* to indicate base 10 */  
#define HEX 16      /* to indicate base 16 */  

#include <stdio.h>  


/* array used for ASCII conversion */  
const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
  
/*-------------------------------------------------------------------------- 
Function Name:         List the function name. 
Purpose:               Say why the function exists in a sentence or two. 
Description:           Describe the underlying algorithm of how the function 
                       is implemented in a few sentences. 
Input:                 A list of the parameters with brief explanation of each. 
Result:                A list of possible outcomes when the function is called. 
                       Describe return value. 
--------------------------------------------------------------------------*/  
void baseout (long number, long base, FILE * stream) {  
    /* YOUR CODE GOES HERE */
             
	// test
    //printf("%li\n", number);
    //printf("base  = %li\n",base);
    // test

    // buffer
    char  result[1024];
	char * pto_result = result;
    
    int idx = 0;
    while(number / base > 0) {
	    
        result[idx] = digits[(int)(number % base)];
        idx++;
        //printf("%s\n", result);
        
        number = number / base;
    } // end of while(number / base > 0)
    //printf("idx = %d", idx);
    
    // residul treatment
    result[idx] = digits[(int)(number % base)];
    //printf("%s\n", result);
    //printf("%lu\n", strlen(result));

    if(base == 16) {

        for (int i = 15; i >= 0; i--) {    
            if (i < (idx + 1)) {
                fprintf(stream, "%c", result[i]);
            } else {
                fprintf(stream, "%c", '0');
            }
        }

    } // end of if(base == 16)

} // end of void baseout (long number, long base, FILE * stream)
  
  
/*-------------------------------------------------------------------------- 
Function Name:         List the function name. 
Purpose:               Say why the function exists in a sentence or two. 
Description:           Describe the underlying algorithm of how the function 
                       is implemented in a few sentences. 
Input:                 A list of the parameters with brief explanation of each. 
Result:                A list of possible outcomes when the function is called. 
                       Describe return value. 
--------------------------------------------------------------------------*/  
void decout (unsigned long number, FILE * stream) {  
    /* YOUR CODE GOES HERE */  
}  
  
/*-------------------------------------------------------------------------- 
Function Name:         List the function name. 
Purpose:               Say why the function exists in a sentence or two. 
Description:           Describe the underlying algorithm of how the function 
                       is implemented in a few sentences. 
Input:                 A list of the parameters with brief explanation of each. 
Result:                A list of possible outcomes when the function is called. 
                       Describe return value. 
--------------------------------------------------------------------------*/  
void newline (FILE * stream) {  
    /* YOUR CODE GOES HERE */
    fprintf(stream, "\n");
}  
  
  
/*-------------------------------------------------------------------------- 
Function Name:         writeline 
Purpose:               to  
Description:           Describe the underlying algorithm of how the function 
                       is implemented in a few sentences. 
Input:                 A list of the parameters with brief explanation of each. 
Result:                A list of possible outcomes when the function is called. 
                       Describe return value. 
--------------------------------------------------------------------------*/  
  
long writeline (const char * message, FILE * stream) {  
    /* YOUR CODE GOES HERE */  
	int index = 0;  /* to track use of message array*/
	
	/*print message char by char */
	while(message[index] != 0){
		
		/*print one character of message */
		fputc(message[index], stream);
		index++;
	} 

	index += 1;
	return   index;
}  


  
/*-------------------------------------------------------------------------- 
Function Name:         hexout 
Purpose:               Prints a number in base 16 to the parameter FILE stream 
Description:           Goal is achieved via delegating to the baseout function 
Input:                 number: the number to display 
                       stream: where to display, likely stdout or stderr 
Result:                Number in base 16 is displayed. 
                       No return value. 
--------------------------------------------------------------------------*/  


void hexout (unsigned long number, FILE * stream) {  
  
    /* Output "0x" for hexidecimal. */  
    writeline ("0x", stream);  
    baseout (number, HEX, stream);  
}  
  
int main (int argc, char *const* argv) {  
    writeline ("Hello World", stdout);  
    writeline ("Zdravei Sviat", stderr);  
    newline(stderr);  
    newline(stdout);  
    decout (123, stdout);  
    newline(stdout);  
    decout (0, stdout);  
    newline(stdout);  
    hexout (0xFEEDDAD, stdout);  
    newline(stdout);  
    return 0;  
} 
 
