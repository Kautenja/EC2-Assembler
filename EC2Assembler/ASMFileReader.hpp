//  Program:      EC-2 Assembler
//  File:         ASMFileReader.hpp
//  Description:  This class allows a user to read an ASM file into an array.
//
//  Created by Christian Kauten on 12/1/15.
//  Copyright (c) 2015 James Kauten. All rights reserved.
//

#ifndef ASMFileReader_hpp
#define ASMFileReader_hpp

#include <stdio.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;

const static string ASM = ".asm";
const static string ERROR_NO_FILE = "ERROR: no file found with name: ";

const static string CMD_LOAD =   "LOAD";
const static string CMD_STORE =  "STORE";
const static string CMD_ADD =    "ADD";
const static string CMD_SUB =    "SUB";
const static string CMD_IN =     "IN";
const static string CMD_JZ =     "JZ";
const static string CMD_JNNEG =  "JNNEG";
const static string CMD_HALT =   "HALT";
const static string A_COM =      "A,";
const static string A =          "A";
const static string CMD_CMT =    "--";

class ASMFileReader
{
private:
    enum Opcode { LOAD = 0, STORE = 32, ADD = 64, SUB = 96, IN = 128, JZ = 160, JNNEG = 192, HALT = 224 };
    string fileName;
    vector<char> bytes;
    
    // Function:     generateVector
    // Inputs:       NA
    // Outputs:      true
    // Description:  Looks through each line of the file and encodes it into binary.
    //
    bool generateVector();
    
    // Function:     convertToInt
    // Inputs:       bin,  a string of 1s and 0s to convert to an unsigned integer.
    // Outputs:      an integer representation of bin's contents
    // Description:  Convert a binary string to an integer.
    //
    int convertToInt(string bin);
    
public:
    ASMFileReader(string fileName);
    
    // Function:     getBytes
    // Inputs:       NA
    // Outputs:      a vector of byte commands
    // Description:  Returns the encoded program in a vector.
    //
    vector<char> getBytes();
    
    // Function:     writeToConsole
    // Inputs:       NA
    // Outputs:      NA
    // Description:  Writes the assembly code and machine code to the console.
    //
    void writeToConsole();
    
    // Function:     getFileName
    // Inputs:       NA
    // Outputs:      the file name
    // Description:  Return the name of this ASM file.
    //
    string getFileName();
};

#endif /* ASMFileReader_hpp */
