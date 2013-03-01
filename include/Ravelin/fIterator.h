/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

#ifndef _FITERATOR_H
#define _FITERATOR_H

#include <stdexcept>

namespace Ravelin {

#define REAL float
#define CONST_ITERATOR fIterator_const
#define ITERATOR fIterator
#define MATRIXN MatrixNf
#define VECTORN VectorNf
#define VECTOR3 Vector3f
#define VECTOR2 Vector2f
#define MATRIX3 Matrix3f
#define MATRIX2 Matrix2f
#define SHAREDVECTORN SharedVectorNf
#define SHAREDMATRIXN SharedMatrixNf

#include "rIterator.h"

#undef REAL
#undef ITERATOR 
#undef MATRIXN
#undef VECTORN
#undef VECTOR3
#undef VECTOR2
#undef MATRIX3
#undef MATRIX2
#undef SHAREDVECTORN
#undef SHAREDMATRIXN

} // end namespace

#endif
