#!/bin/sh
nfiles=25
nfileperjob=1
njobs=`echo "$nfiles/$nfileperjob" | bc`
echo "split into $njobs jobs, $nfileperjob files per job"
for i in `seq 1 $njobs`
do
echo $i
start=`echo "($i-1)*$nfileperjob" | bc`
end=`echo "$i*$nfileperjob" | bc`
export I=$i
export START=$start
export END=$end
sbatch --account=cms_stage2 -J PU1j$i -o job$i.out runjobs.slurm
#sbatch --account=cms_stage2 runjobs.slurm
done
