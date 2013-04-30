//tell elliott to fix his code re: North to North_, East to East_, Up to Up_ & remove const where appropriate

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
  protected:
    int North_;
    int East_;
    int Up_;
  
  public:
    Coordinate():North_(0),East_(0),Up_(0){};
    Coordinate(int North_,int East_, int Up_):North_(North_),East_(East_),Up_(Up_){};
    ~Coordinate(){};

    Coordinate setCoordinate(int North_,int East_, int Up_);
    
    void getCoordinate(int North_,int East_, int Up_);

    bool DeathZone(const Coordinate &input);

    friend bool operator== (const Coordinate &lhs, const Coordinate &rhs);
    friend bool operator!= (const Coordinate &lhs,const Coordinate &rhs);
    Coordinate operator= (const Coordinate &rhs);
    Coordinate operator+ (const Coordinate &rhs);   
};

bool DeathZone(const Coordinate &temp)// if DeathZone is true player will be mauled by bunnies
{
  if((temp.North > 5 || -5 < temp.North) || (temp.East >5 || -5 < temp.East))
    {return true;}
  else
    {return false;}
}

bool operator== (const Coordinate &lhs, const Coordinate &hrs)const;
{
    return ((lhs.North == rhs.North)&&(lhs.East==rhs.East)&&(lhs.Up==rhs.Up))
}

bool operator!= (Coordinate &lhs, const Coordinate &hrs)const;
{
    return !(lhs==rhs);
}

Coordinate operator= (const Coordinate &rhs)
{
    Coordinate temp;
    temp.North=rhs.North;
    temp.East=rhs.East;
    temp.Up=rhs.East;

    return temp;
}

Coordinate operator+ (const Coordinate &lhs, const Coordinate &rhs)
{
    Coordinate temp;
    
    temp.North=rhs.North+lhs.North;
    temp.East=rhs.East+lhs.East;
    temp.Up=rhs.Up+lhs.Up

    return temp;
}

#endif 
