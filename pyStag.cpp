#include "extern/pybind11_opencv_numpy/ndarray_converter.h"
#include <pybind11/cast.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "StagWrapper.cpp"
namespace py = pybind11;
using namespace py::literals;

PYBIND11_MODULE(pyStag, m) {
  // this is crucial for convertation between numpy::ndarray and cv::Mat
  NDArrayConverter::init_numpy();
  m.def("detectMarkers", &detectMarkers, "Test");

}