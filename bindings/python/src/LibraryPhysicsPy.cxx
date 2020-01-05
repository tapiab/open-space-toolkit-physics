////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           LibraryPhysicsPy.cxx
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>

#include <LibraryPhysicsPy/Environment.cpp>
#include <LibraryPhysicsPy/Coordinate.cpp>
#include <LibraryPhysicsPy/Time.cpp>
#include <LibraryPhysicsPy/Units.cpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_PYTHON_MODULE (LibraryPhysicsPy)
{

    boost::python::object package = boost::python::scope() ;

    package.attr("__path__") = "Library" ;

    LibraryPhysicsPy_Units() ;
    LibraryPhysicsPy_Time() ;
    LibraryPhysicsPy_Coordinate() ;
    LibraryPhysicsPy_Environment() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
