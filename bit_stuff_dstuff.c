#include <stdio.h>

int main()
{
    char option;
    int M1;
    int i1;
    printf("  A.for stuffing\n  B.for destuffing\n  C. Code for flag ");
    scanf("%c", &option);

    switch(option)

    {
    case 'A':
{

    printf("enter the no of bits to be stuffed\n");
    scanf("%d",&M1);
    int arry1[M1];
    printf("enter the values of data\n");
    for(i1=0; i1<M1; i1++)
    {
        scanf("%d", &arry1[i1]);
    }

    int str1[40];

    // Variables to traverse arrays
    int j1, k1;
    i1 = 0;
    j1 = 0;

    // Stores the count of consecutive ones
    int count1 = 1;

    // Loop to traverse in the range [0, N)
    while (i1 < M1) {

        // If the current bit is a set bit
        if (arry1[i1] == 1) {

            // Insert into array str[]
            str1[j1] = arry1[i1];

            // Loop to check for
            // next 5 bits
            for (k1 = i1 + 1;
                 arry1[k1] == 1
                 && k1 < M1
                 && count1 < 5;
                 k1++) {
                j1++;
                str1[j1] = arry1[k1];
                count1++;

                // If 5 consecutive set bits
                // are found insert a 0 bit
                if (count1 == 5) {
                    j1++;
                    str1[j1] = 0;
                }
                i1 = k1;
            }
        }
        // Otherwise insert arry[i] into
        // the array str[]
        else {
            str1[j1] = arry1[i1];
        }
        i1++;
        j1++;
    }

    // Printing answer
    for (i1 = 0; i1 < j1; i1++){
        printf("%d", str1[i1]);
    }
    return 0;
    break;
    }


  case 'B':
   {
    int M2;
    int i2;
    printf("enter the no of bits to be stuffed\n");
    scanf("%d",&M2);
    int arry2[M2];
    printf("enter the values of data\n");
    for(i2=0; i2<M2; i2++)
    {
        scanf("%d", &arry2[i2]);
    }

    // Stores the de-stuffed array
    int str2[40];

    // Variables to traverse the arrays
    int j2, k2;
    i2 = 0;
    j2 = 0;

    // Stores the count of consecutive ones
    int count2 = 1;

    // Loop to traverse in the range [0, M)
    while (i2 < M2) {

        // If the current bit is a set bit
        if (str2[i2] == 1) {

            // Insert into array str[]
            str2[j2] = str2[i2];

            // Loop to check for
            // the next 5 bits
            for (k2 = i2 + 1;
                 arry2[k2] == 1
                 && k2 < M2
                 && count2 < 5;
                 k2++) {
                j2++;
                str2[j2] = arry2[k2];
                count2++;

                // If 5 consecutive set
                // bits are found skip the
                // next bit in arry[]
                if (count2 == 5) {
                    k2++;
                }
                i2 = k2+1;
            }
        }

        // Otherwise insert arry[i] into
        // the array str
        else {
            str2[j2] = arry2[i2];
        }
        i2++;
        j2++;
    }

    // Printing
    for (i2 = 0; i2 < j2; i2++)
        {printf("%d", str2[i2]);

        }
         return 0;
   }

    case 'C':
    {int M3;
    int i3;
    printf("enter the no of bits to be stuffed\n");
    scanf("%d",&M3);
    int arry3[M3];
    printf("enter the values of data\n");
    for(i3=0; i3<M3; i3++)
    {
        scanf("%d", &arry3[i3]);
    }

    int str3[40];

    // Variables to traverse arrays
    int j3, k3;
    i3 = 0;
    j3= 0;

    // Stores the count of consecutive ones
    int count3 = 1;

    // Loop to traverse in the range [0, N)
    while (i3 < M3) {

        // If the current bit is a set bit
        if (arry3[i3] == 1) {

            // Insert into array str[]
            str3[j3] = arry3[i3];

            // Loop to check for
            // next 5 bits
            for (k3 = i3 + 1;
                 arry3[k3] == 1
                 && k3 < M3
                 && count3 < 5;
                 k3++) {
                j3++;
                str3[j3] = arry3[k3];
                count3++;

                // If 5 consecutive set bits
                // are found insert a 0 bit
                if (count3 == 5) {

                        if(arry3[k3]==0)
                        {
                            j3++;
                            str3[j3] = arry3[k3];
                            k3++;
                        }


                        else{
                                j3++;
                                str3[j3] = 0;
                            }}
                i3 = k3;

        }
        // Otherwise insert arry[i] into
        // the array str[]
}
        else {
            str3[j3] = arry3[i3];
             }
        i3++;
        j3++;
    }

    // Printing answer
    for (i3 = 0; i3 < j3; i3++){
        printf("%d", str3[i3]);
    }
    return 0;
    break;
    }
}    }
