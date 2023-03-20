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
    char reversed_string[word_count][biggest_word];
    for(int j = 0 ; j < word_count ; j++) //loop to to assign values to the new reversed array
    {
        int k = 0; //the iterator fo characters to assign each charecter individually 
        while( string2[word_count - j - 1][k] != '\0') // loop for assigning words from end to begining
        {
            reversed_string[j][k] = string2[word_count - j - 1][k]; //we used the index from the end of second array to be assinged at first array in the other
            k++;
        }
        *(*(reversed_string+j)+k) = '\0';//putting null at the end of each string

    }
    //printing the elements of the reversed string
    for (int j = 0; j < word_count; j++)
    {
        printf("%s ",*(reversed_string + j));
    }
}
