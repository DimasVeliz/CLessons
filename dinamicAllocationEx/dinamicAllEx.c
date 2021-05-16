#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int age;
} Musician;

typedef struct
{
    char name[50];
    int cache;
    int num_musicians;
    Musician *musicians;
} Band;

typedef struct
{
    char name[50];
    int capacity;
} Venue;

int readEntitySize(char *);

int main()
{
    char * filename;

    Venue *venues;
    Musician *musicians;
    Band *bands;

    int venuesSize;
    int musiciansSize;
    int bandsSize;

    filename = "./bands";
    bandsSize = readEntitySize(filename);

    filename = "./musicians";
    musiciansSize = readEntitySize(filename);

    filename = "./venues";
    venuesSize = readEntitySize(filename);

    printf("%d %d %d\n",venuesSize,musiciansSize,bandsSize);

    venues = (Venue *)malloc(venuesSize*sizeof(Venue));
    musicians = (Musician *)malloc(venuesSize*sizeof(Musician));
    bands = (Band *)malloc(venuesSize*sizeof(Band));



    return 0;
}
int readEntitySize(char *filename)
{
    int size;

    FILE *file;
    if (file = fopen(filename, "r"))
    {

        fscanf(file, "%d", &size);
        fclose(file);
        return size;
    }
    return 0;
}
