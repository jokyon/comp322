# comp322 
## lab0 v2
lab0 is C program submission for Comp322 that reads a series of 1's and 0's from a file

## Project Status
after given the extension, was able to receive from stdin and also read from file\
Bugs or self-errors:\
-unable to read a file without .extension\
-there is a space before padding 0's\
-should have made separate functions\
-line spacing\
-decimal may be off which would make the ascii value off as well


## Log
My initial outline was:\
  -read a file\
  -convert the acsii number into binary\
  -convert:\
    -- decimal\
    -- char\
    -- parity
    
My first real challenge was actually installing gcc and  trying to run the makefile and the program because I was unawared of the command ./<file>.exe
My thought process for the binary was to read them backwards and decrement an exponent counter which to get the sum of decimals then used "%c" to print a decimal to char.\
-----\
 After the extension, I started back from the beginning to try to figure out how to read from the stdin and how to use the read() and open() syscalls. Eventually I was able to get a workable output and tried to implement old code with some revisions and moving around
