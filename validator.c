/*
** Credit Card number validator. Checks to see if a credit card number
** is a valid number using Luhn's algorithm
** 
** Author: Timothy Yue
** March 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char* argv[]) {

  if(argc == 2){
    printf("Checking....\n\n");
  }
  else {
    printf("Invalid number of arguments\nUsage: ./validator [credit card number]\n");
    return 0;
  }

  int numbers[strlen(argv[1])];
  char *number = strdup(argv[1]);

  switch(number[0]) {
    case '4':
      printf("Visa\n");
      break;
    case '3':
      printf("American Express\n");
      break;
    case '5':
      printf("Mastercard\n");
      break;
    case '6':
      printf("Discover\n");
      break;
  }

  for(int i = 0; i < strlen(number); i++){
    // Check if char is a digit, vulnerability / exploit checking.
    if( !isdigit(number[i]) ) {
        printf("Incorrect character found in input. Exitting...\n");
        return -1;
    }

    // Convert each char to an int.
    numbers[i] = (number[i] - '0');
  }

  for(int i = 0; i < strlen(number); i = i + 2){
    // Luhn's algorithm follows pattern
    // 2 1 2 1 2 1 2 1 2 1 2 1
    // Which means every second variable should be doubled.
    numbers[i] = numbers[i] * 2;

    // Checking if entry is greater than 10, if so, we add the left and ride side of the value for this index
    if( numbers[i]  > 9) {
      // Extract left side
      int leftside = numbers[i] % 10;

      // Since we know the greatest value is 9, and 9 * 2 is 18
      // and the lowest value is 5, 5 * 2 is 10
      // The right side has to be 1
      numbers[i] = 1 + leftside;
    }
  }

  int checksum = 0;
  // Loop through array and add up all the sums
  for(int i = 0; i < strlen(number); i++){
    checksum = checksum + numbers[i];
  }

  if( checksum % 10 == 0) {
    printf("Valid\n");
  }
  else {
    printf("Checksum: %d\nInvalid\n", checksum);
  }

  return 0;
}
