/// @file ticktock.h
///
/// @brief Supplies the class TickTock to measure walltime
///
#ifndef _TICKTOCKH_
#define _TICKTOCKH_

/// @brief Class TickTock keeps track of elapsed time
class TickTock 
{
  public:

    /// @brief Start measuring time.
    void tick();                              

    /// @brief Measure elapsed time and print in seconds, optionally
    ///        prefixed with 'prefix'.  
    /// @param prefix  optional string to write before the elapsed tim
    void tock(const char* prefix=0) const;

    /// @brief Measuring elapsed time.
    /// @return elapsed seconds since call to tick().
    double silent_tock() const;               

  private:
    double tick_; //< stores starting point in seconds
};

#endif
