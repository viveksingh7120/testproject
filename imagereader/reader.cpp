/*
 * reader.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Vivek
 */

#include <iostream>
#include <fstream>
#include "base64.h"
using namespace std;

int main ()
{
    std::ifstream  inputFile;
    inputFile.open("abcd.png",std::ios::binary);
    std::filebuf* pbuf = inputFile.rdbuf();

    inputFile.seekg (0, ios_base::end);
    int length = inputFile.tellg();
    inputFile.seekg (0, ios_base::beg);
    // allocate memory to contain file data
     char* buffer=new char[length];

    // get file data
    pbuf->sgetn (buffer,length);
    inputFile.close();

    string const encodedData = base64_encode((unsigned char const*)buffer,length);
    delete[] buffer;
    cout<<"image data in base of 64"<<encodedData<<endl;
    string decodedData = base64_decode(encodedData);

    ofstream outPutFile;
    outPutFile.open("xyz.png",ios_base::out | ios_base::binary );
    outPutFile.write(decodedData.c_str(), decodedData.length());
    outPutFile.close();
}

