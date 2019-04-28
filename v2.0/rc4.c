//  rc4.c
//
//  Created by Smith on 2017/07/31.
//  Copyright © 2017 Smith. All rights reserved.

#include "rc4.h"

#include <stdlib.h>
#include <stdio.h>

void rc4_encrypt(unsigned char* schedule, unsigned char* data, unsigned char* dest, unsigned int length)
{
    unsigned char* temp = (unsigned char*)malloc(length);


    int  j = 0;
unsigned int i;
    for ( i = 0; i < length; i++) {
        i = (i + 1) % RC4_TABLE_LENGTH;
        j = (j + schedule[i]) % RC4_TABLE_LENGTH;
        unsigned char _i = schedule[i];
        schedule[i] = schedule[j];
        schedule[j] = _i;
        temp[i] = schedule[(schedule[i] + schedule[j]) % RC4_TABLE_LENGTH];
    }
    for ( i = 0; i < length; i++) {
        dest[i] = data[i] ^ temp[i];
    }
}

void rc4_decrypt(unsigned char* schedule, unsigned char* data, unsigned char* dest, unsigned int length)
{
    unsigned char* temp = (unsigned char*)malloc(length);

    int  j = 0;
unsigned int i;
    for (i = 0; i < length; i++) {
        i = (i + 1) % RC4_TABLE_LENGTH;
        j = (j + schedule[i]) % RC4_TABLE_LENGTH;
        unsigned char _i = schedule[i];
        schedule[i] = schedule[j];
        schedule[j] = _i;
        temp[i] = schedule[(schedule[i] + schedule[j]) % RC4_TABLE_LENGTH];
    }
    for ( i = 0; i < length; i++) {
        dest[i] = data[i] ^ temp[i];
    }
}


void rc4_generate_key(unsigned char* schedule, const unsigned char* key, int key_length)

{
unsigned int i;
    for ( i = 0; i <= 0xff; i++)
        schedule[i] = i;

    int j = 0;
    for ( i = 0; i <= 0xff; i++) {
        // this is RC4
        j = (j + schedule[i] + key[i % key_length]) % RC4_TABLE_LENGTH;

        unsigned char _j = schedule[j];
        schedule[j] = schedule[i];
        schedule[i] = _j;
    }
}
