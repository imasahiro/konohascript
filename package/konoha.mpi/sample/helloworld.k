using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.getRank();
size = world.getSize();

print "Hello world from "+rank+"/"+size;
