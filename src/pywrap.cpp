#include <servoce/servoce.h>
//#include <servoce/display.h>
#include <servoce/util/b64.h>

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include <exception>

namespace py = pybind11;
using namespace servoce;

#define DEF_TRANSFORM_OPERATIONS(TYPE) 				\
.def("transform", &TYPE::transform)				\
.def("translate", &TYPE::translate)							\
.def("up", &TYPE::up)							\
.def("down", &TYPE::down)						\
.def("right", &TYPE::right)						\
.def("left", &TYPE::left)						\
.def("forw", &TYPE::forw)						\
.def("back", &TYPE::back)						\
.def("rotateX", &TYPE::rotateX)					\
.def("rotateY", &TYPE::rotateY)					\
.def("rotateZ", &TYPE::rotateZ)					\
.def("mirrorX", &TYPE::mirrorX)					\
.def("mirrorY", &TYPE::mirrorY)					\
.def("mirrorZ", &TYPE::mirrorZ)					\
.def("mirrorXY", &TYPE::mirrorXY)				\
.def("mirrorYZ", &TYPE::mirrorYZ)				\
.def("mirrorXZ", &TYPE::mirrorXZ)				\
.def("scale", (shape(TYPE::*)(double,point3))&TYPE::scale, py::arg("factor"), py::arg("center") = point3())

PYBIND11_MODULE(libservoce, m)
{
//EXCEPTONS
	py::register_exception<std::runtime_error>(m, "std::runtime_error");

//OBJECTS
	py::class_<point3>(m, "point3")
	//DEF_TRANSFORM_OPERATIONS(point3)
	.def(py::init<double, double, double>())
	.def(py::init<double, double>())
	.def(py::init<const servoce::point3&>())
	.def(py::init<py::list>())
	.def_readwrite("x", &point3::x)
	.def_readwrite("y", &point3::y)
	.def_readwrite("z", &point3::z)
	.def("__eq__", [](const point3 & a, const point3 & b)
	{
		return point3::early(a, b);
	})
	.def("__repr__", [](const point3 & pnt)
	{
		char buf[128];
		sprintf(buf, "point3(%f,%f,%f)", pnt.x, pnt.y, pnt.z);
		return std::string(buf);
	})
	.def(py::pickle(
	         [](const point3 & self)
	{
		double arr[3] = {self.x, self.y, self.z};
		return b64::base64_encode((uint8_t*)&arr, 3 * sizeof(double));
	},
	[](const std::string & in)
	{
		double arr[3];
		std::string decoded = b64::base64_decode(in);
		memcpy(&arr, decoded.data(), 3 * sizeof(double));
		return point3(arr);
	}))
	;

	py::class_<vector3>(m, "vector3")
	//DEF_TRANSFORM_OPERATIONS(vector3)
	.def(py::init<double, double, double>())
	.def(py::init<double, double>())
	.def(py::init<py::list>())
	.def_readwrite("x", &vector3::x)
	.def_readwrite("y", &vector3::y)
	.def_readwrite("z", &vector3::z)
	.def("__repr__", [](const vector3 & pnt)
	{
		char buf[128];
		sprintf(buf, "vector3(%f,%f,%f)", pnt.x, pnt.y, pnt.z);
		return std::string(buf);
	})
	;

	py::class_<shape>(m, "Shape")
	DEF_TRANSFORM_OPERATIONS(shape)
	.def("__add__", &shape::operator+)
	.def("__sub__", &shape::operator-)
	.def("__xor__", &shape::operator^)
	.def(py::pickle(
	[](const shape & self) { return b64::base64_encode(self.string_dump()); },
	[](const std::string & in) { return shape::restore_string_dump(b64::base64_decode(in)); }))
	.def("fillet", &shape::fillet, py::arg("r"), py::arg("nums") = py::tuple())
	.def("fill", &shape::fill)
	.def("vertices", &shape::vertices)
	.def("center", &shape::center)
	.def("extrude", (shape(shape::*)(const vector3&, bool)) &shape::extrude, py::arg("vec"), py::arg("center") = false)
	.def("extrude", (shape(shape::*)(double, double, double, bool)) &shape::extrude, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("center") = false)
	.def("extrude", (shape(shape::*)(double, bool)) &shape::extrude, py::arg("z"), py::arg("center") = false)
	;

//PRIM3D
	m.def("make_box", 		box, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("center") = false);
	m.def("make_sphere", 	sphere, py::arg("r"));
	m.def("make_cylinder", 	(shape(*)(double, double, bool)) &cylinder, py::arg("r"), py::arg("h"), py::arg("center") = false);
	m.def("make_cylinder", 	(shape(*)(double, double, double, bool)) &cylinder, py::arg("r"), py::arg("h"), py::arg("angle"), py::arg("center") = false);
	m.def("make_cone", 		cone, py::arg("r1"), py::arg("r2"), py::arg("h"), py::arg("center") = false);
	m.def("make_torus", 	torus, py::arg("r1"), py::arg("r2"));

	m.def("box", 		box, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("center") = false);
	m.def("sphere", 	sphere, py::arg("r"));
	m.def("cylinder", 	(shape(*)(double, double, bool)) &cylinder, py::arg("r"), py::arg("h"), py::arg("center") = false);
	m.def("cylinder", 	(shape(*)(double, double, double, bool)) &cylinder, py::arg("r"), py::arg("h"), py::arg("angle"), py::arg("center") = false);
	m.def("cone", 		cone, py::arg("r1"), py::arg("r2"), py::arg("h"), py::arg("center") = false);
	m.def("torus", 		torus, py::arg("r1"), py::arg("r2"));

//OPS3D
	m.def("make_linear_extrude", (shape(*)(const shape&, const vector3&, bool)) &make_linear_extrude, py::arg("shp"), py::arg("vec"), py::arg("center") = false);
	m.def("make_linear_extrude", (shape(*)(const shape&, double, bool)) &make_linear_extrude, py::arg("shp"), py::arg("z"), py::arg("center") = false);
	m.def("make_linear_extrude", [](const shape & shp, const py::list & lst, bool center) { return servoce::make_linear_extrude(shp, vector3(lst[0].cast<double>(), lst[1].cast<double>(), lst[2].cast<double>()), center); }, py::arg("shp"), py::arg("vec"), py::arg("center") = false);
	m.def("make_pipe", 			make_pipe, py::arg("prof"), py::arg("path"));
	m.def("make_pipe_shell", 	make_pipe_shell, py::arg("prof"), py::arg("path"), py::arg("isFrenet") = false);

//PRIM2D
	m.def("make_circle", 	(shape(*)(double)) &circle, py::arg("r"));
	m.def("make_circle", 	(shape(*)(double, double)) &circle, py::arg("r"), py::arg("angle"));
	m.def("make_ngon", 		ngon, py::arg("r"), py::arg("n"));
	m.def("make_square", 	square, py::arg("a"), py::arg("center") = false);
	m.def("make_rectangle", rectangle, py::arg("a"), py::arg("b"), py::arg("center") = false);
	m.def("make_polygon", 	(shape(*)(const std::vector<point3>&))&polygon, py::arg("pnts"));

	m.def("square", 	square, py::arg("a"), py::arg("center") = false);
	m.def("rectangle", 	rectangle, py::arg("a"), py::arg("b"), py::arg("center") = false);
	m.def("circle", 	(shape(*)(double)) &circle, py::arg("r"));
	m.def("circle", 	(shape(*)(double, double)) &circle, py::arg("r"), py::arg("angle"));
	m.def("ngon", 		ngon, py::arg("r"), py::arg("n"));
	m.def("polygon", 	(shape(*)(const std::vector<point3>&))&polygon, py::arg("pnts"));

//PRIM1D
	m.def("make_segment", make_segment);
	m.def("make_polysegment", (shape(*)(const std::vector<point3>&, const bool))&make_polysegment, py::arg("pnts"), py::arg("closed") = false);
	m.def("make_interpolate", (shape(*)(const std::vector<point3>&, const std::vector<vector3>&, bool))&make_interpolate, py::arg("pnts"), py::arg("tang"), py::arg("closed") = false);
	m.def("make_interpolate", (shape(*)(const std::vector<point3>&, const bool))&make_interpolate, py::arg("pnts"), py::arg("closed") = false);
	m.def("make_helix", make_helix, py::arg("step"), py::arg("height"), py::arg("radius"), py::arg("angle") = 0, py::arg("leftHanded") = false, py::arg("newStyle") = true);
	m.def("make_long_helix", make_long_helix, py::arg("step"), py::arg("height"), py::arg("radius"), py::arg("angle") = 0, py::arg("leftHanded") = false);

	m.def("make_circle_arc", (shape(*)(double))&make_circle_arc);
	m.def("make_circle_arc", (shape(*)(double, double, double))&make_circle_arc);

//BOOLEAN
	m.def("make_union", (shape(*)(const std::vector<const shape*>&))&make_union);
	m.def("make_difference", (shape(*)(const std::vector<const shape*>&))&make_difference);
	m.def("make_intersect", (shape(*)(const std::vector<const shape*>&))&make_intersect);

//TRANS
	py::class_<transformation>(m, "transformation")
	.def("__call__", (shape(transformation::*)(const shape&)const)&transformation::operator())
	.def("__call__", (transformation(transformation::*)(const transformation&)const)&transformation::operator())
	.def("__mul__", &transformation::operator* )
	.def(py::pickle(
	[](const transformation & self) { return b64::base64_encode(self.string_dump()); },
	[](const std::string & in) { return transformation::restore_string_dump(b64::base64_decode(in)); }))
	;

	m.def("translate", (transformation(*)(double, double, double)) &translate);
	m.def("translate", (transformation(*)(double, double)) &translate);
	m.def("translate", (transformation(*)(const vector3&)) &translate);
	m.def("axrotation", axrotation);
	m.def("axis_mirror", axis_mirror);
	m.def("plane_mirror", plane_mirror);

	m.def("rotateX", rotateX);
	m.def("rotateY", rotateY);
	m.def("rotateZ", rotateZ);
	m.def("mirrorX", mirrorX);
	m.def("mirrorY", mirrorY);
	m.def("mirrorZ", mirrorZ);
	m.def("mirrorXY", mirrorXY);
	m.def("mirrorXZ", mirrorXZ);
	m.def("mirrorYZ", mirrorYZ);
	m.def("up", up);
	m.def("down", down);
	m.def("left", left);
	m.def("right", right);
	m.def("forw", forw);
	m.def("back", back);
	m.def("scale", scale, py::arg("factor"), py::arg("center") = servoce::point3());

	//m.def("simplify_with_bspline", &simplify_with_bspline);

//GRAPHIC
	py::class_<color>(m, "Color")
	.def(py::init<float, float, float>());

	py::class_<shape_view>(m, "ShapeView")
	.def("shape", &shape_view::shape)
	.def("color", &shape_view::color)
	;

	py::class_<scene>(m, "Scene")
	.def(py::init<>())
	.def("add", (void(scene::*)(const shape&, color))&scene::add, py::arg("shape"), py::arg("color") = color{0.6, 0.6, 0.8})
	.def("add", (void(scene::*)(const point3&, color))&scene::add, py::arg("shape"), py::arg("color") = color{0.6, 0.6, 0.8})
	.def("append", (void(scene::*)(const scene&))&scene::append, py::arg("scene"))
	.def("__getitem__", [](const scene & s, size_t i) { return s[i]; })
	;

	py::class_<viewer>(m, "Viewer")
	.def(py::init<>())
	.def(py::init<const scene&>())
	.def("create_view", &viewer::create_view)
	.def("set_triedron_axes", &viewer::set_triedron_axes)
	;

	py::class_<view>(m, "View")
	.def("set_window", &view::set_window)
	.def("set_virtual_window", &view::set_virtual_window)
	.def("set_triedron", &view::set_triedron)
	.def("see", &view::see)
	.def("redraw", &view::redraw)
	.def("must_be_resized", &view::must_be_resized)
	.def("fit_all", &view::fit_all)
	.def("set_projection", &view::set_projection)
	.def("pan", &view::pan)
	.def("zoom", &view::zoom)

	.def("set_gradient", &view::set_gradient)
	.def("reset_orientation", &view::reset_orientation)
	.def("autoscale", &view::autoscale)
	.def("start_rotation", &view::start_rotation)
	.def("rotation", &view::rotation)

	.def("rawarray", &view::rawarray)
	.def("screen", &view::screen)
	.def("see", &view::see)
	;

//CONVERT
	m.def("make_stl", &make_stl);
	m.def("brep_write", &brep_write);
	m.def("brep_read", &brep_read);
}

servoce::point3::point3(const py::list& lst)
{
	if (lst.size() >= 1) x = lst[0].cast<double>();

	if (lst.size() >= 2) y = lst[1].cast<double>();

	if (lst.size() >= 3) z = lst[2].cast<double>();
}

servoce::vector3::vector3(const py::list& lst)
{
	if (lst.size() >= 1) x = lst[0].cast<double>();

	if (lst.size() >= 2) y = lst[1].cast<double>();

	if (lst.size() >= 3) z = lst[2].cast<double>();
}