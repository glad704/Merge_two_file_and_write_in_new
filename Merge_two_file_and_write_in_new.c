/*************************************************************************
 * FILE		: Merge_two_file_and_write_in_new().c
 * DESCRIPTION	: Program to merge two files and write it in a new file.
 * AUTHOR	: GLADSON HANSDA
 * DATED	: 19/07/2020
 * **********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr1,*fptr2,*fnew;
	char ch, fname1[20],fname2[20],fname3[40];
	printf("\n\nMerge two files and write it in a new file :\n");
	printf("------------------------------------------------\n");
	printf("Input the 1st file name : ");
	scanf("%s",fname1);
	printf("Input the 2nd file name : ");
	scanf("%s",fname2);
	printf("Input the new file name where to merge the above two files : ");
	scanf("%s",fname3);
	fptr1 = fopen(fname1,"r");
	fptr2 = fopen(fname2,"r");
	if(fptr1==NULL|| fptr2==NULL)
	{
		perror("Error Message ");
		printf("File does not exist or error in opening...!!\n");
		exit(EXIT_FAILURE);
	}

	fnew = fopen(fname3,"w");
	if(fnew==NULL)
	{
		perror("Error Message ");
		printf("File does not exist or error in opening...!!\n");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(fptr1))!=EOF)
	{
		fputc(ch,fnew);
	}
	while((ch=fgetc(fptr2))!=EOF)
	{
		fputc(ch,fnew);
	}
	printf("The two files merged into %s file successfully...!!\n\n",fname3);
	fclose(fptr1);
	fclose(fptr2);
	fclose(fnew);
	return 0;
}

