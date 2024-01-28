#include "../include/mallickMohammadAdibA2.h"

char *readFile(char *filename)
{
	// A pointer to the buffer where the file contents will be stored
	char *buffer = 0;
	/* The length of the file in bytes */
	long length;
	/* A FILE pointer to the file being read */
	FILE *f = fopen(filename, "r");
	/* Check if the file was opened successfully */
	if (f)
	{
		/* Move the file pointer to the end of the file */
		fseek(f, 0, SEEK_END);

		/* Get the position of the file pointer (which is the length of the file) */
		length = ftell(f);

		/* Move the file pointer back to the beginning of the file */
		fseek(f, 0, SEEK_SET);

		/* Allocate memory for the buffer */
		buffer = malloc(length);

		/* Check if the allocation was successful */
		if (buffer)
		{
			/* Read the entire file into the buffer */
			fread(buffer, 1, length, f);
		}

		/* Add a null terminator to the end of the buffer */
		buffer[length] = '\0';

		/* Close the file */
		fclose(f);
	}

	/* Return the buffer */
	return (buffer);
}

void dejaVu(char *aString, int *numWords, int *numSentences)
{
	int flag_sent_found = 0;

	/* Loop through the string */
	while (*aString++)
	{

		if (*aString == ' ')
		{
			/* If a sentence-ending punctuation hasn't been found yet, increment the word count */
			if (flag_sent_found == 0)
				(*numWords)++;
		}
		/* If a newline character is found, a word and a sentence have ended */
		else if (*aString == '\n')
		{
			(*numWords)++;
		}
		/* If a sentence-ending punctuation is found, a sentence and a word have ended */
		else if (*aString == '.' || *aString == '?' || *aString == '!')
		{
			/* Set the sentence-ending flag */
			flag_sent_found = 1;

			/* Increment the word and sentence counts */
			(*numWords)++;
			(*numSentences)++;
		}
		/* If none of the above conditions are met, the sentence-ending flag is reset */
		else
			flag_sent_found = 0;
	}
}

char *goBig(char *aString)
{
	int total_length;

	// getting length of the string
	total_length = strlen(aString);

	int user_nums[total_length];

	/* Prompt the user to input a numeric value for each character */
	printf("\nEnter numbers here:\n");

	for (int itr = 0; itr < total_length; itr++)
	{
		printf("Enter numeric value for character %d: ", itr);
		scanf("%d", &user_nums[itr]);
		fflush(stdin);

		/* If an invalid value is entered, prompt the user to input a new value */
		while (user_nums[itr] <= 0)
		{
			printf("\nInvalid numeric value. Please enter again here: ");
			scanf("%d", &user_nums[itr]);
			fflush(stdin);
		}
	}

	/* Calculate the total length of the new string */
	int sum = 0;
	for (int itr = 0; itr < total_length; itr++)
		sum = user_nums[itr] + sum;

	/* Allocate memory for the new string */
	char *temp = malloc(sum + 1);
	int itrp = 0;

	for (int i = 0; i < total_length; i++)
	{
		/* Concatenate the character to the new string a number of times equal to the corresponding numeric value */
		for (int j = 0; j < user_nums[i]; j++)
		{
			temp[itrp] = aString[i];
			itrp++;
		}
	}

	/* Add a null terminator to the end of the new string */
	temp[itrp] = 0;

	/* Return the new string */
	return temp;
}

char **goAway(char *aString, int *numWordsReturned)
{
	// Check if the input string is not NULL, and exit if it is
	if (aString == NULL)
		exit(1);

	// Allocate memory for a copy of the input string
	char *tempcpy = malloc(strlen(aString) + 1);

	// Check if the allocation was successful, and exit if it was not
	if (tempcpy == NULL)
		exit(1);

	// Copy the input string to the allocated memory
	strcpy(tempcpy, aString);

	// Initialize variables for row count and data buffer
	unsigned rows = 0;
	char **databuffer = NULL;

	// Define delimiters to tokenize the string
	const char *delims = " \t\n,.";

	// Tokenize the string and allocate memory for each word
	char *tempptr = strtok(tempcpy, delims);

	while (tempptr)
	{
		// Resize the data buffer to add a new row
		databuffer = realloc(databuffer, (rows + 1) * sizeof *databuffer);

		// Check if the reallocation was successful, and exit if it was not
		if (databuffer == NULL)
			exit(1);

		// Allocate memory for the current word and copy it to the data buffer
		databuffer[rows] = malloc(strlen(tempptr) + 1);

		// Check if the allocation was successful, and exit if it was not
		if (databuffer[rows] == NULL)
			exit(1);

		// Copy the current word to the data buffer
		strcpy(databuffer[rows], tempptr);

		// Increment the row count and tokenize the next word
		++rows;

		tempptr = strtok(NULL, delims);
	}

	// Resize the data buffer to add a NULL terminator at the end
	databuffer = realloc(databuffer, (rows + 1) * sizeof *databuffer);

	// Check if the reallocation was successful, and exit if it was not
	if (databuffer == NULL)
		exit(1);

	// Add a NULL terminator at the end of the data buffer
	databuffer[rows] = NULL;

	// Set the output parameter to the number of words in the data buffer
	*numWordsReturned = rows;

	// Free the memory allocated for the copy of the input string
	free(tempcpy);

	// Return the data buffer
	return databuffer;
}

char *breathless(char *aString)
{
	int itr = 0;
	int itrp = 0;
	int len = strlen(aString);

	// allocate memory for the new string
	char *temp = malloc(len + 1);

	for (itr = 0; itr < len; itr++)
	{
		// if the character is not a punctuation mark
		if (aString[itr] != '.' && aString[itr] != ':' && aString[itr] != ';' && aString[itr] != '?' && aString[itr] != '!')
		{
			// copy the character to the new string
			temp[itrp] = aString[itr];
			itrp++;
		}
	}
	// Add a null terminator to the end of the new string
	temp[itrp] = 0;

	// Return the new string
	return temp;
}

void tail(char *aString, int whichWord, char *desiredSuffix)
{
	int numWordsReturned = 0;
	int j = 0;
	char **databuffer = goAway(aString, &numWordsReturned);

	// Get the word specified by whichWord from the array
	char *temp = databuffer[whichWord - 1];

	// Create a buffer to store output string
	char *buffer = malloc(strlen(desiredSuffix) + 1);
	memset(buffer, 0, strlen(buffer));

	// Loop through each character in the selected word and append the desired suffix
	for (int i = 0; i < strlen(temp); i++)
	{
		buffer[j] = temp[i];
		strcat(buffer, desiredSuffix);
		printf("%s\n", buffer);
		memset(buffer, 0, strlen(buffer));
	}
	
	// Clear the buffer and repeat the process for the remaining characters in the word
	free(buffer);
}
