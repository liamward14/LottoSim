#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Global vars
int i;
int drawn[6];
int tracking[95];
int select[6];
int play=1;

//Fxn prototypes
void select_numbers(void);
void display_winners(void);
void generate_winners(void);
void sort_winners(void);
int check_win(void);
int check_response(void);

int main()
{
    printf("Welcome to the Lottery Simulation!\n");

    //Execute simulation
    while(play)
    {
        generate_winners();
        sort_winners();
        select_numbers();
        display_winners();
        int win_status = check_win();
        if (win_status>=6)
        {
            printf("You won!\nThank you for playing!\n");
        }
        else
        {
            printf("\nYou lost, sorry\n");
            play = check_response();
        }
    }

    getchar();
    getchar();


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
        while (selection<1||selection>51)
        {
            printf("\nInvalid input, please try again\n");
            printf("Selection: ");
            scanf("%d",&selection);
        }
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
            if (drawn[x]<drawn[y])
            {
                int temp = drawn[y];
                drawn[y] = drawn[x];
                drawn[x] = temp;
            }
        }
    }
}

int check_win(void)
{
    int x,y;
    int sum=0;
    for(x=0;x<6;x++)
    {
        for(y=0;y<6;y++)
        {
            if (drawn[x]==select[y])
            {
                sum++;
            }
        }
    }
    return(sum);
}

int check_response(void)
{
    char response;
    printf("Would you like to play again?\n");
    printf("Response ('y' or 'n'): ");
    getchar();
    scanf("%c",&response);
    if (toupper(response)=='Y')
    {
        return(1);
    }
    else if (toupper(response)=='N')
    {
        printf("The game will exit now...\n");
        return(0);
    }
    else
    {
        printf("Invalid response, please try again...\n");
        check_response();
    }
}
