/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

#ifndef TRANSFORM2
#error This class is not to be included by the user directly. Use Transform2d.h or Transform2h.h instead. 
#endif

class POSE2;

/// A transformation between 2D rigid body poses 
class TRANSFORM2
{
  public:
    TRANSFORM2();
    TRANSFORM2(const TRANSFORM2& source) { operator=(source); }
    TRANSFORM2(const ROT2& r, const ORIGIN2& x);
    TRANSFORM2(const ORIGIN2& x);
    TRANSFORM2(const ROT2& r);
    static TRANSFORM2 identity() { TRANSFORM2 T; T.set_identity(); return T; }
    static bool rel_equal(const TRANSFORM2& p1, const TRANSFORM2& p2, REAL tol=EPS);
    static REAL wrap(REAL theta);
    POSE2 transform(const POSE2& p) const;
    POSE2 inverse_transform(const POSE2& p) const;
    POINT2 transform(const POINT2& v) const;
    VECTOR2 transform(const VECTOR2& v) const;
    POINT2 inverse_transform(const POINT2& v) const;
    VECTOR2 inverse_transform(const VECTOR2& v) const;
    TRANSFORM2& set_identity();
    TRANSFORM2& invert();
    TRANSFORM2 inverse() const { return invert(*this); }
    static TRANSFORM2 invert(const TRANSFORM2& m);
    TRANSFORM2& set(const ROT2& r, const ORIGIN2& v);
    TRANSFORM2& set(const ROT2& r);
    TRANSFORM2& operator=(const TRANSFORM2& source);
    TRANSFORM2 operator*(const TRANSFORM2& m) const;

    /// the orientation of the pose frame
    ROT2 r;

    /// the position of the pose frame
    ORIGIN2 x;

    /// the source pose
    boost::shared_ptr<const POSE2> source; 

    /// the target pose
    boost::shared_ptr<const POSE2> target; 

}; // end class

std::ostream& operator<<(std::ostream& out, const TRANSFORM2& m);

