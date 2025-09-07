#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
struct student
{
    char cin[50];
    char fname[50];
    char lname[50];
    float notes[5];
    float avg;
};

// calculer le moyen d'un etudiant selon leur cin
float avg(float notes[5])
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += notes[i];
    }
    return sum / 5;
}
int getIndexByCin(struct student tab[SIZE], char cin[])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (strcmp(tab[i].cin, cin) == 0)
        {
            return i;
        }
    }
    return -1;
}

// calcul de moyen general
float general_avg(struct student stdnts[SIZE])
{
    float sum = 0;
    int nbrs_stdnts = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (stdnts[i].fname[0] == '\0' && stdnts[i].lname[0] == '\0')
        {
            break;
        }
        sum += stdnts[i].avg;
        nbrs_stdnts++;
    }
    if (nbrs_stdnts == 0)
    {
        return 0;
    }
    return sum / nbrs_stdnts;
}

// procedure pour afficher tout les etudiants
void afficher(struct student tab[SIZE])
{
    int i = 0;
    while (tab[i].fname[0] != '\0' && tab[i].lname[0] != '\0')
    {
        printf("%s-%s-%s of notes : ", tab[i].cin, tab[i].fname, tab[i].lname);

        for (int j = 0; j < 5; j++)
        {
            printf("%f - ", tab[i].notes[j]);
        }

        printf(" de moyen : %f", tab[i].avg);
        printf("\n");
        i++;
    }
}

// procedure pour ajouter un autre etudiant
void ajouter(struct student tab[SIZE], char cin[50], char fname[50], char lname[50], float notes[5], float avg)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (tab[i].fname[0] == '\0' && tab[i].lname[0] == '\0')
        {
            strcpy(tab[i].cin, cin);
            strcpy(tab[i].fname, fname);
            strcpy(tab[i].lname, lname);
            for (int j = 0; j < 5; j++)
            {
                tab[i].notes[j] = notes[j];
            }
            tab[i].avg = avg;
            break;
        }
    }
}

// procedure pour modifier un etudiant selon leur cin
void modifier(struct student tab[SIZE], char cin[50], char fname[50], char lname[50], float notes[5], float moy)
{
    int i = getIndexByCin(tab, cin);
    if (i == -1)
    {
        printf("student not found!!");
    }
    else
    {
        strcpy(tab[i].fname, fname);
        strcpy(tab[i].lname, lname);
        for (int j = 0; j < 5; j++)
        {
            tab[i].notes[j] = notes[j];
        }
        tab[i].avg = moy;
        printf("the student is updated succefully");
    }
}

// procedure pour suprimer un etudiant selon leur cin
void delete(struct student tab[SIZE], char cin[50])
{
    int i = getIndexByCin(tab, cin);
    if (i == -1)
    {
        printf("student not found!!");
    }
    else
    {
        for (int j = i; j < SIZE - 1; j++)
        {
            strcpy(tab[i].cin, tab[i + 1].cin);
            strcpy(tab[i].fname, tab[i + 1].fname);
            strcpy(tab[i].lname, tab[i + 1].lname);
            for (int k = 0; k < 10; k++)
            {
                tab[i].notes[k] = tab[i + 1].notes[k];
            }
            tab[i].avg = tab[i + 1].avg;
        }
        printf("the student deleted succefully");
    }
}

void setNotesForStudent(struct student tab[SIZE], char cin[50]){
    
}
