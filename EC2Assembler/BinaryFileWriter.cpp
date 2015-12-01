//  Program:      EC-2 Assembler
//  File:         BinaryFileWriter.cpp
//  Description:  This class allows a user to write an array to a binary file.
//
//  Created by Christian Kauten on 12/1/15.
//  Copyright (c) 2015 James Kauten. All rights reserved.
//

#include "BinaryFileWriter.hpp"

BinaryFileWriter::BinaryFileWriter(string fileName, vector<char> bytesToWrite)
{
    this->fileName = fileName;
    this->bytes = bytesToWrite;
    
    if ( fileName.find(BIN) == std::string::npos )
    {
        this->fileName = this->fileName + BIN;
    }
    
    ifstream inputFile;
    inputFile.open(this->fileName.c_str(), std::ios::in);
    
    // If the input file does not exist, create the file and write the default settings.
    if ( inputFile )
    {
        inputFile.close();
        cout << ERROR_FILE << endl;
        cout << OVERWRITE;
        string response;
        cin >> response;
        if ( response.compare(YES) == 0 )
        {
            writeBytes();
        }
    }
    else
    {
        inputFile.close();
        writeBytes();
    }
}

// Function:     writeToConsole
// Inputs:       NA
// Outputs:      NA
// Description:  Writes the contents of the byte array to the console.
//
void BinaryFileWriter::writeToConsole()
{
    for ( int i = 0; i < bytes.size(); i++)
    {
        std::bitset<8> byte(bytes.at(i));
        cout << byte << " ";
    }
    cout << endl;
}

// Function:     writeBytes
// Inputs:       NA
// Outputs:      true
// Description:  Writes the byte vector to a binary file.
//
bool BinaryFileWriter::writeBytes()
{
    ofstream outputFile;
    outputFile.open(this->fileName.c_str(), std::ios::out | std::ios::binary );
    for ( int i = 0; i < bytes.size(); i++ )
    {
        outputFile << bytes.at(i);
    }
    return true;
}

// Function:     getFileName
// Inputs:       NA
// Outputs:      the file name
// Description:  Return the name of this BIN file.
//
string BinaryFileWriter::getFileName()
{
    return fileName;
}