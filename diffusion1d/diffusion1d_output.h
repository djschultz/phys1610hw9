///
/// @file diffusion1d_output.h
///
/// @brief Module for output for 1d diffusion with periodic boundary conditions
///
#ifndef DIFFUSION1DOUTPUTH
#define DIFFUSION1DOUTPUTH

#include <fstream>
#include <rarray>

/// @brief Setup output into a file of file name datafilename.
///        A header will be written to screen as well.
///
/// @param file          the file object to use to open a file
/// @param datafilename  name of the file to open
void diffusion1d_output_init(std::ofstream& file, std::string datafilename);

/// @brief Output into an opened file. There will be other output to
///        screen as well, such as a little graph of the density.
///
/// @param file        the file object to use
/// @param step        number of the current time step
/// @param time        current value of the time
/// @param P           density array
/// @param outputcols  width of the output graph.
void diffusion1d_output(std::ofstream& file, int step, double time, const rvector<double> &P, int outputcols);

/// @brief Finalize output.
///
/// @param file  the file object that was used
void diffusion1d_output_finish(std::ofstream& file);

#endif

