#pragma once

char* HelloWorldToHelloJapan(char ioString[]);

char* HelloWorldToByeWorld(char ioString[]);

char* HelloWorldToHelloWorld(char ioString[]);


void Replace(char srcChar[], char desChar[], int startIndex, int endindex);

void Erase(char srcChar[], int index);

void Erase(char srcChar[], int startIndex, int endIndex);


char* Insert(char srcChar[], int indeX, char insertChar);

void Copy(char srcChar[], char desChar[]);