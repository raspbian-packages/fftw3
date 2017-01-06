/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include "ifftw.h"

#if HAVE_NEON

#ifdef __linux__

#ifdef __aarch64__

/* HWCAP_ASIMD is defined in <asm/hwcap.h> but not included by <sys/auxv.h>.
   Since all current AArch64 implementations have NEON/ASIMD it is probably
   better to return 1 than include a header file which is not intended for
   use by user programs. */

int X(have_simd_neon)(void)
{
  return 1;
}

#else

#include <sys/auxv.h>

int X(have_simd_neon)(void)
{
  static int cached = 2;
  int ret;

  /* This should be thread-safe in all reasonable circumstances. */
  ret = cached;
  if (ret == 2)
    {
      ret = !!(getauxval(AT_HWCAP) & HWCAP_ARM_NEON);
      cached = ret;
    }
  return ret;
}

#endif

#else

#error Please implement a run-time test for NEON/ASIMD for your platform.

#endif

#endif
