#include <stdio.h>
#include <string.h>

typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Books;

int main()
{

   
    struct Books Book1; /* Declare Book1 of type Book  */

    /* book 1 specification */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

  

    /* print Book1 info */
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 book_id : %d\n", Book1.book_id);

   

     /* print thirdBook info using Aliases, manual initialization */
    Books thirdBook={"Tensorflow","O'Really","Object Detection",7};
    printf("Book 3 title : %s\n", thirdBook.title);
    printf("Book 3 author : %s\n", thirdBook.author);
    printf("Book 3 subject : %s\n", thirdBook.subject);
    printf("Book 3 book_id : %d\n", thirdBook.book_id);


    Books * pointerBook= &thirdBook;

    printf("%s\n",pointerBook->title);

    return 0;
}