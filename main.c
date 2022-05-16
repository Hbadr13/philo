#include <stdio.h>
#include <stdlib.h>

void ftprim(int nb)
{
    int i = 2;
    if(nb == 1)
    {
        printf("1");
        return ;
    }
    while (i <= nb)
    {
        if(nb % i == 0)
        {
            printf("%d",i);
            if(i != nb)
                printf("*");
            nb = nb / i;
           // printf(" -%d- ",nb);
        }
        else
            i++;
    }
}

int main(int ac ,char **av)
{
    if(ac == 2)
        ftprim(atoi(av[1]));
    printf("\n");
    return 0;
}






// char **ft_split(char *str)
// {
//     int i;
//     int j;
//     int k;
//     i = j = k = 0;
//     char **tab;
//     tab = (char **)malloc(sizeof(**tab) * 1000);
//     while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
//         i++;
//     while (str[i])
//     {
//         if (str[i] > 32)
//         {
//             k = 0;
//             tab[j] = (char *)malloc(sizeof(char) * 1000);
//             while (str[i] > 32)
//             {
//                 tab[j][k] = str[i];
//                 i++;
//                 k++;
//             }
//             tab[j][k] = '\0';
//             j++;
//         }
//         else
//             i++;
//     }
//     return tab;
// }

// int main()
// {

//     char **tab;
//     tab = ft_split("     hzma a size   ");
//     int i = 0;
//     while (tab[i])
//     {
//         printf("%s\n", tab[i]);
//         i++;
//     }
// }