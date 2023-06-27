/// Apache License 2.0

#include <OpenSpaceToolkit/Physics/Coordinate/Position.hpp>
#include <OpenSpaceToolkit/Physics/Coordinate/Spherical/LLA.hpp>
#include <OpenSpaceToolkit/Physics/Environment/Atmospheric/Earth.hpp>
#include <OpenSpaceToolkit/Physics/Time/Instant.hpp>

#include <OpenSpaceToolkitPhysicsPy/Environment/Atmospheric/Earth/CSSISpaceWeather.cpp>
#include <OpenSpaceToolkitPhysicsPy/Environment/Atmospheric/Earth/Manager.cpp>

inline void OpenSpaceToolkitPhysicsPy_Environment_Atmospheric_Earth(pybind11::module& aModule)
{
    using namespace pybind11;

    using ostk::core::fs::Directory;

    using ostk::core::types::Shared;

    using ostk::physics::environment::atmospheric::Earth;
    using ostk::physics::time::Instant;
    using ostk::physics::coord::Position;
    using ostk::physics::coord::Position;
    using ostk::physics::coord::spherical::LLA;

    {
        class_<Earth, Shared<Earth>> earth_class(aModule, "Earth");

        earth_class

            .def(init<const Earth::Type&, const Directory&>(), arg("type"), arg("directory"))

            .def(init<const Earth::Type&>(), arg("type"))

            .def("get_type", &Earth::getType)

            .def("is_defined", &Earth::isDefined)

            .def(
                "get_density_at",
                pybind11::overload_cast<const Position&, const Instant&>(&Earth::getDensityAt, pybind11::const_),
                arg("position"),
                arg("instant")
            )

            .def(
                "get_density_at",
                pybind11::overload_cast<const LLA&, const Instant&>(&Earth::getDensityAt, pybind11::const_),
                arg("lla"),
                arg("instant")
            )

            ;

        enum_<Earth::Type>(earth_class, "Type")

            .value("Undefined", Earth::Type::Undefined)
            .value("Exponential", Earth::Type::Exponential);
    }

    // Create "earth" python submodule
    auto earth = aModule.def_submodule("earth");

    // Add __path__ attribute for "earth" submodule
    earth.attr("__path__") = "ostk.physics.environment.atmospheric.earth";

    OpenSpaceToolkitPhysicsPy_Environment_Atmospheric_Earth_CSSISpaceWeather(earth);
    OpenSpaceToolkitPhysicsPy_Environment_Atmospheric_Earth_Manager(earth);
}
