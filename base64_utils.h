#ifndef BASE64_UTILS_H /* Include guard */
#define BASE64_UTILS_H

//Function declarations

int insert(char*data, int index, int element, int uSize, int tSize);
int delete(char*data, int index, int len);
void reverse(char*str);
int power(int base, int exp);
int Strlen(const char* string);
char* decToBin(int dec);
int binToDec(char* bin);
int charValidate(char ch);
int base64Validate(char b64ed);
int get_filesize(char file_name[]);
int checkIfFileExists(const char * filename);
char *basename(char const *path, char slash);
void delspace(char* s);

#endif
