//============================================================================
// Yet Another ms Timer
//  This module provides yet another a mechanism to perform ms timing based on
//  the arduino millis() function
//
// Author:      Peter Harris
// Date:        2020-06-28
//===========================================================================
#ifndef _YAmsTIMER_H_
#define _YAmsTIMER_H_

#include <arduino.h>
#include <stdbool.h>
#include <stdint.h>

class Yamst
{
  public:
    Yamst()                                     { this->stop();}

    // Stops the timer
    void     stop()                             { this->timestamp = 0;}       // 0 denotes a stopped timer

    // Starts the timer
    void     start();
                                                
    // Returns true if the timer is running
    bool     is_running()                       { return (0 != this->timestamp);}

    // Returns the time in millisecond since the timer was started
    uint32_t get_elapsed_millis(); 

    // Returns true if period milliseconds have passed since the timer was started
    bool     time_has_elapsed(uint32_t period)  { return (this->get_elapsed_millis() >= period); }
  
  private:
    uint32_t timestamp;
};

#endif /* _YAmsTIMER_H_ */
