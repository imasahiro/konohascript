using konoha.mpi.*;

world = MPIComm.WORLD;
rank = world.getRank();
size = world.getSize();

if (size != 2) exit(0);

class Person(String name, String sex);
Person p;

if (rank == 0) {
    p = new Person("John Doe", "male");
    world.send((MPIData)p, 0, 1);
} else {
    MPIData md = new MPIData(Person);
    world.recv(md, 0, 0);
    p = md.decode();
}
print rank, p;