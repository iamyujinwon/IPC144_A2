//==============================================
// Name:           Yujin Won
// Student Number: 153565197
// Email:          ywon9@myseneca.ca
// Section:        NGG
// Date:           2020-07-26
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

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

  while (running)
  {
    int option = menu();

    switch (option)
    {
    case 1:
      printf("<<< Feature 1 is unavailable >>>");
      printf("\n");
      printf("\n");
      pause();
      break;

    case 2:
      printf("<<< Feature 2 is unavailable >>>");
      printf("\n");
      printf("\n");
      pause();
      break;

    case 3:
      printf("<<< Feature 3 is unavailable >>>");
      printf("\n");
      printf("\n");
      pause();
      break;

    case 4:
      printf("<<< Feature 4 is unavailable >>>");
      printf("\n");
      printf("\n");
      pause();
      break;

    case 5:
      printf("<<< Feature 5 is unavailable >>>");
      printf("\n");
      printf("\n");
      pause();
      break;

    case 6:
      printf("<<< Feature 6 is unavailable >>>");
      printf("\n");
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
    int needInput = 1;

    while (needInput == 1) 
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
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
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{


}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}