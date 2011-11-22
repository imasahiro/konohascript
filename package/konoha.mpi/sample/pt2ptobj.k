using konoha.mpi.*;
using konoha.io.*;

world = MPIComm.WORLD;
rank = world.getRank();

class Person(String name, int age);
Person p;
b = new byte[0];
if (rank == 0) {
    p = new ("uh", 25);
    b.writeMsgPack(p);
    i = [|b|]
    world.send((MPIData)i, 1, 1);
    world.send((MPIData)b, i[0], 1);
} else {
    i = [0];
    world.recv((MPIData)i, 1, 0);
    world.recv((MPIData)b, i[0], 0);
    p = b.readMsgPack();
}
print p;
