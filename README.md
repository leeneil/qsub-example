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
