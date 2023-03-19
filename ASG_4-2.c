#include <stdio.h> 
#include <stdlib.h> 
/*withou using string.h*/
char* get_string(void);// to get string from user
void reverse_string(char *sentence);// reversing words of the string 
int main(){
    printf("Enter sentence to be replaced : ");
    char* sentence = get_string();
    reverse_string(sentence);
    return 0;
}
char* get_string(void){
    char* string = (char*)malloc(sizeof(char));// using dynamic memory allocation for first character
    char c;
    int i = 0;//index count for string (as it's array of charecters) 
    while ((c = getchar()) != '\n')//take input until user press enter (new line has started)
    {
        string = realloc(string,sizeof(char)*(i+sizeof('\0')));// make space for extra character plus space for null terminator
        *(string + i) = c;
        ++i;
    }
    *(string + i) = '\0';// put null as last element of characters array to be used as string  
  
    return string;   
}

void reverse_string(char* string){
    /*loop to determine the dimensions of array needed
    which is number of charecters in biggest word and number of words in the given sentence 
    */
    int biggest_word = 0, word_count = 1,char_count = 1,i = 0;//least number of both charecters and words must be 1 at least
    while(*(string+i) != '\0')
    {
        
        if(*(string+i) == ' ')
        {       
            char_count = 1;
            if((*string+i+1) == '\0'){ 
                break;
            /*if the space is the last character in the 
            sentence so we don't need to count extra word or put the last space in the array of strings string*/
            }  
            word_count++;
        }
        else 
        {
            char_count++;
            if(char_count > biggest_word)
                biggest_word = char_count;
        }
        ++i;

    }
    
    //now we know the required dimensions for the new array of strings
    char string2[word_count][biggest_word];
    int itr_char = 0,itr_word = 0;//we need two iterators one for the first dimenstion(words) and the other for the second dimention(characters)
    for(int j = 0; j < i + 1; j++)//loop with new iterator (j) to assign the values of sentence to the new array of strings
    {       /*the loop need to start from first index(0) to the last index in 
            the given string also we need to add another iteration to put the last NULL*/
        if(*(string+j) == ' ' || *(string+j) == '\0')
        {
            *(*(string2 + itr_word)+itr_char) ='\0';
            itr_char = 0; 
            ++itr_word; /*if we have space we need to put NULL, count new word and put the character iterator back to zero
            or if it's the element we also need to put NULL knowing that changing 
            value of iterators won't matter now so we can use it in the same conditon */ 
        }
        else 
        {
            *(*(string2 + itr_word)+itr_char) = *(string+j);
            ++itr_char;//in case the character nither NULL nor space so we need to add it in the string inside the array and increment the iterator
        }
    }
    for(int j = word_count-1; j >= 0; j--) //to print the array in reverse we need to start from the last word (max index) until the first one (0's index)
    {
        printf("%s ",*(string2+j)); //printing the strings from the array of strings 
    }
}
