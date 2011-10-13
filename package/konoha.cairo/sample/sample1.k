using konoha.cairo.*;
using konoha.math.*;
void main (String[] args) {
    filename = "hoge.png";
    size = 128;
    radius_scale = size / 3;
    origin = size / 2.0;

    s = new CairoImageSurface(Cairo.FORMAT_RGB24, size, size);
    c = new Cairo(s);

    /* Fill background with white */
    c.set_source_rgb(1.0, 1.0, 1.0);
    c.rectangle(0, 0, size, size);
    c.fill();

    /* Draw the lens disk outline */
    c.set_source_rgb(1.0, 0.0, 0.0);
    c.arc(origin, origin, radius_scale, 0.0, 2 * Math.PI);
    c.stroke();
    s.write_to_png(filename);
}
