#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #include <sys/wait.h>
#include<time.h>
int main()
{
   
   FILE *fptr;
   
   int rc = fork();
   fptr = fopen("program.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!   %d\n", (int)getpid());
      exit(1);
   }
      char sentence[1000];

      strcpy(sentence, "Hello World before child!");
      //printf("Enter a sentence:\n");
      //scanf("%s",sentence);
      fprintf(fptr,"%s", sentence);

   if (rc < 0) { // fork failed; exit
      fprintf(stderr, "fork failed\n");
      exit(1);
   } 
   else if (rc == 0) { // child (new process)
      char sentence[1000];
   
      strcpy(sentence, "Hello World");
      //printf("Enter a sentence:\n");
      //scanf("%s",sentence);
      fprintf(fptr,"%s", sentence);
    // fclose(fptr);


 // char *myargs[3];
 // myargs[0] = strdup("wc"); // program: "wc" (word count)
 // myargs[1] = strdup("p3.c"); // argument: file to count
 // myargs[2] = NULL; // marks end of array
 // execvp(myargs[0], myargs); // runs word count
 // printf("this shouldn’t print out");
   } else { // parent goes down this path (main)
      int wc = sleep(5);
      char sentence[1000];
// fptr = fopen("program.txt", "w");
//    if(fptr == NULL)
//    {
//       printf("Error!");
//       exit(1);
//    }

      //printf("Enter a sentence:\n");
      //scanf("%s",sentence);
      strcpy(sentence, "Good Bye");
      fprintf(fptr,"%s", sentence);
    // fclose(fptr);
      return 0;
   }
   fclose(fptr);
}