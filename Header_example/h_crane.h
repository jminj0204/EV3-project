// 2017.09.09 Jeong San 
// 2017.09.10 Changbeom Choi -
//Programming 2 class 
//This file contains essential lines and example lines.
//Any question  E-mail 21400684@handong.edu  SMS 010-2393-5390 


#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <time.h>

#include "ev3dev.h"

class CraneCrane
{
private:
    clock_t tNow;
    int nDiff;

protected:
    bool m_down;
    bool m_up;
    bool m_right;
    bool m_left;
    bool m_enter;
    bool m_escape;
         
protected:
    virtual bool get_down() = 0;    // you should override this function
    virtual bool get_up() = 0;      // you should override this function
    virtual bool get_right() = 0;   // you should override this function
    virtual bool get_left() = 0;    // you should override this function
    virtual bool get_enter() = 0;   // you should override this function
    virtual bool get_escape() = 0;  // you should override this function
    virtual int  get_speed() = 0;   // you should override this function

    virtual void set_down(bool val) = 0;    // you should override this function
    virtual void set_up(bool val) = 0;      // you should override this function
    virtual void set_right(bool val) = 0;   // you should override this function
    virtual void set_left(bool val) = 0;    // you should override this function
    virtual void set_enter(bool val) = 0;   // you should override this function
    virtual void set_escape(bool val) = 0;  // you should override this function
    virtual void set_speed(int val) = 0;   // you should override this function
         
public:
    CraneCrane();
    virtual ~CraneCrane();
};


