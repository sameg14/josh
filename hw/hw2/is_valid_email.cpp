/*
Problem 2 (2 points). Suggested time: 15 minutes.
Write a function called is_valid_email that takes an array of characters representing an email id, the array's size, and returns true if it is a valid email id, else false. An email id is valid if it contains a sequence of characters followed by ‘@’, followed by another sequence of characters, and ends with “.com”. Assume that the array only contains alphabets, and special characters ‘@’ and ‘.’. Do not use inbuilt string library functionalities. Using a main function, demonstrate that it works.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline

/*#include <string>
#include <algorithm>*/

using namespace std;

/*bool is_valid_email(string email_address) {
	bool has_dot_com = (email_address.find(".com") == email_address.length() - 4);
	bool has_at_symbol = (count(email_address.begin(), email_address.end(), '@') == 1);
	return (has_dot_com && has_at_symbol);
}*/

bool is_valid_email(char email_address[], int email_size){
	bool valid_email=true;
	bool has_at_symbol = false;
	bool has_dot_com = false;
	for(int email_index=0;email_index<email_size-4;email_index++){
		char currentChar = email_address[email_index];
		if(currentChar == '@'){
			if (has_at_symbol == false) {
				has_at_symbol = true;
			}
			else {
				valid_email = false;
			}
		}
		else if(!((currentChar>='A' && currentChar<='Z')||
			  (currentChar>='a' && currentChar<='z'))){
			valid_email = false;
		}
	}

	if(email_address[email_size-1]== 'm' && 
	   email_address[email_size-2]== 'o' && 
	   email_address[email_size-3]== 'c' && 
	   email_address[email_size-4]== '.'){
		has_dot_com = true;
	}

	if (has_at_symbol && has_dot_com && valid_email) {
		valid_email = true;
	}
	else {
		valid_email = false;
	}

	return valid_email;
}

int main(){
	//string email_address = "abc@gmail.com";
	char * email_address = "abc@gmail.com";
	//char email_address[] = { 'a', 'b', 'c', '@', 'g', 'm', 'a', 'i', 'l', '.', 'c', 'o', 'm' };
	cout << "Checking " << email_address << "... " << (
	       //is_valid_email(emial_address,enter length of characters in email)	
		is_valid_email(email_address,13) ? "valid" : "invalid"
	        ) << endl;
	return 0;
}
