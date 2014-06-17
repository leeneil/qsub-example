qsub-example
============

Shell script example for TORQUE submission

# Get started

To download this example, run

```
wget https://github.com/leeneil/qsub-example/archive/master.tar.gz
```

then untar the tar.gz file by runnung

```
tar -zxvf master.tar.gz
```

Now you can checkout the directory or try to modify the `job.sh` by using `vim`.

```
cd qsub-example-master/
```

or 

```
vim qsub-example-master/job.sh
```

# Run example

```
qsub job.sh
```

Right after the submission, you might `qstat` to check out if the job is sucessfully submitted.


# Reference

The file `job.sh` looks

``` sh
#!/bin/bash
#PBS -N hello
#PBS -q workq
#PBS -m n
#PBS -l nodes=1:ppn=4
cd $PBS_O_WORKDIR

mpirun echo "Hello world!"
```

There are some optional fields you can set.

## Job name
```
#PBS -N hello
```

Just replace `hello` by any other name you like.

## Numbers of nodes and cores
```
#PBS -l nodes=1:ppn=4
```

In this line you can specify how many nodes you want to use and number of cores **in each node**. For example, `nodes=2:ppn=12` will distribute your job to 2 nodes, with each 12 cors, yielding 24 processors in total. Please note `ppn` means ** processors per node**.


## Executable

Last but not least, please specify the binary file you want to run. For example
```
mpirun ./a.out 1 
```
will run the binary file `a.out` under your local directory with an argument `1`.



