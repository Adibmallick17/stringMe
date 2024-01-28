#include "../include/mallickMohammadAdibA2.h"

int main(int argc, char *argv[])  
{
	char *sa;
	int total_words = 0, total_sentences = 0;
	int* words = &total_words;
	int* sen = &total_sentences;
	char *newString;
	int numWordsReturned = 0;
	
	sa = readFile(argv[1]);
	printf("%s", sa);
	
	dejaVu(sa, words, sen);
	printf("\nNumber of words = %d", *words);
	printf("\nNumber of sentences = %d", *sen);

	printf("\ngoBig Function Test\n");	
	newString = goBig("Hello!");
	printf("New string:%s\n",newString);

	printf("\ngoAway Function Test\n");	
	char** arr = goAway(sa,&numWordsReturned);
   	printf("Num Words Returned : %d\n", numWordsReturned);
	printf("Word array returned\n");
	for(int i=0;i<numWordsReturned;i++)
			printf("Word[%d] : %s\n",i,arr[i]);
	
	printf("\nBreathless Function Test\n");
   	char * test1 = "What was the colour of the dress? Oh, it was red!"; 
	char * temp = breathless(test1);
	printf("%s\n",temp);

	printf("\nTail Function Test\n");
	char * test2 = "Now is the winter of our discontent Made glorious summer by this Sun of York."; 
	tail(test2,8,"otter");
}

