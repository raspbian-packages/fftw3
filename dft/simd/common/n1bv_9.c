/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
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
/* Generated on Sat Apr 28 11:00:08 EDT 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 9 -name n1bv_9 -include n1b.h */

/*
 * This function contains 46 FP additions, 38 FP multiplications,
 * (or, 12 additions, 4 multiplications, 34 fused multiply/add),
 * 68 stack variables, 19 constants, and 18 memory accesses
 */
#include "n1b.h"

static void n1bv_9(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP907603734, +0.907603734547952313649323976213898122064543220);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP666666666, +0.666666666666666666666666666666666666666666667);
     DVK(KP879385241, +0.879385241571816768108218554649462939872416269);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP826351822, +0.826351822333069651148283373230685203999624323);
     DVK(KP347296355, +0.347296355333860697703433253538629592000751354);
     DVK(KP898197570, +0.898197570222573798468955502359086394667167570);
     DVK(KP673648177, +0.673648177666930348851716626769314796000375677);
     DVK(KP420276625, +0.420276625461206169731530603237061658838781920);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP586256827, +0.586256827714544512072145703099641959914944179);
     DVK(KP968908795, +0.968908795874236621082202410917456709164223497);
     DVK(KP726681596, +0.726681596905677465811651808188092531873167623);
     DVK(KP439692620, +0.439692620785908384054109277324731469936208134);
     DVK(KP203604859, +0.203604859554852403062088995281827210665664861);
     DVK(KP152703644, +0.152703644666139302296566746461370407999248646);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T1, T2, T3, T6, Tf, T7, T8, Tb, Tc, Tp, T4;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       T3 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
	       T6 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       Tf = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T7 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       T8 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
	       Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       Tc = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	       Tp = VSUB(T2, T3);
	       T4 = VADD(T2, T3);
	       {
		    V Te, T9, Tg, Td, TF, T5;
		    Te = VSUB(T8, T7);
		    T9 = VADD(T7, T8);
		    Tg = VADD(Tb, Tc);
		    Td = VSUB(Tb, Tc);
		    TF = VADD(T1, T4);
		    T5 = VFNMS(LDK(KP500000000), T4, T1);
		    {
			 V Ta, TH, Th, TG;
			 Ta = VFNMS(LDK(KP500000000), T9, T6);
			 TH = VADD(T6, T9);
			 Th = VFNMS(LDK(KP500000000), Tg, Tf);
			 TG = VADD(Tf, Tg);
			 {
			      V Tr, Tu, Tm, Tv, Ts, Ti, TI, TK;
			      Tr = VFNMS(LDK(KP152703644), Te, Ta);
			      Tu = VFMA(LDK(KP203604859), Ta, Te);
			      Tm = VFNMS(LDK(KP439692620), Td, Ta);
			      Tv = VFNMS(LDK(KP726681596), Td, Th);
			      Ts = VFMA(LDK(KP968908795), Th, Td);
			      Ti = VFNMS(LDK(KP586256827), Th, Te);
			      TI = VADD(TG, TH);
			      TK = VMUL(LDK(KP866025403), VSUB(TG, TH));
			      {
				   V Tt, TA, Tw, Tz, Tj, TJ, To, TE, Tn;
				   Tn = VFNMS(LDK(KP420276625), Tm, Te);
				   Tt = VFNMS(LDK(KP673648177), Ts, Tr);
				   TA = VFMA(LDK(KP673648177), Ts, Tr);
				   Tw = VFMA(LDK(KP898197570), Tv, Tu);
				   Tz = VFNMS(LDK(KP898197570), Tv, Tu);
				   Tj = VFNMS(LDK(KP347296355), Ti, Td);
				   ST(&(xo[0]), VADD(TI, TF), ovs, &(xo[0]));
				   TJ = VFNMS(LDK(KP500000000), TI, TF);
				   To = VFNMS(LDK(KP826351822), Tn, Th);
				   TE = VMUL(LDK(KP984807753), VFMA(LDK(KP879385241), Tp, TA));
				   {
					V TB, TD, Tx, Tk, Tq, TC, Ty, Tl;
					TB = VFMA(LDK(KP666666666), TA, Tz);
					TD = VFMA(LDK(KP852868531), Tw, T5);
					Tx = VFNMS(LDK(KP500000000), Tw, Tt);
					Tk = VFNMS(LDK(KP907603734), Tj, Ta);
					ST(&(xo[WS(os, 6)]), VFNMSI(TK, TJ), ovs, &(xo[0]));
					ST(&(xo[WS(os, 3)]), VFMAI(TK, TJ), ovs, &(xo[WS(os, 1)]));
					Tq = VMUL(LDK(KP984807753), VFNMS(LDK(KP879385241), Tp, To));
					TC = VMUL(LDK(KP866025403), VFNMS(LDK(KP852868531), TB, Tp));
					ST(&(xo[WS(os, 8)]), VFNMSI(TE, TD), ovs, &(xo[0]));
					ST(&(xo[WS(os, 1)]), VFMAI(TE, TD), ovs, &(xo[WS(os, 1)]));
					Ty = VFMA(LDK(KP852868531), Tx, T5);
					Tl = VFNMS(LDK(KP939692620), Tk, T5);
					ST(&(xo[WS(os, 5)]), VFNMSI(TC, Ty), ovs, &(xo[WS(os, 1)]));
					ST(&(xo[WS(os, 4)]), VFMAI(TC, Ty), ovs, &(xo[0]));
					ST(&(xo[WS(os, 2)]), VFMAI(Tq, Tl), ovs, &(xo[0]));
					ST(&(xo[WS(os, 7)]), VFNMSI(Tq, Tl), ovs, &(xo[WS(os, 1)]));
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 9, XSIMD_STRING("n1bv_9"), {12, 4, 34, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_9) (planner *p) {
     X(kdft_register) (p, n1bv_9, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 9 -name n1bv_9 -include n1b.h */

/*
 * This function contains 46 FP additions, 26 FP multiplications,
 * (or, 30 additions, 10 multiplications, 16 fused multiply/add),
 * 41 stack variables, 14 constants, and 18 memory accesses
 */
#include "n1b.h"

static void n1bv_9(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DVK(KP813797681, +0.813797681349373692844693217248393223289101568);
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP296198132, +0.296198132726023843175338011893050938967728390);
     DVK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DVK(KP663413948, +0.663413948168938396205421319635891297216863310);
     DVK(KP556670399, +0.556670399226419366452912952047023132968291906);
     DVK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP150383733, +0.150383733180435296639271897612501926072238258);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T5, Ty, Tm, Ti, Tw, Th, Tj, To, Tb, Tv, Ta, Tc, Tn;
	       {
		    V T1, T2, T3, T4;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    T3 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    T4 = VADD(T2, T3);
		    T5 = VFNMS(LDK(KP500000000), T4, T1);
		    Ty = VADD(T1, T4);
		    Tm = VMUL(LDK(KP866025403), VSUB(T2, T3));
	       }
	       {
		    V Td, Tg, Te, Tf;
		    Td = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    Te = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Tf = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    Tg = VADD(Te, Tf);
		    Ti = VSUB(Te, Tf);
		    Tw = VADD(Td, Tg);
		    Th = VFNMS(LDK(KP500000000), Tg, Td);
		    Tj = VFNMS(LDK(KP852868531), Ti, VMUL(LDK(KP173648177), Th));
		    To = VFMA(LDK(KP150383733), Ti, VMUL(LDK(KP984807753), Th));
	       }
	       {
		    V T6, T9, T7, T8;
		    T6 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T7 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    T9 = VADD(T7, T8);
		    Tb = VSUB(T7, T8);
		    Tv = VADD(T6, T9);
		    Ta = VFNMS(LDK(KP500000000), T9, T6);
		    Tc = VFNMS(LDK(KP556670399), Tb, VMUL(LDK(KP766044443), Ta));
		    Tn = VFMA(LDK(KP663413948), Tb, VMUL(LDK(KP642787609), Ta));
	       }
	       {
		    V Tx, Tz, TA, Tt, Tu;
		    Tx = VBYI(VMUL(LDK(KP866025403), VSUB(Tv, Tw)));
		    Tz = VADD(Tv, Tw);
		    TA = VFNMS(LDK(KP500000000), Tz, Ty);
		    ST(&(xo[WS(os, 3)]), VADD(Tx, TA), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[0]), VADD(Ty, Tz), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 6)]), VSUB(TA, Tx), ovs, &(xo[0]));
		    Tt = VFMA(LDK(KP852868531), Tb, VFMA(LDK(KP173648177), Ta, VFMA(LDK(KP296198132), Ti, VFNMS(LDK(KP939692620), Th, T5))));
		    Tu = VBYI(VSUB(VFMA(LDK(KP984807753), Ta, VFMA(LDK(KP813797681), Ti, VFNMS(LDK(KP150383733), Tb, VMUL(LDK(KP342020143), Th)))), Tm));
		    ST(&(xo[WS(os, 7)]), VSUB(Tt, Tu), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 2)]), VADD(Tt, Tu), ovs, &(xo[0]));
		    {
			 V Tl, Ts, Tq, Tr, Tk, Tp;
			 Tk = VADD(Tc, Tj);
			 Tl = VADD(T5, Tk);
			 Ts = VFMA(LDK(KP866025403), VSUB(To, Tn), VFNMS(LDK(KP500000000), Tk, T5));
			 Tp = VADD(Tn, To);
			 Tq = VBYI(VADD(Tm, Tp));
			 Tr = VBYI(VADD(Tm, VFNMS(LDK(KP500000000), Tp, VMUL(LDK(KP866025403), VSUB(Tc, Tj)))));
			 ST(&(xo[WS(os, 8)]), VSUB(Tl, Tq), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 5)]), VSUB(Ts, Tr), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 1)]), VADD(Tl, Tq), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 4)]), VADD(Tr, Ts), ovs, &(xo[0]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 9, XSIMD_STRING("n1bv_9"), {30, 10, 16, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_9) (planner *p) {
     X(kdft_register) (p, n1bv_9, &desc);
}

#endif				/* HAVE_FMA */
