/* 
 * output the No.4263116 prime
 * The answeris:7262 1257
*/

//header files
#include <stdio.h>   //for printf()
#include <stdlib.h>  //for calloc()
#include <time.h>    //for time_t
#include <math.h>    //for squrt()

//macro definition
#define MAX_NUM    (100000000)
#define TARGET_NO  (4263116)

//sub functions
long getPrimebyNo(long index, long maxNum)
{
    char *num;
    long i,j,k,m;
    long loopNum;
    
    num = (char*)calloc(sizeof(char),maxNum);
    loopNum = sqrt(maxNum);
    k = 1;
    for (i = 3; i < maxNum; i+=2) //+2 to ignore all the even numbers.
    {
        if((num[i] == 1)) //find the smallest one that not marked with "1", and it is a prime.
        {
            continue;
        }
        k+=1;
        if(k == index)
        {
            break;
        }
        if(i <= loopNum)
        {
            m=i*i;
            for (j = m; j < maxNum; j+= (i+i)) //mark the composite numbers, the number larger than target number are useless.
            {
                num[j] = 1;//this is a composite number and it is an odd number.
            }
        }
    }
    free(num);
    return i;
}

long getPrimebyNo2(long index, long maxNum)
{
    char *num;
    long i,j,count,k,m;
    long half=sqrt(maxNum);
    num = (char*)calloc(sizeof(char), maxNum);
    count=2;
    k=5;
    for(i = 3; i < half; i+=2)
    {
        if(num[i] == 1)
        {
            continue;
        }
        m = i+i;
        for(j=m+i; j < maxNum; j+=m )
        {
            num[j] = 1;
        }
        m = i*i;
        for(j=k; j < m; j+=2)
        {
            if(num[j] == 0) 
            {
                count+=1;
            }
            if(count == index )
            {
                return j;
            }
        }
        k=m+2;
    }
    free(num);
    return 0;
}

//main function
int main(void)
{
    time_t beginT, endT;
    
    beginT=clock();
    printf("%ld.\n", getPrimebyNo(TARGET_NO, MAX_NUM));
    //printf("%ld.\n", getPrimebyNo2(TARGET_NO, MAX_NUM));
    endT=clock();
    printf("the consumed time: %ldms.\n", endT-beginT);
    return 0;
}
