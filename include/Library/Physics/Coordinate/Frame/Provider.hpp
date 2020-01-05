////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           Library/Physics/Coordinate/Frame/Provider.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Coordinate_Frame_Provider__
#define __Library_Physics_Coordinate_Frame_Provider__

#include <Library/Physics/Coordinate/Transform.hpp>
#include <Library/Physics/Time/Instant.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace physics
{
namespace coord
{
namespace frame
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::physics::time::Instant ;
using library::physics::coord::Transform ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Frame provider

class Provider
{

    public:

                                Provider                                    ( ) ;

        virtual                 ~Provider                                   ( ) = 0 ;

        virtual Provider*       clone                                       ( ) const = 0 ;

        virtual bool            isDefined                                   ( ) const = 0 ;

        virtual Transform       getTransformAt                              (   const   Instant&                    anInstant                                   ) const = 0 ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
