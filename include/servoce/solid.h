#ifndef SERVOCE_SOLID_H
#define SERVOCE_SOLID_H

#include <servoce/shape.h>

namespace servoce
{
	class shell_shape;

	class solid_shape :
		public shape_typed<solid_shape>
	{
	public:
		//wire_shape(TopoDS_Wire& arg) : shape(arg) {}
		solid_shape() {}
		solid_shape(const TopoDS_Solid& arg) : shape_typed((const TopoDS_Shape&)arg) {}
		solid_shape(servoce::shape&& arg) : solid_shape(arg.Solid()) {}
	};

	//class sweep_solid_shape {};

	solid_shape box(double x, double y, double z, bool center = false);
	solid_shape sphere(double r);
	solid_shape sphere(double r, double an1);
	solid_shape sphere(double r, double an1, double an2);
	solid_shape sphere(double r, double an1, double an2, double an3);
	solid_shape cylinder(double r, double h, bool center = false);
	solid_shape cylinder(double r, double h, double angle, bool center = false);
	solid_shape cylinder(double r, double h, double a1, double a2, bool center = false);
	solid_shape cone(double r1, double r2, double h, bool center = false);
	solid_shape cone(double r1, double r2, double h, double angle, bool center = false);
	solid_shape cone(double r1, double r2, double h, double a1, double a2, bool center = false);
	solid_shape torus(double r1, double r2);
	solid_shape torus(double r1, double r2, double ua);
	solid_shape torus(double r1, double r2, double va1, double va2);
	solid_shape torus(double r1, double r2, double va1, double va2, double ua);

	//shape make_pipe_shell(const shape& profile, const shape& spine, 
	//	const shape& auxiliary_spine, bool curvilinear_equivalence);

	shape loft(const std::vector<shape>& vec, bool smooth=false, bool solid=true, int maxdegree=4);
	shape revol(const shape& proto, double angle = 0.0);

	solid_shape halfspace();
	shape thicksolid(const shape& proto, const std::vector<point3>& pnt, double thickness);

	shape fillet(const shape& shp, double r, const std::vector<point3>& refs);
	shape fillet(const shape& shp, double r);
	shape chamfer(const shape& shp, double r, const std::vector<point3>& refs);
	shape chamfer(const shape& shp, double r);

	shape unify(const shape& proto);

	servoce::solid_shape make_solid(const servoce::shell_shape& shp);
	servoce::solid_shape make_solid(const std::vector<const servoce::shell_shape*>& shp);

	shape offset_shape(const servoce::shape& shp, double off);


	// TODO: Move to face
}

#endif
