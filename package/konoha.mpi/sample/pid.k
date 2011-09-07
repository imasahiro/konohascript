using konoha.mpi.*;
using konoha.posix.*;

world = MPIComm.WORLD;
rank = world.getRank();
size = world.getSize();

print "Hello world from "+"%2d"(rank)+"/"+size+", PID<"+System.getPid()+">";
