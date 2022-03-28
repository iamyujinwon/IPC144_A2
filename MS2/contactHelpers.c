//==============================================
// Name:           Yujin Won
// Student Number: 153565197
// Email:          ywon9@myseneca.ca
// Section:        NGG
// Date:           2020-07-16
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
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