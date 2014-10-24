#pragma once

#include <vector>

class CacheSimulator
{
private:

    unsigned int line_width = 0, set_count = 0, lines_per_set = 0;
    unsigned int m_mem_start, m_mem_size;

    struct Set
    {
        std::vector<int> tags;
    };
    
    std::vector<Set> sets;


    void initialize();
    inline bool powerOfTwo(unsigned int x) { return !(x == 0) && !(x & (x - 1)); }
    void displayCache();
    void simulate();
    void CacheSimulator::populate(unsigned int set, unsigned tag);

    
public:
    CacheSimulator();
    ~CacheSimulator(){};



};

