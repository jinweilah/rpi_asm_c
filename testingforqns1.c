#include <stdio.h>
#include <math.h>

 typedef union Converter {   /* union as all use the same memory of 32 bits in float */
    float start;
    struct{                 /* Split into 3 parts starting from the LSB */
                            /* Used unsigned int as the values in the mantissa,exponent and sign is always positive and always integer */
        
        unsigned int m :23;  /* mantissa(23 bits) */
        unsigned int e :8;   /* exponent(8 bits) */
        unsigned int s :1;   /* sign(1 bit) */
        }point;
}floating;

unsigned int binarytoint(int IEEE[], int msb, int lsb);
int binarynum(int a, int b);

int main()
{
    floating num; /* To instatiate the union created */
    int a;
    
    /*Please input converter choice number 1 or 2 only*/
    printf("Enter convert choice 1)Decimal num to IEEE 754 binary floating num 2)IEEE 754 binary floating num to Decimal num: "); 
    scanf("%d", &a); 

    if(a==1)/* If user choose option 1 */
    {
    
    printf("Enter the decimal number to be converted into IEEE754 binary: "); /*Please input float range number only*/
    scanf("%f", &num.start/* Store integer in union float start */);

    printf("The input of decimal number is: %g \n",num.start);
    printf("After conversion, the 1-bit sign bit is: %d \n",num.point.s);
    printf("The actual exponent is: %d",num.point.e-127); /* Take the biased exponent and minus 127 to get actual exponent */
    printf("\nThe 8-bit biased exponent is: ");
    binarynum(num.point.e, 8); /* Go to function to print out the 8-bits binary in exponent */
    printf("\nThe 23-bit fraction is: ");
    binarynum(num.point.m, 23);/* Go to function to print out the 23-bits binary in mantissa */
    printf("\nThe 32-bit fraction is: ");
    binarynum(num.point.s, 1);/* Go to function to print out the 1-bit binary in sign */
    printf(" ");              /* Space */
    binarynum(num.point.e, 8);/* Go to function to print out the 8-bits binary in exponent */
    printf(" ");              /* Space */
    binarynum(num.point.m, 23);/* Go to function to print out the 23-bits binary in mantissa */
}
    else if(a==2) /* If user choose option 2 */
    {
        char string[32];
         printf("Enter the 32-bit IEEE754 binary to be converted into decimal number:");/* Store it as character in a string first to let user input the 32bits*/
         scanf("%s",&string);
        
         int IEEE[32];
         int x;

        for(x=0;x<32;x++)
	{
		 IEEE[x] = string[x] - '0';/* Convert the values in character array to interger and store it in the integer array */
	}
        
        printf("IEEE 754 floating point input:");
        for(x=0;x<32;x++)
        {
        printf("%d",IEEE[x]); /* Print out the whole input */
        }
        printf("\nBefore conversion, the 1-bit sign bit is:%d ",IEEE[0]);/* Print out the first array number for sign bit */
        printf("\nThe 8-bit biased exponent is:");
        for(x=1;x<9;x++)      /* Print out the number from array 1 to 8 which is the exponent part */
        {
        printf("%d",IEEE[x]);
        }

        num.point.m = binarytoint(IEEE, 9, 31); /* Go to function to convert binary into corresponding integer value for mantissa part and store it in int m in the union */
        num.point.e = binarytoint(IEEE, 1, 8);  /* Go to function to convert binary into corresponding integer value for exponent part and store it in int e in the union */
        num.point.s = IEEE[0];/* Store the sign bit into int s in the union */

        printf("\nThe actual exponent is:%d",num.point.e-127);/* Use the integer value store in num.point.e which is the biased exponent value and minus 127 to get the actual exponent value */

        printf("\nThe 23-bit fraction is:");
        for(x=9;x<32;x++)        /* Print out the number from array 9 to 31 which is the mantissa part */
        {
        printf("%d",IEEE[x]);
        }
        
        /* Based on the values store in int m, int e and int s which is the matissa, exponent and sign values, we will able to get the decimal number value store in float start */
        printf("\nAfter conversion the decimal number is:%g",num.start);/* use %g to remove trailing zeros */
    }
}
int binarynum(int a, int b) /* Function to print out the binary representation for mantissa, exponent and sign */
{
    int c;
    for (b--; b>= 0;b--)
    {
        c = a >> b; /* Shift the MSB all the way to the LSB first, then slowly reduce the shift by 1 each time */
        if(c&1)            /* Check the LSB and print out the corresponding binary */
            printf("1");   /* If binary is 1 it will print out 1 */
            else
            printf("0");   /* If binary is not 1 it will print out 0 */
         }
}
unsigned int binarytoint(int IEEE[]/*pointer to array*/, int msb, int lsb)
/* Function to change binary array into corresponding integer representation for mantissa, exponent and sign */
{
    unsigned sum = 0;
    unsigned s;
    for (s = lsb; s >= msb; s--) {        
        sum += IEEE[s] * pow(2, lsb - s); /* Convert the binary representation to decimal number */
    }
    return sum;
}
    
    

    





