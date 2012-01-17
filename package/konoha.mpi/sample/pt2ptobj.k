using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.getRank();
size = world.getSize();

if (size != 2) exit(0);

class Person(String name, int age);

if (rank == 0) {
    MPIData md = (MPIData)new Person("uh", 25);
    world.send(md, -1, 1);
} else {
    MPIData md = (MPIData)new byte[0];
    world.recv(md, -1, 0);
    p = md.decode(Person);
    print p, p.class;
}
