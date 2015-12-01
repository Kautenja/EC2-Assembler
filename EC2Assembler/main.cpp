//  Program:      EC-2 Assembler
//  Name:         James Kauten
//  Class:        COMP3350
//  Date:         Dec 1, 2015
//  Email:        jck0022@auburn.edu
//
//  Description:  This program assembles programs written in EC-2 assembly language into binary machine code files.
//
//  Created by Christian Kauten on 12/1/15.
//  Copyright (c) 2015 James Kauten. All rights reserved.
//

#include "BinaryFileWriter.hpp"
#include "ASMFileReader.hpp"

int main(int argc, char *argv[])
{
    // Read two file names from the console and attempt to assemble the first to the second
    if (argc > 2 )
    {
        ASMFileReader asmFile = ASMFileReader(argv[1]);
        BinaryFileWriter binFile = BinaryFileWriter(argv[2], asmFile.getBytes());
    }
    return 0;
}
