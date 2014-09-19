#include "CacheSimulator.hpp"

#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

CacheSimulator::CacheSimulator()
{

    cout << " Welcome. \n This is a cache simulator to simulate memory read in a 32-bit address space. \n";

    while (!powerOfTwo(line_width))
    {
        cout << " Enter the desired number of bytes in a cache line (must be power of 2): ";
        cin >> line_width;
    }
    while (!powerOfTwo(set_count))
    {
        cout << " Enter the desired number of sets (must be power of 2): ";
        cin >> set_count;
    }
    while (!powerOfTwo(lines_per_set))
    {
        cout << " Enter the desired number of lines per set (must be power of 2): ";
        cin >> lines_per_set;
    }

    
    cout << "Enter the memory start location (hex): " << endl;
    cin >> hex >> m_mem_start;
    cout << "Enter the memory size (hex): " << endl;
    cin >> hex >> m_mem_size;

    srand(time(NULL));

    initialize();

    bool sim = 1;
    while (sim)
    {
        char command;
        cout << " Press D to display cache, Q to quit, any other key to quit.\n";
        cin >> command;

        switch (command)
        {
        case 'Q':
        case 'q':
        {
            sim = false;
            break;
        }
        case 'D':
        case 'd':
        {
            displayCache();
            break;
        }
        default:
        {
            simulate();
            break;
        }
        }

    }
}

void CacheSimulator::initialize()
{
    sets.resize(set_count);
    for (unsigned int i = 0; i < set_count; i++) sets[i].tags.resize(lines_per_set, -1);

}

void CacheSimulator::displayCache()
{
    for (int i = 0; i < set_count; i++)
    {
        cout << "\nSet [" << i << "]:" << endl;
        for (int j = 0; j < lines_per_set; j++)
        {
           
            std::stringstream stream;
            if (sets[i].tags[j] == -1) stream<< "empty";
            else
                stream <<std::hex << sets[i].tags[j];

            cout << "Line[" << j << "]:  " << stream.str() << endl;
        }

     }
}

 void CacheSimulator::simulate()
{
     double random = ((double)rand()) / RAND_MAX;
     unsigned int rand_addr =  random* m_mem_size + m_mem_start;

     int offset_bits = round(log2(line_width));

     int set_bits = (int)round(log2(set_count));
     
     unsigned int set_mask = (((1 << set_bits) - 1) << offset_bits);

     unsigned int set = (rand_addr & set_mask) >> offset_bits;

     unsigned int offset = ((1 << offset_bits) - 1) & rand_addr;
     unsigned int tag_mask= ~((1 << offset_bits + set_bits) - 1);

     unsigned tag = (rand_addr & tag_mask) >> (offset_bits + set_bits);

     cout << "Address: " << hex << rand_addr << "  tag=" << hex << tag << "  set=" << set << " offset=" << hex << offset << endl;
     
     populate(set, tag);

}

 void CacheSimulator::populate(unsigned int set, unsigned tag)
 {
     
     for (int i = 0; i < lines_per_set; i++)
     {
         if (sets[set].tags[i] == tag)
         {
             cout << "Address alraed exists in cache.";
                 return;
         }

     }

     unsigned random_line = rand() % lines_per_set;

     cout << "Populating set " << set << " line " << random_line << " , tag = " << hex << tag << endl;
     sets[set].tags[random_line] = tag;

 }
