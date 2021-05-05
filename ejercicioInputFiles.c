#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_COSTUMES 100
#define MAX_NUMBER_OF_ACTORS 100
#define MAX_NUMBER_OF_SEARCHS 100

#define MAX_COSTUME_SIZE_STRING_LENGTH 3
#define MAX_EMAIL_STRING_LENGTH 30
#define MAX_PHONE_STRING_LENGTH 15
#define MAX_ACTOR_NAME_STRING_LENGTH 30

typedef char CostumeSize[MAX_COSTUME_SIZE_STRING_LENGTH];

typedef struct
{
    char email[MAX_EMAIL_STRING_LENGTH];
    char phone[MAX_PHONE_STRING_LENGTH];
} ContactInformation;

typedef struct
{
    int id;
    char cat;
    int weight;
    CostumeSize size;
} Costume;

typedef struct
{
    char name[MAX_ACTOR_NAME_STRING_LENGTH];
    int age;
    int height;
    CostumeSize costume_size;
    ContactInformation contact_information;
} Actor;

typedef struct
{
    char cat;
    char name[MAX_ACTOR_NAME_STRING_LENGTH];

} Search;

int fileExist(char []);
int loadIndividualCostume(Costume [], int, char [], int);
int loadAllCostumes(Costume [], int, char []);
void printCostumes(Costume [], int);
void printIndividualCostume(Costume);

int loadIndividualActor(Actor [], int, char [], int);
int loadAllActors(Actor [], int, char []);
void printActors(Actor [], int);
void printIndividualActor(Actor);

int loadIndividualSearch(Search [], int, char [], int);
int loadAllSearchs(Search [], int, char []);
void printSearchs(Search [], int);
void printIndividualSearch(Search);

void showAllRelationships(Search [], Costume [], Actor [],int,int,int);

int findCorrespondingPersonInActorsList(Actor [], Actor, char [], int);
int countOutfitsThatMatch(char [], char, Costume [], int);



int main()
{
    int flagActorsLoaded = 0;
    int flagCostumesLoaded = 0;
    int flagSearchLoaded = 0;

    Costume allCostumes[MAX_NUMBER_OF_COSTUMES];
    Actor allActors[MAX_NUMBER_OF_ACTORS];
    Search allSearchs[MAX_NUMBER_OF_SEARCHS];

    int currentNumberOFActors = 0;
    int currentNumberOFCostumes = 0;
    int currentNumberOFSearchs = 0;

    char userOption[7];
    while (strcmp(userOption, "exit") != 0)
    {

        printf("Choose actions from: actors | costumes | search | exit\nAction:");
        scanf("%s", userOption);
        if (strcmp(userOption, "actors") == 0)
        {
            if (flagActorsLoaded == 0)
            {
                char filenameActors[256];
                printf("Introduce the file name for actors\n");
                scanf("%s", filenameActors);
                if (fileExist(filenameActors) == 0)
                {
                    printf("Enter a valid file name\n");
                }
                else
                {
                    flagActorsLoaded = 1;
                    currentNumberOFActors =loadAllActors(allActors, currentNumberOFActors, filenameActors);
                }
            }
            else
            {
                printf("Actors were already loaded\n");
            }
        }
        else if (strcmp(userOption, "costumes") == 0)
        {
            if (flagCostumesLoaded == 0)
            {
                char filenameCostumes[256];
                printf("Introduce the file name for costumes\n");
                scanf("%s", filenameCostumes);
                if (fileExist(filenameCostumes) == 0)
                {
                    printf("Enter a valid file name\n");
                }
                else
                {
                    flagCostumesLoaded = 1;
                    currentNumberOFCostumes =loadAllCostumes(allCostumes, currentNumberOFCostumes, filenameCostumes);
                }
            }
            else
            {
                printf("Costumes were already loaded\n");
            }
        }

        else if (strcmp(userOption, "search") == 0)
        {
            if (flagActorsLoaded == 0 || flagCostumesLoaded == 0)
            {
                printf("Either actors or costumes files were not loaded\n");
            }

            else if (flagSearchLoaded == 0)
            {
                char filenameSearches[256];
                printf("Introduce the file name for searches\n");
                scanf("%s", filenameSearches);
                if (fileExist(filenameSearches) == 0)
                {
                    printf("Enter a valid file name\n");
                }
                else
                {
                    flagSearchLoaded = 1;
                    currentNumberOFSearchs =loadAllSearchs(allSearchs, currentNumberOFSearchs, filenameSearches);
                    showAllRelationships(allSearchs, allCostumes, allActors,currentNumberOFSearchs,currentNumberOFCostumes,currentNumberOFActors);
                }
            }
            else
            {
                printf("Searches were already loaded\n");
            }
        }
        else if (strcmp(userOption, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("You didnt enter any valid option\n");
        }
    }

    printf("Thanks\n");
    return 0;
}

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

int loadIndividualCostume(Costume allCostumes[], int index, char strLine[], int sizeLine)
{

    Costume newOne;
    int separatorsPositions[3];
    int indexSeparators = 0;
    for (int i = 1; i < sizeLine; i++)
    {
        if (strLine[i] == '>')
        {
            separatorsPositions[indexSeparators] = i;
            indexSeparators++;
        }
    }

    char letter[1];
    char firstNumStr[32];
    char secondNumberStr[32];
    char sizeChar[3];

    /*extracting id from line */
    int fNumEnds = separatorsPositions[0] - 2;
    strncpy(firstNumStr, strLine + 1, fNumEnds);
    firstNumStr[fNumEnds] = '\0';
    int id = atoi(firstNumStr);

    /*extracting category from line */

    char cat = strLine[separatorsPositions[0] + 2];

    /*extracting weight from line */

    int sNumStarts = separatorsPositions[1] + 2;
    int sNumEnds = separatorsPositions[2] - 2;
    strncpy(secondNumberStr, strLine + sNumStarts, sNumEnds - sNumStarts + 1);
    secondNumberStr[sNumEnds - sNumStarts + 1] = '\0';
    int weight = atoi(secondNumberStr);

    /*extracting size from line */
    int sizeStarts = separatorsPositions[2] + 2;
    int sizeEnds = sizeLine - 2;
    strncpy(sizeChar, strLine + sizeStarts, sizeEnds - sizeStarts + 1);
    sizeChar[sizeEnds - sizeStarts + 1] = '\0';

    newOne.id = id;
    strcpy(newOne.size, sizeChar);
    newOne.cat = cat;
    newOne.weight = weight;

    /*
    printf("%d ",newOne.id);
    printf("%c  ",newOne.cat);
    printf("%d ",newOne.weight);
    printf("%s \n",newOne.size);
    */
    allCostumes[index++] = newOne;
    return index;
}
int loadAllCostumes(Costume allCostumes[], int currentSize, char fileName[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        return currentSize;

    while ((read = getline(&line, &len, fp)) != -1)
    {

        currentSize = loadIndividualCostume(allCostumes, currentSize, line, read);
    }
    printCostumes(allCostumes, currentSize);

    fclose(fp);
    return currentSize;
}

void printCostumes(Costume allCostumes [], int size)
{
    for (int i = 0; i < size; i++)
    {
        printIndividualCostume(allCostumes[i]);
    }
}
void printIndividualCostume(Costume c)
{
    printf("%d ", c.id);
    printf("%c  ", c.cat);
    printf("%d ", c.weight);
    printf("%s \n", c.size);
}

int loadIndividualActor(Actor allActors[], int index, char strLine [], int sizeLine)
{
    Actor newOne;
    int separatorsPositions[3];
    int indexSeparators = 0;
    for (int i = 1; i < sizeLine; i++)
    {
        if (strLine[i] == '-')
        {
            separatorsPositions[indexSeparators] = i;
            indexSeparators++;
        }
    }

    char name[MAX_ACTOR_NAME_STRING_LENGTH];
    char ageChar[32];
    char sizeChar[MAX_COSTUME_SIZE_STRING_LENGTH];
    char email[MAX_EMAIL_STRING_LENGTH];

    /*extracting name from line */
    int nameEnds = separatorsPositions[0] - 2;
    strncpy(name, strLine + 1, nameEnds);
    name[nameEnds] = '\0';

    /*extracting age from line */
    int ageStarts = separatorsPositions[0] + 2;
    int ageEnds = separatorsPositions[1] - 2;

    strncpy(ageChar, strLine + ageStarts, ageEnds - ageStarts + 1);
    ageChar[ageEnds - ageStarts + 1] = '\0';
    int age = atoi(ageChar);

    /*extracting size from line */
    int sizeStarts = separatorsPositions[1] + 2;
    int sizeEnds = separatorsPositions[2] - 2;
    strncpy(sizeChar, strLine + sizeStarts, sizeEnds - sizeStarts + 1);
    sizeChar[sizeEnds - sizeStarts + 1] = '\0';

    /*extracting email from line */
    int emailStars = separatorsPositions[2] + 2;
    int emailEnds = sizeLine - 3;
    strncpy(email, strLine + emailStars, emailEnds - emailStars + 1);
    email[emailEnds - emailStars + 1] = '\0';

    
    strcpy(newOne.name, name);
    strcpy(newOne.costume_size, sizeChar);
    newOne.age = age;
    strcpy(newOne.contact_information.email, email);

    /*
    printf("%s ",newOne.name);
    printf("%s  ",newOne.costume_size);
    printf("%d ",newOne.age);
    printf("%s \n",newOne.contact_information.email);
    */
    allActors[index++] = newOne;
    return index;
}
int loadAllActors(Actor allActors[], int currentSize, char fileName[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        return currentSize;

    while ((read = getline(&line, &len, fp)) != -1)
    {

        currentSize = loadIndividualActor(allActors, currentSize, line, read);
    }
    printActors(allActors, currentSize);

    fclose(fp);
    return currentSize;
}

void printIndividualActor(Actor newOne)
{

    printf("%s ", newOne.name);
    printf("%s  ", newOne.costume_size);
    printf("%d ", newOne.age);
    printf("%s \n", newOne.contact_information.email);
}
void printActors(Actor allActors[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printIndividualActor(allActors[i]);
    }
}

int loadIndividualSearch(Search allSearches[], int index, char strLine[], int sizeLine)
{
    Search newOne;
    int separatorsPositions[1];
    int indexSeparators = 0;
    for (int i = 0; i < sizeLine; i++)
    {
        if (strLine[i] == '-')
        {
            separatorsPositions[indexSeparators] = i;
            indexSeparators++;
        }
    }

    char category;
    char name[MAX_ACTOR_NAME_STRING_LENGTH];

    /*extracting category from line*/
    category = strLine[0];

    /*extracting name from line */
    int nameStarts = separatorsPositions[0] + 2;
    int nameEnds = sizeLine - 2;
    strncpy(name, strLine + nameStarts, nameEnds - nameStarts + 1);
    name[nameEnds - nameStarts + 1] = '\0';

    newOne.cat = category;
    strcpy(newOne.name, name);

    allSearches[index++] = newOne;
    return index;
}
int loadAllSearchs(Search allSearches[], int currentSize, char fileName[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        return currentSize;

    while ((read = getline(&line, &len, fp)) != -1)
    {

        currentSize = loadIndividualSearch(allSearches, currentSize, line, read);
    }
    /* printSearchs(allSearches, currentSize); */

    fclose(fp);
    return currentSize;
}

void printIndividualSearch(Search newOne)
{

    printf("%c ", newOne.cat);
    printf("%s \n", newOne.name);
}
void printSearchs(Search allSearchs[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printIndividualSearch(allSearchs[i]);
    }
}

void showAllRelationships(Search searches[], Costume costumes[], Actor actors[], int sS, int sC, int sA)
{

    char category;
    char name[MAX_ACTOR_NAME_STRING_LENGTH];
    char size[MAX_COSTUME_SIZE_STRING_LENGTH];

    for (int i = 0; i < sS; i++)
    {
        
        category = searches[i].cat;
        strcpy(name, searches[i].name);

        Actor correspondingPerson;
        int foundATIndex = findCorrespondingPersonInActorsList(actors, correspondingPerson, name, sA);
        if (foundATIndex == -1)
        {
            printf("Actor/Actress %s not found\n", searches[i].name);
        }
        else
        {
            strcpy(correspondingPerson.costume_size,actors[foundATIndex].costume_size);

            strcpy(size, correspondingPerson.costume_size);
            int amount = countOutfitsThatMatch(size, category, costumes, sC);
            printf("Actor/Actress %s\n", name);
            printf("%d dresses found for category %c\n\n", amount, category);
        }
    }
}

int findCorrespondingPersonInActorsList(Actor actors[], Actor correspondingPerson, char name[], int sizeActors)
{
    for (int i = 0; i < sizeActors; i++)
    {
        if (strcmp(actors[i].name,name)==0)
        {
            
            return i;
        }
        
    }
    return -1;
    
}
int countOutfitsThatMatch(char sizePeople[], char category, Costume  costumes[], int sizeCostumes){
    int counter =0;
    for (int i = 0; i < sizeCostumes; i++)
    {
        int matchCat= -1;
        char cat=costumes[i].cat;
        if (cat==category)
        {
            matchCat=1;
        }
        
        int matchSize= strcmp(costumes[i].size,sizePeople);

        if (matchCat==1 && matchSize==0)
        {
            counter++;
        }
        
    }
    return counter;
}