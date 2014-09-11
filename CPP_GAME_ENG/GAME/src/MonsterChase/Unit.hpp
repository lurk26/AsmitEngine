#pragma once
class Unit
{

private:
    int m_x;
    int m_y;
public:
	Unit();
	~Unit();

    Unit(int x, int y);

    void    moveUnitRandomly();

    void    setX(int x)      { m_x = x; }
    void    setY(int y)      { m_y = y; }

    int     getX()           { return m_x; }
    int     getY()           { return m_y; }

};

