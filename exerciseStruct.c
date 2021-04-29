#include <stdio.h>
#include <string.h>

#define MAX_LIBRARY_SIZE 10
#define MAX_TITLE_SIZE 50
#define MAX_AUTHOR_SIZE 50
#define MAX_SUBJECT_SIZE 100


typedef struct Books
{
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    int book_id;
} Books;

void printMenu();
void createNewBook(Books * ,int);
void listAllBooks(Books *, int);
void printIndividualBook(Books );

int main()
{
    Books library[MAX_LIBRARY_SIZE];
    int selectedOption;
    int currentSize=0;
    printf("welcome to our library\n");

    while (selectedOption!=-1)
    {
        printMenu();
        scanf("%d",&selectedOption);
        switch (selectedOption)
        {
            case 1:
                createNewBook(library,currentSize);
                currentSize++;
                break;
            case 2:
                listAllBooks(library,currentSize);
                break;
            default:
                break;
        }

    } 
    return 0;
}

void printMenu(){
    printf("\nPlease press 1 to create a new book\n");
    printf("Please press 2 to list all the books\n");
    printf("Please press -1 to exit our system\n");
    return;

}

void createNewBook(Books * library, int index){
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    int book_id;

    printf("please enter the title : \n");
    scanf("%s",title);
    printf("please enter the author : \n");
    scanf("%s",author);

    printf("please enter the subject : \n");
    scanf("%s",subject);

    printf("please enter the book_id : \n");
    scanf("%d",&book_id);

    Books newOne;
    strcpy(newOne.title, title);
    strcpy(newOne.author, author);
    strcpy(newOne.subject, subject);
    newOne.book_id = book_id;

    library[index]=newOne;

}
void listAllBooks(Books * library, int currentSize){
    int i;
    printf("*******Listing******* \n");
    
    for ( i = 0; i < currentSize; i++)
    {
        printIndividualBook(library[i]);
        printf("--------\n");

    }
    printf("************** \n");
    printf("Done \n");
    
}

void printIndividualBook(Books individual){
    printf("title : %s\n", individual.title);
    printf("author : %s\n", individual.author);
    printf("subject : %s\n", individual.subject);
    printf("book_id : %d\n", individual.book_id);

}