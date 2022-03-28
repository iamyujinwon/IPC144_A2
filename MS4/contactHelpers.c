//==============================================
// Name:           Yujin Won
// Student Number: 153565197
// Email:          ywon9@myseneca.ca
// Section:        NGG
// Date:           2020-07-28
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#define MAXCONTACTS 5

#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
  int value;
  char newline;

  scanf("%d%c", &value, &newline);

  while (newline != '\n')
  {
    clearKeyboard();
    printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    scanf("%d%c", &value, &newline);
  }

  return value;
}


// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
  int value;

  value = getInt();

  while (value < min || value > max)
  {
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
    value = getInt();
  }

  return value;
}

// yes function definition goes here:
int yes(void)
{
  char input;
  char newline;
  
  scanf("%c%c", &input, &newline);

  while (newline != '\n' && (input != 'Y' || input != 'y' || input != 'N' || input != 'n'))
  {
    clearKeyboard();
    printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    scanf("%c%c", &input, &newline);
  }

  if (input == 'y' || input == 'Y')
  {
    return 1;
  }

  else
  {
    return 0;
  }
}

// menu function definition goes here:
int menu(void)
{
  int option;

  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n");
  printf("\n");
  printf("Select an option:> ");
  option = getInt();

  while (option < 0 || option > 6)
  {
    printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
    option = getInt();
  }

  printf("\n");

  return option;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
  int running = 1;

  struct Contact default_contacts[MAXCONTACTS] =  
  { { { "Rick", {'\0'}, "Grimes" },
      { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
      { "4161112222", "4162223333", "4163334444" } },
    {
      { "Maggie", "R.", "Greene" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9051112222", "9052223333", "9053334444" } },
    {
      { "Morgan", "A.", "Jones" },
      { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
      { "7051112222", "7052223333", "7053334444" } },
    {
      { "Sasha", {'\0'}, "Williams" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9052223333", "9052223333", "9054445555" } },
  };

  while (running)
  {
    int option = menu();

    switch (option)
    {
    case 1:
      displayContacts(default_contacts, MAXCONTACTS);
      pause();
      break;

    case 2:
      addContact(default_contacts, MAXCONTACTS);
      printf("\n");
      pause();
      break;

    case 3:
      updateContact(default_contacts, MAXCONTACTS);
      printf("\n");
      pause();
      break;

    case 4:
      deleteContact(default_contacts, MAXCONTACTS);
      printf("\n");
      pause();
      break;

    case 5:
      searchContacts(default_contacts, MAXCONTACTS);
      pause();
      break;

    case 6:
      sortContacts(default_contacts, MAXCONTACTS);
      printf("\n");
      pause();
      break;

    case 0:
      printf("Exit the program? (Y)es/(N)o: ");
      if (yes())
      {
        printf("\n");
        printf("Contact Management System: terminated");

        running = 0;
      }

      break;
    }
    printf("\n");
  }
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
  while (1)
  {
    scanf("%s", phoneNum); 
    clearKeyboard();

    // (String Length Function: validate entry of 10 characters)
    if (strlen(phoneNum) == 10)
    {
      int i;
      int digit_input = 1;
      for (i = 0; i < 10; i++)
      {
        if (isdigit(phoneNum[i]) == 0)
        {
          digit_input = 0;
          break;
        }
      }
      if (digit_input == 1)
      {
        return;
      }
      printf("Enter a 10-digit phone number: ");
    }

    else 
    {
      printf("Enter a 10-digit phone number: ");
    }

  }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) 
{
  int i;

  for (i = 0; i < size; i++)
  {
    if (cellNum == NULL)
    {
      if (strlen(contacts[i].numbers.cell) == 0)
      {
        return i;
      }
    }
    else if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
    {
      return i;  
    }
  }

  return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
  printf("+-----------------------------------------------------------------------------+\n");
  printf("|                              Contacts Listing                               |\n");
  printf("+-----------------------------------------------------------------------------+\n"); 
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
  printf("+-----------------------------------------------------------------------------+\n");
  printf("Total contacts: %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
  if (strlen(contact->name.middleInitial) > 0)
  {
    printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
  }
  else
  {
    printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
  }

  printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

  printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

  if (contact->address.apartmentNumber > 0)
  {
    printf("Apt# %d, ", contact->address.apartmentNumber);
  }

  printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
  int i;
  int validContact = 0; 

  displayContactHeader();

  for (i = 0; i < size; i++)
  {
    if (strlen(contacts[i].numbers.cell) > 0) 
    {
      displayContact(&contacts[i]); 
      validContact++;
    }
  }
  displayContactFooter(validContact); 
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) //////// 이 function이 가장 어렵다... ㅠㅠ
{
  int index;
  char cellnumber[11] = { 0 };

  printf("Enter the cell number for the contact: ");
  
  getTenDigitPhone(cellnumber);

  index = findContactIndex(contacts, size, cellnumber); 

  if (index == -1) 
  {
    printf("*** Contact NOT FOUND ***\n");
    printf("\n");
  }
  else 
  {
    printf("\n");
    displayContact(&contacts[index]);
    printf("\n");
  }
}



// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
  int index;

  index = findContactIndex(contacts, size, 0); 

  if (index != -1)
  {
    getContact(&contacts[index]); 
    printf("--- New contact added! ---\n");
    return;
  }

  printf("*** ERROR: The contact list is full! ***\n");
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
  char cellNum[11] = {0};
  int index;

  printf("Enter the cell number for the contact: ");

  getTenDigitPhone(cellNum);   

  index = findContactIndex(contacts, size, cellNum);

  if (index == -1)
  {
    printf("*** Contact NOT FOUND ***\n"); 
  }
  else
  {
    printf("\n");
    printf("Contact found:\n");
    displayContact(&contacts[index]); 
    printf("\n");

    printf("Do you want to update the name? (y or n): ");
    if(yes())
    {
      getName(&contacts[index].name); 
    }

    printf("Do you want to update the address? (y or n): ");
    if(yes())
    {
      getAddress(&contacts[index].address);
    }

    printf("Do you want to update the numbers? (y or n): ");
    if(yes())
    {
      getNumbers(&contacts[index].numbers);
    }
    printf("--- Contact Updated! ---\n");
  }

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) //이거 너무 update이랑 같은 루트인데?
{
  int index;
  char cellNum[11] = { 0 };
  char empty[] = {0};

  printf("Enter the cell number for the contact: "); 

  getTenDigitPhone(cellNum); 

  index = findContactIndex(contacts, size, cellNum);
  
  if (index == -1)
  {
    printf("*** Contact NOT FOUND ***\n");
  }

  else
  {
    printf("\n");
    printf("Contact found:\n");
 
    displayContact(&contacts[index]);
    printf("\n");

    printf("CONFIRM: Delete this contact? (y or n): ");
    if (yes())
    {
      strcpy(contacts[index].numbers.cell, empty);
  
      printf("--- Contact deleted! ---\n");
    }
  }
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
  int i, j, m;

  char name [36];
  char address [31];
  int address_int;
  char numbers [11];

  for (i = 0; i < size; i++)
  {
    m = i;
    for (j = i + 1; j < size; j++)
    {
      if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell) < 0)
      {
        m = j;
      }
    }

    if (m != i)
    {
      
      // name:
      strcpy(name, contacts[i].name.firstName);
      strcpy(contacts[i].name.firstName, contacts[m].name.firstName);
      strcpy(contacts[m].name.firstName, name);

      strcpy(name,contacts[i].name.middleInitial);
      strcpy(contacts[i].name.middleInitial, contacts[m].name.middleInitial);
      strcpy(contacts[m].name.middleInitial, name);

      strcpy(name, contacts[i].name.lastName);
      strcpy(contacts[i].name.lastName, contacts[m].name.lastName);
      strcpy(contacts[m].name.lastName, name);
      

      // addresss:
      address_int = contacts[i].address.streetNumber;
      contacts[i].address.streetNumber = contacts[m].address.streetNumber;
      contacts[m].address.streetNumber = address_int;

      address_int = contacts[i].address.apartmentNumber;
      contacts[i].address.apartmentNumber = contacts[m].address.apartmentNumber;
      contacts[m].address.apartmentNumber = address_int;

      strcpy(address, contacts[i].address.street);
      strcpy(contacts[i].address.street, contacts[m].address.street);
      strcpy(contacts[m].address.street, address);
      

      strcpy(address, contacts[i].address.postalCode);
      strcpy(contacts[i].address.postalCode, contacts[m].address.postalCode);
      strcpy(contacts[m].address.postalCode, address);


      strcpy(address, contacts[i].address.city);
      strcpy(contacts[i].address.city, contacts[m].address.city);
      strcpy(contacts[m].address.city, address);


      //numbers:
      strcpy(numbers, contacts[i].numbers.cell);
      strcpy(contacts[i].numbers.cell, contacts[m].numbers.cell);
      strcpy(contacts[m].numbers.cell, numbers);

      strcpy(numbers, contacts[i].numbers.home);
      strcpy(contacts[i].numbers.home, contacts[m].numbers.home);
      strcpy(contacts[m].numbers.home, numbers);

      strcpy(numbers, contacts[i].numbers.business);
      strcpy(contacts[i].numbers.business, contacts[m].numbers.business);
      strcpy(contacts[m].numbers.business, numbers);
    }
  }
  printf("--- Contacts sorted! ---\n");
}