#ifndef UTILS_H /* Include guard */
#define UTILS_H

//Function declarations

int Strlen(const char* string);
void Strcat(char* destination, const char* source);
int Strcmp(const char* string1, const char* string2);
int Strncut(char* destination, char* source, int nCut);
int insert(char*data, int index, int element, int uSize, int tSize);
int delete(char*data, int index, int len);
void memreset(char*data, int len);
int power(int base, int exp);
void decToBin(int dec, char* bin);
int binToDec(char* bin);

#endif
