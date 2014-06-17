#!/bin/bash
#PBS -N hello
#PBS -q workq
#PBS -m n
#PBS -l nodes=1:ppn=4
cd $PBS_O_WORKDIR
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/intel/composer_xe_2011_sp1.8.273/compiler/lib/intel64/

mpirun echo "Hello world!"