#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

void encode(char*string){

    char six_bit_bin[10], base64_val[400];
    char Ox49_val_bin[10], bin_dump[800];
    int i, j, k, bin_dump_len, ascii_val;

	//I don't understand why the f*ck the length is not 0,
	//i didn't even initialized them with a value,
	//that's resetting the strings
    memreset(Ox49_val_bin, Strlen(Ox49_val_bin));
    memreset(bin_dump, Strlen(bin_dump));

    for(i=0; *(string+i) != '\0'; ++i){
        decToBin(*(string+i), Ox49_val_bin);
		while(Strlen(Ox49_val_bin)%8 != 0){
        	k = insert(Ox49_val_bin, 0, 0x30, Strlen(Ox49_val_bin), sizeof(Ox49_val_bin));
        	Ox49_val_bin[k] = '\0';
    }
        Strcat(bin_dump, Ox49_val_bin);
        memreset(Ox49_val_bin, Strlen(Ox49_val_bin));
    }

    bin_dump_len = Strlen(bin_dump);
    while(bin_dump_len%6 != 0)
        bin_dump_len = insert(bin_dump, bin_dump_len, 0x30, bin_dump_len, sizeof(bin_dump));

    i = 0, j = 0;
    while(*(bin_dump+i)!='\0'){

        bin_dump_len = Strncut(six_bit_bin, bin_dump, 6);
        ascii_val = binToDec(six_bit_bin);
        if(ascii_val>=0 && ascii_val<=25)
            base64_val[j] = ascii_val+65;
        else if(ascii_val>=26 && ascii_val<=51)
            base64_val[j] = ascii_val+71;
        else if(ascii_val>=52 && ascii_val<=61)
            base64_val[j] = ascii_val-4;
        else if(ascii_val==62)
            base64_val[j] = ascii_val-19;
        else if(ascii_val==63)
            base64_val[j] = ascii_val-16;
        j++; i = 0;

    }
    base64_val[j] = '\0';
    while(Strlen(base64_val)%4 != 0)
        insert(base64_val, Strlen(base64_val), 0x3d, Strlen(base64_val), sizeof(base64_val));
    printf("%s", base64_val);

}

void decode(char*base64Data){

	int i, j, k, data_len = Strlen(base64Data);
    char bin_dump[500], Ox49_val_bin[10], byte_bin[10], decodeData[100];

	while(*(base64Data+(data_len-1)) == 0x3D){
		data_len = delete(base64Data, data_len-1, data_len);
	}
    memreset(bin_dump, Strlen(bin_dump));

    for(i=0; *(base64Data+i)!=0; ++i){
        if(*(base64Data+i)>=0x41 && *(base64Data+i)<=0x5A){
            decToBin(*(base64Data+i)-65, Ox49_val_bin);
        } else if(*(base64Data+i)>=0x61 && *(base64Data+i)<=0x7A){
            decToBin(*(base64Data+i)-71, Ox49_val_bin);
        } else if(*(base64Data+i)>=0x30 && *(base64Data+i)<=0x39){
            decToBin(*(base64Data+i)+4, Ox49_val_bin);
        }
        k = Strlen(Ox49_val_bin);
        while(Strlen(Ox49_val_bin)%6 != 0)
            k = insert(Ox49_val_bin, 0, 0x30, k, sizeof(Ox49_val_bin));
        *(Ox49_val_bin+k) = '\0';
        Strcat(bin_dump, Ox49_val_bin);
        memreset(Ox49_val_bin, Strlen(Ox49_val_bin));
    }

    data_len = Strlen(bin_dump);
    while(Strlen(bin_dump)%8 != 0)
        data_len = insert(bin_dump, data_len, 0x30, data_len, sizeof(bin_dump));
    *(bin_dump+data_len) = '\0';

    i = 0, j = 0;
    while(*(bin_dump+i)!='\0'){

        data_len = Strncut(byte_bin, bin_dump, 8);
        *(decodeData+j) = binToDec(byte_bin);
        j++; i = 0;
    }
    *(decodeData+j) = '\0';
    if(*(decodeData)<0x20 || *(decodeData)>0x7e){
        fprintf(stderr, "Error: The string to be decoded is not correctly encoded.");
        exit(1);
    }else if(*(decodeData)>=0x20 && *(decodeData)<=0x7e){
        data_len = Strlen(decodeData);
        for(i=1; *(decodeData+i) != '\0'; ++i){
            if(*(decodeData+i)<0x20 || *(decodeData+i)>0x7e){
                data_len = delete(decodeData, i, data_len);
            }
        }
    }
    printf("%s\n", decodeData);

}

int main(int argc, char* argv[]){
	
	if(argc==3){
		if(!Strcmp(argv[1], "--encode") || !Strcmp(argv[1], "-e")){
			encode(argv[2]);
            // for(int i = 0; i < 127; ++i)
            //     printf("%d: %c\n", i, i);
		} else if(!Strcmp(argv[1], "--decode") || !Strcmp(argv[1], "-d")){
			decode(argv[2]);
		}
	}

}

// 01101000 01100001 01110010 01110011 01101000 		 01101000 01100101 01111001
// 01101000 01100001 01110010 01110011 01101000 00100000 01101000 01100101 01111001
