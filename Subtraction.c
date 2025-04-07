#include<stdio.h>
#include<stdint.h>
#include<string.h>

int get_input(int8_t *, int8_t *, int8_t *, int8_t *, int8_t *);
int subtraction(int8_t *, int8_t *, int8_t *, int8_t *, int8_t *);

int main()
{

   while(1)
   {

    int8_t string1[100], number_1[50], number_2[50], Answer[52];
    int8_t size_1=0, size_2=0;

    if(get_input(string1, number_1, number_2, &size_1, &size_2)==0)

    {

     subtraction(number_1, number_2, &size_1, &size_2, &Answer[0]);
     printf("Answer = %s\n\n", Answer);


    }
    else
    {
        printf("Invalid. Enter a valid number\n\n");
    }
   }

}


int get_input(int8_t *string, int8_t *number_1, int8_t *number_2, int8_t *size_1, int8_t *size_2)
{
   int8_t size, first_set=0;
   printf(">> ");
    fgets(string, 100, stdin);
    size =strlen(string)-1;
    for(int8_t i=0; i<size; i++)
    {
        if(*(string+i)<48 || *(string + i)>57 )
        {
            if(*(string+i)!=43 && *(string+i)!='-' && *(string+i)!='*' && *(string+ i)!='/'  )
            return -1;

        }
        if(*(string+i)=='-')
        {   i+=1;
            for(int8_t j=0; i<size; i++)
            {
               *(number_2+j)=*(string+i)-48;
               j++;
               (*size_2)++;
            }

            break;

        }
        else
        {
            *(number_1+i)=*(string+i)-48;
            (*size_1)++;
        }

    }
   return 0;
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
            for(int8_t i=*(size_2)-1; i>=0; i--)
        {
            result[z] = *(number_1 + i + diff) - *(number_2 + i);
            if(result[z]<0)
            {
                result[z] = *(number_1 + i + diff) + 10 - *(number_2 + i);
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
            if(result[z]<0)
            {
                result[z] = *(number_1 + i + diff) + 10 - *(number_2 + i);
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

