#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global vars
int i;
int drawn[6];
int tracking[95];
int select[6];

//Fxn prototypes
void select_numbers(void);
void display_winners(void);
void generate_winners(void);
void sort_winners(void);

int main()
{
    printf("Welcome to the Lottery Simulation!\n");

    //Execute simulation
    generate_winners();
    select_numbers();
    display_winners();

    return(0);
}

void generate_winners(void)
{
    srand((unsigned)time(NULL));
    for(i=0;i<6;i++)
    {
        int r = rand() % 51 + 1;
        drawn[i] = r;
    }
}

void select_numbers(void)
{
    printf("Select 6 numbers in the range {1,51} below\n");
    for (i=0;i<6;i++)
    {
        int selection;
        printf("Selection: ");
        scanf("%d",&selection);
        select[i] = selection;
    }

    printf("\nYou selected: ");
    for (i=0;i<6;i++)
    {
        printf(" %d",select[i]);
    }
}

void display_winners(void)
{
    printf("\nWinning numbers: ");
    for(i=0;i<6;i++)
    {
        printf("%d ",drawn[i]);
    }
}

void sort_winners(void)
{
    int x,y;
    //Employ bubble sort method
    for (x=0;x<6;x++)
    {
        for(y=0;y<6;y++)
        {
            if (drawn[x]>drawn[y])
            {
                int temp = drawn[y];
                drawn[y] = drawn[x];
                drawn[x] = temp;
            }
        }
    }
}
