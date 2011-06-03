using konoha.mpi.*;

int main(void)
{
    c = new MPIContext();
    if (c.size == 2) {
        if (c.rank == 0) {
            /* sender */
            data = (Bytes)"Peter Piper picked a peck of pickled peppers.";
            c.send(data, 1);
            print "SEND: " + data.decode();
        } else {
            /* reciever */
            data = new Bytes(0);
            c.recv(data, 0);
            print "RECV: " + data.decode();
        }
    }
    return 0;
}
