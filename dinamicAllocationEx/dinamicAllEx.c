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

int readAllVenues(Venue *, int, char *);
int readAllBands(Band *, int, char *);
int readAllMusicians(Musician *, int, char *, char **);
void assingBandsFromListOFMusicians(Band *, Musician *, char **, int, int);

int fileExist(char[]);

void baseMenu();
void mainMenu();
void printSubMenuOption1();
void printSubMenuOption2();
void printSubMenuOption3();

float calculateTicketPrice(int, int);




int fileExist(char filename[])
{
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
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
    printf("Members\n");
    for (i = 0; i < musicianSize; i++)
    {
        printf("-");
        printIndividualMusician(musicians[i]);
    }
}
void printIndividualMusician(Musician item)
{
    printf("%s", item.name);
}

void printAllBands(Band *bands, int bandsSize)
{
    int i;

    for (i = 0; i < bandsSize; i++)
    {
        printf("%d- ", i + 1);
        printIndividualBand(bands[i]);
    }
}
void printIndividualBand(Band item)
{
    printf("%s", item.name);
}

void printAllVenues(Venue *venues, int venuesSize)
{
    int i;

    for (i = 0; i < venuesSize; i++)
    {
        printf("%d- ", i + 1);
        printIndividualVenues(venues[i]);
    }
}
void printIndividualVenues(Venue item)
{
    printf("%s", item.name);
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

void mainMenu()
{
    printf("1 show  Bands or show venues |2 Calculate ticket price | 3 show band members | 4 exit.\n select option : ");
}
void printSubMenuOption1()
{
    printf("1 show bands | 2 show venues.\n select option : ");
}
void printSubMenuOption2()
{
    printf("Select band number and then venue number: ");
}
void printSubMenuOption3()
{
    printf("Select band number: ");
}

float calculateTicketPrice(int cache, int capacity)
{
    return (float)cache / capacity;
}



int main()
{
    int i;
    int loadedVenues = 0;
    int loadedBands = 0;
    int loadedMusicians = 0;

    int optionMenu;
    int childOption;
    int bandNumber;
    int venueNumber;
    float resultTicket;

    char filenameM[50];
    char filenameB[50];
    char filenameV[50];

    Venue *venues;
    Musician *musicians;
    Band *bands;

    int venuesSize;
    int musiciansSize;
    int bandsSize;

    char **musiciansBandNames;

    while (loadedVenues == 0 || loadedBands == 0 || loadedMusicians == 0)
    {
        printf("Welcome!\nIntroduce the file names:\n");
        printf("-bands: ");
        scanf("%s", filenameB);
        printf("-musicians: ");
        scanf("%s", filenameM);
        printf("-venues: ");
        scanf("%s", filenameV);

        loadedBands = fileExist(filenameB);
        loadedMusicians = fileExist(filenameM);
        loadedVenues = fileExist(filenameV);

        if (loadedBands==0)
        {
            printf("Cannot open file '%s'\n",filenameB);
        }
        if (loadedMusicians==0)
        {
            printf("Cannot open file '%s'\n",filenameM);
        }
        if (loadedVenues==0)
        {
            printf("Cannot open file '%s'\n",filenameV);
        }
        
    }

    bandsSize = readEntitySize(filenameB);

    musiciansSize = readEntitySize(filenameM);

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

    while (1)
    {
        mainMenu();
        scanf("%d", &optionMenu);
        if (optionMenu == 1)
        {
            printSubMenuOption1();
            scanf("%d", &childOption);
            if (childOption == 1)
            {
                printAllBands(bands, bandsSize);
            }
            else if (childOption == 2)
            {
                printAllVenues(venues, venuesSize);
            }
            else
            {
                printf("Wrong option number\n");
            }
        }
        else if (optionMenu == 2)
        {
            printSubMenuOption2();
            scanf("%d %d", &bandNumber, &venueNumber);
            resultTicket = calculateTicketPrice(bands[bandNumber - 1].cache, venues[venueNumber - 1].capacity);
            printf("The minimum ticket price is %.2f\n", resultTicket);
        }
        else if (optionMenu == 3)
        {
            printSubMenuOption3();
            scanf("%d", &bandNumber);
            printAllMusicians(bands[bandNumber - 1].musicians, bands[bandNumber - 1].num_musicians);
        }
        else if (optionMenu == 4)
        {
            printf("bye!\n");
            break;
        }
        else
        {
            printf("Wrong option number\n");
        }
    }

    return 0;
}
