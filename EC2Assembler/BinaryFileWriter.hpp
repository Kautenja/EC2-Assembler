//  Program:      EC-2 Assembler
//  File:         BinaryFileWriter.hpp
//  Description:  This class allows a user to write an array to a binary file.
//
//  Created by Christian Kauten on 12/1/15.
//  Copyright (c) 2015 James Kauten. All rights reserved.
//

#ifndef BinaryFileWriter_hpp
#define BinaryFileWriter_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>

using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

const static string BIN = ".bin";
const static string ERROR_FILE = "ERROR: File found with name: ";
const static string OVERWRITE = "Overrite? (y/n): ";
const static string YES = "y";

class BinaryFileWriter
{
private:
    string fileName;
    vector<char> bytes;
    
    // Function:     writeBytes
    // Inputs:       NA
    // Outputs:      true
    // Description:  Writes the byte vector to a binary file.
    //
    bool writeBytes();
    
public:
    BinaryFileWriter(string fileName, vector<char> bytesToWrite);
    
    // Function:     writeToConsole
    // Inputs:       NA
    // Outputs:      NA
    // Description:  Writes the contents of the byte array to the console.
    //
    void writeToConsole();
    
    // Function:     getFileName
    // Inputs:       NA
    // Outputs:      the file name
    // Description:  Return the name of this BIN file.
    //
    string getFileName();
};
#endif /* BinaryFileWriter_hpp */
