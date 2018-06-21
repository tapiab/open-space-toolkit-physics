////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Time/Duration.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Physics/Time/Scale.hpp>
#include <Library/Physics/Time/Instant.hpp>
#include <Library/Physics/Time/Duration.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_Physics_Time_Duration, Constructor)
{

    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        const Int64 nanosecondCount = 123456 ;

        EXPECT_NO_THROW(Duration duration(nanosecondCount)) ;

    }

    {

        const Int64 nanosecondCount = -123456 ;

        EXPECT_NO_THROW(Duration duration(nanosecondCount) ;) ;

    }

    {

        const Int64 nanosecondCount = 0 ;

        EXPECT_NO_THROW(Duration duration(nanosecondCount) ;) ;

    }

}

TEST (Library_Physics_Time_Duration, EqualToOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(0) == Duration(0)) ;
        EXPECT_TRUE(Duration(1) == Duration(1)) ;
        EXPECT_TRUE(Duration(-1) == Duration(-1)) ;

    }

    {

        EXPECT_FALSE(Duration(-1) == Duration(0)) ;
        EXPECT_FALSE(Duration(+1) == Duration(0)) ;

        EXPECT_FALSE(Duration(0) == Duration(-1)) ;
        EXPECT_FALSE(Duration(0) == Duration(+1)) ;

    }

    {

        EXPECT_FALSE(Duration::Undefined() == Duration::Undefined()) ;
        EXPECT_FALSE(Duration::Undefined() == Duration(0)) ;
        EXPECT_FALSE(Duration(0) == Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, NoEqualToOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(-1) != Duration(0)) ;
        EXPECT_TRUE(Duration(+1) != Duration(0)) ;

        EXPECT_TRUE(Duration(0) != Duration(-1)) ;
        EXPECT_TRUE(Duration(0) != Duration(+1)) ;

    }

    {

        EXPECT_TRUE(Duration::Undefined() != Duration::Undefined()) ;
        EXPECT_TRUE(Duration::Undefined() != Duration(0)) ;
        EXPECT_TRUE(Duration(0) != Duration::Undefined()) ;

    }

    {

        EXPECT_FALSE(Duration(0) != Duration(0)) ;
        EXPECT_FALSE(Duration(1) != Duration(1)) ;
        EXPECT_FALSE(Duration(-1) != Duration(-1)) ;

    }

}

TEST (Library_Physics_Time_Duration, LessThanOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(-1) < Duration(0)) ;
        EXPECT_TRUE(Duration(0) < Duration(+1)) ;
        EXPECT_TRUE(Duration(-1) < Duration(+1)) ;

    }

    {

        EXPECT_FALSE(Duration(0) < Duration(0)) ;
        EXPECT_FALSE(Duration(+1) < Duration(0)) ;
        EXPECT_FALSE(Duration(+1) < Duration(-1)) ;
        EXPECT_FALSE(Duration(0) < Duration(-1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() < Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() < Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) < Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, LessThanOrEqualToOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(-1) <= Duration(0)) ;
        EXPECT_TRUE(Duration(0) <= Duration(+1)) ;
        EXPECT_TRUE(Duration(-1) <= Duration(+1)) ;

        EXPECT_TRUE(Duration(0) <= Duration(0)) ;

    }

    {

        EXPECT_FALSE(Duration(+1) <= Duration(0)) ;
        EXPECT_FALSE(Duration(+1) <= Duration(-1)) ;
        EXPECT_FALSE(Duration(0) <= Duration(-1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() <= Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() <= Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) <= Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, GreaterThanOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(+1) > Duration(0)) ;
        EXPECT_TRUE(Duration(+1) > Duration(-1)) ;
        EXPECT_TRUE(Duration(0) > Duration(-1)) ;

    }

    {

        EXPECT_FALSE(Duration(0) > Duration(0)) ;
        
        EXPECT_FALSE(Duration(-1) > Duration(0)) ;
        EXPECT_FALSE(Duration(0) > Duration(+1)) ;
        EXPECT_FALSE(Duration(-1) > Duration(+1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() > Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() > Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) > Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, GreaterThanOrEqualToOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(+1) >= Duration(0)) ;
        EXPECT_TRUE(Duration(+1) >= Duration(-1)) ;
        EXPECT_TRUE(Duration(0) >= Duration(-1)) ;

        EXPECT_TRUE(Duration(0) >= Duration(0)) ;

    }

    {

        EXPECT_FALSE(Duration(-1) >= Duration(0)) ;
        EXPECT_FALSE(Duration(0) >= Duration(+1)) ;
        EXPECT_FALSE(Duration(-1) >= Duration(+1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() >= Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() >= Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) >= Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, AdditionOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) + Duration(0)) ;
        EXPECT_EQ(Duration(1), Duration(1) + Duration(0)) ;
        EXPECT_EQ(Duration(1), Duration(0) + Duration(1)) ;
        EXPECT_EQ(Duration(2), Duration(1) + Duration(1)) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) + Duration(0)) ;
        EXPECT_EQ(Duration(-1), Duration(0) + Duration(-1)) ;
        EXPECT_EQ(Duration(-2), Duration(-1) + Duration(-1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() + Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() + Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) + Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, SubtractionOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) - Duration(0)) ;
        EXPECT_EQ(Duration(+1), Duration(1) - Duration(0)) ;
        EXPECT_EQ(Duration(-1), Duration(0) - Duration(1)) ;
        EXPECT_EQ(Duration(0), Duration(1) - Duration(1)) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) - Duration(0)) ;
        EXPECT_EQ(Duration(+1), Duration(0) - Duration(-1)) ;
        EXPECT_EQ(Duration(0), Duration(-1) - Duration(-1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() - Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() - Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) - Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, MultiplicationOperator)
{
    
    using library::core::types::Real ;
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) * 0) ;
        EXPECT_EQ(Duration(0), Duration(0) * 1) ;

        EXPECT_EQ(Duration(0), Duration(1) * 0) ;
        EXPECT_EQ(Duration(+1), Duration(1) * +1) ;
        EXPECT_EQ(Duration(-1), Duration(1) * -1) ;
        
        EXPECT_EQ(Duration(0), Duration(-1) * 0) ;
        EXPECT_EQ(Duration(-1), Duration(-1) * +1) ;
        EXPECT_EQ(Duration(+1), Duration(-1) * -1) ;

    }

    {

        EXPECT_EQ(Duration(0), Duration(0) * 0.0) ;
        EXPECT_EQ(Duration(0), Duration(0)) ;

        EXPECT_EQ(Duration(0), Duration(1) * 0.0) ;
        EXPECT_EQ(Duration(+1), Duration(1) * +1.0) ;
        EXPECT_EQ(Duration(-1), Duration(1) * -1.0) ;
        
        EXPECT_EQ(Duration(0), Duration(-1) * 0.0) ;
        EXPECT_EQ(Duration(-1), Duration(-1) * +1.0) ;
        EXPECT_EQ(Duration(+1), Duration(-1) * -1.0) ;

    }

    {

        EXPECT_EQ(Duration(0), 0 * Duration(0)) ;
        EXPECT_EQ(Duration(0), 1 * Duration(0)) ;

        EXPECT_EQ(Duration(0), 0 * Duration(1)) ;
        EXPECT_EQ(Duration(+1), +1 * Duration(1)) ;
        EXPECT_EQ(Duration(-1), -1 * Duration(1)) ;
        
        EXPECT_EQ(Duration(0), 0 * Duration(-1)) ;
        EXPECT_EQ(Duration(-1), +1 * Duration(-1)) ;
        EXPECT_EQ(Duration(+1), -1 * Duration(-1)) ;

    }

    {

        EXPECT_EQ(Duration(0), 0.0 * Duration(0)) ;
        EXPECT_EQ(Duration(0), 1.0 * Duration(0)) ;

        EXPECT_EQ(Duration(0), 0.0 * Duration(1)) ;
        EXPECT_EQ(Duration(+1), +1.0 * Duration(1)) ;
        EXPECT_EQ(Duration(-1), -1.0 * Duration(1)) ;
        
        EXPECT_EQ(Duration(0), 0.0 * Duration(-1)) ;
        EXPECT_EQ(Duration(-1), +1.0 * Duration(-1)) ;
        EXPECT_EQ(Duration(+1), -1.0 * Duration(-1)) ;

    }

    {

        EXPECT_EQ(Duration(+123456), Duration(1000) * +123.456) ;
        EXPECT_EQ(Duration(-123456), Duration(1000) * -123.456) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() * Real::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() * 0) ;
        EXPECT_ANY_THROW(Duration::Undefined() * 0.0) ;
        EXPECT_ANY_THROW(0 * Duration::Undefined()) ;
        EXPECT_ANY_THROW(0.0 * Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, DivisionOperator)
{
    
    using library::core::types::Real ;
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) / 1) ;

        EXPECT_EQ(Duration(+1), Duration(1) / +1) ;
        EXPECT_EQ(Duration(-1), Duration(1) / -1) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) / +1) ;
        EXPECT_EQ(Duration(+1), Duration(-1) / -1) ;

    }

    {

        EXPECT_EQ(Duration(0), Duration(0) / 1.0) ;

        EXPECT_EQ(Duration(+1), Duration(1) / +1.0) ;
        EXPECT_EQ(Duration(-1), Duration(1) / -1.0) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) / +1.0) ;
        EXPECT_EQ(Duration(+1), Duration(-1) / -1.0) ;

    }

    {

        EXPECT_EQ(Duration(+20), Duration(+1000) / +50.0) ;
        EXPECT_EQ(Duration(-20), Duration(+1000) / -50.0) ;

        EXPECT_EQ(Duration(-20), Duration(-1000) / +50.0) ;
        EXPECT_EQ(Duration(+20), Duration(-1000) / -50.0) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() / Real::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() / 1) ;
        EXPECT_ANY_THROW(Duration::Undefined() / 1.0) ;
        EXPECT_ANY_THROW(Duration::Undefined() / 0) ;
        EXPECT_ANY_THROW(Duration::Undefined() / 0.0) ;

        EXPECT_ANY_THROW(Duration(123) / Real::Undefined()) ;
        EXPECT_ANY_THROW(Duration(123) / 0) ;
        EXPECT_ANY_THROW(Duration(123) / 0.0) ;

    }

}

TEST (Library_Physics_Time_Duration, AdditionAssignementOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) += Duration(0)) ;
        EXPECT_EQ(Duration(1), Duration(1) += Duration(0)) ;
        EXPECT_EQ(Duration(1), Duration(0) += Duration(1)) ;
        EXPECT_EQ(Duration(2), Duration(1) += Duration(1)) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) += Duration(0)) ;
        EXPECT_EQ(Duration(-1), Duration(0) += Duration(-1)) ;
        EXPECT_EQ(Duration(-2), Duration(-1) += Duration(-1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() += Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() += Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) += Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, SubtractionAssignementOperator)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) -= Duration(0)) ;
        EXPECT_EQ(Duration(+1), Duration(1) -= Duration(0)) ;
        EXPECT_EQ(Duration(-1), Duration(0) -= Duration(1)) ;
        EXPECT_EQ(Duration(0), Duration(1) -= Duration(1)) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) -= Duration(0)) ;
        EXPECT_EQ(Duration(+1), Duration(0) -= Duration(-1)) ;
        EXPECT_EQ(Duration(0), Duration(-1) -= Duration(-1)) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() -= Duration::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() -= Duration(0)) ;
        EXPECT_ANY_THROW(Duration(0) -= Duration::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, MultiplicationAssignementOperator)
{
    
    using library::core::types::Real ;
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) *= 0) ;
        EXPECT_EQ(Duration(0), Duration(0) *= 1) ;

        EXPECT_EQ(Duration(0), Duration(1) *= 0) ;
        EXPECT_EQ(Duration(+1), Duration(1) *= +1) ;
        EXPECT_EQ(Duration(-1), Duration(1) *= -1) ;
        
        EXPECT_EQ(Duration(0), Duration(-1) *= 0) ;
        EXPECT_EQ(Duration(-1), Duration(-1) *= +1) ;
        EXPECT_EQ(Duration(+1), Duration(-1) *= -1) ;

    }

    {

        EXPECT_EQ(Duration(0), Duration(0) *= 0.0) ;
        EXPECT_EQ(Duration(0), Duration(0) *= 1.0) ;

        EXPECT_EQ(Duration(0), Duration(1) *= 0.0) ;
        EXPECT_EQ(Duration(+1), Duration(1) *= +1.0) ;
        EXPECT_EQ(Duration(-1), Duration(1) *= -1.0) ;
        
        EXPECT_EQ(Duration(0), Duration(-1) *= 0.0) ;
        EXPECT_EQ(Duration(-1), Duration(-1) *= +1.0) ;
        EXPECT_EQ(Duration(+1), Duration(-1) *= -1.0) ;

    }

    {

        EXPECT_EQ(Duration(+123456), Duration(1000) *= +123.456) ;
        EXPECT_EQ(Duration(-123456), Duration(1000) *= -123.456) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() *= Real::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() *= 0) ;
        EXPECT_ANY_THROW(Duration::Undefined() *= 0.0) ;

    }

}

TEST (Library_Physics_Time_Duration, DivisionAssignementOperator)
{
    
    using library::core::types::Real ;
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0) /= 1) ;

        EXPECT_EQ(Duration(+1), Duration(1) /= +1) ;
        EXPECT_EQ(Duration(-1), Duration(1) /= -1) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) /= +1) ;
        EXPECT_EQ(Duration(+1), Duration(-1) /= -1) ;

    }

    {

        EXPECT_EQ(Duration(0), Duration(0) /= 1.0) ;

        EXPECT_EQ(Duration(+1), Duration(1) /= +1.0) ;
        EXPECT_EQ(Duration(-1), Duration(1) /= -1.0) ;
        
        EXPECT_EQ(Duration(-1), Duration(-1) /= +1.0) ;
        EXPECT_EQ(Duration(+1), Duration(-1) /= -1.0) ;

    }

    {

        EXPECT_EQ(Duration(+20), Duration(+1000) /= +50.0) ;
        EXPECT_EQ(Duration(-20), Duration(+1000) /= -50.0) ;

        EXPECT_EQ(Duration(-20), Duration(-1000) /= +50.0) ;
        EXPECT_EQ(Duration(+20), Duration(-1000) /= -50.0) ;

    }

    {

        EXPECT_ANY_THROW(Duration::Undefined() /= Real::Undefined()) ;
        EXPECT_ANY_THROW(Duration::Undefined() /= 1) ;
        EXPECT_ANY_THROW(Duration::Undefined() /= 1.0) ;
        EXPECT_ANY_THROW(Duration::Undefined() /= 0) ;
        EXPECT_ANY_THROW(Duration::Undefined() /= 0.0) ;

        EXPECT_ANY_THROW(Duration(123) /= Real::Undefined()) ;
        EXPECT_ANY_THROW(Duration(123) /= 0) ;
        EXPECT_ANY_THROW(Duration(123) /= 0.0) ;

    }

}

TEST (Library_Physics_Time_Duration, StreamOperator)
{
    
    using library::physics::time::Duration ;

    {

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << Duration(123) << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (Library_Physics_Time_Duration, IsDefined)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(0).isDefined()) ;
        
        EXPECT_TRUE(Duration(+1).isDefined()) ;
        EXPECT_TRUE(Duration(-1).isDefined()) ;

    }

    {
        
        EXPECT_FALSE(Duration::Undefined().isDefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, IsZero)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(0).isZero()) ;
        
    }

    {

        EXPECT_FALSE(Duration(+1).isZero()) ;
        EXPECT_FALSE(Duration(-1).isZero()) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().isZero()) ;

    }

}

TEST (Library_Physics_Time_Duration, IsPositive)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(0).isPositive()) ;
        EXPECT_TRUE(Duration(+1).isPositive()) ;
        
    }

    {

        EXPECT_FALSE(Duration(-1).isPositive()) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().isPositive()) ;

    }

}

TEST (Library_Physics_Time_Duration, IsStrictlyPositive)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_TRUE(Duration(+1).isStrictlyPositive()) ;
        
    }

    {

        EXPECT_FALSE(Duration(0).isStrictlyPositive()) ;
        EXPECT_FALSE(Duration(-1).isStrictlyPositive()) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().isStrictlyPositive()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetNanoseconds)
{

    using library::physics::time::Duration ;

    {

        EXPECT_EQ(0, Duration(0).getNanoseconds()) ;
        EXPECT_EQ(1, Duration(1).getNanoseconds()) ;
        EXPECT_EQ(10, Duration(10).getNanoseconds()) ;
        EXPECT_EQ(100, Duration(100).getNanoseconds()) ;
        EXPECT_EQ(999, Duration(999).getNanoseconds()) ;
        
        EXPECT_EQ(0, Duration(1000).getNanoseconds()) ;
        EXPECT_EQ(1, Duration(1001).getNanoseconds()) ;

    }

    {

        EXPECT_EQ(1, Duration(-1).getNanoseconds()) ;
        EXPECT_EQ(10, Duration(-10).getNanoseconds()) ;
        EXPECT_EQ(100, Duration(-100).getNanoseconds()) ;
        EXPECT_EQ(999, Duration(-999).getNanoseconds()) ;
        
        EXPECT_EQ(0, Duration(-1000).getNanoseconds()) ;
        EXPECT_EQ(1, Duration(-1001).getNanoseconds()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getNanoseconds()) ;
            EXPECT_GE(999, duration.getNanoseconds()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getNanoseconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetMicroseconds)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(1).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(10).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(100).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(999).getMicroseconds()) ;
        
        EXPECT_EQ(1, Duration(1000).getMicroseconds()) ;
        EXPECT_EQ(1, Duration(1001).getMicroseconds()) ;
        EXPECT_EQ(2, Duration(2001).getMicroseconds()) ;

        EXPECT_EQ(0, Duration(1000000).getMicroseconds()) ;
        EXPECT_EQ(1, Duration(1001000).getMicroseconds()) ;
        EXPECT_EQ(2, Duration(1002000).getMicroseconds()) ;

    }

    {

        EXPECT_EQ(0, Duration(-1).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(-10).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(-100).getMicroseconds()) ;
        EXPECT_EQ(0, Duration(-999).getMicroseconds()) ;
        
        EXPECT_EQ(1, Duration(-1000).getMicroseconds()) ;
        EXPECT_EQ(1, Duration(-1001).getMicroseconds()) ;
        EXPECT_EQ(2, Duration(-2001).getMicroseconds()) ;

        EXPECT_EQ(0, Duration(-1000000).getMicroseconds()) ;
        EXPECT_EQ(1, Duration(-1001000).getMicroseconds()) ;
        EXPECT_EQ(2, Duration(-1002000).getMicroseconds()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getMicroseconds()) ;
            EXPECT_GE(999, duration.getMicroseconds()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getMicroseconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetMilliseconds)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(1).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(10).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(100).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(999).getMilliseconds()) ;
        
        EXPECT_EQ(0, Duration(1000).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(1001).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(1002).getMilliseconds()) ;

        EXPECT_EQ(1, Duration(1000000).getMilliseconds()) ;
        EXPECT_EQ(1, Duration(1001000).getMilliseconds()) ;
        EXPECT_EQ(1, Duration(1002000).getMilliseconds()) ;

        EXPECT_EQ(2, Duration(2000000).getMilliseconds()) ;
        EXPECT_EQ(2, Duration(2001000).getMilliseconds()) ;
        EXPECT_EQ(2, Duration(2002000).getMilliseconds()) ;

    }

    {

        EXPECT_EQ(0, Duration(-1).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(-10).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(-100).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(-999).getMilliseconds()) ;
        
        EXPECT_EQ(0, Duration(-1000).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(-1001).getMilliseconds()) ;
        EXPECT_EQ(0, Duration(-1002).getMilliseconds()) ;

        EXPECT_EQ(1, Duration(-1000000).getMilliseconds()) ;
        EXPECT_EQ(1, Duration(-1001000).getMilliseconds()) ;
        EXPECT_EQ(1, Duration(-1002000).getMilliseconds()) ;

        EXPECT_EQ(2, Duration(-2000000).getMilliseconds()) ;
        EXPECT_EQ(2, Duration(-2001000).getMilliseconds()) ;
        EXPECT_EQ(2, Duration(-2002000).getMilliseconds()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getMilliseconds()) ;
            EXPECT_GE(999, duration.getMilliseconds()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getMilliseconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetSeconds)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getSeconds()) ;
        EXPECT_EQ(0, Duration(1).getSeconds()) ;
        EXPECT_EQ(0, Duration(10).getSeconds()) ;
        EXPECT_EQ(0, Duration(100).getSeconds()) ;
        EXPECT_EQ(0, Duration(999).getSeconds()) ;
        
        EXPECT_EQ(0, Duration(1000).getSeconds()) ;
        EXPECT_EQ(0, Duration(1001).getSeconds()) ;
        EXPECT_EQ(0, Duration(1002).getSeconds()) ;

        EXPECT_EQ(0, Duration(1000000).getSeconds()) ;
        EXPECT_EQ(0, Duration(1001000).getSeconds()) ;
        EXPECT_EQ(0, Duration(1002000).getSeconds()) ;

        EXPECT_EQ(0, Duration(2000000).getSeconds()) ;
        EXPECT_EQ(0, Duration(2001000).getSeconds()) ;
        EXPECT_EQ(0, Duration(2002000).getSeconds()) ;

        EXPECT_EQ(1, Duration(1000000000).getSeconds()) ;
        EXPECT_EQ(1, Duration(1001000000).getSeconds()) ;
        EXPECT_EQ(1, Duration(1002000000).getSeconds()) ;

        EXPECT_EQ(2, Duration(2000000000).getSeconds()) ;
        EXPECT_EQ(2, Duration(2001000000).getSeconds()) ;
        EXPECT_EQ(2, Duration(2002000000).getSeconds()) ;

    }

    {

        EXPECT_EQ(0, Duration(-1).getSeconds()) ;
        EXPECT_EQ(0, Duration(-10).getSeconds()) ;
        EXPECT_EQ(0, Duration(-100).getSeconds()) ;
        EXPECT_EQ(0, Duration(-999).getSeconds()) ;
        
        EXPECT_EQ(0, Duration(-1000).getSeconds()) ;
        EXPECT_EQ(0, Duration(-1001).getSeconds()) ;
        EXPECT_EQ(0, Duration(-1002).getSeconds()) ;

        EXPECT_EQ(0, Duration(-1000000).getSeconds()) ;
        EXPECT_EQ(0, Duration(-1001000).getSeconds()) ;
        EXPECT_EQ(0, Duration(-1002000).getSeconds()) ;

        EXPECT_EQ(0, Duration(-2000000).getSeconds()) ;
        EXPECT_EQ(0, Duration(-2001000).getSeconds()) ;
        EXPECT_EQ(0, Duration(-2002000).getSeconds()) ;

        EXPECT_EQ(1, Duration(-1000000000).getSeconds()) ;
        EXPECT_EQ(1, Duration(-1001000000).getSeconds()) ;
        EXPECT_EQ(1, Duration(-1002000000).getSeconds()) ;

        EXPECT_EQ(2, Duration(-2000000000).getSeconds()) ;
        EXPECT_EQ(2, Duration(-2001000000).getSeconds()) ;
        EXPECT_EQ(2, Duration(-2002000000).getSeconds()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getSeconds()) ;
            EXPECT_GE(59, duration.getSeconds()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getSeconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetMinutes)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getMinutes()) ;
        EXPECT_EQ(0, Duration(1).getMinutes()) ;
        
        EXPECT_EQ(1, (Duration::Minutes(1.0) + Duration::Seconds(30.0)).getMinutes()) ;
        EXPECT_EQ(2, (Duration::Minutes(1.0) + Duration::Seconds(60.0)).getMinutes()) ;
        EXPECT_EQ(2, (Duration::Minutes(1.0) + Duration::Seconds(61.0)).getMinutes()) ;

        EXPECT_EQ(1, (Duration::Minutes(1.0) + Duration::Hours(1.0)).getMinutes()) ;
        EXPECT_EQ(1, (Duration::Minutes(1.0) + Duration::Hours(2.0)).getMinutes()) ;

    }

    {
        
        EXPECT_EQ(1, (-(Duration::Minutes(1.0) + Duration::Seconds(30.0))).getMinutes()) ;
        EXPECT_EQ(2, (-(Duration::Minutes(1.0) + Duration::Seconds(60.0))).getMinutes()) ;
        EXPECT_EQ(2, (-(Duration::Minutes(1.0) + Duration::Seconds(61.0))).getMinutes()) ;

        EXPECT_EQ(1, (-(Duration::Minutes(1.0) + Duration::Hours(1.0))).getMinutes()) ;
        EXPECT_EQ(1, (-(Duration::Minutes(1.0) + Duration::Hours(2.0))).getMinutes()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getMinutes()) ;
            EXPECT_GE(59, duration.getMinutes()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getMinutes()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetHours)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getHours()) ;
        EXPECT_EQ(0, Duration(1).getHours()) ;
        
        EXPECT_EQ(1, (Duration::Hours(1.0) + Duration::Minutes(30.0)).getHours()) ;
        EXPECT_EQ(2, (Duration::Hours(1.0) + Duration::Minutes(60.0)).getHours()) ;
        EXPECT_EQ(2, (Duration::Hours(1.0) + Duration::Minutes(61.0)).getHours()) ;

        EXPECT_EQ(1, (Duration::Hours(1.0) + Duration::Days(1.0)).getHours()) ;
        EXPECT_EQ(1, (Duration::Hours(1.0) + Duration::Days(2.0)).getHours()) ;

    }

    {

        EXPECT_EQ(1, (-(Duration::Hours(1.0) + Duration::Minutes(30.0))).getHours()) ;
        EXPECT_EQ(2, (-(Duration::Hours(1.0) + Duration::Minutes(60.0))).getHours()) ;
        EXPECT_EQ(2, (-(Duration::Hours(1.0) + Duration::Minutes(61.0))).getHours()) ;

        EXPECT_EQ(1, (-(Duration::Hours(1.0) + Duration::Days(1.0))).getHours()) ;
        EXPECT_EQ(1, (-(Duration::Hours(1.0) + Duration::Days(2.0))).getHours()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getHours()) ;
            EXPECT_GE(23, duration.getHours()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getHours()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetDays)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getDays()) ;
        EXPECT_EQ(0, Duration(1).getDays()) ;
        
        EXPECT_EQ(1, (Duration::Days(1.0) + Duration::Hours(12.0)).getDays()) ;
        EXPECT_EQ(2, (Duration::Days(1.0) + Duration::Hours(24.0)).getDays()) ;
        EXPECT_EQ(2, (Duration::Days(1.0) + Duration::Hours(25.0)).getDays()) ;

        EXPECT_EQ(8, (Duration::Days(1.0) + Duration::Weeks(1.0)).getDays()) ;
        EXPECT_EQ(15, (Duration::Days(1.0) + Duration::Weeks(2.0)).getDays()) ;

    }

    {

        EXPECT_EQ(1, (-(Duration::Days(1.0) + Duration::Hours(12.0))).getDays()) ;
        EXPECT_EQ(2, (-(Duration::Days(1.0) + Duration::Hours(24.0))).getDays()) ;
        EXPECT_EQ(2, (-(Duration::Days(1.0) + Duration::Hours(25.0))).getDays()) ;

        EXPECT_EQ(8, (-(Duration::Days(1.0) + Duration::Weeks(1.0))).getDays()) ;
        EXPECT_EQ(15, (-(Duration::Days(1.0) + Duration::Weeks(2.0))).getDays()) ;

    }

    {

        for (auto idx = 0; idx < 100000; ++idx)
        {

            const Duration duration = Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getDays()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getDays()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetWeeks)
{

    using library::physics::time::Duration ;

    { 

        EXPECT_EQ(0, Duration(0).getWeeks()) ;
        EXPECT_EQ(0, Duration(1).getWeeks()) ;
        
        EXPECT_EQ(1, (Duration::Weeks(1.0) + Duration::Days(4.5)).getWeeks()) ;
        EXPECT_EQ(2, (Duration::Weeks(1.0) + Duration::Days(7.0)).getWeeks()) ;
        EXPECT_EQ(2, (Duration::Weeks(1.0) + Duration::Days(8.0)).getWeeks()) ;

        EXPECT_EQ(2, (Duration::Weeks(1.0) + Duration::Weeks(1.0)).getWeeks()) ;
        EXPECT_EQ(3, (Duration::Weeks(1.0) + Duration::Weeks(2.0)).getWeeks()) ;

    }

    {

        EXPECT_EQ(1, (-(Duration::Weeks(1.0) + Duration::Days(4.5))).getWeeks()) ;
        EXPECT_EQ(2, (-(Duration::Weeks(1.0) + Duration::Days(7.0))).getWeeks()) ;
        EXPECT_EQ(2, (-(Duration::Weeks(1.0) + Duration::Days(8.0))).getWeeks()) ;

        EXPECT_EQ(2, (-(Duration::Weeks(1.0) + Duration::Weeks(1.0))).getWeeks()) ;
        EXPECT_EQ(3, (-(Duration::Weeks(1.0) + Duration::Weeks(2.0))).getWeeks()) ;

    }

    {

        for (auto idx = 0; idx < 1000; ++idx)
        {

            const Duration duration = Duration::Weeks(idx)
                                    + Duration::Days(idx)
                                    + Duration::Hours(idx)
                                    + Duration::Minutes(idx)
                                    + Duration::Seconds(idx)
                                    + Duration::Milliseconds(idx)
                                    + Duration::Microseconds(idx)
                                    + Duration::Nanoseconds(idx) ;
            
            EXPECT_LE(0, duration.getWeeks()) ;
        
        }
        
    }

    {

        EXPECT_ANY_THROW(Duration::Undefined().getWeeks()) ;

    }

}


TEST (Library_Physics_Time_Duration, InNanoseconds)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inNanoseconds(), 1e-15) ;

        EXPECT_NEAR(1.0, Duration(1).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR(1000.0, Duration(1000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR(1000000.0, Duration(1000000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR(1000000000.0, Duration(1000000000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 1000000000.0), Duration(Int64(60) * 1000000000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 60.0 * 1000000000.0), Duration(Int64(60) * 60 * 1000000000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR((24.0 * 60.0 * 60.0 * 1000000000.0), Duration(Int64(24) * 60 * 60 * 1000000000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR((7.0 * 24.0 * 60.0 * 60.0 * 1000000000.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inNanoseconds(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0 * 1000000000.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inNanoseconds(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inNanoseconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, InMicroseconds)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inMicroseconds(), 1e-15) ;

        EXPECT_NEAR(0.001, Duration(1).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(1000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR(1000.0, Duration(1000000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR(1000000.0, Duration(1000000000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 1000000.0), Duration(Int64(60) * 1000000000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 60.0 * 1000000.0), Duration(Int64(60) * 60 * 1000000000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR((24.0 * 60.0 * 60.0 * 1000000.0), Duration(Int64(24) * 60 * 60 * 1000000000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR((7.0 * 24.0 * 60.0 * 60.0 * 1000000.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inMicroseconds(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0 * 1000000.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inMicroseconds(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inMicroseconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, InMilliseconds)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inMilliseconds(), 1e-15) ;

        EXPECT_NEAR(0.000001, Duration(1).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR(0.001, Duration(1000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(1000000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR(1000.0, Duration(1000000000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 1000.0), Duration(Int64(60) * 1000000000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 60.0 * 1000.0), Duration(Int64(60) * 60 * 1000000000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR((24.0 * 60.0 * 60.0 * 1000.0), Duration(Int64(24) * 60 * 60 * 1000000000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR((7.0 * 24.0 * 60.0 * 60.0 * 1000.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inMilliseconds(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0 * 1000.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inMilliseconds(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inMilliseconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, InSeconds)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inSeconds(), 1e-15) ;

        EXPECT_NEAR(0.000000001, Duration(1).inSeconds(), 1e-15) ;
        EXPECT_NEAR(0.000001, Duration(1000).inSeconds(), 1e-15) ;
        EXPECT_NEAR(0.001, Duration(1000000).inSeconds(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(1000000000).inSeconds(), 1e-15) ;
        EXPECT_NEAR(60.0, Duration(Int64(60) * 1000000000).inSeconds(), 1e-15) ;
        EXPECT_NEAR((60.0 * 60.0), Duration(Int64(60) * 60 * 1000000000).inSeconds(), 1e-15) ;
        EXPECT_NEAR((24.0 * 60.0 * 60.0), Duration(Int64(24) * 60 * 60 * 1000000000).inSeconds(), 1e-15) ;
        EXPECT_NEAR((7.0 * 24.0 * 60.0 * 60.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inSeconds(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inSeconds(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inSeconds()) ;

    }

}

TEST (Library_Physics_Time_Duration, InMinutes)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inMinutes(), 1e-15) ;

        EXPECT_NEAR((0.000000001 / 60.0), Duration(1).inMinutes(), 1e-15) ;
        EXPECT_NEAR((0.000001 / 60.0), Duration(1000).inMinutes(), 1e-15) ;
        EXPECT_NEAR((0.001 / 60.0), Duration(1000000).inMinutes(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0), Duration(1000000000).inMinutes(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(Int64(60) * 1000000000).inMinutes(), 1e-15) ;
        EXPECT_NEAR(60.0, Duration(Int64(60) * 60 * 1000000000).inMinutes(), 1e-15) ;
        EXPECT_NEAR((24.0 * 60.0), Duration(Int64(24) * 60 * 60 * 1000000000).inMinutes(), 1e-15) ;
        EXPECT_NEAR((7.0 * 24.0 * 60.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inMinutes(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inMinutes(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inMinutes()) ;

    }

}

TEST (Library_Physics_Time_Duration, InHours)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inHours(), 1e-15) ;

        EXPECT_NEAR((0.000000001 / 60.0 / 60.0), Duration(1).inHours(), 1e-15) ;
        EXPECT_NEAR((0.000001 / 60.0 / 60.0), Duration(1000).inHours(), 1e-15) ;
        EXPECT_NEAR((0.001 / 60.0 / 60.0), Duration(1000000).inHours(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0 / 60.0), Duration(1000000000).inHours(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0), Duration(Int64(60) * 1000000000).inHours(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(Int64(60) * 60 * 1000000000).inHours(), 1e-15) ;
        EXPECT_NEAR(24.0, Duration(Int64(24) * 60 * 60 * 1000000000).inHours(), 1e-15) ;
        EXPECT_NEAR((7.0 * 24.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inHours(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inHours(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inHours()) ;

    }

}

TEST (Library_Physics_Time_Duration, InDays)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inDays(), 1e-15) ;

        EXPECT_NEAR((0.000000001 / 60.0 / 60.0 / 24.0), Duration(1).inDays(), 1e-15) ;
        EXPECT_NEAR((0.000001 / 60.0 / 60.0 / 24.0), Duration(1000).inDays(), 1e-15) ;
        EXPECT_NEAR((0.001 / 60.0 / 60.0 / 24.0), Duration(1000000).inDays(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0 / 60.0 / 24.0), Duration(1000000000).inDays(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0 / 24.0), Duration(Int64(60) * 1000000000).inDays(), 1e-15) ;
        EXPECT_NEAR((1.0 / 24.0), Duration(Int64(60) * 60 * 1000000000).inDays(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(Int64(24) * 60 * 60 * 1000000000).inDays(), 1e-15) ;
        EXPECT_NEAR((7.0), Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inDays(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inDays(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inDays()) ;

    }

}

TEST (Library_Physics_Time_Duration, InWeeks)
{
    
    using library::core::types::Int64 ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR(0.0, Duration(0).inWeeks(), 1e-15) ;

        EXPECT_NEAR((0.000000001 / 60.0 / 60.0 / 24.0 / 7.0), Duration(1).inWeeks(), 1e-15) ;
        EXPECT_NEAR((0.000001 / 60.0 / 60.0 / 24.0 / 7.0), Duration(1000).inWeeks(), 1e-15) ;
        EXPECT_NEAR((0.001 / 60.0 / 60.0 / 24.0 / 7.0), Duration(1000000).inWeeks(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0 / 60.0 / 24.0 / 7.0), Duration(1000000000).inWeeks(), 1e-15) ;
        EXPECT_NEAR((1.0 / 60.0 / 24.0 / 7.0), Duration(Int64(60) * 1000000000).inWeeks(), 1e-15) ;
        EXPECT_NEAR((1.0 / 24.0 / 7.0), Duration(Int64(60) * 60 * 1000000000).inWeeks(), 1e-15) ;
        EXPECT_NEAR((1.0 / 7.0), Duration(Int64(24) * 60 * 60 * 1000000000).inWeeks(), 1e-15) ;
        EXPECT_NEAR(1.0, Duration(Int64(7) * 24 * 60 * 60 * 1000000000).inWeeks(), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 / 7.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).inWeeks(), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().inWeeks()) ;

    }

}

TEST (Library_Physics_Time_Duration, In)
{
    
    using library::core::types::Int64 ;
    using library::physics::units::Time ;
    using library::physics::time::Duration ;

    {

        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0 * 1000000000.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Nanosecond), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0 * 1000000.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Microsecond), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0 * 1000.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Millisecond), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0 * 60.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Second), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0 * 60.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Minute), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 * 24.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Hour), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Day), 1e-15) ;
        EXPECT_NEAR((100.0 * 365.0 / 7.0), Duration(Int64(100) * 365 * 24 * 60 * 60 * 1000000000).in(Time::Unit::Week), 1e-15) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().in(Time::Unit::Nanosecond)) ;

    }

}

TEST (Library_Physics_Time_Duration, GetAbsolute)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration(0).getAbsolute()) ;
        EXPECT_EQ(Duration(+1), Duration(+1).getAbsolute()) ;
        EXPECT_EQ(Duration(+1), Duration(-1).getAbsolute()) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Undefined().getAbsolute()) ;

    }

}

TEST (Library_Physics_Time_Duration, GetString)
{
    
    using library::physics::time::Duration ;

    {

        FAIL() ;

    }

}

TEST (Library_Physics_Time_Duration, Undefined)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Undefined()) ;
        EXPECT_FALSE(Duration::Undefined().isDefined()) ;

    }

}

TEST (Library_Physics_Time_Duration, Zero)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Zero()) ;
        EXPECT_TRUE(Duration::Zero().isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Zero()) ;

    }

}

TEST (Library_Physics_Time_Duration, Nanoseconds)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Nanoseconds(0)) ;
        EXPECT_TRUE(Duration::Nanoseconds(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Nanoseconds(0)) ;
        EXPECT_EQ(Duration(123), Duration::Nanoseconds(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Microseconds)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Microseconds(0)) ;
        EXPECT_TRUE(Duration::Microseconds(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Microseconds(0)) ;
        EXPECT_EQ(Duration(123 * 1e3), Duration::Microseconds(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Milliseconds)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Milliseconds(0)) ;
        EXPECT_TRUE(Duration::Milliseconds(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Milliseconds(0)) ;
        EXPECT_EQ(Duration(123 * 1e6), Duration::Milliseconds(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Seconds)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Seconds(0)) ;
        EXPECT_TRUE(Duration::Seconds(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Seconds(0)) ;
        EXPECT_EQ(Duration(123 * 1e9), Duration::Seconds(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Minutes)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Minutes(0)) ;
        EXPECT_TRUE(Duration::Minutes(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Minutes(0)) ;
        EXPECT_EQ(Duration(123 * 60 * 1e9), Duration::Minutes(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Hours)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Hours(0)) ;
        EXPECT_TRUE(Duration::Hours(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Hours(0)) ;
        EXPECT_EQ(Duration(123 * 60 * 60 * 1e9), Duration::Hours(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Days)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Days(0)) ;
        EXPECT_TRUE(Duration::Days(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Days(0)) ;
        EXPECT_EQ(Duration(123 * 24 * 60 * 60 * 1e9), Duration::Days(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Weeks)
{
    
    using library::physics::time::Duration ;

    {

        EXPECT_NO_THROW(Duration::Weeks(0)) ;
        EXPECT_TRUE(Duration::Weeks(0).isDefined()) ;

        EXPECT_EQ(Duration(0), Duration::Weeks(0)) ;
        EXPECT_EQ(Duration(123 * 7 * 24 * 60 * 60 * 1e9), Duration::Weeks(123)) ;

    }

}

TEST (Library_Physics_Time_Duration, Between)
{
    
    using library::physics::time::Scale ;
    using library::physics::time::Instant ;
    using library::physics::time::Duration ;

    {

        EXPECT_EQ(Duration(0), Duration::Between(Instant(0, true, Scale::UTC), Instant(0, true, Scale::UTC))) ;

        EXPECT_EQ(Duration(0), Duration::Between(Instant(1, true, Scale::UTC), Instant(1, true, Scale::UTC))) ;
        EXPECT_EQ(Duration(0), Duration::Between(Instant(1, false, Scale::UTC), Instant(1, false, Scale::UTC))) ;

        EXPECT_EQ(Duration(0), Duration::Between(Instant(1, true, Scale::TT), Instant(1, true, Scale::TT))) ;

    }

    {

        EXPECT_EQ(Duration(+1), Duration::Between(Instant(1, true, Scale::UTC), Instant(2, true, Scale::UTC))) ;
        EXPECT_EQ(Duration(+1), Duration::Between(Instant(2, true, Scale::UTC), Instant(3, true, Scale::UTC))) ;
        EXPECT_EQ(Duration(+2), Duration::Between(Instant(1, false, Scale::UTC), Instant(1, true, Scale::UTC))) ;

        EXPECT_EQ(Duration(-1), Duration::Between(Instant(2, true, Scale::UTC), Instant(1, true, Scale::UTC))) ;
        EXPECT_EQ(Duration(-1), Duration::Between(Instant(3, true, Scale::UTC), Instant(2, true, Scale::UTC))) ;
        EXPECT_EQ(Duration(-2), Duration::Between(Instant(1, true, Scale::UTC), Instant(1, false, Scale::UTC))) ;

    }
    
    {

        EXPECT_NE(Duration(0), Duration::Between(Instant(0, true, Scale::UTC), Instant(0, true, Scale::TAI))) ;
        EXPECT_NE(Duration(0), Duration::Between(Instant(0, true, Scale::UTC), Instant(0, true, Scale::TT))) ;
        EXPECT_NE(Duration(0), Duration::Between(Instant(0, true, Scale::TAI), Instant(0, true, Scale::TT))) ;

    }

    {
        
        EXPECT_ANY_THROW(Duration::Between(Instant::Undefined(), Instant::Undefined())) ;
        EXPECT_ANY_THROW(Duration::Between(Instant(0, true, Scale::UTC), Instant::Undefined())) ;
        EXPECT_ANY_THROW(Duration::Between(Instant::Undefined(), Instant(0, true, Scale::UTC))) ;

    }

}

// TEST (Library_Physics_Time_Duration, Parse)
// {
    
//     using library::physics::time::Duration ;

//     {

//         FAIL() ;

//     }

// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////