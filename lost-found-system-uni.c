#include<stdio.h>
#include<string.h>

/* Structure to store lost item details */
struct LostItem
{
    int id;
    char name[50];
    char location[50];
    char owner[50];
    char lostdate[20];
    float reward;
};

/* Structure to store found item details */
struct FoundItem
{
    int id;
    char name[50];
    char location[50];
    char finder[50];
    char founddate[20];
    char contactnumber[15];
};

/* Arrays of structures to store multiple lost and found records */
struct FoundItem foundItems[100];
struct LostItem lostItems[100];

/* Counters to track how many records are currently stored */
int lostCount = 0;
int foundCount = 0;


void addLostItem();
void addFoundItem();
void displayLostItems();
void displayFoundItems();
void searchLostItem();
void searchFoundItem();
void deleteLostItem();
void deleteFoundItem();
void modifyLostItem();
void modifyFoundItem();
void totalReward();
void highestReward();
void countLostItems();
void countFoundItems();
void concatenateStrings();
void checkSubstring();
void returnToMenu();

/*
   This function pauses the program after each operation */
void returnToMenu()
{
    printf("\nPress ENTER to return to the main menu...");
    getchar();   // clears leftover newline
    getchar();   // waits for user to press Enter
}

int main()
{
    int choice;
    char choiceInput[20];   // used to safely read menu input as text first

    do {
        /* Main menu */
        printf("\n\tLost and Found Management System\t\n");
        printf("\n\tUniversity of Moratuwa\t\n\n");
        printf("1. Add Lost Item\n\n");
        printf("2. Add Found Item\n\n");
        printf("3. Display Lost Items\n\n");
        printf("4. Display Found Items\n\n");
        printf("5. Search Lost Item\n\n");
        printf("6. Search Found Item\n\n");
        printf("7. Modify Lost Item\n\n");
        printf("8. Modify Found Item\n\n");
        printf("9. Delete Lost Item\n\n");
        printf("10. Delete Found Item\n\n");
        printf("11. Calculate Total Reward\n\n");
        printf("12. Find the Highest Reward Item\n\n");
        printf("13. Count Lost Items\n\n");
        printf("14. Count Found Items\n\n");
        printf("15. Concatenate Strings\n\n");
        printf("16. Check Substring\n\n");
        printf("17. Exit\n\n");

        printf("Enter your choice : ");
        scanf("%s", choiceInput);

        if(sscanf(choiceInput, "%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a valid menu option.\n");
            continue;
        }

        if(choice < 1 || choice > 17)
        {
            printf("Invalid choice! Please enter a number between 1 and 17.\n");
            continue;
        }

        /* Menu selection using switch-case */
        switch(choice){
            case 1:
                addLostItem();
                returnToMenu();
                break;

            case 2:
                addFoundItem();
                returnToMenu();
                break;

            case 3:
                displayLostItems();
                returnToMenu();
                break;

            case 4:
                displayFoundItems();
                returnToMenu();
                break;

            case 5:
                searchLostItem();
                returnToMenu();
                break;

            case 6:
                searchFoundItem();
                returnToMenu();
                break;

            case 7:
                modifyLostItem();
                returnToMenu();
                break;

            case 8:
                modifyFoundItem();
                returnToMenu();
                break;

            case 9:
                deleteLostItem();
                returnToMenu();
                break;

            case 10:
                deleteFoundItem();
                returnToMenu();
                break;

            case 11:
                totalReward();
                returnToMenu();
                break;

            case 12:
                highestReward();
                returnToMenu();
                break;

            case 13:
                countLostItems();
                returnToMenu();
                break;

            case 14:
                countFoundItems();
                returnToMenu();
                break;

            case 15:
                concatenateStrings();
                returnToMenu();
                break;

            case 16:
                checkSubstring();
                returnToMenu();
                break;

            case 17:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 17);   // repeat until user selects Exit

    return 0;
}

/* Function to add a new lost item */
    void addLostItem()
    {
        char input[50];

        if(lostCount >= 100)
        {
            printf("Lost item list is full!\n");
            return;
        }

        printf("Enter lost item ID: ");
        scanf(" %[^\n]", input);

        if(strcmp(input, "exit") == 0)
        {
            printf("Returning to main menu...\n");
            return;
        }

        if(sscanf(input, "%d", &lostItems[lostCount].id) != 1)
        {
            printf("Invalid input! ID must be a number.\n");
            return;
        }

        printf("Enter lost item name: ");
        scanf(" %[^\n]", lostItems[lostCount].name);
        if(strcmp(lostItems[lostCount].name, "exit") == 0)
        {
            printf("Returning to main menu...\n");
            return;
        }

        printf("Enter the location: ");
        scanf(" %[^\n]", lostItems[lostCount].location);
        if(strcmp(lostItems[lostCount].location, "exit") == 0)
        {
            printf("Returning to main menu...\n");
            return;
        }

        printf("Enter owner name: ");
        scanf(" %[^\n]", lostItems[lostCount].owner);
        if(strcmp(lostItems[lostCount].owner, "exit") == 0)
        {
            printf("Returning to main menu...\n");
            return;
        }

        printf("Enter lost date: ");
        scanf(" %[^\n]", lostItems[lostCount].lostdate);
        if(strcmp(lostItems[lostCount].lostdate, "exit") == 0)
        {
            printf("Returning to main menu...\n");
            return;
        }

        printf("Enter reward: ");
        scanf(" %[^\n]", input);

        if(strcmp(input, "exit") == 0)
        {
            printf("Returning to main menu...\n");
            return;
        }

        if(sscanf(input, "%f", &lostItems[lostCount].reward) != 1)
        {
            printf("Invalid input! Reward must be a number.\n");
            return;
        }

        lostCount++;
        printf("Lost Item added successfully !!\n");
    }

/* Function to add a new found item */
void addFoundItem()
{
    char input[50];

    if(foundCount >= 100)
    {
        printf("Found item list is full!\n");
        return;
    }

    printf("Enter found item ID: ");
    scanf(" %[^\n]", input);

    if(strcmp(input, "exit") == 0)
    {
        printf("Returning to main menu...\n");
        return;
    }

    if(sscanf(input, "%d", &foundItems[foundCount].id) != 1)
    {
        printf("Invalid input! ID must be a number.\n");
        return;
    }

    printf("Enter found item name: ");
    scanf(" %[^\n]", foundItems[foundCount].name);
    if(strcmp(foundItems[foundCount].name, "exit") == 0)
    {
        printf("Returning to main menu...\n");
        return;
    }

    printf("Enter the location: ");
    scanf(" %[^\n]", foundItems[foundCount].location);
    if(strcmp(foundItems[foundCount].location, "exit") == 0)
    {
        printf("Returning to main menu...\n");
        return;
    }

    printf("Enter name of finder: ");
    scanf(" %[^\n]", foundItems[foundCount].finder);
    if(strcmp(foundItems[foundCount].finder, "exit") == 0)
    {
        printf("Returning to main menu...\n");
        return;
    }

    printf("Enter found date: ");
    scanf(" %[^\n]", foundItems[foundCount].founddate);
    if(strcmp(foundItems[foundCount].founddate, "exit") == 0)
    {
        printf("Returning to main menu...\n");
        return;
    }

    printf("Enter contact number: ");
    scanf(" %[^\n]", foundItems[foundCount].contactnumber);
    if(strcmp(foundItems[foundCount].contactnumber, "exit") == 0)
    {
        printf("Returning to main menu...\n");
        return;
    }

    foundCount++;
    printf("Found Item added successfully !!\n");
}


/* Function to display all lost items */
void displayLostItems()
{
    int i;

    if(lostCount == 0)
    {
        printf("No lost items in the list.\n");
        return;
    }

    printf("\n---- Lost Items ----\n");

    for(i = 0; i < lostCount; i++)
    {
        printf("ID:%d   Name:%s   Location:%s   Owner:%s   Lostdate:%s  Reward:%.2f\n",
               lostItems[i].id, lostItems[i].name, lostItems[i].location,
               lostItems[i].owner, lostItems[i].lostdate, lostItems[i].reward);
    }
}

/* Function to display all found items */
void displayFoundItems()
{
    int i;

    if(foundCount == 0)
    {
        printf("No found items in the list.\n");
        return;
    }

    printf("\n---- Found Items ----\n");

    for(i = 0; i < foundCount; i++)
    {
        printf("ID:%d \nName:%s \nLocation:%s \nFinder:%s \nFoundDate:%s \nContactNumber:%s \n",
               foundItems[i].id, foundItems[i].name, foundItems[i].location,
               foundItems[i].finder, foundItems[i].founddate, foundItems[i].contactnumber);
    }
}

/* Function to search lost items by item name */
void searchLostItem()
{
    char searchName[50];
    int i, found = 0;

    if(lostCount == 0)
    {
        printf("No lost items available to search.\n");
        return;
    }

    printf("Enter lost item name to search : ");
    scanf("%s", searchName);

    for(i = 0; i < lostCount; i++)
    {
        if(strcmp(lostItems[i].name, searchName) == 0)
        {
            printf("Item Found!\n");
            printf("ID:%d\n", lostItems[i].id);
            printf("Name:%s\n", lostItems[i].name);
            printf("Location:%s\n", lostItems[i].location);
            printf("Owner:%s\n", lostItems[i].owner);
            printf("Lost Date:%s\n", lostItems[i].lostdate);
            printf("Reward:%.2f\n", lostItems[i].reward);
            found = 1;
        }
    }

    if(!found)
        printf("Item not found !!\n");
}

/* Function to search found items by item name */
void searchFoundItem()
{
    char searchName[50];
    int i, found = 0;

    if(foundCount == 0)
    {
        printf("No found items available to search.\n");
        return;
    }

    printf("Enter found item name to search : ");
    scanf("%s", searchName);

    for(i = 0; i < foundCount; i++)
    {
        if(strcmp(foundItems[i].name, searchName) == 0)
        {
            printf("Item Found!\n");
            printf("ID:%d\n", foundItems[i].id);
            printf("Name:%s\n", foundItems[i].name);
            printf("Location:%s\n", foundItems[i].location);
            printf("Finder:%s\n", foundItems[i].finder);
            printf("Found Date:%s\n", foundItems[i].founddate);
            printf("Contact Number:%s\n", foundItems[i].contactnumber);
            found = 1;
        }
    }

    if(!found)
        printf("Item not found !!\n");
}

/* Function to modify lost item details */
void modifyLostItem()
{
    int id, i;
    char input[50];

    if(lostCount == 0)
    {
        printf("No lost items available to modify.\n");
        return;
    }

    printf("Enter Lost Item ID to modify: ");
    scanf(" %[^\n]", input);

    if(sscanf(input, "%d", &id) != 1)
    {
        printf("Invalid input! ID must be a number.\n");
        return;
    }

    for(i = 0; i < lostCount; i++)
    {
        if(lostItems[i].id == id)
        {
            printf("Enter New Name (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(lostItems[i].name, input);

            printf("Enter New Location (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(lostItems[i].location, input);

            printf("Enter New Owner (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(lostItems[i].owner, input);

            printf("Enter New Lost Date (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(lostItems[i].lostdate, input);

            printf("Enter New Reward (type 'keep' to keep current): ");
            scanf("%s", input);
            if(strcmp(input, "keep") != 0)
            {
                if(sscanf(input, "%f", &lostItems[i].reward) != 1)
                {
                    printf("Invalid input! Reward must be a number.\n");
                    return;
                }
            }

            printf("Record Updated!\n");
            return;
        }
    }

    printf("Record Not Found\n");
}


/* Function to modify found item details */
void modifyFoundItem()
{
    int id, i;
    char input[50];

    if(foundCount == 0)
    {
        printf("No found items available to modify.\n");
        return;
    }

    printf("Enter Found Item ID to modify: ");
    scanf(" %[^\n]", input);

    if(sscanf(input, "%d", &id) != 1)
    {
        printf("Invalid input! ID must be a number.\n");
        return;
    }

    for(i = 0; i < foundCount; i++)
    {
        if(foundItems[i].id == id)
        {
            printf("Enter New Name (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(foundItems[i].name, input);

            printf("Enter New Location (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(foundItems[i].location, input);

            printf("Enter New Finder (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(foundItems[i].finder, input);

            printf("Enter New Found Date (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(foundItems[i].founddate, input);

            printf("Enter New Contact Number (type 'keep' to keep current): ");
            scanf(" %[^\n]", input);
            if(strcmp(input, "keep") != 0)
                strcpy(foundItems[i].contactnumber, input);

            printf("Record Updated!\n");
            return;
        }
    }

    printf("Record Not Found\n");
}


/* Function to delete lost item by ID */
void deleteLostItem()
{
    int id, i, j;
    char input[50];

    if(lostCount == 0)
    {
        printf("No lost items available to delete.\n");
        return;
    }

    printf("Enter Lost Item ID to Delete: ");
    scanf(" %[^\n]", input);

    if(sscanf(input, "%d", &id) != 1)
    {
        printf("Invalid input! ID must be a number.\n");
        return;
    }

    for(i = 0; i < lostCount; i++)
    {
        if(lostItems[i].id == id)
        {
            for(j = i; j < lostCount - 1; j++)
            {
                lostItems[j] = lostItems[j + 1];
            }
            lostCount--;
            printf("Record Deleted!\n");
            return;
        }
    }
    printf("Record Not Found\n");
}


/* Function to delete found item by ID */
void deleteFoundItem()
{
    int id, i, j;
    char input[50];

    if(foundCount == 0)
    {
        printf("No found items available to delete.\n");
        return;
    }

    printf("Enter Found Item ID to Delete: ");
    scanf(" %[^\n]", input);

    if(sscanf(input, "%d", &id) != 1)
    {
        printf("Invalid input! ID must be a number.\n");
        return;
    }

    for(i = 0; i < foundCount; i++)
    {
        if(foundItems[i].id == id)
        {
            for(j = i; j < foundCount - 1; j++)
            {
                foundItems[j] = foundItems[j + 1];
            }
            foundCount--;
            printf("Record Deleted!\n");
            return;
        }
    }
    printf("Record Not Found\n");
}


/* Function to calculate total reward of all lost items */
void totalReward()
{
    float total = 0;
    int i;

    for(i = 0; i < lostCount; i++)
    {
        total += lostItems[i].reward;
    }

    printf("Total Reward for Lost Items: %.2f\n", total);
}

/* Function to find lost item with highest reward */
void highestReward()
{
    int i, index = -1;
    float max = 0;

    if(lostCount == 0)
    {
        printf("No lost items available.\n");
        return;
    }

    for(i = 0; i < lostCount; i++)
    {
        if(lostItems[i].reward > max)
        {
            max = lostItems[i].reward;
            index = i;
        }
    }

    if(index != -1)
    {
        printf("Highest Reward Item: %s (%.2f)\n", lostItems[index].name, lostItems[index].reward);
    }
}

/* Function to count lost items */
void countLostItems()
{
    if(lostCount == 0)
    {
        printf("No lost items in the list.\n");
        return;
    }

    printf("Total number of lost items: %d\n", lostCount);
}

/* Function to count found items */
void countFoundItems()
{
    if(foundCount == 0)
    {
        printf("No found items in the list.\n");
        return;
    }

    printf("Total number of found items: %d\n", foundCount);
}

/* Function to concatenate item name and location */
void concatenateStrings()
{
    int i;
    char result[100];

    if(lostCount == 0)
    {
        printf("No lost items available.\n");
        return;
    }

    for(i = 0; i < lostCount; i++)
    {
        strcpy(result, lostItems[i].name);
        strcat(result, " - ");
        strcat(result, lostItems[i].location);

        printf("Combined Description: %s\n", result);
    }
}

/* Function to check whether a word is a substring of lost item names */
void checkSubstring()
{
    char word[50];
    int i;

    printf("Enter word to search: ");
    scanf("%s", word);

    for(i = 0; i < lostCount; i++)
    {
        if(strstr(lostItems[i].name, word))
        {
            printf("Found in item: %s\n", lostItems[i].name);
        }
    }
}
