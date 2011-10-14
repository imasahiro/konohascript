using konoha.cairo.*;
using konoha.math.*;

PETAL_MIN = 20;
PETAL_VAR = 40;
N_FLOWERS = 40;

class Flower{
	int x;
	int y;
	int r;
}


void make_flower(Cairo cr, Flower f) {
	Float[] colors =[
		0.71, 0.81, 0.83,
		1.0,  0.78, 0.57,
		0.64, 0.30, 0.35,
		0.73, 0.40, 0.39,
		0.91, 0.56, 0.64,
		0.70, 0.47, 0.45,
		0.92, 0.75, 0.60,
		0.82, 0.86, 0.85,
		0.51, 0.56, 0.67,
		1.0, 0.79, 0.58,
	];

	int idx, last_idx = -1;
	int petal_size = PETAL_MIN + Int.random() % PETAL_VAR;
	int size = petal_size * 8;

	int n_groups = Int.random() % 3 + 1;

	//cr.moveTo(f.x, f.y);
	cr.setTolerance(0.1);
	//cr.setOperator(Cairo.OPERATOR_CLEAR);
	//cr.paint();
	cr.setOperator(Cairo.OPERATOR_OVER);
	cr.translate(f.x/2, f.y/2);
	//cr.rotate(f.r/2);

	for(int i = 0; i < n_groups; i++){
		int n_petals = Int.random() % 5 + 4;
		cr.save();
		cr.rotate(Int.random() % 6);

		do{
			idx = ( Int.random() % ( |colors| / 3 )) * 3;
		}while(idx == last_idx);

		cr.setSourceRgba(colors[idx], colors[idx+1], colors[idx+2], 0.5);

		last_idx = idx;

		int pm1 = Int.random() % 20;
		int pm2 = Int.random() % 4;

		for(int j = 1; j < n_petals+1; j++){
			cr.save();
			cr.rotate((( 2*Math.PI)/n_petals) * j);
			cr.newSubPath();
			cr.moveTo(0,0);
			cr.relCurveTo( petal_size,
					petal_size,
					(pm2 + 2) * petal_size, 
					petal_size,
					(2* petal_size) + pm1,
					0);

			cr.relCurveTo( 0 + (pm2 * petal_size), -petal_size,
					-petal_size, -petal_size, -(( 2 * petal_size) + pm1), 0);
			cr.closePath();
			cr.fill();
			cr.restore();
		}

		petal_size = petal_size - Int.random() % (size/8);
		cr.restore();
	}

	do{
		idx = (Int.random() % ( |colors| / 3)) * 3;
	}while(idx == last_idx);

	if(petal_size < 0) {
		petal_size = Int.random() % 10;
	}

	cr.setSourceRgba(colors[idx], colors[idx+1], colors[idx+2], 0.5);
	cr.arc( 0, 0, petal_size, 0, Math.PI * 2);
	cr.fill();
}

void main(String[] args)
{
	width  = 1024;
	height = 1024;
	s  = new CairoImageSurface(Cairo.FORMAT_RGB24, width, height);
	cr = new Cairo(s);
	cr.set_source_rgba(0, 0, 0, 0xff);
	cr.rectangle(0, 0, width, height);
	cr.fill();
	Flower[] flowers = new Flower[N_FLOWERS];
	for(int i = 0; i < N_FLOWERS; i++){
		f = new Flower();
		f.x = Int.random() % width - (PETAL_MIN + PETAL_VAR) * 2;
		f.y = Int.random() % height;
		f.r = Int.random() % 360 + 1;
		make_flower(cr, f);
		flowers[i] = f;
	}
	s.write_to_png("flower.png");
}

