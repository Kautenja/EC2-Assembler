# EC2 Assembler #

## Preamble ##

* Date Created: Sept, 2015
* Version: 0.1
* Language: C++
* requires: g++

### Contributors ###
* James Christian Kauten (@Kautenja)


## Description 

The EC-2 (Enoch's Computer #2) is a toy microprocessor designed by [Enoch Hwang](https://lasierra.edu/computer-science/enoch-hwang/). The machine is purely for academic purposes and follows this hardware design:

![Hardware](hardware.png)

This project aims to explore the process of assembling basic assembly level instructions written for the EC2 into binary code. The following instruction set architecture will be used in the implementation of this assembler following Enoch's original design:

![ISA](instruction_set_architecture.png)


## Compilation ##

In a terminal in the root directory with the terminal type:

    g++ -o ec2Assembler main.cpp ASMFileReader.cpp BinaryFileWriter.cpp
  
  
## Execution ##
  
    ./ec2Assembler <assembly_file> <binary_file>
  
### Example ###

    ./ec2Assembler palindrome.asm palindrome.o


