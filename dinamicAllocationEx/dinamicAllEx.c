#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printIndividualVenues(Venue);
void printAllVenues(Venue *, int);

void printIndividualBand(Band);
void printAllBands(Band *, int);

void printIndividualMusician(Musician);
void printAllMusicians(Musician *, int);

void printBandNamesAsAppeared(char **, int);

int readAllVenues(Venue *, int, char *);
int readAllBands(Band *, int, char *);
int readAllMusicians(Musician *, int, char *, char **);
void assingBandsFromListOFMusicians(Band *, Musician *, char **, int , int );

int main()
{
    int i;

    char *filenameM;
    char *filenameB;
    char *filenameV;

    Venue *venues;
    Musician *musicians;
    Band *bands;

    int venuesSize;
    int musiciansSize;
    int bandsSize;
  

    char **musiciansBandNames;

    filenameB = "./bands";
    bandsSize = readEntitySize(filenameB);
    filenameM = "./musicians";
    musiciansSize = readEntitySize(filenameM);
    filenameV = "./venues";
    venuesSize = readEntitySize(filenameV);

    venues = (Venue *)malloc(venuesSize * sizeof(Venue));
    bands = (Band *)malloc(venuesSize * sizeof(Band));
    musicians = (Musician *)malloc(musiciansSize * sizeof(Musician));
    musiciansBandNames = (char **)malloc(musiciansSize * sizeof(char *));
    for (i = 0; i < musiciansSize; i++)
    {
        musiciansBandNames[i] = (char *)malloc(50 * sizeof(char));
    }

    readAllVenues(venues, venuesSize, filenameV);
    /*printAllVenues(venues, venuesSize);*/

    readAllBands(bands, bandsSize, filenameB);
    /*printAllBands(bands, bandsSize);*/

    readAllMusicians(musicians, musiciansSize, filenameM, musiciansBandNames);

    /*assigning individual bands to each band from list of musicians*/
    assingBandsFromListOFMusicians(bands, musicians, musiciansBandNames, bandsSize, musiciansSize);

    /*printAllMusicians(musicians, musiciansSize);*/

    /*printf("\nBand names are:\n");*/
    /*printBandNamesAsAppeared(musiciansBandNames, musiciansSize);*/

    /*
    Venue v1;
    Venue v2;
    Venue v3;

    v1.capacity = 27;
    strcpy(v1.name, "testing 1");

    v2.capacity = 21;
    strcpy(v2.name, "testing 2");

    v3.capacity = 80;
    strcpy(v3.name, "testing 3");

    venues[0] = v1;
    venues[1] = v2;
    venues[2] = v3;

*/

    printAllBands(bands, bandsSize);

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

void printBandNamesAsAppeared(char **bandNames, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%s", bandNames[i]);
    }
}

void printAllMusicians(Musician *musicians, int musicianSize)
{
    int i;

    for (i = 0; i < musicianSize; i++)
    {
        printIndividualMusician(musicians[i]);
    }
}
void printIndividualMusician(Musician item)
{
    printf("%s", item.name);
    printf("%d\n", item.age);
}

void printAllBands(Band *bands, int bandsSize)
{
    int i;

    for (i = 0; i < bandsSize; i++)
    {
        printIndividualBand(bands[i]);
    }
}
void printIndividualBand(Band item)
{
    printf("%s", item.name);
    printf("%d\n", item.cache);
    printf("%d\n", item.num_musicians);
    printf("Imprimiendo Banda:\n");
    printAllMusicians(item.musicians, item.num_musicians);
    printf("done\n");
}

void printAllVenues(Venue *venues, int venuesSize)
{
    int i;

    for (i = 0; i < venuesSize; i++)
    {
        printIndividualVenues(venues[i]);
    }
}
void printIndividualVenues(Venue item)
{
    printf("%s", item.name);
    printf("%d\n", item.capacity);
}

int readAllVenues(Venue *venues, int maxSize, char *fileName)
{
    int index = 0;
    int flagLine = 0;

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    int capacityFromFile;
    Venue newOne;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    /*ignoring first line*/
    getline(&line, &len, fp);

    while ((read = getline(&line, &len, fp)) != -1)
    {

        if (flagLine == 0)
        {
            strcpy(newOne.name, line);
            flagLine++;
        }

        else
        {
            capacityFromFile = atoi(line);
            newOne.capacity = capacityFromFile;
            flagLine = 0;

            /*adding the entitity*/
            venues[index] = newOne;
            index++;
        }
    }

    fclose(fp);
    if (line)
        free(line);
    return index;
}

int readAllBands(Band *bands, int maxSize, char *fileName)
{
    int i;

    int index = 0;
    int flagLine = 0;

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    int cacheFromFile;
    int amountOFMusicians;
    Band newOne;
    Musician *musicians;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    /*ignoring first line*/
    getline(&line, &len, fp);

    while ((read = getline(&line, &len, fp)) != -1)
    {

        if (flagLine == 0)
        {
            strcpy(newOne.name, line);
            flagLine++;
        }

        else if (flagLine == 1)
        {
            cacheFromFile = atoi(line);
            newOne.cache = cacheFromFile;
            flagLine++;
        }

        else
        {
            amountOFMusicians = atoi(line);
            newOne.num_musicians = amountOFMusicians;
            flagLine = 0;

            /*adding the entitity*/
            bands[index] = newOne;
            index++;
        }
    }

    fclose(fp);
    if (line)
        free(line);
    return index;
}

int readAllMusicians(Musician *musicians, int maxSize, char *fileName, char **musicianBandNames)
{
    int index = 0;
    int flagLine = 0;

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    int age;
    Musician newOne;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    /*ignoring first line*/
    getline(&line, &len, fp);

    while ((read = getline(&line, &len, fp)) != -1)
    {

        if (flagLine == 0)
        {
            strcpy(newOne.name, line);
            flagLine++;
        }

        else if (flagLine == 1)
        {
            strcpy(musicianBandNames[index], line);
            flagLine++;
        }

        else
        {
            age = atoi(line);
            newOne.age = age;
            flagLine = 0;

            /*adding the entitity*/
            musicians[index] = newOne;
            index++;
        }
    }

    fclose(fp);
    if (line)
        free(line);
    return index;
}

void assingBandsFromListOFMusicians(Band *bands, Musician *musicians, char **musiciansBandNames, int bandsSize, int musiciansSize)
{
    int i;
    int j;
    int numMusiciansTMP;
    int whereToPlaceMusician;
    for (i = 0; i < bandsSize; i++)
    {
        numMusiciansTMP = bands[i].num_musicians;

        bands[i].musicians = (Musician *)malloc(numMusiciansTMP * sizeof(Musician));
        whereToPlaceMusician = 0;

        for (j = 0; j < musiciansSize; j++)
        {
            if (strcmp(bands[i].name, musiciansBandNames[j]) == 0)
            {
                bands[i].musicians[whereToPlaceMusician] = musicians[j];
                whereToPlaceMusician++;
            }
        }
    }
}