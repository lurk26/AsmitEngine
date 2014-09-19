#include "../../ENGINE/src/Engine.hpp"

#include "CacheSimulator\CacheSimulator.hpp"

#include <iostream>

void CreateSentence(char**, const char **, int);

int main(int argv, char** argc)
{
    Engine::Engine();

    char ** words = new char*[]{ "This", "is", "a", "sentence" };
    int num_words = 4;
    char * sentence;
    //CreateSentence(&sentence, (const char **)words, num_words);
    
    //std::cout << sentence;

    new CacheSimulator();
}


void CreateSentence(char ** sentence, const char ** words, int count)
{
    char current_char= **words;
    int current_word = 0;
    int total_char_count= 0;
    while (current_word < count)
    {
        int char_num=0;
        while (1)
        {
            current_char = *(*(words + current_word) + char_num);
            if (current_char == '\0') 
                break;
            char_num++;
            total_char_count++;
        }

        current_word++;
    }

    total_char_count = total_char_count + count + 1;
    *sentence = new char[total_char_count];

    total_char_count = 0;
    current_word = 0;

    while (current_word < count)
    {
        int char_num = 0;
        while (1)
        {
            current_char = *(*(words + current_word) + char_num);
            if (current_char == '\0')
                break;
            (*sentence)[total_char_count] = current_char;
            char_num++;
            total_char_count++;
        }

        (*sentence)[total_char_count] = ' ';
        total_char_count++;
        current_word++;
    }
    (*sentence)[total_char_count-1] = '.';
    (*sentence)[total_char_count] = '\0';
}