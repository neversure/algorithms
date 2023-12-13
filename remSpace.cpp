#include <iostream>

void removeSpaces(char* str) {
    
	//firstly check if input string exists
    if (str == nullptr) {
        return;
    }
    
    char* str_read = str;	
    char* str_write = str;					
   
    while (*str_read) { 				//reading while able to
        if (*str_read != ' ') { 		//if read char is not a space char...
            *str_write = *str_read;		//re-write it to str
            str_write++; 				//when (and only when) moving write pointer forward
        }
        str_read++;						//anw moving read pointer forward				 
    }
    *str_write = '\0';					//since we've moved write ptr only after rewriting...
}										//non-space charachters it now points on the first...
										//symbol we dont need (most likely it should be...
										//alreydy rewritten symbol but not necessarily)
int main() {
    char str[] = "i can do much better";

    std::cout << "original string:\n" << str << "\n";
    removeSpaces(str);
    std::cout << "no space string:\n" << str << std::endl;
    
    return 0;
}
