# EC2 Assembler #

## Preamble ##

* Date Created: Sept, 2015
* Version: 0.1
* Language: C++
* requires: g++

### Contributors ###
* James Christian Kauten (@Kautenja)


## Description 

The EC-2 (Enoch's Computer #2) is a toy microprocessor featuring a single byte instruction set. The hardware design is equally as simple:

![Hardware](hardware.png)

The Instruction Set Architecture to parse looks like this:

![ISA](instruction_set_architecture.png)


## Compilation ##

In a terminal in the root directory with the terminal type:

    g++ -o ec2Assembler main.cpp ASMFileReader.cpp BinaryFileWriter.cpp
  
  
## Execution ##
  
    ./ec2Assembler <assembly_file> <binary_file>
  
### Example ###

    ./ec2Assembler palindrome.asm palindrome.o


