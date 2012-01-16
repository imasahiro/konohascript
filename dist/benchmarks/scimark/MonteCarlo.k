//package jnt.scimark2;
//include "scimarkutil/Random.k";
/**
  Estimate Pi by approximating the area of a circle.

How: generate N random numbers in the unit square, (0,0) to (1,1)
and see how are within a radius of 1 or less, i.e.
<pre>  

sqrt(x^2 + y^2) < r

</pre>
since the radius is 1.0, we can square both sides
and avoid a sqrt() computation:
<pre>

x^2 + y^2 <= 1.0

</pre>
this area under the curve is (Pi * r^2)/ 4.0,
and the area of the unit of square is 1.0,
so Pi can be approximated by 
<pre>
# points with x^2+y^2 < 1
Pi =~ 		--------------------------  * 4.0
total # points

</pre>

*/

SEED = 113;
public class MonteCarlo
{

    public static final double num_flops(int num_samples)
    {
        // 3 flops in x^2+y^2 and 1 flop in random routine

        return ((double) num_samples)* 4.0;

    }



    public static final double integrate(int num_samples)
    {

        Random r = new Random(SEED);


        int under_curve = 0;
        for (int count=0; count<num_samples; count++)
        {
            double x= r.nextDouble();
            double y= r.nextDouble();

            if ( x*x + y*y <= 1.0)
                under_curve ++;

        }

        return ((double) under_curve / num_samples) * 4.0;
    }
}
