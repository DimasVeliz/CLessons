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
    char selectedOption;
    int currentSize=0;
    printf("welcome to our library\n");

    do
    {
        printMenu();
        scanf("%c",selectedOption);
        switch (selectedOption)
        {
        case 'n':
            createNewBook(library,currentSize);
            currentSize++;
            break;
        case 'l':
            listAllBooks(library,currentSize);
            break;
        default:
            break;
        }

    } while (selectedOption!='e');
    
    return 0;
}

void printMenu(){
    printf("Please press n to create a new book\n");
    printf("Please press l to list all the books\n");
    printf("Please press e to exit our system\n");

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
    scanf("%d",book_id);

    Books newOne ={title,author,subject,book_id};
    library[index]=newOne;

}
void listAllBooks(Books * library, int currentSize){
    int i;
    for ( i = 0; i < currentSize; i++)
    {
        printIndividualBook(library[i]);
    }
    
}

void printIndividualBook(Books individual){
    printf("title : %s\n", individual.title);
    printf("author : %s\n", individual.author);
    printf("subject : %s\n", individual.subject);
    printf("book_id : %d\n", individual.book_id);

}