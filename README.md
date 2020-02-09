# comp322 
## lab0
lab0 is C program submission for Comp322 that reads a series of 1's and 0's from a file

## Project status
This program is able to read a specific file (the given example) and output the desired information. Probably doens't work correctly with other general case examples. I believe the main requirements I could not figure out how were: 1) use "read()", 2)how to pad a shorter number and 3)how to read a file from the commandline.

## Journal
My initial outline was:
  -read a file 
  -convert the acsii number into binary
  -covert 
    - decimal
    - char
    - parity
    
My first real challenge was actually installing gcc and  trying to run the makefile and the program because I was unawared of the command ./<file>.exe
Next I hardcoded opening the file with fopen and am guessing how to do parity. My thought process for the binary was to read them backwards nad decrement an exponent counter which to get the sum of decimal but if the was too large(I don't max), I had to subtract by 128 which gave the correct output. Then I just used "%c" to print a decimal to char.
