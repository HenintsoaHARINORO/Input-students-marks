  # include <stdio.h>
  # include <stdlib.h>
  
    /* declaration of global variables */
    int nEtu;  
    int nNotes;
    
    /* declaration of functions */
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

    /* fonction which input the number of the students and the marks */
    void saisirInfo()
    {
       printf("numbers of students:");
       scanf("%d",&nEtu);
       printf("numbers of the marks:");
       scanf("%d",&nNotes);
    }
   
   /* function qui alloue le nombre des etudiants */
   int ** allouer()
    {
       return (int**)malloc(nEtu* sizeof(int *));
    }

   /* function which allocate the marks of each students */
   void saisirNotes(int **notes)
   {
 int i,j;
      for(i=0;i<nEtu;i++)
        {
           notes[i]=(int*)malloc(nNotes* sizeof(int )); // dynamic allocation
           printf("Etudiant numero %d\n",i+1);
           for(j=0;j<nNotes;j++)
             {
                scanf("%d",&notes[i][j]); //(*(notes+i)+j);
             }
        }
   }

   /*  function which print the result of the input */
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

/* function which set free the allocated zone */
    void liberer(int **p){
int i;
for(i=0;i<nEtu;i++)
free(p[i]);
free(p);
}
   






