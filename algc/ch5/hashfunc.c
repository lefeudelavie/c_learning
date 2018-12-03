#include <stdio.h>
#define Min (999)

typedef unsigned int Index;

    Index 
    Hash1 ( const char *Key, int TableSize) 
    {
        unsigned int HashVal = 0;
        while ( *Key != '\0')
            HashVal += *Key++;
        return HashVal % TableSize;
    }


    Index 
    Hash2 ( const char *Key, int TableSize) 
    {
        return (Key[0] + 27 * Key[1] + 729 * Key[2])
                    % TableSize;
    }


    Index 
    Hash3 ( const char *Key, int TableSize) 
    {
        unsigned int HashVal = 0;
        while ( *Key != '\0')
            HashVal = ( HashVal << 5 )+ *Key++;
        return HashVal % TableSize;
    }


int main(void)
{
    char *s1 = "john";
    char *s2 = "phil";
    char *s3 = "dave";
    char *s4 = "mary";
    
    printf("hash for %s is:%d\n", s1, Hash1(s1, 10));
    printf("hash for %s is:%d\n", s2, Hash1(s2, 10));
    printf("hash for %s is:%d\n", s3, Hash1(s3, 10));
    printf("hash for %s is:%d\n\n", s4, Hash1(s4, 10));
    
    printf("hash for %s is:%d\n", s1, Hash2(s1, 10));
    printf("hash for %s is:%d\n", s2, Hash2(s2, 10));
    printf("hash for %s is:%d\n", s3, Hash2(s3, 10));
    printf("hash for %s is:%d\n\n", s4, Hash2(s4, 10));


    printf("hash for %s is:%d\n", s1, Hash3(s1, 10));
    printf("hash for %s is:%d\n", s2, Hash3(s2, 10));
    printf("hash for %s is:%d\n", s3, Hash3(s3, 10));
    printf("hash for %s is:%d\n\n", s4, Hash3(s4, 10));
    
    int a = Min;
    char *s = "Min";
    printf("Min is:%d\n", a);
    printf("Min is:%s\n", s);

}
