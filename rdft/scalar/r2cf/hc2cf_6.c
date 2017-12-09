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

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Oct 29 08:18:12 EDT 2017 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4 -pipeline-latency 4 -n 6 -dit -name hc2cf_6 -include rdft/scalar/hc2cf.h */

/*
 * This function contains 46 FP additions, 32 FP multiplications,
 * (or, 24 additions, 10 multiplications, 22 fused multiply/add),
 * 31 stack variables, 2 constants, and 24 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cf_6(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 10); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 10, MAKE_VOLATILE_STRIDE(24, rs)) {
	       E T1, TX, T7, TW, Tl, TS, TB, TJ, Ty, TR, TC, TO;
	       T1 = Rp[0];
	       TX = Rm[0];
	       {
		    E T3, T6, T4, TV, T2, T5;
		    T3 = Ip[WS(rs, 1)];
		    T6 = Im[WS(rs, 1)];
		    T2 = W[4];
		    T4 = T2 * T3;
		    TV = T2 * T6;
		    T5 = W[5];
		    T7 = FMA(T5, T6, T4);
		    TW = FNMS(T5, T3, TV);
	       }
	       {
		    E Ta, Td, Tb, TF, Tg, Tj, Th, TH, T9, Tf;
		    Ta = Rp[WS(rs, 1)];
		    Td = Rm[WS(rs, 1)];
		    T9 = W[2];
		    Tb = T9 * Ta;
		    TF = T9 * Td;
		    Tg = Ip[WS(rs, 2)];
		    Tj = Im[WS(rs, 2)];
		    Tf = W[8];
		    Th = Tf * Tg;
		    TH = Tf * Tj;
		    {
			 E Te, TG, Tk, TI, Tc, Ti;
			 Tc = W[3];
			 Te = FMA(Tc, Td, Tb);
			 TG = FNMS(Tc, Ta, TF);
			 Ti = W[9];
			 Tk = FMA(Ti, Tj, Th);
			 TI = FNMS(Ti, Tg, TH);
			 Tl = Te - Tk;
			 TS = TI - TG;
			 TB = Te + Tk;
			 TJ = TG + TI;
		    }
	       }
	       {
		    E Tn, Tq, To, TK, Tt, Tw, Tu, TM, Tm, Ts;
		    Tn = Rp[WS(rs, 2)];
		    Tq = Rm[WS(rs, 2)];
		    Tm = W[6];
		    To = Tm * Tn;
		    TK = Tm * Tq;
		    Tt = Ip[0];
		    Tw = Im[0];
		    Ts = W[0];
		    Tu = Ts * Tt;
		    TM = Ts * Tw;
		    {
			 E Tr, TL, Tx, TN, Tp, Tv;
			 Tp = W[7];
			 Tr = FMA(Tp, Tq, To);
			 TL = FNMS(Tp, Tn, TK);
			 Tv = W[1];
			 Tx = FMA(Tv, Tw, Tu);
			 TN = FNMS(Tv, Tt, TM);
			 Ty = Tr - Tx;
			 TR = TN - TL;
			 TC = Tr + Tx;
			 TO = TL + TN;
		    }
	       }
	       {
		    E TT, T8, Tz, TQ;
		    TT = TR - TS;
		    T8 = T1 - T7;
		    Tz = Tl + Ty;
		    TQ = FNMS(KP500000000, Tz, T8);
		    Rm[WS(rs, 2)] = T8 + Tz;
		    Rp[WS(rs, 1)] = FMA(KP866025403, TT, TQ);
		    Rm[0] = FNMS(KP866025403, TT, TQ);
	       }
	       {
		    E T14, T11, T12, T13;
		    T14 = Ty - Tl;
		    T11 = TS + TR;
		    T12 = TX - TW;
		    T13 = FMA(KP500000000, T11, T12);
		    Im[WS(rs, 2)] = T11 - T12;
		    Ip[WS(rs, 1)] = FMA(KP866025403, T14, T13);
		    Im[0] = FMS(KP866025403, T14, T13);
	       }
	       {
		    E TP, TA, TD, TE;
		    TP = TJ - TO;
		    TA = T1 + T7;
		    TD = TB + TC;
		    TE = FNMS(KP500000000, TD, TA);
		    Rp[0] = TA + TD;
		    Rm[WS(rs, 1)] = FMA(KP866025403, TP, TE);
		    Rp[WS(rs, 2)] = FNMS(KP866025403, TP, TE);
	       }
	       {
		    E T10, TU, TY, TZ;
		    T10 = TB - TC;
		    TU = TJ + TO;
		    TY = TW + TX;
		    TZ = FNMS(KP500000000, TU, TY);
		    Ip[0] = TU + TY;
		    Ip[WS(rs, 2)] = FMA(KP866025403, T10, TZ);
		    Im[WS(rs, 1)] = FMS(KP866025403, T10, TZ);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 6},
     {TW_NEXT, 1, 0}
};

static const hc2c_desc desc = { 6, "hc2cf_6", twinstr, &GENUS, {24, 10, 22, 0} };

void X(codelet_hc2cf_6) (planner *p) {
     X(khc2c_register) (p, hc2cf_6, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4 -pipeline-latency 4 -n 6 -dit -name hc2cf_6 -include rdft/scalar/hc2cf.h */

/*
 * This function contains 46 FP additions, 28 FP multiplications,
 * (or, 32 additions, 14 multiplications, 14 fused multiply/add),
 * 23 stack variables, 2 constants, and 24 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cf_6(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 10); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 10, MAKE_VOLATILE_STRIDE(24, rs)) {
	       E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
	       {
		    E T1, TN, T6, TM;
		    T1 = Rp[0];
		    TN = Rm[0];
		    {
			 E T3, T5, T2, T4;
			 T3 = Ip[WS(rs, 1)];
			 T5 = Im[WS(rs, 1)];
			 T2 = W[4];
			 T4 = W[5];
			 T6 = FMA(T2, T3, T4 * T5);
			 TM = FNMS(T4, T3, T2 * T5);
		    }
		    T7 = T1 - T6;
		    TS = TN - TM;
		    Tv = T1 + T6;
		    TO = TM + TN;
	       }
	       {
		    E Tn, TD, Ts, TE;
		    {
			 E Tk, Tm, Tj, Tl;
			 Tk = Rp[WS(rs, 2)];
			 Tm = Rm[WS(rs, 2)];
			 Tj = W[6];
			 Tl = W[7];
			 Tn = FMA(Tj, Tk, Tl * Tm);
			 TD = FNMS(Tl, Tk, Tj * Tm);
		    }
		    {
			 E Tp, Tr, To, Tq;
			 Tp = Ip[0];
			 Tr = Im[0];
			 To = W[0];
			 Tq = W[1];
			 Ts = FMA(To, Tp, Tq * Tr);
			 TE = FNMS(Tq, Tp, To * Tr);
		    }
		    Tt = Tn - Ts;
		    TJ = TE - TD;
		    Tx = Tn + Ts;
		    TF = TD + TE;
	       }
	       {
		    E Tc, TA, Th, TB;
		    {
			 E T9, Tb, T8, Ta;
			 T9 = Rp[WS(rs, 1)];
			 Tb = Rm[WS(rs, 1)];
			 T8 = W[2];
			 Ta = W[3];
			 Tc = FMA(T8, T9, Ta * Tb);
			 TA = FNMS(Ta, T9, T8 * Tb);
		    }
		    {
			 E Te, Tg, Td, Tf;
			 Te = Ip[WS(rs, 2)];
			 Tg = Im[WS(rs, 2)];
			 Td = W[8];
			 Tf = W[9];
			 Th = FMA(Td, Te, Tf * Tg);
			 TB = FNMS(Tf, Te, Td * Tg);
		    }
		    Ti = Tc - Th;
		    TI = TA - TB;
		    Tw = Tc + Th;
		    TC = TA + TB;
	       }
	       {
		    E TK, Tu, TH, TT, TR, TU;
		    TK = KP866025403 * (TI + TJ);
		    Tu = Ti + Tt;
		    TH = FNMS(KP500000000, Tu, T7);
		    Rm[WS(rs, 2)] = T7 + Tu;
		    Rp[WS(rs, 1)] = TH + TK;
		    Rm[0] = TH - TK;
		    TT = KP866025403 * (Tt - Ti);
		    TR = TJ - TI;
		    TU = FMA(KP500000000, TR, TS);
		    Im[WS(rs, 2)] = TR - TS;
		    Ip[WS(rs, 1)] = TT + TU;
		    Im[0] = TT - TU;
	       }
	       {
		    E TG, Ty, Tz, TP, TL, TQ;
		    TG = KP866025403 * (TC - TF);
		    Ty = Tw + Tx;
		    Tz = FNMS(KP500000000, Ty, Tv);
		    Rp[0] = Tv + Ty;
		    Rm[WS(rs, 1)] = Tz + TG;
		    Rp[WS(rs, 2)] = Tz - TG;
		    TP = KP866025403 * (Tw - Tx);
		    TL = TC + TF;
		    TQ = FNMS(KP500000000, TL, TO);
		    Ip[0] = TL + TO;
		    Ip[WS(rs, 2)] = TP + TQ;
		    Im[WS(rs, 1)] = TP - TQ;
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 6},
     {TW_NEXT, 1, 0}
};

static const hc2c_desc desc = { 6, "hc2cf_6", twinstr, &GENUS, {32, 14, 14, 0} };

void X(codelet_hc2cf_6) (planner *p) {
     X(khc2c_register) (p, hc2cf_6, &desc, HC2C_VIA_RDFT);
}
#endif
