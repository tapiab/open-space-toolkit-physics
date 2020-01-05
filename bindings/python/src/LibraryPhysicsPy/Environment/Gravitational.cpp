////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           LibraryPhysicsPy/Environment/Gravitational.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <LibraryPhysicsPy/Environment/Gravitational/Earth.cpp>
#include <LibraryPhysicsPy/Environment/Gravitational/Spherical.cpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryPhysicsPy_Environment_Gravitational  ( )
{

    boost::python::object module(boost::python::handle<>(boost::python::borrowed(PyImport_AddModule("Library.Physics.Environment.Gravitational")))) ;

    boost::python::scope().attr("Gravitational") = module ;

    boost::python::scope scope = module ;

    LibraryPhysicsPy_Environment_Gravitational_Spherical() ;
    LibraryPhysicsPy_Environment_Gravitational_Earth() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
