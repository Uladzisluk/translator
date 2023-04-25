/*
Celem programu jest stworzenie s³ownika polsko-angielskiego i angielsko-polskiego.
Na pocz¹tku dzia³ania programu wybierany jest jêzyk podstawowy;
w trakcie dzia³ania powinna istnieæ mo¿liwoœæ jego zmiany.
U¿ytkownik podaje s³owo w jêzyku podstawowym a program wyszukuje jego t³umaczenie,
przy czym wyszukiwanie powinno dzia³aæ równie¿ dla pocz¹tkowego fragmentu wyrazu, np.:
wpisanie s³owa kot powinno zaowocowaæ znalezieniem t³umaczeñ cat (kot) oraz kitty (kotek).
Zbiór dostêpnych s³ów przechowywany jest w pliku. Program powinien umo¿liwiaæ dodawanie,
edycjê oraz usuwanie wyrazów zawartych w s³owniku. Ka¿de s³owo ma tylko jedno t³umaczenie,
s³owa nie mog¹ siê powtarzaæ w ¿adnym jêzyku.
Do realizacji nale¿y wykorzystaæ dwie listy powi¹zane ze sob¹. Listy powinny przechowywaæ s³owa w
porz¹dku alfabetycznym. Przyk³adowa struktura mo¿e wygl¹daæ nastêpuj¹co:
struct lista
{
  char *slowo;
  struct lista *nast.;
  struct lista *t³umaczenie;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>



typedef struct tab
{
    char slowo[50];
    char tlumaczenie[50];
}Tab;

typedef struct lista
{
    char slowo[50];
    struct lista *nast;
    struct lista *tlumaczenie;
}Lista;

int main()
{
    Lista *headp=NULL;
    Lista *heada=NULL;
    char wyb;
    int opcja;
    void uzupelnienie_listy(Lista**, Lista**);
    void obejrzec_tresc_polski(Lista*);
    void obejrzec_tresc_angielski(Lista*);
    void oczyszczenie(Lista**, Lista**);
    void sortowanie_polski(Lista**);
    void sortowanie_angielski(Lista**);
    void dodac_polski(Lista**, Lista**);
    void dodac_angielski(Lista**, Lista**);
    void zapis_do_pliku(Lista*);
    void edytowac_polski(Lista*);
    void edytowac_angielski(Lista*);
    void usunac_polski(Lista**, Lista**);
    void usunac_angielski(Lista**, Lista**);
    void tlumaczenie_polski(Lista*);
    void tlumaczenie_angielski(Lista*);
    void sprawdzanie_polski(Lista**);
    void sprawdzanie_angielski(Lista**);

    system("color F0");
    system("mode con cols=150 lines=30");

    while(1)
    {
        opcja=9;
        system("cls");

        oczyszczenie(&headp, &heada);
        uzupelnienie_listy(&headp, &heada);
        sortowanie_polski(&headp);

        printf("                       Tlumacz                     \n");
        printf("___________________________________________________\n");
        printf("\nProsze wybrac podstawowy jezyk: \n");
        printf("p-Polski\n");
        printf("a-Angielski\n");
        printf("x-Wyjsc\n\n");

        while(1)
        {
            wyb=getch();
            if(wyb=='p' || wyb=='a')
                break;
            else if(wyb=='x')
            {
                system("cls");

                printf("Do widzenia!\n\n");
                return 0;
            }
            else
            {
                printf("Podaj jedna z podanych opcji\n\n");
                continue;
            }
        }

        if (wyb=='p')
        {
            while(opcja!=0)
            {
                system("cls");
                printf("                       Tlumacz                     \n");
                printf("___________________________________________________\n");
                printf("\nZostal wybrany jezyk polski\n\n");
                printf("Wybierz opcje:\n");
                printf("1.Szukac tlumaczenia.\n");
                printf("2.Obejrzec tresc slowniku.\n");
                printf("3.Dodac slowo do slowniku.\n");
                printf("4.Edytowac slownik.\n");
                printf("5.Usunac slowo ze slowniku.\n");
                printf("6.Sprawdzanie slow.\n");
                printf("0.Wroc.\n\n");
                printf("Wybor: ");
                scanf("%d", &opcja);

                switch(opcja)
                {
                case 1:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        tlumaczenie_polski(headp);
                        getch();
                        break;
                    }
                case 2:
                    {
                        sortowanie_polski(&headp);
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        obejrzec_tresc_polski(headp);
                        getch();
                        break;
                    }
                case 3:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        dodac_polski(&headp, &heada);
                        zapis_do_pliku(headp);
                        getch();
                        break;
                    }
                case 4:
                    {
                        edytowac_polski(headp);
                        zapis_do_pliku(headp);
                        break;
                    }
                case 5:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        usunac_polski(&headp, &heada);
                        zapis_do_pliku(headp);
                        getch();
                        break;
                    }
                case 6:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        sprawdzanie_polski(&headp);
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            while(opcja!=0)
            {
                system("cls");
                printf("                       Tlumacz                     \n");
                printf("___________________________________________________\n");
                printf("\nZostal wybrany jezyk angielski\n\n");
                printf("Wybierz opcje:\n");
                printf("1.Szukac tlumaczenia.\n");
                printf("2.Obejrzec tresc slowniku.\n");
                printf("3.Dodac slowo do slowniku.\n");
                printf("4.Edytowac slownik.\n");
                printf("5.Usunac slowo ze slowniku.\n");
                printf("6.Sprawdzanie slow.\n");
                printf("0.Wroc.\n\n");
                printf("Wybor: ");
                scanf("%d", &opcja);

                switch(opcja)
                {
                case 1:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        tlumaczenie_angielski(heada);
                        getch();
                        break;
                    }
                case 2:
                    {
                        sortowanie_angielski(&heada);
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        obejrzec_tresc_angielski(heada);
                        getch();
                        break;
                    }
                case 3:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        dodac_angielski(&heada, &headp);
                        zapis_do_pliku(headp);
                        getch();
                        break;
                    }
                case 4:
                    {
                        edytowac_angielski(heada);
                        zapis_do_pliku(headp);
                        break;
                    }
                case 5:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        usunac_angielski(&heada, &headp);
                        zapis_do_pliku(headp);
                        getch();
                        break;
                    }
                case 6:
                    {
                        system("cls");
                        printf("                       Tlumacz                     \n");
                        printf("___________________________________________________\n");
                        sprawdzanie_angielski(&heada);
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
            }
        }
    }
}

void uzupelnienie_listy(Lista** poczp, Lista** pocza)
{
    FILE *f;
    char c;
    int g=0;
    Lista *nowap, *nowaa, *wskp, *wska;
    f=fopen("Slownik.txt", "r");
    if(!f)
    {
        return;
    }

    while(1)
    {
        int i=0;
        nowap=(Lista*)malloc(sizeof(Lista));
        nowaa=(Lista*)malloc(sizeof(Lista));

        while((c=fgetc(f))!=' ')
        {
            if (c==EOF)
            {
                g=1;
                break;
            }
            nowap->slowo[i]=c;
            i++;
        }
        if(g==1)
            break;
        nowap->slowo[i]='\0';
        i=0;
        while ((c=fgetc(f))!='\n')
        {
            nowaa->slowo[i]=c;
            i++;
        }
        nowaa->slowo[i]='\0';
        nowap->nast=NULL;
        nowap->tlumaczenie=nowaa;
        nowaa->nast=NULL;
        nowaa->tlumaczenie=nowap;

        if (*poczp==NULL)
        {
            *poczp=nowap;
        }
        else
        {
            wskp=*poczp;
            while(wskp->nast!=NULL)
            {
                wskp=wskp->nast;
            }
            wskp->nast=nowap;
        }

        if(*pocza==NULL)
        {
            *pocza=nowaa;
        }
        else
        {
            wska=*pocza;
            while(wska->nast!=NULL)
            {
                wska=wska->nast;
            }
            wska->nast=nowaa;
        }
    }
    fclose(f);
}

void obejrzec_tresc_polski(Lista *pp)
{
    if(pp==NULL)
    {
        printf("Slownik jest pusty.\n");
        return;
    }
    while(pp!=NULL)
    {
        printf("%s - %s\n", pp->slowo, pp->tlumaczenie->slowo);
        pp=pp->nast;
    }
}

void obejrzec_tresc_angielski(Lista *pa)
{
    if(pa==NULL)
    {
        printf("Slownik jest pusty.\n");
        return;
    }
    while(pa!=NULL)
    {
        printf("%s - %s\n", pa->slowo, pa->tlumaczenie->slowo);
        pa=pa->nast;
    }
}

void oczyszczenie(Lista **pp, Lista** pa)
{
    *pp=NULL;
    *pa=NULL;
}

void sortowanie_polski(Lista** pp)
{
      Lista *wsk=*pp;
      char x[50];
      int i, j, z, u;
      int licz=0;

      while(wsk!=NULL)
      {
          wsk=wsk->nast;
          licz++;
      }


      for (i=licz -1; i >= 1; i--)
      {
          wsk=*pp;
          for (j = 0; j < i; j++)
          {
              for (z=0; z<50; z++)
              {
                  u=1;
                  if(wsk->slowo[z] == wsk->nast->slowo[z])
                  {
                      u=0;
                  }
                  else if (wsk->slowo[z] > wsk->nast->slowo[z])
                  {
                      strcpy(x, wsk->slowo);
                      strcpy(wsk->slowo, wsk->nast->slowo);
                      strcpy(wsk->nast->slowo, x);
                      strcpy(x, wsk->tlumaczenie->slowo);
                      strcpy(wsk->tlumaczenie->slowo, wsk->nast->tlumaczenie->slowo);
                      strcpy(wsk->nast->tlumaczenie->slowo, x);
                      break;
                  }
                  if (u==1)
                    break;
              }
              wsk=wsk->nast;
          }
      }
}

void sortowanie_angielski(Lista** pa)
{
      Lista *wsk=*pa;
      char x[50];
      int i, j, z, u;
      int licz=0;

      while(wsk!=NULL)
      {
          wsk=wsk->nast;
          licz++;
      }


      for (i=licz -1; i >= 1; i--)
      {
          wsk=*pa;
          for (j = 0; j < i; j++)
          {
              for (z=0; z<50; z++)
              {
                  u=1;
                  if(wsk->slowo[z] == wsk->nast->slowo[z])
                  {
                      u=0;
                  }
                  else if (wsk->slowo[z] > wsk->nast->slowo[z])
                  {
                      strcpy(x, wsk->slowo);
                      strcpy(wsk->slowo, wsk->nast->slowo);
                      strcpy(wsk->nast->slowo, x);
                      strcpy(x, wsk->tlumaczenie->slowo);
                      strcpy(wsk->tlumaczenie->slowo, wsk->nast->tlumaczenie->slowo);
                      strcpy(wsk->nast->tlumaczenie->slowo, x);
                      break;
                  }
                  if (u==1)
                    break;
              }
              wsk=wsk->nast;
          }
      }
}

void dodac_polski(Lista** pp, Lista** pa)
{
    char slowo[50];
    Lista* nowep;
    Lista* nowea;
    nowep=(Lista*)malloc(sizeof(Lista));
    nowea=(Lista*)malloc(sizeof(Lista));
    system("cls");
    printf("                       Tlumacz                     \n");
    printf("___________________________________________________\n");
    printf("Jakie slowo chcesz dodac: ");
    scanf("%s", slowo);
    strcpy(nowep->slowo, slowo);
    printf("Jego tlumaczenie na angielski: ");
    scanf("%s", slowo);
    printf("\n");
    strcpy(nowea->slowo, slowo);
    nowep->tlumaczenie=nowea;
    nowea->tlumaczenie=nowep;
    nowep->nast=NULL;
    nowea->nast=NULL;


    if(*pp==NULL)
    {
        *pp=nowep;
        *pa=nowea;
    }
    else
    {
        Lista* wskp=*pp;
        Lista* wska=*pa;
        while(wskp->nast!=NULL)
        {
            if(((strcmp(wskp->slowo, nowep->slowo))==0) || ((strcmp(wskp->slowo, nowep->slowo))==0))
            {
                printf("Takie slowo juz istnieje!");
                return;
            }
            wskp=wskp->nast;
        }
        wskp->nast=nowep;

        while(wska->nast!=NULL)
        {
            wska=wska->nast;
        }
        wska->nast=nowea;
    }
}

void dodac_angielski(Lista** pa, Lista** pp)
{
    char slowo[50];
    Lista* nowea;
    Lista* nowep;
    nowea=(Lista*)malloc(sizeof(Lista));
    nowep=(Lista*)malloc(sizeof(Lista));
    system("cls");
    printf("                       Tlumacz                     \n");
    printf("___________________________________________________\n");
    printf("Jakie slowo chcesz dodac: ");
    scanf("%s", slowo);
    strcpy(nowea->slowo, slowo);
    printf("Jego tlumaczenie na polski: ");
    scanf("%s", slowo);
    printf("\n");
    strcpy(nowep->slowo, slowo);
    nowea->tlumaczenie=nowep;
    nowep->tlumaczenie=nowea;
    nowea->nast=NULL;
    nowep->nast=NULL;


    if(*pa==NULL)
    {
        *pa=nowea;
        *pp=nowep;
    }
    else
    {
        Lista* wska=*pa;
        Lista* wskp=*pp;
        while(wska->nast!=NULL)
        {
             if(((strcmp(wska->slowo, nowea->slowo))==0) || ((strcmp(wska->slowo, nowea->slowo))==0))
            {
                printf("Takie slowo juz istnieje!");
                return;
            }
            wska=wska->nast;
        }
        wska->nast=nowea;

        while(wskp->nast!=NULL)
        {
            wskp=wskp->nast;
        }
        wskp->nast=nowep;
    }
}

void zapis_do_pliku(Lista* pp)
{
    FILE* f;
    f=fopen("Slownik.txt", "w");
    while(pp!=NULL)
    {
        fprintf(f, "%s %s\n", pp->slowo, pp->tlumaczenie->slowo);
        pp=pp->nast;
    }
    fclose(f);
}

void edytowac_polski(Lista* pp)
{
    Lista* wsk=pp;
    char slowo[50];
    char slowop[50];
    int licz=0;
    system("cls");
    printf("                       Tlumacz                     \n");
    printf("___________________________________________________\n");
    printf("Podaj slowo ktore chcesz edytowac: ");
    scanf("%s", slowo);
    while(pp!=NULL)
    {
        if((strcmp(pp->slowo, slowo))==0)
        {
            licz++;
            printf("Podaj slowo w jezyku polskim: ");
            scanf("%s", slowop);
            while(wsk!=NULL)
            {
                if((strcmp(wsk->slowo, slowop))==0)
                {
                    printf("Takie slowo juz istnieje!");
                    getch();
                    return;
                }
                wsk=wsk->nast;
            }
            strcpy(pp->slowo, slowop);
            printf("Podaj tlumaczenie w angielskim: ");
            scanf("%s", slowop);
            strcpy(pp->tlumaczenie->slowo, slowop);
        }
        pp=pp->nast;
    }
    if (licz==0)
        printf("Nie znaleziono takiego slowa.");
    getch();
}

void edytowac_angielski(Lista* pa)
{
    Lista* wsk=pa;
    char slowo[50];
    char slowop[50];
    int licz=0;
    system("cls");
    printf("                       Tlumacz                     \n");
    printf("___________________________________________________\n");
    printf("Podaj slowo ktore chcesz edytowac: ");
    scanf("%s", slowo);
    while(pa!=NULL)
    {
        if((strcmp(pa->slowo, slowo))==0)
        {
            licz++;
            printf("Podaj slowo w jezyku angielskim: ");
            scanf("%s", slowop);
            while(wsk!=NULL)
            {
                if((strcmp(wsk->slowo, slowop))==0)
                {
                    printf("Takie slowo juz istnieje!");
                    getch();
                    return;
                }
                wsk=wsk->nast;
            }
            strcpy(pa->slowo, slowop);
            printf("Podaj tlumaczenie w polskim: ");
            scanf("%s", slowop);
            strcpy(pa->tlumaczenie->slowo, slowop);
        }
        pa=pa->nast;
    }
    if (licz==0)
        printf("Nie znaleziono takiego slowa.");
    getch();
}

void usunac_polski(Lista **pp, Lista **pa)
{
    int licz=0;
    char slowo[50];
    printf("Podaj slowe ktore chcesz usunac: ");
    scanf("%s", slowo);
    if(*pp==NULL)
    {
        printf("Slownik jest pusty!");
        return;
    }
    if((strcmp((*pp)->slowo, slowo))==0)
    {
        *pp=(*pp)->nast;
        *pa=(*pa)->nast;
    }
    else
    {
        Lista* wskp=*pp;
        Lista* wska=*pa;
        while(wskp->nast!=NULL)
        {
            if((strcmp(wskp->nast->slowo, slowo))==0)
            {
                licz++;
                wskp->nast=wskp->nast->nast;
                wska->nast=wska->nast->nast;
                return;
            }
            wskp=wskp->nast;
            wska=wska->nast;
        }
        if (licz==0)
            printf("Nie znaleziono takiego slowa");
    }
}

void usunac_angielski(Lista **pa, Lista **pp)
{
    int licz=0;
    char slowo[50];
    printf("Podaj slowe ktore chcesz usunac: ");
    scanf("%s", slowo);
    if(*pa==NULL)
    {
        printf("Slownik jest pusty!");
        return;
    }
    if((strcmp((*pa)->slowo, slowo))==0)
    {
        *pp=(*pp)->nast;
        *pa=(*pa)->nast;
    }
    else
    {
        Lista* wskp=*pp;
        Lista* wska=*pa;
        while(wska->nast!=NULL)
        {
            if((strcmp(wska->nast->slowo, slowo))==0)
            {
                licz++;
                wskp->nast=wskp->nast->nast;
                wska->nast=wska->nast->nast;
                return;
            }
            wskp=wskp->nast;
            wska=wska->nast;
        }
        if (licz==0)
            printf("Nie znaleziono takiego slowa");
    }
}

void tlumaczenie_polski(Lista* pp)
{
    char slowo[50];
    int licz=0;
    printf("Do jakiego slowa chcesz znalezc  tlumaczenie: ");
    scanf("%s", slowo);
    while(pp!=NULL)
    {
        if((strstr(pp->slowo, slowo))!=NULL)
        {
            licz++;
            printf("%s - %s\n", pp->slowo, pp->tlumaczenie->slowo);
        }
        pp=pp->nast;
    }
    if(licz==0)
    {
        printf("Nie znaleziono takiego slowa.");
    }
}

void tlumaczenie_angielski(Lista* pa)
{
    char slowo[50];
    int licz=0;
    printf("Do jakiego slowa chcesz znalezc  tlumaczenie: ");
    scanf("%s", slowo);
    while(pa!=NULL)
    {
        if((strstr(pa->slowo, slowo))!=NULL)
        {
            licz++;
            printf("%s - %s\n", pa->slowo, pa->tlumaczenie->slowo);
        }
        pa=pa->nast;
    }
    if(licz==0)
    {
        printf("Nie znaleziono takiego slowa.");
    }
}

void sprawdzanie_polski(Lista** pp)
{
    char opcja='a';
    int licz=0;
    int i, g, f, j=0, c=0;;
    Lista *wsk=*pp;
    char **tabp;
    char **taba;

    while (wsk!=NULL)
    {
        licz++;
        wsk=wsk->nast;
    }

    tabp=(char**)malloc(licz*sizeof(char*));
    taba=(char**)malloc(licz*sizeof(char*));

    wsk=*pp;

    for (i=0; i<licz; i++)
    {
        tabp[i]=wsk->slowo;
        taba[i]=wsk->tlumaczenie->slowo;
        wsk=wsk->nast;
    }

    printf("Zeby wyjsc podaj 'x'\n\n");

    srand(time(NULL));

    int sp[licz];
    g=0;

    while(opcja!='x')
    {
        opcja='a';

        while(1)
        {
            c=0;
            f=rand()%licz;
            for(i=0; i<g; i++)
            {
                if(f==sp[i])
                    c=1;
            }
            if(c==1)
                continue;
            break;
        }

        sp[g]=f;
        g++;

        printf("%s ", tabp[f]);
        getch();
        printf("%s\n", taba[f]);
        opcja=getch();
        j++;
        if(j==licz)
            break;
    }
    free(tabp);
    free(taba);
}

void sprawdzanie_angielski(Lista** pa)
{
    char opcja='a';
    int licz=0;
    int i, g, f, j=0, c=0;;
    Lista *wsk=*pa;
    char **tabp;
    char **taba;

    while (wsk!=NULL)
    {
        licz++;
        wsk=wsk->nast;
    }

    tabp=(char**)malloc(licz*sizeof(char*));
    taba=(char**)malloc(licz*sizeof(char*));

    wsk=*pa;

    for (i=0; i<licz; i++)
    {
        taba[i]=wsk->slowo;
        tabp[i]=wsk->tlumaczenie->slowo;
        wsk=wsk->nast;
    }

    printf("Zeby wyjsc podaj 'x'\n\n");

    srand(time(NULL));

    int sp[licz];
    g=0;

    while(opcja!='x')
    {
        opcja='a';

        while(1)
        {
            c=0;
            f=rand()%licz;
            for(i=0; i<g; i++)
            {
                if(f==sp[i])
                    c=1;
            }
            if(c==1)
                continue;
            break;
        }

        sp[g]=f;
        g++;

        printf("%s ", taba[f]);
        getch();
        printf("%s\n", tabp[f]);
        opcja=getch();
        j++;
        if(j==licz)
            break;
    }
    free(tabp);
    free(taba);
}
