/**
* Program Name: Cesar Cipher Decryption using brute force
* Author: Sheikh Rabiul Islam
* Date: 03/10/2017
* Purpose: Information assurance and cryptography assignment 3 part 1  
*/ 
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

/* takes a character and give its position in alphabet sequence */
int char_position(char c)
{
	return int(c)-65;
}

/* takes a position and tell the character on that position in alphabet series */
char char_at_position(int p)
{
	char c = p+65;
	return c;
}

/* check whether the input contains any other character than A-Z and Spaces */
void input_checker(char* c_text)
{
	int ascii_val=0;
	for(int i=0; i< strlen(c_text);i++)
	{
		if(c_text[i]!=' ')
		{
			ascii_val = int(c_text[i]);
			if(ascii_val < 65 || ascii_val > 90 )
			{
				cout << "Input should be only character between A to Z and/or spaces \n";
				exit(0);
			}
		}
		
	}		
}

/* tries to decrypt the message with supplied key */
void brute_force(char* c_text, int key)
{
	char p_text[500]="";
	for( int i=0; i< strlen(c_text); i++)
	{
		if(c_text[i] != ' ')
		{
			p_text[i] = char_at_position((26 + char_position(c_text[i]) -key) % 26);
			
		}else{
			p_text[i] = ' ';	
		}
	}
	string c_text_str(c_text);
	string p_text_str(p_text);
	cout << "Key:" << char_at_position(key) << " or " << key << ",  Encrypted: " << c_text_str  << ",  Decrypted: " << p_text_str << endl;	
	
}

/* main */
int main()
{
	char c_text[500] = "LT HDGJWJFLQJX";  //input ceasar cipher
	for(int i=0; i< strlen(c_text); i++)   // uppercase conversion incase of lowercase given
	{
		c_text[i] = toupper(c_text[i]); 
	}
	
	input_checker(c_text);  // check inputs
	
	int key=0;		
	for(int j=0;j<26;j++)	// do the bruteforce attack to reveal the key and decrypted message
	{	
		key = j;
		brute_force(c_text,key); 
	} 	
	
	return 0;
}