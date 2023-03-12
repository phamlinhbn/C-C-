#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Exercise 1
void Convert_to_Binary(char* arr)
{
    uint8_t Dec[50]; 
    uint8_t Bit[7];

    for(int i = 0; i < strlen(arr); i++)
    {
        //convert each char to ASCII value
        Dec[i] = (int) arr[i]; 
        
        if(Dec[i] == 32)
        {
            printf("\n");
            continue;
        }

        printf("%c: = ",arr[i]); 

        //Convert ASCII value to binary
        for(int j = 7; j >= 0;j--)
        {  
            Bit[j]=Dec[i]%2;  
            Dec[i]=Dec[i]/2;  
        }
        //print as char as binary value
        for(int k =0; k <= 7; k++)  
        {
            printf("%d", Bit[k]);
        }

        printf("\n"); 
    }
}
//Excerise 2
typedef union
{
    char data_frame[12];
    struct
    {
        char uID[4];
        char Data[8];
    }frame;
}frame_nfc;


char* Transmit(char* uid, char* data)
{
    frame_nfc nfc;
    strcpy(nfc.frame.uID, uid);
    strcpy(nfc.frame.Data, data);
    printf("\nData transmit: %s\n", nfc.data_frame);
}

int main()
{
    char arr[50] = "Hello Word";
    
    printf("----------Exercise 1----------\n");
    printf("Convert \"%s\" to binary\n", arr);
    Convert_to_Binary(arr);
    printf("\n----------Exercise 2----------");
    Transmit((char*)"1101", (char*)"123456778");
    return 0;
}