#include <servoce/servoce.h>
//#include <servoce/display.h>
#include <servoce/util/b64.h>

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include <exception>

#include <Standard_Failure.hxx>

//#include <nos/trace.h>

namespace py = pybind11;
using namespace servoce;

#define DEF_TRANSFORM_OPERATIONS(TYPE) 					\
.def("transform", (TYPE(TYPE::*)(const transformation& trans)) &TYPE::transform, ungil())			\
.def("transform", (TYPE(TYPE::*)(const general_transformation& trans)) &TYPE::transform, ungil())	\
.def("translate", &TYPE::translate, py::arg("x")=0, py::arg("y")=0, py::arg("z")=0, ungil())			\
.def("up", &TYPE::up, ungil())							\
.def("down", &TYPE::down, ungil())						\
.def("right", &TYPE::right, ungil())					\
.def("left", &TYPE::left, ungil())						\
.def("forw", &TYPE::forw, ungil())						\
.def("back", &TYPE::back, ungil())						\
.def("rotate", &TYPE::rotate, ungil())					\
.def("rotateX", &TYPE::rotateX, ungil())				\
.def("rotateY", &TYPE::rotateY, ungil())				\
.def("rotateZ", &TYPE::rotateZ, ungil())				\
.def("mirrorX", &TYPE::mirrorX, ungil())				\
.def("mirrorY", &TYPE::mirrorY, ungil())				\
.def("mirrorZ", &TYPE::mirrorZ, ungil())				\
.def("mirrorXY", &TYPE::mirrorXY, ungil())				\
.def("mirrorYZ", &TYPE::mirrorYZ, ungil())				\
.def("mirrorXZ", &TYPE::mirrorXZ, ungil())				\
.def("scale", 	 &TYPE::scale,    ungil(), py::arg("factor"), py::arg("center") = point3()) \
.def("scaleX",   &TYPE::scaleX,   ungil(), py::arg("factor")) \
.def("scaleY",   &TYPE::scaleY,   ungil(), py::arg("factor")) \
.def("scaleZ",   &TYPE::scaleZ,   ungil(), py::arg("factor")) \
.def("scaleXY",  &TYPE::scaleXY,  ungil(), py::arg("x"), py::arg("y")) \
.def("scaleYZ",  &TYPE::scaleYZ,  ungil(), py::arg("y"), py::arg("z")) \
.def("scaleXZ",  &TYPE::scaleXZ,  ungil(), py::arg("x"), py::arg("z")) \
.def("scaleXYZ", &TYPE::scaleXYZ, ungil(), py::arg("x"), py::arg("y"), py::arg("z")) 

using ungil = py::call_guard<py::gil_scoped_release>;

std::vector<servoce::point3> points(const py::list& lst) 
{
	std::vector<servoce::point3> ret;
	ret.reserve(lst.size());
	for (auto& l : lst) 
	{
		bool b = py::isinstance<py::list>(l);
		if (b)
			ret.emplace_back(servoce::point3(l.cast<py::list>()));
		else 
			ret.emplace_back(l.cast<servoce::point3>());
	}
	return ret;
} 

PYBIND11_MODULE(libservoce, m)
{
// EXCEPTIONS
	static py::exception<Standard_Failure> standart_failure(m, 
		"OpenCascade_Standard_Failure");
	
	static py::exception<Standard_ConstructionError> construction_error(m, 
		"OpenCascade_Standard_ConstructionError");


	py::register_exception_translator([](std::exception_ptr p)
	{
		try
		{
			if (p) std::rethrow_exception(p);
		}
		catch (const Standard_ConstructionError &e)
		{
			construction_error(e.GetMessageString());
		}
		catch (const Standard_Failure &e)
		{
			standart_failure(e.GetMessageString());	
		}
	});

// OBJECTS
	py::class_<point3>(m, "point3")
	.def(py::init<>())
	.def(py::init<double, double, double>())
	.def(py::init<double, double>())
	.def("distance", &point3::distance)
	.def("lerp", &point3::lerp)
	.def(py::init<const servoce::point3&>())
	.def(py::init<py::list>())
	.def(py::init<py::tuple>())
	.def_readwrite("x", &point3::x)
	.def_readwrite("y", &point3::y)
	.def_readwrite("z", &point3::z)
	.def("__iter__", [](const point3& p){return py::make_iterator(&p.x, &p.x + 3);})
	.def("__len__", [](const point3&){return 3;})
	.def("__sub__", (vector3(*)(const point3&, const point3&)) &servoce::operator- )
	.def("__add__", (point3(*)(const point3&, const vector3&)) &servoce::operator+ )
	.def("__sub__", (point3(*)(const point3&, const vector3&)) &servoce::operator- )
	.def("__setitem__", [](point3 & self, int key, double value) { self[key] = value; })
	.def("__getitem__", [](const point3 & self, int key) { return self[key]; })
	.def("__eq__", [](const point3 & a, const point3 & b)
	{
		return point3::early(a, b);
	})
	.def("__repr__", [](const point3 & pnt)
	{
		char buf[128];
		sprintf(buf, "point3(%f,%f,%f)", (double)pnt.x, (double)pnt.y, (double)pnt.z);
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

	py::class_<point2>(m, "point2")
	.def(py::init<>())
	.def(py::init<double, double>())
	.def(py::init<const servoce::point2&>())
	.def(py::init<py::list>())
	.def(py::init<py::tuple>())
	.def("__len__", [](const point2&){return 2;})
	.def("__iter__", [](const point2& p){return py::make_iterator(&p.x, &p.x + 2);})
	.def_readwrite("x", &point2::x)
	.def_readwrite("y", &point2::y)
	.def("__setitem__", [](point2 & self, int key, double value) { self[key] = value; })
	.def("__getitem__", [](const point2 & self, int key) { return self[key]; })
	.def("__eq__", [](const point2 & a, const point2 & b)
	{
		return point2::early(a, b);
	})
	.def("__repr__", [](const point3 & pnt)
	{
		char buf[128];
		sprintf(buf, "point2(%f,%f)", (double)pnt.x, (double)pnt.y);
		return std::string(buf);
	})
	.def(py::pickle(
			 [](const point2 & self)
	{
		double arr[2] = {self.x, self.y};
		return b64::base64_encode((uint8_t*)&arr, 2 * sizeof(double));
	},
	[](const std::string & in)
	{
		double arr[2];
		std::string decoded = b64::base64_decode(in);
		memcpy(&arr, decoded.data(), 2 * sizeof(double));
		return point2(arr);
	}))
	;

	py::class_<xyz>(m, "xyz")
	.def("__add__", &gp_XYZ::operator+ )
	.def("__sub__", &gp_XYZ::operator- )
	.def("__mul__", (gp_XYZ(gp_XYZ::*)(double)const)&gp_XYZ::operator* )
	//.def("__mul__", (gp_XYZ(gp_XYZ::* const)(double))&gp_XYZ::operator* )
	.def("dot", &gp_XYZ::Dot)
	;

	py::class_<vector3>(m, "vector3")
	.def(py::init<>())
	.def(py::init<const servoce::vector3&>())
	.def(py::init<double, double, double>())
	.def(py::init<double, double>())
	.def(py::init<py::list>())
	.def(py::init<py::tuple>())
	.def("to_point3", &vector3::to_point3)
	.def("__iter__", [](const vector3& p){return py::make_iterator(&p.x, &p.x + 3);})
	.def_readwrite("x", &vector3::x)
	.def_readwrite("y", &vector3::y)
	.def_readwrite("z", &vector3::z)
	.def("__len__", [](const vector3&){return 3;})
	.def("__mul__", (vector3(*)(const vector3&, double)) &servoce::operator* )
	.def("__rmul__", (vector3(*)(const vector3&, double)) &servoce::operator* )
	.def("__truediv__", (vector3(*)(const vector3&, double)) &servoce::operator/ )
	.def("__add__", (vector3(*)(const vector3&, const vector3&)) &servoce::operator+ )
	.def("__sub__", (vector3(*)(const vector3&, const vector3&)) &servoce::operator- )
	.def("__neg__", (vector3(vector3::* const)()) &servoce::vector3::operator- )
	.def("__setitem__", [](vector3 & self, int key, double value) { self[key] = value; })
	.def("__getitem__", [](const vector3 & self, int key) { return self[key]; })
	.def("normalize", &vector3::normalize)
	.def("outerprod", &vector3::outerprod)
	.def("length", &vector3::length)
	.def("length2", &vector3::length2)
	.def("early", &vector3::early)
	.def("dot", &vector3::dot)
	.def("cross", &vector3::cross)
	.def("vecmul_matrix", &vector3::vecmul_matrix)
	.def("elementwise_mul", &vector3::elementwise_mul)
	.def("__repr__", [](const vector3 & pnt)
	{
		char buf[128];
		sprintf(buf, "vector3(%f,%f,%f)", (double)pnt.x, (double)pnt.y, (double)pnt.z);
		return std::string(buf);
	})
	.def(py::pickle(
	[](const vector3 & self)
	{
		double arr[3] = {self.x, self.y, self.z};
		return b64::base64_encode((uint8_t*)&arr, 3 * sizeof(double));
	},
	[](const std::string & in)
	{
		double arr[3];
		std::string decoded = b64::base64_decode(in);
		memcpy(&arr, decoded.data(), 3 * sizeof(double));
		return vector3(arr);
	}))
	;

	py::class_<quaternion>(m, "quaternion")
	.def(py::init<>())
	.def(py::init<double, double, double,double>())
	.def(py::init<py::list>())
	.def(py::init<py::tuple>())
	.def("__iter__", [](const quaternion& p){return py::make_iterator(&p.x, &p.x + 4);})
	.def_readwrite("x", &quaternion::x)
	.def_readwrite("y", &quaternion::y)
	.def_readwrite("z", &quaternion::z)
	.def_readwrite("w", &quaternion::w)
	.def("normalize", &quaternion::normalize)
	.def("__len__", [](const quaternion&){return 4;})
	.def("rotation_vector", &quaternion::rotation_vector)
	.def("rotate", &quaternion::rotate)
	.def("to_matrix", &quaternion::to_matrix)
	.def("inverse", &quaternion::inverse)
	//.def("__mul__", (vector3(*)(const vector3&, double)) &servoce::operator* )
	//.def("__truediv__", (vector3(*)(const vector3&, double)) &servoce::operator/ )
	//.def("__add__", (vector3(*)(const vector3&, const vector3&)) &servoce::operator+ )
	//.def("__sub__", (vector3(*)(const vector3&, const vector3&)) &servoce::operator- )
	//.def("__setitem__", [](vector3 & self, int key, double value) { self[key] = value; })
	//.def("__getitem__", [](const vector3 & self, int key) { return self[key]; })
	.def("__repr__", [](const quaternion & pnt)
	{
		char buf[128];
		sprintf(buf, "quaternion(%f,%f,%f,%f)", (double)pnt.x, (double)pnt.y, (double)pnt.z, (double)pnt.w);
		return std::string(buf);
	})

	.def(py::pickle(
		[](const quaternion & self)
		{
			return b64::base64_encode((const uint8_t*)self.data(), 4 * sizeof(double));
		},
		[](const std::string & in)
		{
			double arr[4];
			std::string decoded = b64::base64_decode(in);
			memcpy(&arr, decoded.data(), 4 * sizeof(double));
			return quaternion(arr);
		}))
	;

	py::class_<matrix33>(m, "matrix33", py::buffer_protocol())
		.def(py::init<>())
		.def(py::init<double,double,double>())
		.def(py::init<double,double,double,double,double,double,double,double,double>())
		.def("inverse", &matrix33::inverse)
		.def("transpose", &matrix33::transpose)
		.def("__mul__", (matrix33(matrix33::*)(const matrix33&)) &matrix33::operator*)
		.def("__mul__", (vector3(matrix33::*)(const vector3&)) &matrix33::operator*)
		.def("__mul__", (matrix33(matrix33::*)(double)) &matrix33::operator*)
		.def("__rmul__", (matrix33(matrix33::*)(double)) &matrix33::operator*)
		.def("__add__", (matrix33(matrix33::*)(const matrix33&)) &matrix33::operator+)
		.def("__sub__", (matrix33(matrix33::*)(const matrix33&)) &matrix33::operator-)
		.def("__getitem__", (double&(matrix33::*)(std::pair<int,int>))&matrix33::operator())
		.def("__repr__", [](const matrix33 & m)
		{
			char buf[128];
			sprintf(buf, "matrix33(%f,%f,%f,%f,%f,%f,%f,%f,%f)", 
				m.x.x, m.y.x, m.z.x, m.x.y, m.y.y, m.z.y, m.x.z, m.y.z, m.z.z);
			return std::string(buf);
		})
		.def_buffer([](matrix33 &m) -> py::buffer_info {
			return py::buffer_info(
				m.data(),                               /* Pointer to buffer */
				sizeof(double),                          /* Size of one scalar */
				py::format_descriptor<double>::format(), /* Python struct-style format descriptor */
				2,                                      /* Number of dimensions */
				{ m.rows(), m.cols() },                 /* Buffer dimensions */
				{ sizeof(double),             /* Strides (in bytes) for each index */
				 sizeof(double) * m.cols() }
			);
		})
		.def(py::pickle(
		[](const matrix33 & self)
		{
			return b64::base64_encode((const uint8_t*)self.data(), 9 * sizeof(double));
		},
		[](const std::string & in)
		{
			double arr[9];
			std::string decoded = b64::base64_decode(in);
			memcpy(&arr, decoded.data(), 9 * sizeof(double));
			return matrix33(arr);
		}))
	;

	;

	py::class_<shape>(m, "Shape")
	DEF_TRANSFORM_OPERATIONS(shape)
	.def("__add__", (shape(shape::*)(const shape&))&shape::operator+, ungil())
	.def("__sub__", &shape::operator-, ungil())
	.def("__xor__", &shape::operator^, ungil())
	.def(py::pickle(
	[](const shape & self) { return b64::base64_encode(string_dump(self)); },
	[](const std::string & in) { return restore_string_dump<shape>(b64::base64_decode(in)); }), ungil())
	.def("fill", &shape::fill)
	.def("center", &shape::center, ungil())
	.def("extrude", (shape(shape::*)(const vector3&, bool)) &shape::extrude, ungil(), py::arg("vec"), py::arg("center") = false)
	.def("extrude", (shape(shape::*)(double, double, double, bool)) &shape::extrude, ungil(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("center") = false)
	.def("extrude", (shape(shape::*)(double, bool)) &shape::extrude, ungil(), py::arg("z"), py::arg("center") = false)
	.def("is_closed", &shape::is_closed, ungil())
	.def("sfvertex", &shape::sfvertex, ungil())
	.def("endpoints", &shape::sfvertex, ungil())

	.def("vertices", &shape::vertices, ungil())
	.def("solids", &shape::solids, ungil())
	.def("faces", &shape::faces, ungil())
	.def("edges", &shape::edges, ungil())
	.def("wires", &shape::wires, ungil())
	.def("shells", &shape::shells, ungil())
	.def("compounds", &shape::compounds, ungil())
	.def("compsolids", &shape::compsolids, ungil())

	.def("shapetype", &shape::shapetype_as_string, ungil())
	.def("print_topo_dump", &shape::print_topo_dump, ungil())

	.def("fillet", (shape(shape::*)(double, const std::vector<point3>&))&shape::fillet, ungil(), py::arg("r"), py::arg("refs"))
	.def("fillet", (shape(shape::*)(double))&shape::fillet, ungil(), py::arg("r"))
	.def("chamfer", (shape(shape::*)(double, const std::vector<point3>&))&shape::chamfer, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer", (shape(shape::*)(double))&shape::chamfer, ungil(), py::arg("r"))
	
	.def("fillet2d", (shape(shape::*)(double, const std::vector<point3>&))&shape::fillet2d, ungil(), py::arg("r"), py::arg("refs"))
	.def("fillet2d", (shape(shape::*)(double))&shape::fillet2d, ungil(), py::arg("r"))
	.def("chamfer2d", (shape(shape::*)(double, const std::vector<point3>&))&shape::chamfer2d, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer2d", (shape(shape::*)(double))&shape::chamfer2d, ungil(), py::arg("r"))
	
	.def("fillet", [](const shape& shp, double r, const py::list& arr) { return fillet(shp,r,points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer", [](const shape& shp, double r, const py::list& arr) { return fillet(shp,r,points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer2d", [](const shape& shp, double r, const py::list& arr) { return fillet(shp,r,points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	.def("fillet2d", [](const shape& shp, double r, const py::list& arr) { return fillet(shp,r,points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	
	.def("cmradius", &shape::cmradius, ungil())
	.def("mass", &shape::mass, ungil())
	.def("matrix_of_inertia", &shape::matrix_of_inertia, ungil())
	.def("static_moments", &shape::static_moments, ungil())
	//.def("moment_of_inertia", &shape::moment_of_inertia, ungil()) //TODO
	//.def("radius_of_gyration", &shape::radius_of_gyration, ungil()) //TODO


	;

	py::class_<edge_shape, shape>(m, "Edge")
	.def(py::pickle(
	[](const edge_shape & self) { return b64::base64_encode(string_dump(self)); },
	[](const std::string & in) { return restore_string_dump<edge_shape>(b64::base64_decode(in)); }), ungil())
	.def("range", &edge_shape::range, ungil())
	.def("length", &edge_shape::length, ungil())
	.def("d0", &edge_shape::d0, ungil())
	.def("d1", &edge_shape::d1, ungil())
	.def("linoff", (double(edge_shape::*)(double,double)const)&edge_shape::linoff, ungil())
	//.def("linoff", (double(edge_shape::*)(double)const)&edge_shape::linoff, ungil())
	.def("linoff_point", (point3(edge_shape::*)(double,double)const)&edge_shape::linoff_point, ungil())
	//.def("linoff_point", (point3(edge_shape::*)(double)const)&edge_shape::linoff_point, ungil())
	.def("uniform_points", (std::vector<servoce::point3>(edge_shape::crvalgo::*)(int, double, double)const)&edge_shape::uniform_points, ungil(), py::arg("npnts"), py::arg("strt"), py::arg("fini"))
	.def("uniform_points", (std::vector<servoce::point3>(edge_shape::crvalgo::*)(int)const)&edge_shape::uniform_points, ungil(), py::arg("npnts"))
	.def("uniform", (std::vector<double>(edge_shape::crvalgo::*)(int, double, double)const)&edge_shape::uniform, ungil(), py::arg("npnts"), py::arg("strt"), py::arg("fini"))
	.def("uniform", (std::vector<double>(edge_shape::crvalgo::*)(int)const)&edge_shape::uniform, ungil(), py::arg("npnts"))
	;

	py::class_<wire_shape, shape>(m, "Wire")
	.def(py::pickle(
	[](const wire_shape & self) { return b64::base64_encode(string_dump(self)); },
	[](const std::string & in) { return restore_string_dump<wire_shape>(b64::base64_decode(in)); }), ungil())
	;

	m.def("fillet", (shape(*)(const shape&, double, const std::vector<point3>&))&servoce::fillet, ungil(), py::arg("shp"), py::arg("r"), py::arg("refs"));
	m.def("fillet", (shape(*)(const shape&, double))&servoce::fillet, ungil(), py::arg("shp"), py::arg("r"));
	m.def("chamfer", (shape(*)(const shape&, double, const std::vector<point3>&))&servoce::chamfer, ungil(), py::arg("shp"), py::arg("r"), py::arg("refs"));
	m.def("chamfer", (shape(*)(const shape&, double))&servoce::chamfer, ungil(), py::arg("shp"), py::arg("r"));
	
	m.def("fillet2d", (shape(*)(const shape&, double, const std::vector<point3>&))&servoce::fillet2d, ungil(), py::arg("shp"), py::arg("r"), py::arg("refs"));
	m.def("fillet2d", (shape(*)(const shape&, double))&servoce::fillet2d, ungil(), py::arg("shp"), py::arg("r"));
	m.def("chamfer2d", (shape(*)(const shape&, double, const std::vector<point3>&))&servoce::chamfer2d, ungil(), py::arg("shp"), py::arg("r"), py::arg("refs"));
	m.def("chamfer2d", (shape(*)(const shape&, double))&servoce::chamfer2d, ungil(), py::arg("shp"), py::arg("r"));

//PRIM3D
	m.def("box", 		box, ungil(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("center") = false);

	m.def("sphere", 	(shape(*)(double))&sphere, ungil(), py::arg("r"));
	m.def("sphere", 	(shape(*)(double,double))&sphere, ungil(), py::arg("r"), py::arg("yaw"));
	m.def("sphere", 	(shape(*)(double,double,double))&sphere, ungil(), py::arg("r"), py::arg("pitch0"), py::arg("pitch1"));
	m.def("sphere", 	(shape(*)(double,double,double,double))&sphere, ungil(), py::arg("r"), py::arg("pitch0"), py::arg("pitch1"), py::arg("yaw"));

	m.def("cylinder", 	(shape(*)(double, double, bool)) &cylinder, ungil(), py::arg("r"), py::arg("h"), py::arg("center") = false);
	m.def("cylinder", 	(shape(*)(double, double, double, bool)) &cylinder, ungil(), py::arg("r"), py::arg("h"), py::arg("yaw"), py::arg("center") = false);

	m.def("cone", 		(shape(*)(double, double, double, bool)) &cone, ungil(), py::arg("r1"), py::arg("r2"), py::arg("h"), py::arg("center") = false);
	m.def("cone", 		(shape(*)(double, double, double, double, bool)) &cone, ungil(), py::arg("r1"), py::arg("r2"), py::arg("h"), py::arg("yaw"), py::arg("center") = false);

	m.def("torus", 		(shape(*)(double, double)) &torus, ungil(), py::arg("r1"), py::arg("r2"));
	m.def("torus", 		(shape(*)(double, double, double)) &torus, ungil(), py::arg("r1"), py::arg("r2"), py::arg("yaw"));
	m.def("torus", 		(shape(*)(double, double, double, double)) &torus, ungil(), py::arg("r1"), py::arg("r2"), py::arg("pitch0"), py::arg("pitch1"));
	m.def("torus", 		(shape(*)(double, double, double, double, double)) &torus, ungil(), py::arg("r1"), py::arg("r2"), py::arg("pitch0"), py::arg("pitch1"), py::arg("yaw"));
	m.def("halfspace", 	&halfspace, ungil());

	m.def("thicksolid", &thicksolid, ungil());
	m.def("unify", 		&unify, ungil());

//OPS3D
	m.def("linear_extrude", (shape(*)(const shape&, const vector3&, bool)) &make_linear_extrude, ungil(), py::arg("shp"), py::arg("vec"), py::arg("center") = false);
	m.def("linear_extrude", (shape(*)(const shape&, double, bool)) &make_linear_extrude, ungil(), py::arg("shp"), py::arg("z"), py::arg("center") = false);
	m.def("linear_extrude", [](const shape & shp, const py::list & lst, bool center) { return servoce::make_linear_extrude(shp, vector3(lst[0].cast<double>(), lst[1].cast<double>(), lst[2].cast<double>()), center); }, ungil(), py::arg("shp"), py::arg("vec"), py::arg("center") = false);
	m.def("pipe", 			make_pipe, ungil(), py::arg("prof"), py::arg("path"));
	m.def("pipe_shell", 	make_pipe_shell, ungil(), py::arg("prof"), py::arg("path"), py::arg("isFrenet") = false);
	m.def("loft", 			loft, ungil(), py::arg("arr"), py::arg("smooth")=false);
	m.def("revol", 			revol, ungil());

//PRIM2D
	m.def("square", 	square, ungil(), py::arg("a"), py::arg("center") = false, py::arg("wire")=false);
	m.def("rectangle", 	rectangle, ungil(), py::arg("a"), py::arg("b"), py::arg("center") = false, py::arg("wire")=false);
	
	m.def("circle", 	(shape(*)(double, bool)) &circle, ungil(), py::arg("r"), py::arg("wire")=false);
	m.def("circle", 	(shape(*)(double, double, bool)) &circle, ungil(), py::arg("r"), py::arg("angle"), py::arg("wire")=false);
	m.def("circle", 	(shape(*)(double, double, double, bool)) &circle, ungil(), py::arg("r"), py::arg("a1"), py::arg("a2"), py::arg("wire")=false);
	
	m.def("ellipse", 	(shape(*)(double, double, bool)) &ellipse, ungil(), py::arg("r1"), py::arg("r2"), py::arg("wire")=false);
	m.def("ellipse", 	(shape(*)(double, double, double, double, bool)) &ellipse, ungil(), py::arg("r1"), py::arg("r2"), py::arg("a1"), py::arg("a2"), py::arg("wire")=false);
	
	m.def("ngon", 		ngon, ungil(), py::arg("r"), py::arg("n"), py::arg("wire")=false);
	m.def("polygon", 	(shape(*)(const std::vector<point3>&))&polygon, ungil(), py::arg("pnts"));
	m.def("textshape", 	textshape, ungil(), py::arg("text"), py::arg("fontpath"), py::arg("size"));

	m.def("infplane", 	infplane, ungil());

	m.def("fill", &fill, ungil());

//PRIM1D
	#include <pywrap/wire.h>

//SURFACE
	py::class_<surface::surface>(m, "surface")
		.def("map", &surface::surface::map, ungil());
	m.def("surface_cylinder", surface::cylinder, ungil());
	
//CURVE2
	py::class_<curve2::curve2>(m, "curve2")
		.def("value", &curve2::curve2::value)
		.def(py::pickle(
		[](const curve2::curve2 & self) { return b64::base64_encode(string_dump(self)); },
		[](const std::string & in) { return restore_string_dump<curve2::curve2>(b64::base64_decode(in)); }), ungil())
		.def("rotate", &curve2::curve2::rotate, ungil())
	;
	py::class_<curve2::trimmed_curve2, curve2::curve2>(m, "trimmed_curve2")
		.def(py::init<const curve2::curve2&, double, double>(), ungil())
	;
	m.def("curve2_ellipse", curve2::ellipse, ungil());
	m.def("curve2_segment", curve2::segment, ungil());

//CURVE3
	#include <pywrap/curve3.h>

//BOOLEAN
	m.def("union", (shape(*)(const std::vector<const shape*>&))&make_union, ungil());
	m.def("difference", (shape(*)(const std::vector<const shape*>&))&make_difference, ungil());
	m.def("intersect", (shape(*)(const std::vector<const shape*>&))&make_intersect, ungil());
	m.def("section", (shape(*)(const shape&, const shape&))&make_section, ungil());
	m.def("section", (shape(*)(const shape&))&make_section, ungil());

//TRANS
	py::class_<transformation>(m, "transformation")
	.def("__call__", (shape(transformation::*)(const shape&)const)&transformation::operator(), ungil())
	.def("__call__", (point3(transformation::*)(const point3&)const)&transformation::operator(), ungil())
	.def("__call__", (vector3(transformation::*)(const vector3&)const)&transformation::operator(), ungil())
	.def("__call__", (transformation(transformation::*)(const transformation&)const)&transformation::operator(), ungil())
	.def("__mul__", &transformation::operator*, ungil())
	.def("invert", &transformation::invert)
	.def("inverse", &transformation::invert)
	.def(py::pickle(
	[](const transformation & self) { return b64::base64_encode(self.string_dump()); },
	[](const std::string & in) { return transformation::restore_string_dump(b64::base64_decode(in)); }), ungil())
	.def("translation_part", &transformation::translation_part)
	.def("rotation_part", &transformation::rotation_part)
	.def("translation", &transformation::translation)
	.def("rotation", &transformation::rotation)
	.def("__repr__", [](const transformation & trsf)
	{
		char buf[128];
		auto rot = trsf.rotation();
		auto mov = trsf.translation(); 
		sprintf(buf, "trans((%f,%f,%f,%f),(%f,%f,%f))", rot.x, rot.y, rot.z, rot.w, mov.x, mov.y, mov.z);
		return std::string(buf);
	})
	;

	py::class_<general_transformation>(m, "general_transformation")
	.def("__call__", (shape(general_transformation::*)(const shape&)const)&general_transformation::operator(), ungil())
	.def("__call__", (general_transformation(general_transformation::*)(const general_transformation&)const)&general_transformation::operator(), ungil())
	//.def("__mul__", &general_transformation::operator* )
	.def(py::pickle(
	[](const general_transformation & self) { return b64::base64_encode(self.string_dump()); },
	[](const std::string & in) { return general_transformation::restore_string_dump(b64::base64_decode(in)); }), ungil())
	;

	m.def("translate", (transformation(*)(double, double, double)) &translate, py::arg("x")=0, py::arg("y")=0, py::arg("z")=0, ungil());
	m.def("translate", (transformation(*)(double, double)) &translate, py::arg("x")=0, py::arg("y")=0, ungil());
	m.def("translate", (transformation(*)(const vector3&)) &translate, ungil());
	m.def("axrotation", axrotation, ungil());
	m.def("axis_mirror", axis_mirror, ungil());
	m.def("plane_mirror", plane_mirror, ungil());

	m.def("rotate", rotate, ungil());
	m.def("rotateX", rotateX, ungil());
	m.def("rotateY", rotateY, ungil());
	m.def("rotateZ", rotateZ, ungil());
	m.def("mirrorX", mirrorX, ungil());
	m.def("mirrorY", mirrorY, ungil());
	m.def("mirrorZ", mirrorZ, ungil());
	m.def("mirrorXY", mirrorXY, ungil());
	m.def("mirrorXZ", mirrorXZ, ungil());
	m.def("mirrorYZ", mirrorYZ, ungil());
	m.def("up", up, ungil());
	m.def("down", down, ungil());
	m.def("left", left, ungil());
	m.def("right", right, ungil());
	m.def("forw", forw, ungil());
	m.def("back", back, ungil());
	m.def("scale", &scale, ungil(), py::arg("factor"), py::arg("center") = servoce::point3());
	m.def("scaleX", scaleX, ungil(), py::arg("factor"));
	m.def("scaleY", scaleY, ungil(), py::arg("factor"));
	m.def("scaleZ", scaleZ, ungil(), py::arg("factor"));
	m.def("scaleXY", scaleXY, ungil(), py::arg("x"), py::arg("y"));
	m.def("scaleYZ", scaleYZ, ungil(), py::arg("y"), py::arg("z"));
	m.def("scaleXZ", scaleXZ, ungil(), py::arg("x"), py::arg("z"));
	m.def("scaleXYZ", &scaleXYZ, ungil(), py::arg("x"), py::arg("y"), py::arg("z"));
	m.def("nulltrans", nulltrans, ungil());

	m.def("short_rotate", &short_rotate, ungil());

//GRAPHIC
	py::class_<color>(m, "Color")
	.def(py::init<>(), ungil())
	.def(py::init<py::list>())
	.def(py::init<py::tuple>())
	.def(py::init<const color&>(), ungil())
	.def(py::init<float, float, float>(), ungil())
	.def(py::init<float, float, float,float>(), ungil())
	.def_readwrite("r", &color::r)
	.def_readwrite("g", &color::g)
	.def_readwrite("b", &color::b)
	.def_readwrite("a", &color::a)
	.def(py::pickle(
	[](const color & self)
	{
		float arr[4] = {self.r, self.g, self.b, self.a};
		return b64::base64_encode((uint8_t*)&arr, 4 * sizeof(float));
	},
	[](const std::string & in)
	{
		float arr[4];
		std::string decoded = b64::base64_decode(in);
		memcpy(&arr, decoded.data(), 4 * sizeof(float));
		return color{arr[0],arr[1],arr[2],arr[3]};
	}), ungil())
	;

	py::class_<interactive_object, std::shared_ptr<interactive_object>>(m, "interactive_object")
	.def(py::init<const servoce::shape&>(), ungil())
	.def("set_color", (void(interactive_object::*)(const servoce::color&))&interactive_object::set_color, ungil())
	.def("set_color", (void(interactive_object::*)(float,float,float,float))&interactive_object::set_color, py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a")=0, ungil())
	.def("color", &interactive_object::color, ungil())
	.def("set_location", &interactive_object::set_location, ungil())
	.def("relocate", &interactive_object::relocate, ungil())
	.def("hide", &interactive_object::hide, ungil())
	;

	/*py::class_<shape_view, std::shared_ptr<shape_view>>(m, "ShapeView")
	.def("shape", &shape_view::shape, ungil())
	.def("color", &shape_view::color, ungil())
	.def("set_color", (void(shape_view::*)(const servoce::color&))&shape_view::set_color, ungil())
	.def("set_color", (void(shape_view::*)(float,float,float,float))&shape_view::set_color, py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a")=0, ungil())
	.def("set_location", &shape_view::set_location, ungil())
	.def("relocate", &shape_view::relocate, ungil())
	.def("hide", &shape_view::hide, ungil())
	;*/

	py::class_<scene>(m, "Scene")
	.def(py::init<>(), ungil())
	.def_readonly("viewer", &scene::vwer, py::return_value_policy::reference)
	.def("add", (std::shared_ptr<interactive_object>(scene::*)(const shape&, color))&scene::add, py::arg("shape"), py::arg("color") = color{0.6, 0.6, 0.8}, ungil())
	.def("add", (std::shared_ptr<interactive_object>(scene::*)(const point3&, color))&scene::add, py::arg("shape"), py::arg("color") = color{0.6, 0.6, 0.8}, ungil())
	.def("add", (std::shared_ptr<interactive_object>(scene::*)(std::shared_ptr<servoce::interactive_object>))&scene::add, py::arg("iobj"), ungil())
	//.def("append", (void(scene::*)(const scene&))&scene::append, py::arg("scene"), ungil())
	//.def("shapes_array", (std::vector<shape>(scene::*)())&scene::shapes_array, ungil())
	//.def("color_array", (std::vector<color>(scene::*)())&scene::color_array, ungil())
	.def("__getitem__", &scene::operator[])
	.def("total", &scene::total)
	//.def("__getitem__", [](const scene & s, size_t i) { return s[i]; }, ungil())
	;

	py::class_<viewer, std::shared_ptr<viewer>>(m, "Viewer")
	.def("create_view", &viewer::create_view, ungil())
	.def("redraw", &viewer::redraw, ungil())
	.def("close", &viewer::close, ungil())
//	.def("add_scene", &viewer::add_scene, ungil())
	.def("clean_context", &viewer::clean_context, ungil())
//	.def("display", (void(viewer::*)(shape_view&))&viewer::display, ungil())
	.def("display", (void(viewer::*)(interactive_object&))&viewer::display, ungil())
	.def("set_triedron_axes", &viewer::set_triedron_axes, py::arg("en")=true, ungil())
	;

	py::class_<view>(m, "View")
	.def("set_window", &view::set_window, ungil())
	.def("set_virtual_window", &view::set_virtual_window, ungil())
	.def("set_triedron", &view::set_triedron, py::arg("en")=true, ungil())
	.def("see", &view::see, ungil())
	.def("destroy", &view::destroy, ungil())
	.def("redraw", &view::redraw, ungil())
	.def("redraw_immediate", &view::redraw_immediate, ungil())
	.def("must_be_resized", &view::must_be_resized, ungil())
	.def("fit_all", &view::fit_all, py::arg("scale")=0.1, ungil())
	.def("set_direction", &view::set_direction, ungil())
	.def("direction", &view::direction, ungil())
	.def("pan", &view::pan, ungil())
	.def("zoom", &view::zoom, ungil())
	.def("scale", &view::scale, ungil())
	.def("set_scale", &view::set_scale, ungil())
	.def("set_eye", &view::set_eye, ungil())
	.def("eye", &view::eye, ungil())
	.def("set_center", &view::set_center, ungil())
	.def("center", &view::center, ungil())
	//.def("resize", &view::resize, ungil())
	.def("size", &view::size, ungil())
	.def("set_orthogonal", &view::set_orthogonal, ungil())

	.def("set_gradient", &view::set_gradient, ungil())
	.def("set_background", &view::set_background, ungil())
	.def("reset_orientation", &view::reset_orientation, ungil())
	.def("autoscale", &view::autoscale, ungil())
	.def("centering", &view::centering, ungil())
	.def("start_rotation", &view::start_rotation, ungil())
	.def("rotation", &view::rotation, ungil())

	.def("rawarray", (std::vector<unsigned char>(view::*)())&view::rawarray, ungil())
	.def("rawarray", (std::vector<unsigned char>(view::*)(int,int))&view::rawarray, ungil())
	//.def("screen", &view::screen)
	.def("see", &view::see, ungil())

	.def("intersect_point", &view::intersect_point, ungil())
	;

// CONVERT
	m.def("make_stl", &make_stl, ungil());
	m.def("brep_write", &brep_write, ungil());
	m.def("brep_read", &brep_read, ungil());

	m.def("getSVG", &getSVG, ungil());

// REFLECTION
	m.def("near_edge", &near_edge, ungil());	
	m.def("near_face", &near_face, ungil());
	m.def("near_vertex", &near_vertex, ungil());

// PRESENTATION
	m.attr("white") = white;
	m.attr("black") = black;
	m.attr("red") = red;
	m.attr("green") = green;
	m.attr("blue") = blue;
	m.attr("yellow") = yellow;
	m.attr("gray") = gray;
	m.attr("mech") = mech;

	py::enum_<line_style>(m, "line_style")
		.value("solid_line", line_style::solid_line)
		.value("dash_line", line_style::dash_line)
		.value("dot_line", line_style::dot_line)
		.value("dotdash_line", line_style::dotdash_line)
	.export_values();

	m.def("draw_arrow", &draw::arrow, py::arg("pnt"), py::arg("vec"), py::arg("clr")=yellow, py::arg("arrlen")=1, py::arg("width")=1);
	m.def("draw_line", &draw::line, py::arg("a"), py::arg("b"), py::arg("clr")=black, py::arg("style")=line_style::solid_line, py::arg("width")=1);

	py::class_<geomprops>(m, "geomprops")
	//	.def("volume_properties", &geomprops::volume_properties)
	//	.def("mass", &GProp_GProps::Mass)
		.def("cmpoint", &GProp_GProps::CentreOfMass)
	//	.def("cmradius", &geomprops::cmradius)
	//	.def("inermat", &GProp_GProps::MatrixOfInertia)
	;
}
