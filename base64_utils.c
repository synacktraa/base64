int Strlen(const char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}

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

int delete(char*data, int index, int length){

    int i;
    for (i = index; i < (length)-1; i++){
        *(data+i) = *(data+i+1);
    }
    *(data+i) = '\0';
    length--;
    return length;

}

char *Strcpy(char* destination, char* source){
   
   int i;
   for(i = 0; *(source+i) != '\0'; i++)
      *(destination+i) = *(source+i);

   *(destination+i) = '\0';
   
   return destination;
   
}

void Strcat(char* string1, const char* string2){

   int i, j;

    for(i = Strlen(string1), j = 0;j < Strlen(string2); i++, j++)
        *(string1+i) = *(string2+j);            
    *(string1+i) = '\0';

}

int Strcmp(const char* string1, const char* string2){

   int len_string1 = Strlen(string1);
   int len_string2 = Strlen(string2);

   if((len_string1 - len_string2) == 0){
      for(int i = 0; i < len_string1; i++){
         if(*(string1+i) == *(string2+i))
            len_string2--;         
      }
      if(len_string2 == 0)
         return 0;
      else
         return 1;
   } else{
      return 1;
      }
}

int Strncut(char* destination, char* source, int ncut){
   
   int i, len;
   for(i = 0; i < ncut; i++){
      *(destination+i) = *source;
        len = delete(source, 0, Strlen(source));
    }
   *(destination+i) = '\0';
   
   return len;
   
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
    
    int n;
    int i = 0, j, k;
    int dec = 0;
    while(*(binary+i) != '\0')
        ++i;
    for(j = i-1, k = 0; j >= 0; --j, ++k){
        dec += (*(binary+k)-48)*power(2,j); 
    }
    return dec;

}

void decToBin(int n, char*out){ 
    
    unsigned int dec = n;
    int binary[50]; 
    int i = 0, k = Strlen(out); 

    while(dec){ 

        int remain = dec % 2; 
        binary[i++] = remain; 
        dec = dec/2; 
    }
    for(int j = i-1; j >= 0; j--, k++)
        out[k] = binary[j]+48;

    out[k] = '\0';

}

void memreset(char*data, int len){
   int val = 0;
   for(int i = 0; i < len; i++){
      *(data+i) = val;
   }
}
