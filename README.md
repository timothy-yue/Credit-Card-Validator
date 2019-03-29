# Credit-Card-Validator
Credit card number validator using Luhn's algorithm. Basic C program that takes in a credit card as an input and determines if it is a valid number and what kind of card it is. (Visa, Mastercard, etc.)

### Luhn's Algorithm

---
> The Luhn algorithm, also known as ___mod10___ algorithm. A simple checksum formula used to validate a variet of identification numbers, such as credit card numbers, IMEI numbers, Candian Social Insurance numbers.
>
> 1. Double every other digit 
> 2. If doubling of a number results in a 2 digit number, i.e greater than 9, then add the digits of the product together. Example: 
>       * Example: (6 * 2) = 12 -> 1 + 2 = 3. Resulting value would be ***3***
> 3. Take the sum of all the digits. 
> 4. If the modulo 10 of the sum is ***0***, then the number is valud according to the Luhn formula. 

### Commands

---
To compile the binary, run the command:
> make

To remove executable:
> make clean

To run the binary:
> ./validator ***1234567891234567***

Program checks if the input is exactly two, ___program name___ and ___number___. Also checks if the ___number___ also contains all digits. 