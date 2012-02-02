//package jnt.scimark2;

public class SOR
{
    public static final double num_flops(int m, int n, int num_iterations)
    {
        double md = (double) m;
        double nd = (double) n;
        double num_iterD = (double) num_iterations;

        return (md-1)*(nd-1)*num_iterD*6.0;
    }

    public static final void execute(double omega, double[][] g, int 
            num_iterations)
    {
        int m = g.size;
        int n = g[0].size;

        double omega_over_four = omega * 0.25;
        double one_minus_omega = 1.0 - omega;

        // update interior points
        //
        int mm1 = m-1;
        int nm1 = n-1; 
        for (int p=0; p<num_iterations; p++)
        {
            for (int i=1; i<mm1; i++)
            {
                double[] gi = g[i];
                double[] gim1 = g[i-1];
                double[] gip1 = g[i+1];
                for (int j=1; j<nm1; j++)
                    gi[j] = omega_over_four * (gim1[j] + gip1[j] + gi[j-1] 
                            + gi[j+1]) + one_minus_omega * gi[j];
            }
        }
    }
}

