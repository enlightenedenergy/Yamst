
#include <Yamst.h>

// Starts the timer
void Yamst::start()
{ 
  this->timestamp = millis(); // Set timestamp to current time
  if (0 == this->timestamp)   
  {
    // Special case at startup and rollover. 
    // As 0 represents a stopped timer we advance to 1
    this->timestamp = 1; 
  }
}
                                                
// Returns the time in millisecond since the timer was started
uint32_t Yamst::get_elapsed_millis()
{ 
  uint32_t result = 0;
  if (0 < this->timestamp)
  {
    result = millis() - this->timestamp;
  }
  return result; 
} 
  

