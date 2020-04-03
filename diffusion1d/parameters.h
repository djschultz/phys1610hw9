/// 
/// @file parameters.h
///
/// @brief Module for reading parameters for 1d diffusion.
///

#ifndef PARAMETERSH
#define PARAMETERSH

#include <string>

/// @brief The function 'read_parameters' reads in the file
///        inifilename and stores the parameters in that file in
///        variables passed by reference.
///
/// @param inifilename          name of the file containing the parameters (in)
/// @param L   system length (out)
/// @param D   diffusion constant (out)
/// @param T   total time (out)
/// @param dx  spatial resolution (out)
/// @param dt  temporal resolution, i.e., time step (out)
/// @param Z   unused number (out)
/// @param datafile             name of the output file (out)
/// @param time_between_output  how frequently the program writes out (out)
void read_parameters(const std::string &inifilename, 
                     double&      L,
                     double&      D,
                     double&      T,
                     double&      dx,
                     double&      dt,
                     int&         Z,
                     std::string& datafile,
                     double&      time_between_output);

#endif
