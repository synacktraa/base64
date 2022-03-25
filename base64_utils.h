#ifndef BASE64_UTILS_H /* Include guard */
#define BASE64_UTILS_H

//Function declarations

int insert(char*data, int index, int element, int uSize, int tSize);
int delete(char*data, int index, int len);
void reverse(char*str);
int power(int base, int exp);
char* decToBin(int dec);
int binToDec(char* bin);
char *basename(char const *path);

#endif
