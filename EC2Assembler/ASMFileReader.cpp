//  Program:      EC-2 Assembler
//  File:         ASMFileReader.cpp
//  Description:  This class allows a user to read an ASM file into an array.
//
//  Created by Christian Kauten on 12/1/15.
//  Copyright (c) 2015 James Kauten. All rights reserved.
//

#include "ASMFileReader.hpp"

ASMFileReader::ASMFileReader(string fileName)
{
    this->fileName = fileName;
    
    if ( fileName.find(ASM) == std::string::npos )
    {
        this->fileName = this->fileName + ASM;
    }
    
    ifstream inputFile;
    inputFile.open(this->fileName.c_str(), std::ios::in);
    
    // If the input file does not exist, throw error.
    if ( !inputFile )
    {
        inputFile.close();
        cout << ERROR_NO_FILE << this->fileName << endl;
    }
    else
    {
        generateVector();
        inputFile.close();
    }
}

// Function:     generateVector
// Inputs:       NA
// Outputs:      true
// Description:  Looks through each line of the file and encodes it into binary.
//
bool ASMFileReader::generateVector()
{
    ifstream inputFile;
    inputFile.open(fileName.c_str(), std::ios::in | std::ios::binary );
    
    string current;
    while ( getline(inputFile, current) )
    {
        // Check if current line is a comment
        if ( current.find(CMD_CMT) != 0 && current.length() != 0 )
        {
            // Command without address
            if ( current.find(CMD_IN) == 0 && current.find(A) != string::npos )
            {
                bytes.push_back((char)IN);
            }
            // Command without address
            else if ( current.find(CMD_HALT) == 0 )
            {
                bytes.push_back(HALT);
            }
            // Commands with address
            else if ( current.find(A_COM) != string::npos )
            {
                if ( current.find(CMD_LOAD) == 0 )
                {
                    bytes.push_back((char)(LOAD));
                }
                else if ( current.find(CMD_STORE) == 0 )
                {
                    bytes.push_back((char)(STORE));
                }
                else if ( current.find(CMD_ADD) == 0 )
                {
                    bytes.push_back((char)(ADD));
                }
                else if ( current.find(CMD_SUB) == 0 )
                {
                    bytes.push_back((char)(SUB));
                }
                else if ( current.find(CMD_JZ) == 0 )
                {
                    bytes.push_back((char)(JZ));
                }
                else if ( current.find(CMD_JNNEG) == 0 )
                {
                    bytes.push_back((char)(JNNEG));
                }
                
                // Determine the address and add it to the top of the byte queue.
                if (  current.find_first_of("0") < current.find_first_of("1") )
                {
                    current.replace(0, current.find_first_of("0"), "");
                }
                else
                {
                    current.replace(0, current.find_first_of("1"), "");
                }
                string address = current.substr(current.find_first_not_of(" "),5);
                bytes.at(bytes.size()-1) = bytes.at(bytes.size()-1) + convertToInt(address);
            }
        }
    }
    
    return true;
}

// Function:     convertToInt
// Inputs:       bin,  a string of 1s and 0s to convert to an unsigned integer.
// Outputs:      an integer representation of bin's contents
// Description:  Convert a binary string to an integer.
//
int ASMFileReader::convertToInt(string bin)
{
    int num = 0;
    for ( int i = (int)bin.size()-1; i >= 0; i--)
    {
        if ( bin.substr(i,1).compare("1") == 0 )
        {
            num += std::pow(2,(bin.size()-i)-1);
        }
    }
    
    return num;
}

// Function:     writeToConsole
// Inputs:       NA
// Outputs:      NA
// Description:  Writes the assembly code and machine code to the console.
//
void ASMFileReader::writeToConsole()
{
    ifstream inputFile;
    inputFile.open(fileName.c_str(), std::ios::in | std::ios::binary );
    
    std::string current;
    while ( getline(inputFile, current) )
    {
        cout << current << endl;
    }
    cout << endl;
    inputFile.close();
    
    for (int i = 0; i < bytes.size(); i ++)
    {
        std::bitset<8> b(bytes.at(i));
        cout << b << " ";
    }
    cout << endl;
}

// Function:     getBytes
// Inputs:       NA
// Outputs:      a vector of byte commands
// Description:  Returns the encoded program in a vector.
//
vector<char> ASMFileReader::getBytes()
{
    return bytes;
}

// Function:     getFileName
// Inputs:       NA
// Outputs:      the file name
// Description:  Return the name of this ASM file.
//
string ASMFileReader::getFileName()
{
    return fileName;
}