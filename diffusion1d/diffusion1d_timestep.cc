// 
// diffusion1d_timestep.cc
//
// Time step module for 1d diffusion with periodic boundary conditions 
//
#include <mpi.h>
#include "diffusion1d_timestep.h"
#include <iostream>
// perform a single time step
void diffusion1d_timestep(rvector<double>& P, double D, double dt, double dx)
{     
    int size;
    int rank;
   
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 
    static rvector<double> laplacian;
    const int Nguards = 2;
    const int Nplusguard = P.size();
    const int N = Nplusguard - Nguards; // note that this is the local N because we are dealing with a local P    
    
    int left = rank-1; 
    if(left < 0) left = size-1;
    int right = rank+1; 
    if(right>=size) right=0;
    if (laplacian.size() != Nplusguard) laplacian = rvector<double>(Nplusguard);
    const double alpha = D*dt/(dx*dx);   
    // fill guard cells for correct periodic boundary conditions
    const int guardleft = 0;
    const int guardright = N+1;
    P[guardleft] = P[N];
    P[guardright] = P[1];
    MPI_Sendrecv(&P[1], 1, MPI_DOUBLE, left, 11, &P[guardright], 1, MPI_DOUBLE, right, 11, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Sendrecv(&P[N], 1, MPI_DOUBLE, right, 11, &P[guardleft], 1, MPI_DOUBLE, left, 11, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
    // compute rhs
    for (int i = 1; i <= N; i++)
       laplacian[i] = P[i-1] + P[i+1] - 2*P[i];
    // apply change
    for (int i = 1; i <= N; i++)
       P[i] += alpha*laplacian[i];
}
