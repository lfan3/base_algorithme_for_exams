#include <stdio.h>
#include <stdlib.h>

char **create_area(char **tab, int x, int y)
{
    int i = 0;
    char **area;


    area = malloc(sizeof(char *) * y);
    
    while(i < y)
    {
        int j = 0;
        area[i]= malloc(sizeof(char) * (x));
        while (j < x)
        {
            area[i][j] = tab[i][j];
            j++;
        }
        area[i][j] = 0;
        
        i++;
    }
    return (area);
}

int main()
{
   char zone[5][9] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
    };
   
   //  printf("%c\n", zone[3][1]);
     zone[3][1] = 'f';
  //   printf("%c\n", zone[3][1]);
     
     char *zone1[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
    };
    
   char **area;
   area= create_area(zone1, 8, 5);
   // char *c = zone1[1];
    
    // printf("%c\n", zone1[3][1]);
     printf("%c\n", area[3][1]);
     area[3][1] = 'f';
    printf("%c\n", area[3][1]);
    // printf("%c\n", *(*(zone1+3) + 1));
    // *(*(zone1+3)) = 'f';
  
     /*
      printf("%p\n", (zone1[3] + 2));
      printf("%s\n", *zone1);
      printf("%p\n", zone1[3]);
      printf("%s\n", zone1[1]+ 1);
      zone1[2] = "11100001";*/
     
    //    printf("%c\n", zone1[2][3]);
    // **(zone1 + 1) = '0';

    return 0;
}


