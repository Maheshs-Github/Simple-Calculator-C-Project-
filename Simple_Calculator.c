#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Decimal_To_Binary(int No);
int Decimal_To_Hex(int No);
int Binary_To_Decimal(int No);
int Binary_To_Hex(int No);
int Hex_To_Decimal(char *Hex);
int Hex_To_Binary(char *Hex);
float Addition();
float Subtraction();
float Multiplication();
float Division();
float Modula();
float Floor_Division();
float Ceiling_Division();

void main()
{
    int No, Choice, Choice1, Choice2;
    char HexNo[20];
    printf("\n***This Is A Simple Calculator***\n");
    printf("\nWhat do you like to perform:\n");
    printf("1.Arithmatic Problems Such as ('+','*',etc)\n");
    printf("2.Number System Conversion Such as ('Decimal to Binary','Decimal to Hex',etc)\n");
    scanf("%d", &Choice);
    do
    {
        switch (Choice)
        {
        case 1:
            printf("\n\n\n1.Addition\n2.Multiplication\n3.Subtraction\n4.Division\n5.Modulo/Remainder\n6.Floor Division\n7.Ceiling Division\n8.Quit");
            printf("\nInput the number of arithmatic operation u like to perform from above:\n");
            scanf("%d", &Choice1);
            do
            {
                switch (Choice1)
                {
                case 1:
                    Addition();
                    break;
                case 2:
                    Multiplication();
                    break;
                case 3:
                    Subtraction();
                    break;
                case 4:
                    Division();
                    break;
                case 5:
                    Modula();
                    break;
                case 6:
                    Floor_Division();
                    break;
                case 7:
                    Ceiling_Division();
                    break;
                case 8:
                    exit(0);
                default:
                    printf("Wrong Choice reee!\n");
                    break;
                }
            } while (Choice1 != 8);
            break;
        case 2:
            printf(">>Which Conversion you like to do?\n\t1.Decimal To Binary\n\t2.Decimal To Hexadecimal\n");
            printf("\t3.Binary To Decimal\n\t4.Binary To Hex\n");
            printf("\t5.Hex To Decimal\n\t6.Hex To Binary\n\t7.Quit\n");
            printf("\tEnter the choice from 1-7:\n");
            scanf("%d", &Choice2);
            do
            {
                switch (Choice2)
                {
                case 1:
                    printf("\nEnter the Decimal number:\n");
                    scanf("%d", &No);
                    Decimal_To_Binary(No);
                    break;
                case 2:
                    printf("\nEnter the Decimal number:\n");
                    scanf("%d", &No);
                    Decimal_To_Hex(No);
                    break;
                case 3:
                    printf("\nEnter the Binary number:\n");
                    scanf("%d", &No);
                    int Decimal1 = Binary_To_Decimal(No);
                    printf("The decimal equvalent to the binary no %d=%d ", No, Decimal1);
                    break;
                case 4:
                    printf("\nEnter the Binary number:\n");
                    scanf("%d", &No);
                    Binary_To_Hex(No);
                    break;
                case 5:
                    printf("\nEnter the Hex Number:\n");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%s", &HexNo);
                    int Decimal2 = Hex_To_Decimal(HexNo);
                    printf("The decimal equvalent to the Hex no %s=%d ", HexNo, Decimal2);
                    break;
                case 6:
                    printf("\nEnter the Hex number:\n");
                    scanf("%s", &HexNo);
                    Hex_To_Binary(HexNo);
                    // printf("The Binary equvalent to the Hex no %s=%d ", HexNo, Decimal3);
                    break;
                case 7:
                    exit(0);
                default:
                    printf("\nPlz.. Enter the correct choice reee! \n");
                    break;
                }

            } while (Choice2 != 7);
            break;

        default:
            printf("Wrong Choice reee..\n");
            break;
        }
    } while (Choice < 3);
}



// Number System Conversion Related Operations
int Decimal_To_Binary(int No)
{
    int Remainder[20], i = 0, No1 = No;
    while (No > 0)
    {
        Remainder[i] = No % 2;
        No = No / 2;
        i++;
    }
    printf("The Binary eqivalent to decimal no %d=", No1);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", Remainder[j]);
    }
    return 0;
}

int Decimal_To_Hex(int No)
{
    int Remainder, Hex[20], i = 0, No1 = No;
    while (No > 0)
    {
        Remainder = No % 16;
        if (Remainder < 10)
        {
            Hex[i] = Remainder + '0';
        }
        else
        {
            Hex[i] = Remainder - 10 + 'A';
        }
        No = No / 16;
        i++;
    }
    printf("The Hex eqivalent to decimal no %d=", No1);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", Hex[j]);
    }
    return 0;
}
int Binary_To_Decimal(int No)
{
    char Binarystr[20];
    sprintf(Binarystr, "%d", No);
    int length = strlen(Binarystr);
    int Decimal = 0, base = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        if (Binarystr[i] == '1')
            Decimal = Decimal + base;
        base = base * 2;
    }
    // printf("The decimal equvalent to the binary no %s=%d ",Binarystr,Decimal);
    return Decimal;
}
int Binary_To_Hex(int No)
{
    int Hex[20], i = 0, j;
    int Decimal = Binary_To_Decimal(No);
    // printf("%d",Decimal);
    while (Decimal > 0)
    {
        int Remainder = Decimal % 16;
        if (Remainder < 10)
        {
            Hex[i] = Remainder + '0';
        }
        else
        {
            Hex[i] = Remainder - 10 + 'A';
        }
        Decimal = Decimal / 16;
        i++;
    }
    printf("The equvalent Hex to the binary no %d= ", No);
    // printf("%c",Hex[i]);
    for (int j = i - 1; j >= 0; j--)
    {
        // printf("dnvldn");
        printf("%c", Hex[j]);
    }
    return 0;
}
int Hex_To_Decimal(char *Hex)
{
    /*char Hex[20];
    sprintf(Hex,"%d",HexNo);
    int Length=strlen(Hex),Decimal,base=1;*/
    int Length = 0, Decimal, base = 1, Decimal_value = 0;
    while (Hex[Length] != '\0')
    {
        Length++;
    }

    for (int j = Length - 1; j >= 0; j--)
    {
        if (Hex[j] >= '0' && Hex[j] <= '9')
        {
            Decimal = (Hex[j] - '0');
        }
        else if (Hex[j] >= 'A' && Hex[j] <= 'F')
        {
            Decimal = (Hex[j] - 'A' + 10);
        }
        else if (Hex[j] >= 'a' && Hex[j] <= 'f')
        {
            Decimal = (Hex[j] - 'a' + 10);
        }
        else
        {
            return -1;
        }
        Decimal_value += Decimal * base;
        base *= 16;
    }
    return Decimal_value;
}

int Hex_To_Binary(char *Hex)
{
    int Decimal_value = Hex_To_Decimal(Hex);
    // printf("%d",Decimal_value);
    int Binary[20], i = 0;
    while (Decimal_value > 0)
    {
        Binary[i] = Decimal_value % 2;
        Decimal_value = Decimal_value / 2;
        i++;
    }
    // printf("\n%d",Binary[i]);
    printf("The Binary equvalent number is=");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", Binary[j]);
    }
    return 0;
}


//Arithamatic Operations Relateds Functions
float Addition()
{
    float No1, No2;
    printf("\nEnter any Two Numbers to Add:\n ");
    scanf("%f %f", &No1, &No2);
    printf("The Add of %f & %f is= %f", No1, No2, No1 + No2);
    // return 0;
}
float Subtraction()
{
    float No1, No2;
    printf("\nEnter any Two Numbers to Subtract:\n ");
    scanf("%f%f", &No1, &No2);
    printf("The Subtraction of %f & %f is= %f", No1, No2, No1 - No2);
    return 0;
}
float Multiplication()
{
    float No1, No2;
    printf("\nEnter any Two NUmbers to Multiply:\n ");
    scanf("%f%f", &No1, &No2);
    printf("The Multiplication of %f & %f is= %f", No1, No2, No1 * No2);
    return 0;
}

float Division()
{
    float No1, No2;
    printf("\nEnter any Two NUmbers to Divide:\n ");
    scanf("%f%f", &No1, &No2);
    if (No2 != 0)
    {
        printf("The Division of %f & %f is= %f", No1, No2, No1 / No2);
    }
    else
    {
        printf("Division by zero will be infinte try something else:\n");
    }
    return 0;
}
float Modula()
{
    int No1, No2;
    printf("\nEnter any Two intger NUmbers to find its Remainder/Modula:\n ");
    scanf("%d%d", &No1, &No2);
    printf("The Modula of %d & %d is= %d", No1, No2, No1 % No2);
    return 0;
}
float Floor_Division()
{
    float No1, No2;
    int c;
    printf("\nEnter any two NUmbers to find its floor division:\n ");
    scanf("%f%f", &No1, &No2);
    c = (No1 / No2);
    // printf("%f",&c);
    printf("The Floor Division of %f & %f= %d", No1, No2, c);
    return 0;
}
float Ceiling_Division()
{
    float No1, No2;
    int c, d;
    printf("\nEnter any two NUmbers to find its Ceiling division:\n ");
    scanf("%f%f", &No1, &No2);
    c = (No1 / No2);
    d = fmod(No1, No2);
    if (d != 0)
        printf("The Floor Division of %f & %f= %d", No1, No2, c + 1);
    else
        printf("The Floor Division of %f & %f= %d", No1, No2, c);
    return 0;
}
