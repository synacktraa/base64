#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int power(int base, int p){
   int result = 1;
   if(p){  
      for(int i = p; i > 0; i--){  
       
         result *= base;
      }
      return result;
   }
   else{  
      return result;  
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


int binToDec(char* binary){  
    
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


int retbuf(char* file_name){

    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fclose(fp);
  
    return res;
}


int fcheck(const char * filename) {

    FILE *file;
    if((file = fopen(filename, "r")) != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}


char* retrieve(char*file) {

/*
    Checks if file exists on the system, if yes
    stores the file size in buffer_len var
    by evaulating get_filesize function which 
    retrieves the file size and then reads the
    file line by line and stores it in buffer 
    and then concatenate it to data_storage
    and finally frees the buffer and return data_storage
*/
    if(!fcheck(file)) {
        return (NULL);
    }

    int buffer_len = retbuf(file)+2;
    
    FILE * file_in = fopen(file, "r");
    char* data_storage = (char*)malloc(sizeof(char) * buffer_len);
    char* buffer = (char*)malloc(sizeof(char) * buffer_len);

    memset(data_storage, 0, Strlen(data_storage));
    while (fgets(buffer, buffer_len, file_in))
        strcat(data_storage, buffer);

    free(buffer);
    return data_storage;
}


char *basename(char const *path, char slash) {

    char *s = strrchr(path, slash);
    if(!s) 
        return strdup(path);
    else 
        return strdup(s + 1);
}


void delspace(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
}