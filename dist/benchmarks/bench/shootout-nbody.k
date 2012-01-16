/* The Computer Language Benchmarks Game
 * http://shootout.alioth.debian.org/
 * 
 * contributed by Mark C. Lewis
 * modified slightly by Chad Whipkey
 */

include "_bench.k";
using konoha.math.Math;

PI = 3.141592653589793;
SOLAR_MASS = 4 * PI * PI;
DAYS_PER_YEAR = 365.24;

class Body {
    double x, y, z, vx, vy, vz, mass;

    @Static Body jupiter(){
        Body p = new Body();
        p.x = 4.84143144246472090e+00;
        p.y = -1.16032004402742839e+00;
        p.z = -1.03622044471123109e-01;
        p.vx = 1.66007664274403694e-03 * DAYS_PER_YEAR;
        p.vy = 7.69901118419740425e-03 * DAYS_PER_YEAR;
        p.vz = -6.90460016972063023e-05 * DAYS_PER_YEAR;
        p.mass = 9.54791938424326609e-04 * SOLAR_MASS;
        return p;
    }

    @Static Body saturn(){
        Body p = new Body();
        p.x = 8.34336671824457987e+00;
        p.y = 4.12479856412430479e+00;
        p.z = -4.03523417114321381e-01;
        p.vx = -2.76742510726862411e-03 * DAYS_PER_YEAR;
        p.vy = 4.99852801234917238e-03 * DAYS_PER_YEAR;
        p.vz = 2.30417297573763929e-05 * DAYS_PER_YEAR;
        p.mass = 2.85885980666130812e-04 * SOLAR_MASS;
        return p;
    }

    @Static Body uranus(){
        Body p = new Body();
        p.x = 1.28943695621391310e+01;
        p.y = -1.51111514016986312e+01;
        p.z = -2.23307578892655734e-01;
        p.vx = 2.96460137564761618e-03 * DAYS_PER_YEAR;
        p.vy = 2.37847173959480950e-03 * DAYS_PER_YEAR;
        p.vz = -2.96589568540237556e-05 * DAYS_PER_YEAR;
        p.mass = 4.36624404335156298e-05 * SOLAR_MASS;
        return p;
    }

    @Static Body neptune(){
        Body p = new Body();
        p.x = 1.53796971148509165e+01;
        p.y = -2.59193146099879641e+01;
        p.z = 1.79258772950371181e-01;
        p.vx = 2.68067772490389322e-03 * DAYS_PER_YEAR;
        p.vy = 1.62824170038242295e-03 * DAYS_PER_YEAR;
        p.vz = -9.51592254519715870e-05 * DAYS_PER_YEAR;
        p.mass = 5.15138902046611451e-05 * SOLAR_MASS;
        return p;
    }

    @Static Body sun(){
        Body p = new Body();
        p.mass = SOLAR_MASS;
        return p;
    }

    Body offsetMomentum(double px, double py, double pz){
        vx = -px / SOLAR_MASS;
        vy = -py / SOLAR_MASS;
        vz = -pz / SOLAR_MASS;
        return this;
    }
}

class NBodySystem {
    Body[] bodies;

    NBodySystem() {
        double px = 0.0;
        double py = 0.0;
        double pz = 0.0;
        bodies = [Body.sun(), Body.jupiter(), Body.saturn(), Body.uranus(), Body.neptune()];
        for(int i=0; i < bodies.size; ++i) {
            px += bodies[i].vx * bodies[i].mass;
            py += bodies[i].vy * bodies[i].mass;
            pz += bodies[i].vz * bodies[i].mass;
        }
        bodies[0].offsetMomentum(px,py,pz);
    }

    void advance(double dt) {
        for(int i=0; i < bodies.size; ++i) {
            Body iBody = bodies[i];
            for(int j=i+1; j < bodies.size; ++j) {
                double dx = iBody.x - bodies[j].x;
                double dy = iBody.y - bodies[j].y;
                double dz = iBody.z - bodies[j].z;
                double dSquared = dx * dx + dy * dy + dz * dz;
                double distance = Math.sqrt(dSquared);
                double mag = dt / (dSquared * distance);

                iBody.vx -= dx * bodies[j].mass * mag;
                iBody.vy -= dy * bodies[j].mass * mag;
                iBody.vz -= dz * bodies[j].mass * mag;

                bodies[j].vx += dx * iBody.mass * mag;
                bodies[j].vy += dy * iBody.mass * mag;
                bodies[j].vz += dz * iBody.mass * mag;
            }
        }

        for(int i=0; i < bodies.size; ++i) {
            Body body = bodies[i];
            body.x += dt * body.vx;
            body.y += dt * body.vy;
            body.z += dt * body.vz;
        }
    }

    double energy(){
        double dx, dy, dz, distance;
        double e = 0.0;

        for (int i=0; i < bodies.size; ++i) {
            Body iBody = bodies[i];
            e += (0.5 * iBody.mass * ( iBody.vx * iBody.vx + iBody.vy * iBody.vy + iBody.vz * iBody.vz ));

            for (int j=i+1; j < bodies.size; ++j) {
                Body jBody = bodies[j];
                dx = iBody.x - jBody.x;
                dy = iBody.y - jBody.y;
                dz = iBody.z - jBody.z;

                distance = Math.sqrt(dx*dx + dy*dy + dz*dz);
                e -= (iBody.mass * jBody.mass) / distance;
            }
        }
        return e;
    }
}

class NbodyBench extends BenchMarkTask {
    NbodyBench() {
        this.name = "NBody";
    }
    @Override void run() {
        int n = 50000000;
        NBodySystem bodies = new NBodySystem();
        OUT.println("energy:"+ bodies.energy());
        for (int i = 0; i < n; i++) {
            bodies.advance(0.01);
        }
        OUT.println("energy:"+ bodies.energy());
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask(new NbodyBench());
    bm.run();
}
