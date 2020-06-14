  # include <stdio.h>
  # include <stdlib.h>
  
    /* declaration des variables globales */
    int nEtu;  
    int nNotes;
    
    /* declaration des fonctions */
    void saisirInfo(); 
    void saisirNotes(int **p);  
    void afficher(int **p); 
    int ** allouer();
    void liberer(int **p);

   
    int main()
    {
       int **notes;

       saisirInfo();
       notes=allouer();
       saisirNotes(notes);
       afficher(notes);
       liberer(notes);

       return 0;
    }

    /* fonction qui saisit le nombre des etudiants et le nombre des notes */
    void saisirInfo()
    {
       printf("nombre des etudiants:");
       scanf("%d",&nEtu);
       printf("nombre de notes:");
       scanf("%d",&nNotes);
    }
   
   /* fonction qui alloue le nombre des etudiants */
   int ** allouer()
    {
       return (int**)malloc(nEtu* sizeof(int *));
    }

   /* fonction qui saisit les notes de chaque etudiant */
   void saisirNotes(int **notes)
   {
 int i,j;
      for(i=0;i<nEtu;i++)
        {
           notes[i]=(int*)malloc(nNotes* sizeof(int )); // allocation dynamique du nombre des notes saisit
           printf("Etudiant numero %d\n",i+1);
           for(j=0;j<nNotes;j++)
             {
                scanf("%d",&notes[i][j]); //(*(notes+i)+j);
             }
        }
   }

   /*  fonction qui affiche des notes de chaque etudiant */
   void afficher(int **notes)
   {
   int i,j;
     printf("Voici les resultats\n");
      for(i=0;i<nEtu;i++)
       {
     printf("Etudiant numero %d\n",i+1);
for(j=0;j<nNotes;j++){
printf("%d\n",notes[i][j]); //*(*(notes+i)+j);
}

}
}

/* fonction qui libere les zones allouees */
    void liberer(int **p){
int i;
for(i=0;i<nEtu;i++)
free(p[i]);
free(p);
}
   






