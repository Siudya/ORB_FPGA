/***************************************************************************
Copyright (c) 2018, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
this list of conditions and the following disclaimer in the documentation 
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors 
may be used to endorse or promote products derived from this software 
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ***************************************************************************/

#include "comDescriptor.h"
const char bit_pattern_31_[256][8] =
{
8, -3, -3, 8, 9, 5, 5, 9,
4, 2, 2, 4, 7, -12, -12, 7,
-11, 9, 9, -11, -8, 2, 2, -8,
7, -12, -12, 7, 12, -13, -13, 12,
2, -13, -13, 2, 2, 12, 12, 2,
1, -7, -7, 1, 1, 6, 6, 1,
-2, -10, -10, -2, -2, -4, -4, -2,
-13, -13, -13, -13, -11, -8, -8, -11,
-13, -3, -3, -13, -12, -9, -9, -12,
10, 4, 4, 10, 11, 9, 9, 11,
-13, -8, -8, -13, -8, -9, -9, -8,
-11, 7, 7, -11, -9, 12, 12, -9,
7, 7, 7, 7, 12, 6, 6, 12,
-4, -5, -5, -4, -3, 0, 0, -3,
-13, 2, 2, -13, -12, -3, -3, -12,
-9, 0, 0, -9, -7, 5, 5, -7,
12, -6, -6, 12, 12, -1, -1, 12,
-3, 6, 6, -3, -2, 12, 12, -2,
-6, -13, -13, -6, -4, -8, -8, -4,
11, -13, -13, 11, 12, -8, -8, 12,
4, 7, 7, 4, 5, 1, 1, 5,
5, -3, -3, 5, 10, -3, -3, 10,
3, -7, -7, 3, 6, 12, 12, 6,
-8, -7, -7, -8, -6, -2, -2, -6,
-2, 11, 11, -2, -1, -10, -10, -1,
-13, 12, 12, -13, -8, 10, 10, -8,
-7, 3, 3, -7, -5, -3, -3, -5,
-4, 2, 2, -4, -3, 7, 7, -3,
-10, -12, -12, -10, -6, 11, 11, -6,
5, -12, -12, 5, 6, -7, -7, 6,
5, -6, -6, 5, 7, -1, -1, 7,
1, 0, 0, 1, 4, -5, -5, 4,
9, 11, 11, 9, 11, -13, -13, 11,
4, 7, 7, 4, 4, 12, 12, 4,
2, -1, -1, 2, 4, 4, 4, 4,
-4, -12, -12, -4, -2, 7, 7, -2,
-8, -5, -5, -8, -7, -10, -10, -7,
4, 11, 11, 4, 9, 12, 12, 9,
0, -8, -8, 0, 1, -13, -13, 1,
-13, -2, -2, -13, -8, 2, 2, -8,
-3, -2, -2, -3, -2, 3, 3, -2,
-6, 9, 9, -6, -4, -9, -9, -4,
8, 12, 12, 8, 10, 7, 7, 10,
0, 9, 9, 0, 1, 3, 3, 1,
7, -5, -5, 7, 11, -10, -10, 11,
-13, -6, -6, -13, -11, 0, 0, -11,
10, 7, 7, 10, 12, 1, 1, 12,
-6, -3, -3, -6, -6, 12, 12, -6,
10, -9, -9, 10, 12, -4, -4, 12,
-13, 8, 8, -13, -8, -12, -12, -8,
-13, 0, 0, -13, -8, -4, -4, -8,
3, 3, 3, 3, 7, 8, 8, 7,
5, 7, 7, 5, 10, -7, -7, 10,
-1, 7, 7, -1, 1, -12, -12, 1,
3, -10, -10, 3, 5, 6, 6, 5,
2, -4, -4, 2, 3, -10, -10, 3,
-13, 0, 0, -13, -13, 5, 5, -13,
-13, -7, -7, -13, -12, 12, 12, -12,
-13, 3, 3, -13, -11, 8, 8, -11,
-7, 12, 12, -7, -4, 7, 7, -4,
6, -10, -10, 6, 12, 8, 8, 12,
-9, -1, -1, -9, -7, -6, -6, -7,
-2, -5, -5, -2, 0, 12, 12, 0,
-12, 5, 5, -12, -7, 5, 5, -7,
3, -10, -10, 3, 8, -13, -13, 8,
-7, -7, -7, -7, -4, 5, 5, -4,
-3, -2, -2, -3, -1, -7, -7, -1,
2, 9, 9, 2, 5, -11, -11, 5,
-11, -13, -13, -11, -5, -13, -13, -5,
-1, 6, 6, -1, 0, -1, -1, 0,
5, -3, -3, 5, 5, 2, 2, 5,
-4, -13, -13, -4, -4, 12, 12, -4,
-9, -6, -6, -9, -9, 6, 6, -9,
-12, -10, -10, -12, -8, -4, -4, -8,
10, 2, 2, 10, 12, -3, -3, 12,
7, 12, 12, 7, 12, 12, 12, 12,
-7, -13, -13, -7, -6, 5, 5, -6,
-4, 9, 9, -4, -3, 4, 4, -3,
7, -1, -1, 7, 12, 2, 2, 12,
-7, 6, 6, -7, -5, 1, 1, -5,
-13, 11, 11, -13, -12, 5, 5, -12,
-3, 7, 7, -3, -2, -6, -6, -2,
7, -8, -8, 7, 12, -7, -7, 12,
-13, -7, -7, -13, -11, -12, -12, -11,
1, -3, -3, 1, 12, 12, 12, 12,
2, -6, -6, 2, 3, 0, 0, 3,
-4, 3, 3, -4, -2, -13, -13, -2,
-1, -13, -13, -1, 1, 9, 9, 1,
7, 1, 1, 7, 8, -6, -6, 8,
1, -1, -1, 1, 3, 12, 12, 3,
9, 1, 1, 9, 12, 6, 6, 12,
-1, -9, -9, -1, -1, 3, 3, -1,
-13, -13, -13, -13, -10, 5, 5, -10,
7, 7, 7, 7, 10, 12, 12, 10,
12, -5, -5, 12, 12, 9, 9, 12,
6, 3, 3, 6, 7, 11, 11, 7,
5, -13, -13, 5, 6, 10, 10, 6,
2, -12, -12, 2, 2, 3, 3, 2,
3, 8, 8, 3, 4, -6, -6, 4,
2, 6, 6, 2, 12, -13, -13, 12,
9, -12, -12, 9, 10, 3, 3, 10,
-8, 4, 4, -8, -7, 9, 9, -7,
-11, 12, 12, -11, -4, -6, -6, -4,
1, 12, 12, 1, 2, -8, -8, 2,
6, -9, -9, 6, 7, -4, -4, 7,
2, 3, 3, 2, 3, -2, -2, 3,
6, 3, 3, 6, 11, 0, 0, 11,
3, -3, -3, 3, 8, -8, -8, 8,
7, 8, 8, 7, 9, 3, 3, 9,
-11, -5, -5, -11, -6, -4, -4, -6,
-10, 11, 11, -10, -5, 10, 10, -5,
-5, -8, -8, -5, -3, 12, 12, -3,
-10, 5, 5, -10, -9, 0, 0, -9,
8, -1, -1, 8, 12, -6, -6, 12,
4, -6, -6, 4, 6, -11, -11, 6,
-10, 12, 12, -10, -8, 7, 7, -8,
4, -2, -2, 4, 6, 7, 7, 6,
-2, 0, 0, -2, -2, 12, 12, -2,
-5, -8, -8, -5, -5, 2, 2, -5,
7, -6, -6, 7, 10, 12, 12, 10,
-9, -13, -13, -9, -8, -8, -8, -8,
-5, -13, -13, -5, -5, -2, -2, -5,
8, -8, -8, 8, 9, -13, -13, 9,
-9, -11, -11, -9, -9, 0, 0, -9,
1, -8, -8, 1, 1, -2, -2, 1,
7, -4, -4, 7, 9, 1, 1, 9,
-2, 1, 1, -2, -1, -4, -4, -1,
11, -6, -6, 11, 12, -11, -11, 12,
-12, -9, -9, -12, -6, 4, 4, -6,
3, 7, 7, 3, 7, 12, 12, 7,
5, 5, 5, 5, 10, 8, 8, 10,
0, -4, -4, 0, 2, 8, 8, 2,
-9, 12, 12, -9, -5, -13, -13, -5,
0, 7, 7, 0, 2, 12, 12, 2,
-1, 2, 2, -1, 1, 7, 7, 1,
5, 11, 11, 5, 7, -9, -9, 7,
3, 5, 5, 3, 6, -8, -8, 6,
-13, -4, -4, -13, -8, 9, 9, -8,
-5, 9, 9, -5, -3, -3, -3, -3,
-4, -7, -7, -4, -3, -12, -12, -3,
6, 5, 5, 6, 8, 0, 0, 8,
-7, 6, 6, -7, -6, 12, 12, -6,
-13, 6, 6, -13, -5, -2, -2, -5,
1, -10, -10, 1, 3, 10, 10, 3,
4, 1, 1, 4, 8, -4, -4, 8,
-2, -2, -2, -2, 2, -13, -13, 2,
2, -12, -12, 2, 12, 12, 12, 12,
-2, -13, -13, -2, 0, -6, -6, 0,
4, 1, 1, 4, 9, 3, 3, 9,
-6, -10, -10, -6, -3, -5, -5, -3,
-3, -13, -13, -3, -1, 1, 1, -1,
7, 5, 5, 7, 12, -11, -11, 12,
4, -2, -2, 4, 5, -7, -7, 5,
-13, 9, 9, -13, -9, -5, -5, -9,
7, 1, 1, 7, 8, 6, 6, 8,
7, -8, -8, 7, 7, 6, 6, 7,
-7, -4, -4, -7, -7, 1, 1, -7,
-8, 11, 11, -8, -7, -8, -8, -7,
-13, 6, 6, -13, -12, -8, -8, -12,
2, 4, 4, 2, 3, 9, 9, 3,
10, -5, -5, 10, 12, 3, 3, 12,
-6, -5, -5, -6, -6, 7, 7, -6,
8, -3, -3, 8, 9, -8, -8, 9,
2, -12, -12, 2, 2, 8, 8, 2,
-11, -2, -2, -11, -10, 3, 3, -10,
-12, -13, -13, -12, -7, -9, -9, -7,
-11, 0, 0, -11, -10, -5, -5, -10,
5, -3, -3, 5, 11, 8, 8, 11,
-2, -13, -13, -2, -1, 12, 12, -1,
-1, -8, -8, -1, 0, 9, 9, 0,
-13, -11, -11, -13, -12, -5, -5, -12,
-10, -2, -2, -10, -10, 11, 11, -10,
-3, 9, 9, -3, -2, -13, -13, -2,
2, -3, -3, 2, 3, 2, 2, 3,
-9, -13, -13, -9, -4, 0, 0, -4,
-4, 6, 6, -4, -3, -10, -10, -3,
-4, 12, 12, -4, -2, -7, -7, -2,
-6, -11, -11, -6, -4, 9, 9, -4,
6, -3, -3, 6, 6, 11, 11, 6,
-13, 11, 11, -13, -5, 5, 5, -5,
11, 11, 11, 11, 12, 6, 6, 12,
7, -5, -5, 7, 12, -2, -2, 12,
-1, 12, 12, -1, 0, 7, 7, 0,
-4, -8, -8, -4, -3, -2, -2, -3,
-7, 1, 1, -7, -6, 7, 7, -6,
-13, -12, -12, -13, -8, -13, -13, -8,
-7, -2, -2, -7, -6, -8, -8, -6,
-8, 5, 5, -8, -6, -9, -9, -6,
-5, -1, -1, -5, -4, 5, 5, -4,
-13, 7, 7, -13, -8, 10, 10, -8,
1, 5, 5, 1, 5, -13, -13, 5,
1, 0, 0, 1, 10, -13, -13, 10,
9, 12, 12, 9, 10, -1, -1, 10,
5, -8, -8, 5, 10, -9, -9, 10,
-1, 11, 11, -1, 1, -13, -13, 1,
-9, -3, -3, -9, -6, 2, 2, -6,
-1, -10, -10, -1, 1, 12, 12, 1,
-13, 1, 1, -13, -8, -10, -10, -8,
8, -11, -11, 8, 10, -6, -6, 10,
2, -13, -13, 2, 3, -6, -6, 3,
7, -13, -13, 7, 12, -9, -9, 12,
-10, -10, -10, -10, -5, -7, -7, -5,
-10, -8, -8, -10, -8, -13, -13, -8,
4, -6, -6, 4, 8, 5, 5, 8,
3, 12, 12, 3, 8, -13, -13, 8,
-4, 2, 2, -4, -3, -3, -3, -3,
5, -13, -13, 5, 10, -12, -12, 10,
4, -13, -13, 4, 5, -1, -1, 5,
-9, 9, 9, -9, -4, 3, 3, -4,
0, 3, 3, 0, 3, -9, -9, 3,
-12, 1, 1, -12, -6, 1, 1, -6,
3, 2, 2, 3, 4, -8, -8, 4,
-10, -10, -10, -10, -10, 9, 9, -10,
8, -13, -13, 8, 12, 12, 12, 12,
-8, -12, -12, -8, -6, -5, -5, -6,
2, 2, 2, 2, 3, 7, 7, 3,
10, 6, 6, 10, 11, -8, -8, 11,
6, 8, 8, 6, 8, -12, -12, 8,
-7, 10, 10, -7, -6, 5, 5, -6,
-3, -9, -9, -3, -3, 9, 9, -3,
-1, -13, -13, -1, -1, 5, 5, -1,
-3, -7, -7, -3, -3, 4, 4, -3,
-8, -2, -2, -8, -8, 3, 3, -8,
4, 2, 2, 4, 12, 12, 12, 12,
2, -5, -5, 2, 3, 11, 11, 3,
6, -9, -9, 6, 11, -13, -13, 11,
3, -1, -1, 3, 7, 12, 12, 7,
11, -1, -1, 11, 12, 4, 4, 12,
-3, 0, 0, -3, -3, 6, 6, -3,
4, -11, -11, 4, 4, 12, 12, 4,
2, -4, -4, 2, 2, 1, 1, 2,
-10, -6, -6, -10, -8, 1, 1, -8,
-13, 7, 7, -13, -11, 1, 1, -11,
-13, 12, 12, -13, -11, -13, -13, -11,
6, 0, 0, 6, 11, -13, -13, 11,
0, -1, -1, 0, 1, 4, 4, 1,
-13, 3, 3, -13, -9, -2, -2, -9,
-9, 8, 8, -9, -6, -3, -3, -6,
-13, -6, -6, -13, -8, -2, -2, -8,
5, -9, -9, 5, 8, 10, 10, 8,
2, 7, 7, 2, 3, -9, -9, 3,
-1, -6, -6, -1, -1, -1, -1, -1,
9, 5, 5, 9, 11, -2, -2, 11,
11, -3, -3, 11, 12, -8, -8, 12,
3, 0, 0, 3, 3, 5, 5, 3,
-1, 4, 4, -1, 0, 10, 10, 0,
3, -6, -6, 3, 4, 5, 5, 4,
-13, 0, 0, -13, -10, 5, 5, -10,
5, 8, 8, 5, 12, 11, 11, 12,
8, 9, 9, 8, 9, -6, -6, 9,
7, -4, -4, 7, 8, -12, -12, 8,
-10, 4, 4, -10, -10, 9, 9, -10,
7, 3, 3, 7, 12, 4, 4, 12,
9, -7, -7, 9, 10, -2, -2, 10,
7, 0, 0, 7, 12, -2, -2, 12,
-1, -6, -6, -1, 0, -11, -11, 0
};
void Descriptors(
		hls::stream<ap_uint<328> > &dataPackStreamIn,
		hls::stream<ap_axiu<32,1,1,1> > &descriptor_out
		)
{
#pragma HLS RESOURCE variable=bit_pattern_31_ core=ROM_1P
#pragma HLS ARRAY_PARTITION variable=bit_pattern_31_ complete dim=2
	unsigned char src_buf0[31][31];
#pragma HLS ARRAY_PARTITION variable=src_buf0 complete dim=1
#pragma HLS ARRAY_PARTITION variable=src_buf0 complete dim=2
	unsigned char src_buf1[31][31];
#pragma HLS ARRAY_PARTITION variable=src_buf1 complete dim=1
#pragma HLS ARRAY_PARTITION variable=src_buf1 complete dim=2

	static hls::stream<ap_int<6> > mul_resA0;
#pragma HLS STREAM variable=mul_resA0 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resB0;
#pragma HLS STREAM variable=mul_resB0 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resC0;
#pragma HLS STREAM variable=mul_resC0 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resD0;
#pragma HLS STREAM variable=mul_resD0 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resA1;
#pragma HLS STREAM variable=mul_resA1 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resB1;
#pragma HLS STREAM variable=mul_resB1 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resC1;
#pragma HLS STREAM variable=mul_resC1 depth=8 dim=1
	static hls::stream<ap_int<6> > mul_resD1;
#pragma HLS STREAM variable=mul_resD1 depth=8 dim=1

	static hls::stream<ap_uint<5> > res_x0;
#pragma HLS STREAM variable=res_x0 depth=8 dim=1
	static hls::stream<ap_uint<5> > res_y0;
#pragma HLS STREAM variable=res_y0 depth=8 dim=1
	static hls::stream<ap_uint<5> > res_x1;
#pragma HLS STREAM variable=res_x1 depth=8 dim=1
	static hls::stream<ap_uint<5> > res_y1;
#pragma HLS STREAM variable=res_y1 depth=8 dim=1
	ap_uint<72> momVal=0;
	ap_int<24> m_10_int,m_01_int;
	ap_fixed<24,23> m_10,m_01;
	ap_uint<320> descriptor = 0;
	ap_uint<12>posX,posY;
	unsigned char t0, t1;
	ap_uint<5> x0,y0,x1,y1;
	ap_uint<5> x0_res,y0_res,x1_res,y1_res;
	ap_int<6> warpA0,warpB0,warpC0,warpD0;
	ap_int<6> warpA1,warpB1,warpC1,warpD1;
	unsigned char validFlag;
	for(int ss = 0;ss<HEIGHT*(WIDTH+15);ss++)
	{
		ap_uint<328> datapack = dataPackStreamIn.read();
		ap_uint<248> winVal = datapack.range(247,0);
		m_10_int = datapack.range(271,248);
		m_01_int = datapack.range(295,272);
		posX = datapack.range(307,296);
		posY = datapack.range(319,308);
		validFlag = datapack.range(327,320);
		descriptor.range(287,256) = (int)posX;
		descriptor.range(319,288) = (int)posY;
		read_row_loop:
		for(ap_uint<6> k = 0;k<31;k++)
		{
#pragma HLS UNROLL
#pragma HLS LOOP_TRIPCOUNT MAX=31
			for(ap_uint<8> s = 0;s<31;s++)
			{
#pragma HLS UNROLL
				if(k!=30)
				{
					src_buf0[s][k] = src_buf0[s][k+1];
					src_buf1[s][k] = src_buf1[s][k+1];
				}
				else
				{
					src_buf0[s][30] = (unsigned char)winVal.range(s*8+7,s*8);
					src_buf1[s][30] = (unsigned char)winVal.range(s*8+7,s*8);
				}
			}
		}

		if(validFlag != 0)
		{
			m_10 = m_10_int;
			m_01 = m_01_int;
			ap_fixed<14,3> angle = hls::atan2(m_01, m_10);
			ap_fixed<13,2> a = (hls::cos(angle));
			ap_fixed<13,2> b = (hls::sin(angle));
			//float angle = hls::atan2((float)m_01, (float)m_10);
			//float a = (hls::cos(angle)), b = (hls::sin(angle));
			compute_loop:
			for(unsigned int i =0;i<256;i++)
			{
#pragma HLS PIPELINE
				mul_resA0.write(bit_pattern_31_[i][0]*b);
				mul_resB0.write(bit_pattern_31_[i][1]*a);
				mul_resD0.write(bit_pattern_31_[i][2]*b);
				mul_resC0.write(bit_pattern_31_[i][3]*a);
				mul_resA1.write(bit_pattern_31_[i][4]*b);
				mul_resB1.write(bit_pattern_31_[i][5]*a);
				mul_resD1.write(bit_pattern_31_[i][6]*b);
				mul_resC1.write(bit_pattern_31_[i][7]*a);
				warpA0 = mul_resA0.read();
				warpB0 = mul_resB0.read();
				warpD0 = mul_resD0.read();
				warpC0 = mul_resC0.read();
				warpA1 = mul_resA1.read();
				warpB1 = mul_resB1.read();
				warpD1 = mul_resD1.read();
				warpC1 = mul_resC1.read();
				y0_res = warpA0 + warpB0 + 15;
				x0_res = warpC0 - warpD0 + 15;
				y1_res = warpA1 + warpB1 + 15;
				x1_res = warpC1 - warpD1 + 15;
				res_y0.write(y0_res);
				res_x0.write(x0_res);
				res_y1.write(y1_res);
				res_x1.write(x1_res);
				y0 = res_y0.read();
				x0 = res_x0.read();
				y1 = res_y1.read();
				x1 = res_x1.read();
				t0 = src_buf0[y0][x0];
				t1 = src_buf1[y1][x1];
				descriptor.range(i,i) = t0 < t1;

			}
			output_loop:
			for (unsigned int i = 0; i < 10; i++)
			{
#pragma HLS PIPELINE
				ap_axiu<32,1,1,1> outVal;
				ap_uint<32> temp = descriptor.range((i<<5)+31,i<<5);
				outVal.data = temp;
				outVal.keep = 0xf;
				if(posX == 4095 && posY == 4095 && i==9)
					outVal.last = 1;
				else
					outVal.last = 0;
				descriptor_out.write(outVal);
			}
		}
	}
}

template<int ROWS, int COLS, int DEPTH, int NPC, int WORDWIDTH, int TC, int WIN_SZ, int WIN_SZ_SQ>
void lineProcess(hls::stream<ap_uint<8> > & _src_mat,
		hls::stream<ap_uint<80> > &dataPackStreamIn,
		hls::stream<ap_uint<328> > &dataPackStreamOut,
		XF_SNAME(WORDWIDTH) buf[WIN_SZ][(COLS >> XF_BITSHIFT(NPC))],
		XF_PTNAME(DEPTH) src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)],
		uint16_t img_width,
		uint16_t img_height,
		ap_uint<13> row_ind[WIN_SZ],
		ap_uint<13> row,
		ap_uint<8> win_size)
{
#pragma HLS INLINE

	XF_SNAME(WORDWIDTH) buf_cop[WIN_SZ];
#pragma HLS ARRAY_PARTITION variable=buf_cop complete dim=1

	uint16_t npc = XF_NPIXPERCYCLE(NPC);
	uint16_t col_loop_var = 0;
	ap_uint<248> winVal = 0;
	ap_uint<80> dataIn;
	if(npc == 1)
	{
		col_loop_var = (WIN_SZ>>1);
	}
	else
	{
		col_loop_var = 1;
	}
	for(int extract_px=0;extract_px<WIN_SZ;extract_px++)
	{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
#pragma HLS unroll
		for(int ext_copy=0; ext_copy<npc + WIN_SZ - 1; ext_copy++)
		{
#pragma HLS unroll
			src_buf[extract_px][ext_copy] = 0;
		}
	}

	Col_Loop:
	for(ap_uint<13> col = 0; col < ((img_width)>>XF_BITSHIFT(NPC)) + col_loop_var; col++)
	{
#pragma HLS LOOP_TRIPCOUNT min=TC max=TC
#pragma HLS pipeline
#pragma HLS LOOP_FLATTEN OFF
		if(row < img_height && col < (img_width>>XF_BITSHIFT(NPC)))
			buf[row_ind[win_size-1]][col] = _src_mat.read(); // Read data
		if(NPC == XF_NPPC8)
		{
		}
		else
		{
			for(int copy_buf_var=0;copy_buf_var<WIN_SZ;copy_buf_var++)
			{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
#pragma HLS UNROLL
				if(	(row >(img_height-1)) && (copy_buf_var>(win_size-1-(row-(img_height-1)))))
				{
					buf_cop[copy_buf_var] = buf[(row_ind[win_size-1-(row-(img_height-1))])][col];
				}
				else
				{
					buf_cop[copy_buf_var] = buf[(row_ind[copy_buf_var])][col];
				}
			}
			for(int extract_px=0;extract_px<WIN_SZ;extract_px++)
			{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
#pragma HLS UNROLL
				if(col<img_width)
				{
					src_buf[extract_px][win_size-1] = buf_cop[extract_px];
					winVal.range((extract_px<<3)+7,extract_px<<3) = buf_cop[extract_px];
				}
				else
				{
					src_buf[extract_px][win_size-1] = src_buf[extract_px][win_size-2];
					winVal.range((extract_px<<3)+7,extract_px<<3) = src_buf[extract_px][win_size-2];
				}
			}
			if(HEIGHT-1 == row-15 && WIDTH-1 == col-15)
			{
				dataIn= dataPackStreamIn.read();
				dataIn.range(59,48) = 4095;
				dataIn.range(71,60) = 4095;
				dataIn.range(79,72) = 255;
			}
			else if(col >= (WIN_SZ>>1))
			{
				dataIn= dataPackStreamIn.read();
			}
			else
			{
				dataIn = 0;
			}
			ap_uint<328> temp;
			temp.range(247,0) = winVal;
			temp.range(327,248) = dataIn;
			dataPackStreamOut.write(temp);
			for(int wrap_buf=0;wrap_buf<WIN_SZ;wrap_buf++)
			{
#pragma HLS UNROLL
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
				for(int col_warp=0; col_warp<WIN_SZ-1;col_warp++)
				{
#pragma HLS UNROLL
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
					if(col==0)
					{
						src_buf[wrap_buf][col_warp] = src_buf[wrap_buf][win_size-1];
					}
					else
					{
						src_buf[wrap_buf][col_warp] = src_buf[wrap_buf][col_warp+1];
					}
				}
			}
		}
	} // Col_Loop
}



template<int ROWS, int COLS, int DEPTH, int NPC, int WORDWIDTH, int TC,int WIN_SZ, int WIN_SZ_SQ>
void windowSliderProc(hls::stream<ap_uint<8> > &img,
		hls::stream<ap_uint<80> > &dataPackStreamIn,
		hls::stream<ap_uint<328> > &dataPackStreamOut,
		ap_uint<8> win_size,
		uint16_t img_height,
		uint16_t img_width
		)
{
	ap_uint<13> row_ind[WIN_SZ];
#pragma HLS ARRAY_PARTITION variable=row_ind complete dim=1


	uint16_t shift_x = 0;
	ap_uint<13> row, col;

	XF_PTNAME(DEPTH) src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)];
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=1
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=2
	// src_buf1 et al merged

	XF_SNAME(WORDWIDTH) buf[WIN_SZ][(COLS >> XF_BITSHIFT(NPC))];
#pragma HLS ARRAY_PARTITION variable=buf complete dim=1
#pragma HLS RESOURCE variable=buf core=RAM_S2P_BRAM

	//initializing row index

	for(int init_row_ind=0; init_row_ind<win_size; init_row_ind++)
	{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
		row_ind[init_row_ind] = init_row_ind;
	}

	read_lines:
	for(int init_buf=row_ind[win_size>>1]; init_buf <row_ind[win_size-1] ;init_buf++)
	{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
		for(col = 0; col < img_width>>XF_BITSHIFT(NPC) ; col++)
		{
#pragma HLS LOOP_TRIPCOUNT min=TC max=TC
#pragma HLS pipeline
#pragma HLS LOOP_FLATTEN OFF
			buf[init_buf][col] = img.read();
		}
	}

	//takes care of top borders
	for(col = 0; col < img_width>>XF_BITSHIFT(NPC); col++)
	{
#pragma HLS LOOP_TRIPCOUNT min=TC max=TC
		for(int init_buf=0; init_buf < WIN_SZ>>1;init_buf++)
		{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
#pragma HLS UNROLL
			buf[init_buf][col] = 0;//buf[row_ind[win_size>>1]][col];
		}
	}

	Row_Loop:
	for(row = (win_size>>1); row < img_height+(win_size>>1); row++)
	{
#pragma HLS LOOP_TRIPCOUNT min=ROWS max=ROWS

		lineProcess<ROWS, COLS, DEPTH, NPC, WORDWIDTH, TC, WIN_SZ, WIN_SZ_SQ>(img, dataPackStreamIn,dataPackStreamOut,buf, src_buf,img_width, img_height, row_ind, row,win_size);

		//update indices
		ap_uint<13> zero_ind = row_ind[0];
		for(int init_row_ind=0; init_row_ind<WIN_SZ-1; init_row_ind++)
		{
#pragma HLS LOOP_TRIPCOUNT min=WIN_SZ max=WIN_SZ
#pragma HLS UNROLL
			row_ind[init_row_ind] = row_ind[init_row_ind + 1];
		}
		row_ind[win_size-1] = zero_ind;
	} // Row_Loop
}

template<int NMS,int SRC_T,int ROWS, int COLS,int NPC=1>
void windowSlider(
		hls::stream<ap_uint<8> > &src,
		hls::stream<ap_uint<80> > &dataPackStreamIn,
		hls::stream<ap_uint<328> > &dataPackStreamOut)
{
#pragma HLS inline off
#pragma HLS DATAFLOW
	windowSliderProc<ROWS,COLS,XF_DEPTH(SRC_T,NPC),NPC,XF_WORDWIDTH(SRC_T,NPC),(COLS>>XF_BITSHIFT(NPC))+(31>>1),31, 31*31>(src, dataPackStreamIn,dataPackStreamOut,31,ROWS,COLS);
}

void comDescriptor_accel(hls::stream<ap_uint<8> > &srcStream,hls::stream<ap_uint<80> > & dataStreamIn,hls::stream<ap_axiu<32,1,1,1> > & descriptor_out)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=srcStream
#pragma HLS INTERFACE axis register both port=dataStreamIn
#pragma HLS INTERFACE axis register both port=descriptor_out

#pragma HLS DATAFLOW
	hls::stream<ap_uint<328> > dataPackStream;
	windowSlider<1,XF_8UC1,HEIGHT,WIDTH,1>(srcStream,dataStreamIn,dataPackStream);
	Descriptors(dataPackStream,descriptor_out);
}
