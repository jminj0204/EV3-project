#include "h_crane.h"
#include <iostream>

#include "ev3dev.h"

class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::ultrasonic_sensor ultra_q;
    ev3dev::motor a;
    ev3dev::motor b;
    ev3dev::motor c; 
    
public:
    // Hardware Configuration
    Crain(): touch_q(ev3dev::INPUT_2), ultra_q(ev3dev::INPUT_1),a(ev3dev::OUTPUT_A), b(ev3dev::OUTPUT_C), c(ev3dev::OUTPUT_B)
    {
        
    }
    
public:
    // Hardware Configuration
    float Distance;
    
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();
    }
    
    virtual int  get_speed()
    {
        return 100;
    }

    void Crane_UpAndDown(int direction)
    {
        //Up: direct=-1, Down: direct=1
        a.set_position_sp(100*(direction)).set_speed_sp(get_speed()*(10)).run_to_abs_pos();
        sleep(1);
        a.set_stop_action("brake").stop();
    }
    
    void Crane_OpenAndClose(int direction)
    {
        //Open: direct=1, Close: direct=-1
        c.set_position_sp(90*(direction)).set_speed_sp(get_speed()*(9)).run_to_abs_pos();
        sleep(1);
        c.set_stop_action("brake").stop();
    }
      
    void Crane_Find(int direction)
    {
        Distance=16; //Distance Initialize
        
        //Stop Motor when a thing is Found
        while(Distance>9.8)
        {
            Distance=ultra_q.distance_centimeters();
            b.set_speed_sp(get_speed()*(4)*direction); //clockwise: direct=1, Counterclockwise: direct=-1 
            b.run_forever();
        }
        b.stop();
    }
    
     void Crane_ArriveToFinish()
    {
        //Get the thing to finish line
        b.set_position_sp(610).set_speed_sp(get_speed()*(10)).run_to_abs_pos();
        sleep(1);
        b.set_stop_action("brake").stop();
    }
    
    void Crane_AfterFind()
    {
        Crane_OpenAndClose(1); //Open
        Crane_UpAndDown(1); //Down
        Crane_OpenAndClose(-1); //Close
        Crane_UpAndDown(-1); //Up
        Crane_ArriveToFinish(); 
        Crane_UpAndDown(1); //Down
    }
    
    void Crane_FirstPick()
    {
        Crane_UpAndDown(-1); //Up
        Crane_Find(1); 
        Crane_AfterFind();
    }
    
    void Crane_PickAgain()
    {
        Crane_OpenAndClose(1); //Open
        Crane_UpAndDown(-1); //Up
        sleep(1);
        Crane_Find(-1);
        Crane_AfterFind();
    }
   
public:
    void Pick3Items_code();
};

void Crain::Pick3Items_code()
{   
    Crane_FirstPick();
    Crane_PickAgain();
    Crane_PickAgain();
    
    a.stop();
    b.stop();
    c.stop();
}

int main()
{     
    Crain crain;
    while(true){
        if(crain.get_touch_pressed()==true){ 
            crain.Pick3Items_code();
        }
    }
}