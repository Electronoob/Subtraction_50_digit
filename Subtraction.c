/*
Algorithm
1.Get the input as string
2.In the string store the numbers in numbers_1 until '-' and
store the numbers in numbers_2 after '-' and simulaneously assign
and increment size_1 and size_2 values.
// Step 2 is not implemented yet in this program
3.Calculate the difference
4.First condition difference is 0 || greater than 0
and second condition is difference <0



// ippo naa maathanum


*/


#include<stdio.h>   // change the 000 value when both the numbers are same
#include<stdint.h>
#include<string.h>

void get_input(int8_t *, int8_t *, int8_t *, int8_t *);
int subtraction(int8_t *, int8_t *, int8_t *, int8_t *, int8_t *);

int main()
{
    int8_t number_1[50], number_2[50], Answer[50];
    int8_t size_1=0, size_2=0;
    while(1)
    {


    get_input(number_1, number_2, &size_1, &size_2);


    subtraction(number_1, number_2, &size_1, &size_2, &Answer[0]);
    printf("Answer is %s\n\n\n", Answer);
    }

}

void get_input(int8_t *number_1, int8_t *number_2, int8_t *size_1, int8_t *size_2)
{   int8_t string_1[50], string_2[50];

    printf("Enter the first number : ");
    fgets(string_1, 50, stdin);
    *size_1 = strlen(string_1)-1;


    printf("Enter the second number : ");
    fgets(string_2, 50, stdin);
    *size_2 = strlen(string_2)-1;


    for(int8_t i=0; i<(*size_1); i++)
    {
        *(number_1+i) = *(string_1 + i) - 48;
    }

    for(int8_t i=0; i<(*size_2); i++)
    {
        *(number_2+i) = *(string_2 + i) - 48;
    }

}


int subtraction(int8_t *number_1, int8_t *number_2, int8_t *size_1, int8_t *size_2, int8_t *Answer)
{
    int8_t diff=*(size_1) - *(size_2);
    int8_t z=0, j=0, flag=0, first=0, second=0, adjust=0;
    int8_t result[50]={0};



    if(diff==0)
    {
        for(int8_t i=0; i<*(size_1); i++)
        {   if(*(number_1 + i)==*(number_2 + i))
            {
                continue;
            }
            else if(*(number_1+i)>*(number_2+i))
            {
                first=1;
                break;
            }
            else if(*(number_1+i)<*(number_2+i))
            {
                second=1;
                break;
            }
        }

        if(first==0 && second ==0)

        {
          *(Answer)='0';
          *(Answer+1)='\0';
        }
        else if(first==1)
        {
           printf("inga vanthana\n");
            for(int8_t i=*(size_2)-1; i>=0; i--)
        {
            result[z] = *(number_1 + i + diff) - *(number_2 + i);
            printf("%d - %d\n",*(number_1 + i + diff), *(number_2 + i));
            if(result[z]<0)
            {
                printf("borrow vaanga ulla vanthan\n");
                result[z] = *(number_1 + i + diff) + 10 - *(number_2 + i);
                printf("result[z] : %d= %d - %d\n", result[z], *(number_1 + diff), *(number_2 + i) );
                (*(number_1 + (i-1) + diff))--;
            }
            z++;
            if(i==0)
            {
                j=diff-1;
                while(j>=0)
                {
                    result[z] = *(number_1 +j );

                    j--;
                    z++;
                }
            }
        }
        j=0;
        for(int8_t i=z-1; i>=0; i--)
        {
            Answer[j] = result[i] + 48;
            j++;
        }
        Answer[j]=0;

            for(int8_t i=0; i<=j; i++)
        {
            if(*(Answer+i)=='0')
            {
                adjust++;
            }
            else
            {
                break;
            }
        }

        for(int8_t a=0; a<=j-adjust; a++)
        {

            *(Answer + a)=*(Answer + a+adjust);
        }

        return 0;



        }

        else if(second==1)
        {

        for(int8_t i=*(size_1)-1; i>=0; i--)
        {
            result[z]=*(number_2 + i + diff ) - *(number_1 + i);
            if(result[z]<0)
            {

                result[z]=*(number_2 + i + diff) + 10 - *(number_1 + i);
                (*(number_2 + (i-1) + diff))--;
            }
            z++;
            if(i==0)
            {
                j=diff-1;
                while(j>=0)
                {
                    result[z]=*(number_2 + j);
                    j--;
                    z++;
                }
            }
        }
        j=1;
        Answer[0]='-';
        for(int8_t i=z-1; i>=0; i--)
        {
            *(Answer+j)= result[i] + 48;
            j++;
        }
        *(Answer+j)=0;

   printf("inga answer enna %s and j value %d\n", Answer, j);
            for(int8_t i=1; i<=j; i++)
        {
            if(*(Answer+i)=='0')
            {
                adjust++;
            }
            else
            {
                break;
            }
        }

        for(int8_t a=1; a<=j-adjust; a++)
        {

            *(Answer + a)=*(Answer + a+adjust);
        }

        return 0;


        }


    }













    if(diff>0 )
    {


        for(int8_t i=*(size_2)-1; i>=0; i--)
        {
            result[z] = *(number_1 + i + diff) - *(number_2 + i);
            printf("%d - %d\n",*(number_1 + i + diff), *(number_2 + i));
            if(result[z]<0)
            {
                printf("borrow vaanga ulla vanthan\n");
                result[z] = *(number_1 + i + diff) + 10 - *(number_2 + i);
                printf("result[z] : %d= %d - %d\n", result[z], *(number_1 + diff), *(number_2 + i) );
                (*(number_1 + (i-1) + diff))--;
            }
            z++;
            if(i==0)
            {
                j=diff-1;
                while(j>=0)
                {
                    result[z] = *(number_1 +j );

                    j--;
                    z++;
                }
            }
        }
        j=0;
        for(int8_t i=z-1; i>=0; i--)
        {
            Answer[j] = result[i] + 48;
            j++;
        }
        Answer[j]=0;


            for(int8_t i=0; i<=j; i++)
        {
            if(*(Answer+i)=='0')
            {
                adjust++;
            }
            else
            {
                break;
            }
        }

        for(int8_t a=0; a<=j-adjust; a++)
        {

            *(Answer + a)=*(Answer + a+adjust);
        }

        return 0;








    }

    if(diff<0 )
    {
        diff=(-1)*(diff);

        for(int8_t i=*(size_1)-1; i>=0; i--)
        {
            result[z]=*(number_2 + i + diff ) - *(number_1 + i);
            if(result[z]<0)
            {

                result[z]=*(number_2 + i + diff) + 10 - *(number_1 + i);
                (*(number_2 + (i-1) + diff))--;
            }
            z++;
            if(i==0)
            {
                j=diff-1;
                while(j>=0)
                {
                    result[z]=*(number_2 + j);
                    j--;
                    z++;
                }
            }
        }
        j=1;
        Answer[0]='-';
        for(int8_t i=z-1; i>=0; i--)
        {
            *(Answer+j)= result[i] + 48;
            j++;
        }
        *(Answer+j)=0;

            for(int8_t i=1; i<=j; i++)
        {
            if(*(Answer+i)=='0')
            {
                adjust++;
            }
            else
            {
                break;
            }
        }

        for(int8_t a=1; a<=j-adjust; a++)
        {

            *(Answer + a)=*(Answer + a+adjust);
        }

        return 0;




    }
}
