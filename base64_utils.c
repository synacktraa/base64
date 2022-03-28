#include<stdio.h>
#include<string.h>


int power(int base, int p){ //this user defined function takes a number and power vaue and returns base^p
   int result = 1;
   if(p){ //if the value is not 0, it runs the statement below
      for(int i = p; i > 0; i--){ //i i set to p and condition checks if i is greater than 1 if yes...it runs the statement
      // in the for block which is base is multiplied by base until i is equal 1 
         result *= base;
      }
      return result;
   }
   else{ //if the value of p is 0
      return result; //returns 1
   }
}


int Strlen(const char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}


int delete(char*data, int index, int length){

    int i;
    for (i = index; i < (length)-1; i++){
        *(data+i) = *(data+i+1);
    }
    *(data+i) = '\0';
    length--;
    return length;

}


void reverse(char*str){
   
   int len = 0;
   char*ptr = str;
   while(*ptr != '\0'){
      len++;
      ptr++;
   }
   int i = 0, j = len-1;
   while(i < j){
      int temp  = *(str+i);
      *(str+i) = *(str+j);
      *(str+j) = temp;
      ++i;
      --j;
   }
}


int insert(char*data, int index, int element, int uSize, int tSize){

    if(uSize >= tSize)
        return -1;
    for(int i = uSize-1; i >= index; i--)
        *(data+i+1) = *(data+i);
    
    *(data+index) = element;
    uSize++;
    *(data+(uSize)) = '\0';

    return uSize;
}


int binToDec(char* binary){ // function to convert binary value to decimal value
    
    int i = 0, j, k;
    int dec = 0;
    while(*(binary+i) != '\0')
        ++i;
    for(j = i-1, k = 0; j >= 0; --j, ++k){
        dec += (*(binary+k)-48)*power(2,j); 
    }
    return dec;

}


char* decToBin(int n){ 
    
    unsigned int dec = n;
    char binary[20]; 
    int i = 0;

    while(dec){ 

        int remain = dec % 2; 
        binary[i++] = remain+48; 
        dec = dec/2; 
    }

    binary[i] = '\0';

    reverse(binary);
    return strdup(binary);
    
}   


int charValidate(char ch) {

    if(ch < 0 || ch > 126)
        return -1;
    return 0;
}


int base64Validate(char b64ec) {
    
    if(b64ec < 43 || b64ec > 126 || (b64ec >= 44 && b64ec <47))
        return -1;
    if((b64ec > 57 && b64ec < 65) || (b64ec > 90 && b64ec < 97))
        return -1;
    if(b64ec > 122 && b64ec < 126)
        return -1;
    return 0;
}


int get_filesize(char file_name[]){

    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fclose(fp);
  
    return res;
}


int checkIfFileExists(const char * filename) {

    FILE *file;
    if((file = fopen(filename, "r")) != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}


char *basename(char const *path) {

    auto char *win_basename_parser(char const *);
    auto char *unix_basename_parser(char const *);
    
    char *win_basename_parser(char const *path) {
        char *s = strrchr(path, '\\');
        if(!s) 
            return strdup(path);
        else 
            return strdup(s + 1);
    }

    char *unix_basename_parser(char const *path) {
        char *s = strrchr(path, '/');
        if(!s) 
            return strdup(path);
        else 
            return strdup(s + 1);
    }

    if(strcmp(path, unix_basename_parser(path)))
        return strdup(unix_basename_parser(path));

    return strdup(win_basename_parser(path));
}