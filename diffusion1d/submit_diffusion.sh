#!/bin/bash
#SBATCH --nodes=2
#SBATCH --cpus-per-task=1
#SBATCH --ntasks-per-node=16
#SBATCH --time=4:00:00
#SBATCH --job-name=diffusion
#SBATCH --mail-type=FAIL

module load gcc rarray openmpi

for i in {1..32}
do  
    startTime=$(date +%s)
    mpirun -n $i ./diffusion1d
    endTime=$(date +%s)
    runtime=$(echo "$endTime - $startTime" | bc) 
    echo $runtime >> times.dat
    wait
done

