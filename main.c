#include <stdio.h>
#include <string.h>
#include "tools/crud_functions.h"
#define SIZE 100

void menu(struct student stdnts[SIZE])
{
    int tab[6] = {1, 2, 3, 4, 5, 6};
    while (1)
    {
        int ch;
        printf("\n=====================================================================\n");
        printf("\nchose a choice :\n");
        printf("1-afficher tout les etudiant\n2-ajouter un etudiant\n3-modifier un etudiant\n4-suppriemer un etudiant\n5-moyern general\n6-exit");
        printf("\n=====================================================================\n");
        printf("type the number of your choise here:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            afficher(stdnts);
            continue;
        case 2:
        {
            char cin[50], fn[50], ln[50];
            float nts[5], moy;

            printf("donner moi l cin d'un autre etudiant :");
            scanf(" %[^\n]", cin);
            printf("donner moi l fname d'un autre etudiant :");
            scanf(" %[^\n]", fn);
            printf("donner moi l lname d'un autre etudiant :");
            scanf(" %[^\n]", ln);
            printf("donner moi les notes d'un autre etudiant :");
            for (int i = 0; i < 5; i++)
            {
                scanf("%f", &nts[i]);
            }
            moy = avg(nts);
            ajouter(stdnts, cin, fn, ln, nts, moy);
            continue;
        }
        case 3:
        {
            char cin[50], fn[50], ln[50];
            float nts[5], moy;
            printf("donner moi le cin de l'etudiant qui vous vouler de modifier:");
            scanf(" %[^\n]", cin);
            int i = getIndexByCin(stdnts, cin);
            if (i == -1)
            {
                printf("student not found!!");
                continue;
            };
            printf("donner moi l'autre fname:");
            scanf(" %[^\n]", fn);
            printf("donner moi l'autre lname:");
            scanf(" %[^\n]", ln);
            printf("donner moi les autres notes:");
            for (int i = 0; i < 5; i++)
            {
                scanf("%f", &nts[i]);
            }
            moy = avg(nts);
            modifier(stdnts, cin, fn, ln, nts, moy);
            continue;
        }
        case 4:
        {
            char cin[50];
            printf("donner moi le cin de l'etudiant qui vous vouler de supprimer:");
            scanf(" %[^\n]", cin);
            delete (stdnts, cin);
            continue;
        }
        case 6:
            char c;
            printf("you want realy to exit the program,your data will not save \n-yes,i want to exit(y) \n-no,i dont want to exit(n)\n=>");
            scanf(" %c", &c);
            if (c == 'y')
            {
                break;
            }
            else if (c == 'n')
            {
                continue;
            }
        case 5:
        {
            char c;
            printf("\nvoila le moyen general: %f",general_avg(stdnts));
            continue;
        }
        default:
            printf("choice not found!!\n");
            continue;
        }
        if (ch = 5)
        {
            break;
        }
    }
}

int main()
{
    struct student stdnts[SIZE];
    menu(stdnts);
}