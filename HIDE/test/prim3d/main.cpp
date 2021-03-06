#include <servoce/servoce.h>
#include <servoce/display.h>

int main() {
	auto box = servoce::box(10,10,10,true);
	auto sphere = servoce::sphere(10);
	auto cylinder = servoce::cylinder(10,10,true);
	auto cone = servoce::cone(10,5,10,true);
	auto torus = servoce::torus(10, 3);

	servoce::scene scn;
	scn.add(sphere 	.left(60), 	servoce::black);
	scn.add(cylinder.left(30), 	servoce::red);
	scn.add(box, 				servoce::green);
	scn.add(torus 	.right(30), servoce::blue);
	scn.add(cone 	.right(60), servoce::white);


	scn.add(sphere 	.left(60) 	.up(30));
	scn.add(cylinder.left(30)	.up(30));
	scn.add(box 				.up(30));
	scn.add(torus 	.right(30)	.up(30));
	scn.add(cone 	.right(60)	.up(30));

	scn.add(sphere 	.left(60) 	.down(30), servoce::gray);
	scn.add(cylinder.left(30)	.down(30), servoce::gray);
	scn.add(box 				.down(30), servoce::gray);
	scn.add(torus 	.right(30)	.down(30), servoce::gray);
	scn.add(cone 	.right(60)	.down(30), servoce::gray);

	servoce::display(scn);
}