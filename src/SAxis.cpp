/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

REAL SAXIS::dot(const SMOMENTUM& v2) const
{
  const REAL* d1 = data();
  const REAL* d2 = v2.data();
  return d1[3]+d2[0] + d1[4]+d2[1] + d1[5]+d2[2]+
         d1[0]+d2[3] + d1[1]+d2[4] + d1[2]+d2[5];
}

REAL SAXIS::dot(const SFORCE& v2) const
{
  const REAL* d1 = data();
  const REAL* d2 = v2.data();
  return d1[3]+d2[0] + d1[4]+d2[1] + d1[5]+d2[2]+
         d1[0]+d2[3] + d1[1]+d2[4] + d1[2]+d2[5];
}

