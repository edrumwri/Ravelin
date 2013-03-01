/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

#ifndef MATRIX3
#error This class is not to be included by the user directly. Use Matrix3d.h or Matrix3f.h instead.
#endif

class QUAT;
class AANGLE;

/// A 3x3 matrix that may be used for orientation, inertia tensors, etc.
class MATRIX3
{
  public:
    MATRIX3() { }
    MATRIX3(const MATRIX3& source) { operator=(source); }
    MATRIX3(const REAL* array);
    MATRIX3(REAL, REAL, REAL, REAL, REAL, REAL, REAL, REAL, REAL);
    MATRIX3& operator=(const QUAT& q);
    MATRIX3& operator=(const AANGLE& a);
    REAL norm_inf() const;
    unsigned rows() const { return 3; }
    unsigned columns() const { return 3; }
    bool is_symmetric(REAL tolerance) const;
    bool orthonormalize();
    bool is_orthonormal() const;    
    REAL det() const;
    void inverse();
    REAL xx() const { return _data[0]; }
    REAL& xx() { return _data[0]; }
    REAL xy() const { return _data[3]; }
    REAL& xy() { return _data[3]; }
    REAL xz() const { return _data[6]; }
    REAL& xz() { return _data[6]; }
    REAL yx() const { return _data[1]; }
    REAL& yx() { return _data[1]; }
    REAL yy() const { return _data[4]; }
    REAL& yy() { return _data[4]; }
    REAL yz() const { return _data[7]; }
    REAL& yz() { return _data[7]; }
    REAL zx() const { return _data[2]; }
    REAL& zx() { return _data[2]; }
    REAL zy() const { return _data[5]; }
    REAL& zy() { return _data[5]; }
    REAL zz() const { return _data[8]; }
    REAL& zz() { return _data[8]; }
    static VECTOR3 calc_differential(const MATRIX3& R1, const MATRIX3& R2);
    static MATRIX3 inverse(const MATRIX3& m);
    void set_rot_X(REAL angle);
    static MATRIX3 rot_X(REAL angle);
    void set_rot_Y(REAL angle);
    static MATRIX3 rot_Y(REAL angle);
    void set_rot_Z(REAL angle);
    static MATRIX3 rot_Z(REAL angle);
    static MATRIX3 skew_symmetric(REAL a, REAL b, REAL c);
    static MATRIX3 skew_symmetric(const VECTOR3& v);
    static VECTOR3 inverse_skew_symmetric(const MATRIX3& R);
    static MATRIX3 transpose(const MATRIX3& m);
    void transpose();
    static bool valid_rotation(const MATRIX3& R);
    static bool valid_rotation_scale(const MATRIX3& R);
    static MATRIX3 identity() { MATRIX3 m; m.set_identity(); return m; }
    static MATRIX3 zero() { MATRIX3 m; m.set_zero(); return m; }
    void set_identity();
    void set_zero();
    VECTOR3 transpose_mult(const VECTOR3& v) const;
    VECTOR3 mult(const VECTOR3& v) const;
    MATRIX3 mult(const MATRIX3& m) const;
    MATRIX3 transpose_mult(const MATRIX3& m) const;
    MATRIX3 mult_transpose(const MATRIX3& m) const;
    MATRIX3 transpose_mult_transpose(const MATRIX3& m) const;
    MATRIX3& operator=(const MATRIX3& source);
    MATRIX3& operator+=(const MATRIX3& m);
    MATRIX3& operator-=(const MATRIX3& m);
    MATRIX3& operator*=(REAL scalar);
    MATRIX3& operator/=(REAL scalar) { return operator*=(1.0/scalar); }
    MATRIX3 operator+(const MATRIX3& m) const { MATRIX3 n = *this; n += m; return n; }
    MATRIX3 operator-(const MATRIX3& m) const { MATRIX3 n = *this; n -= m; return n; }
    MATRIX3 operator*(REAL scalar) const { MATRIX3 m = *this; m *= scalar; return m; }
    MATRIX3 operator/(REAL scalar) const { return operator*(1.0/scalar); }
    MATRIX3 operator-() const; 
    unsigned leading_dim() const { return 3; }
    unsigned inc() const { return 1; }
    VECTOR3 get_column(unsigned i) const;
    VECTOR3 get_row(unsigned i) const;
    REAL& operator()(unsigned i, unsigned j);
    REAL operator()(unsigned i, unsigned j) const;
    MATRIX3& resize(unsigned rows, unsigned columns, bool preserve = false);
    const REAL* data(unsigned i) const;
    REAL* data(unsigned i);
    ITERATOR begin();
    ITERATOR end();
    CONST_ITERATOR begin() const;
    CONST_ITERATOR end() const;

    /// Gets constant pointer to the beginning of the matrix array
    const REAL* data() const { return _data; }

    /// Gets pointer to the beginning of the matrix array
    REAL* data() { return _data; }

    #define MATRIXX MATRIX3
    #include "MatrixCommon.inl"
    #undef MATRIXX    

  private:
    bool orthonormalize(VECTOR3& a, VECTOR3& b, VECTOR3& c);
    REAL _data[9];
}; // end class

std::ostream& operator<<(std::ostream& out, const MATRIX3& m);
