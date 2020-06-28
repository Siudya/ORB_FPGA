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

#include "myFAST.h"


#define __MIN(a,b) ((a < b) ? a : b)
#define __MAX(a,b) ((a > b) ? a : b)

#define PSize       16
#define NUM         25
const unsigned char mask[31][31] =
{
		000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000,
		000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000,
		000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000,
		000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000,
		000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000,
		000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000,
		000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000,
		000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000,
		000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000,
		000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000,
		000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000,
		000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000,
		000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000, 000, 000, 000,
		000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 255, 255, 255, 255, 255, 255, 255, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
};
void Moments(hls::stream<ap_uint<256> > & datapackStreamIn,
		hls::stream<ap_uint<56> > & momentPackStream )
{
#pragma HLS ARRAY_PARTITION variable=mask complete dim=1
#pragma HLS ARRAY_PARTITION variable=mask complete dim=2
	unsigned char src_buf[31][31];
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=1
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=2

	for(int i=0;i<HEIGHT*(WIDTH+15);i++)
	{
		ap_uint<264> inPack = datapackStreamIn.read();
		ap_uint<248> temp = inPack.range(247,0);
		unsigned char validFlag = inPack.range(255,248);
		ap_int<24> m_10 = 0;
		ap_int<24> m_01 = 0;
		ap_uint<56> val = 0;

		read_col_loop:
		for(ap_uint<6> k = 0;k<31;k++)
		{
#pragma HLS UNROLL
#pragma HLS LOOP_TRIPCOUNT MAX=31
			for(ap_uint<8> s = 0;s<31;s++)
			{
#pragma HLS UNROLL
				if(k!=30)
					src_buf[s][k] = src_buf[s][k+1];
				else
					src_buf[s][30] = (unsigned char)temp.range(s*8+7,s*8);
			}
		}
		if(validFlag == 127)
		{
			momentPackStream.write(val);
		}
		else if(validFlag == 255 )
		{
			for(ap_int<8> i = 0;i<31;i++)
			{
#pragma HLS PIPELINE
				unsigned char vres0[32];
#pragma HLS ARRAY_PARTITION variable=vres0 complete dim=1
				ap_uint<9> vres1[16];
#pragma HLS ARRAY_PARTITION variable=vres1 complete dim=1
				ap_uint<10> vres2[8];
#pragma HLS ARRAY_PARTITION variable=vres2 complete dim=1
				ap_uint<11> vres3[4];
#pragma HLS ARRAY_PARTITION variable=vres3 complete dim=1
			ap_uint<12> vres4[2];
#pragma HLS ARRAY_PARTITION variable=vres4 complete dim=1
			ap_uint<13> vres5;
			ap_int<19> vres;
				for(ap_uint<6>im = 0;im<32;im++)
				{
					if(im!=31)
						vres0[im] = src_buf[i][im]&mask[i][im];
					else
						vres0[im] = 0;
				}
				for(ap_uint<6> i0 = 0;i0<16;i0++)
				{
					vres1[i0] = vres0[i0<<1]+vres0[(i0<<1)+1];
				}
				for(ap_uint<6> i1 = 0;i1<8;i1++)
				{
					vres2[i1] = vres1[i1<<1]+vres1[(i1<<1)+1];
				}
				for(ap_uint<6> i3 = 0;i3<4;i3++)
				{
					vres3[i3] = vres2[i3<<1]+vres2[(i3<<1)+1];
				}
				for(ap_uint<6> i4 = 0;i4<2;i4++)
				{
					vres4[i4] = vres3[i4<<1]+vres3[(i4<<1)+1];
				}
				vres5 = vres4[0]+vres4[1];
				vres = vres5*(i-15);
				m_01 += vres;

				unsigned char ures0[32];
#pragma HLS ARRAY_PARTITION variable=ures0 complete dim=1
				ap_uint<9> ures1[16];
#pragma HLS ARRAY_PARTITION variable=ures1 complete dim=1
				ap_uint<10> ures2[8];
#pragma HLS ARRAY_PARTITION variable=ures2 complete dim=1
				ap_uint<11> ures3[4];
#pragma HLS ARRAY_PARTITION variable=ures3 complete dim=1
				ap_uint<12> ures4[2];
#pragma HLS ARRAY_PARTITION variable=ures4 complete dim=1
				ap_uint<13> ures5;
				ap_int<19> ures;
				for(ap_uint<6> im = 0;im<32;im++)
				{
					if(im!=31)
						ures0[im] = src_buf[im][i]&mask[im][i];
					else
						ures0[im] = 0;
				}
				for(ap_uint<6> i0 = 0;i0<16;i0++)
				{
					ures1[i0] = ures0[i0<<1]+ures0[(i0<<1)+1];
				}
				for(ap_uint<6> i1 = 0;i1<8;i1++)
				{
					ures2[i1] = ures1[i1<<1]+ures1[(i1<<1)+1];
				}
				for(ap_uint<6> i3 = 0;i3<4;i3++)
				{
					ures3[i3] = ures2[i3<<1]+ures2[(i3<<1)+1];
				}
				for(ap_uint<6> i4 = 0;i4<2;i4++)
				{
					ures4[i4] = ures3[i4<<1]+ures3[(i4<<1)+1];
				}
				ures5 = ures4[0]+ures4[1];
				ures = ures5*(i-15);
				m_10 += ures;
			}
			val.range(23,0) = m_10;
			val.range(47,24) = m_01;
			val.range(55,48) = validFlag;
			momentPackStream.write(val);
		}
	}
}
void MCFilter(
		hls::stream<ap_uint<56> > &datapackStreamIn,
		hls::stream<ap_uint<80> >& MomentsStreamOut)
{
	unsigned int count = 0;
	for(unsigned int i =0;i<HEIGHT;i++)
	{
		for(unsigned int j=0;j<WIDTH;j++)
		{
#pragma HLS PIPELINE
			ap_uint<56> datapack = datapackStreamIn.read();
			unsigned char flag = datapack.range(55,48);
			ap_uint<48> momValIn = datapack.range(47,0);
			ap_int<24>m_10 = datapack.range(23,0);
			ap_int<24>m_01 = datapack.range(47,24);
			ap_uint<80> outVal = 0;

			if(flag == 255 && count<MAXCORNERS-1)
			{
				//a strong point is read, pass it forward.
				ap_uint<12> posX = j;
				ap_uint<12> posY = i;
				outVal.range(47,0) = momValIn;
				outVal.range(59,48)= posX;
				outVal.range(71,60) = posY;
				outVal.range(79,72) = 255;
				count++;
			}
			MomentsStreamOut.write(outVal);
		}
	}
}
// coreScore computes the score for corner pixels
// For a given pixel identified as corner in process_function, the theshold is
// increaded by a small value in each iteration till the pixel becomes
// a non-corner. That value of threshold becomes the score for that corner pixel.
void xFCoreScore(short int *flag_d,int _threshold, uchar_t *core)
{
#pragma HLS INLINE
	short int flag_d_min2[NUM-1];
	short int flag_d_max2[NUM-1];
	short int flag_d_min4[NUM-3];
	short int flag_d_max4[NUM-3];
	short int flag_d_min8[NUM-7];
	short int flag_d_max8[NUM-7];

	for(ap_uint<5> i=0;i<NUM-1;i++)
	{
		flag_d_min2[i] = __MIN(flag_d[i],flag_d[i+1]);
		flag_d_max2[i] = __MAX(flag_d[i],flag_d[i+1]);
	}

	for(ap_uint<5> i=0;i<NUM-3;i++)
	{
		flag_d_min4[i] = __MIN(flag_d_min2[i],flag_d_min2[i+2]);
		flag_d_max4[i] = __MAX(flag_d_max2[i],flag_d_max2[i+2]);
	}

	for(ap_uint<5> i=0;i<NUM-7;i++)
	{
		flag_d_min8[i] = __MIN(flag_d_min4[i],flag_d_min4[i+4]);
		flag_d_max8[i] = __MAX(flag_d_max4[i],flag_d_max4[i+4]);
	}

	uchar_t a0= _threshold;

	for(ap_uint<5> i=0;i<PSize;i+=2)
	{
		short int a=255;
		if(PSize == 16) {
			a = flag_d_min8[i+1];
		}
		//		else {
		//			for(ap_uint<5> j=1;j<PSize/2+1;j++)
		//			{
		//				a=__MIN(a,flag_d[i+j]);
		//			}
		//		}
		a0=__MAX(a0,__MIN(a,flag_d[i]));  // a0 >= _threshold
		a0=__MAX(a0,__MIN(a,flag_d[i+PSize/2+1]));
	}
	short int b0= -_threshold;
	for(ap_uint<5> i=0;i<PSize;i+=2)
	{
		short int b=-255;
		if(PSize == 16) {
			b = flag_d_max8[i+1];
		}
		//		} else {
		//			for(ap_uint<5> j=1;j<PSize/2+1;j++)
		//			{
		//				b=__MAX(b,flag_d[i+j]);
		//			}
		//		}
		b0=__MIN(b0,__MAX(b,flag_d[i]));  // b0 <= -_threshold
		b0=__MIN(b0,__MAX(b,flag_d[i+PSize/2+1]));
	}
	*core = __MAX(a0,-b0)-1;
} // Core window score computation complete


template<int NPC,int WORDWIDTH,int DEPTH, int WIN_SZ, int WIN_SZ_SQ>
void xFfastProc(
		unsigned char OutputValues[XF_NPIXPERCYCLE(NPC)],
		unsigned char src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)],
		ap_uint<8> win_size,
		uchar_t _threshold,XF_PTNAME(DEPTH) &pack_corners)
{
#pragma HLS INLINE

	uchar_t kx = 0, ix = 0;

	//XF_SNAME(WORDWIDTH) tbuf_temp;
	unsigned char tbuf_temp = 0;


	////////////////////////////////////////////////
	// Main code goes here
	// Bresenham's circle score computation
	short int flag_d[(1 << XF_BITSHIFT(NPC))][NUM] = {0}, flag_val[(1 << XF_BITSHIFT(NPC))][NUM] = {0};

#pragma HLS ARRAY_PARTITION variable=flag_val dim=1
#pragma HLS ARRAY_PARTITION variable=flag_d dim=1

	for (ap_uint<4> i = 0; i < 1; i++)
	{
#pragma HLS LOOP_TRIPCOUNT MAX=1
#pragma HLS LOOP_FLATTEN off
#pragma HLS PIPELINE II=1
		// Compute the intensity difference between the candidate pixel and pixels on the Bresenham's circle
		flag_d[i][0]  = src_buf[3][3+i] - src_buf[0][3+i]; //tbuf4[3+i] - tbuf1[3+i];
		flag_d[i][1]  = src_buf[3][3+i] - src_buf[0][4+i]; //tbuf4[3+i] - tbuf1[4+i];
		flag_d[i][2]  = src_buf[3][3+i] - src_buf[1][5+i]; //tbuf4[3+i] - tbuf2[5+i];
		flag_d[i][3]  = src_buf[3][3+i] - src_buf[2][6+i]; //tbuf4[3+i] - tbuf3[6+i];
		flag_d[i][4]  = src_buf[3][3+i] - src_buf[3][6+i]; //tbuf4[3+i] - tbuf4[6+i];
		flag_d[i][5]  = src_buf[3][3+i] - src_buf[4][6+i]; //tbuf4[3+i] - tbuf5[6+i];
		flag_d[i][6]  = src_buf[3][3+i] - src_buf[5][5+i]; //tbuf4[3+i] - tbuf6[5+i];
		flag_d[i][7]  = src_buf[3][3+i] - src_buf[6][4+i]; //tbuf4[3+i] - tbuf7[4+i];
		flag_d[i][8]  = src_buf[3][3+i] - src_buf[6][3+i]; //tbuf4[3+i] - tbuf7[3+i];
		flag_d[i][9]  = src_buf[3][3+i] - src_buf[6][2+i]; //tbuf4[3+i] - tbuf7[2+i];
		flag_d[i][10] = src_buf[3][3+i] - src_buf[5][1+i]; //tbuf4[3+i] - tbuf6[1+i];
		flag_d[i][11] = src_buf[3][3+i] - src_buf[4][0+i]; //tbuf4[3+i] - tbuf5[0+i];
		flag_d[i][12] = src_buf[3][3+i] - src_buf[3][0+i]; //tbuf4[3+i] - tbuf4[0+i];
		flag_d[i][13] = src_buf[3][3+i] - src_buf[2][0+i]; //tbuf4[3+i] - tbuf3[0+i];
		flag_d[i][14] = src_buf[3][3+i] - src_buf[1][1+i]; //tbuf4[3+i] - tbuf2[1+i];
		flag_d[i][15] = src_buf[3][3+i] - src_buf[0][2+i]; //tbuf4[3+i] - tbuf1[2+i];
		// Repeating the first 9 values
		flag_d[i][16] = flag_d[i][0];
		flag_d[i][17] = flag_d[i][1];
		flag_d[i][18] = flag_d[i][2];
		flag_d[i][19] = flag_d[i][3];
		flag_d[i][20] = flag_d[i][4];
		flag_d[i][21] = flag_d[i][5];
		flag_d[i][22] = flag_d[i][6];
		flag_d[i][23] = flag_d[i][7];
		flag_d[i][24] = flag_d[i][8];

		// Classification of pixels on the Bresenham's circle into brighter, darker or similar w.r.t.
		// the candidate pixel
		for (ap_uint<4> j = 0; j < 8; j++)
		{
#pragma HLS unroll
			if (flag_d[i][j] > _threshold)
				flag_val[i][j] = 1;
			else if (flag_d[i][j] < -_threshold)
				flag_val[i][j] = 2;
			else
				flag_val[i][j] = 0;

			if (flag_d[i][j+8] > _threshold)
				flag_val[i][j+8] = 1;
			else if (flag_d[i][j+8] < -_threshold)
				flag_val[i][j+8] = 2;
			else
				flag_val[i][j+8] = 0;
			// Repeating the first 9 values
			flag_val[i][j+PSize] = flag_val[i][j];
		}
		flag_val[i][PSize/2+PSize] = flag_val[i][PSize/2];
		flag_d[i][PSize/2+PSize] = flag_d[i][PSize/2];

		// Bresenham's circle score computation complete

		// Decision making for corners
		uchar_t core=0;
		uchar_t iscorner=0;
		uchar_t count=1;
		for (ap_uint<5> c=1; c < PSize+PSize/2+1; c++)
		{
#pragma HLS LOOP_TRIPCOUNT MAX=25
#pragma HLS UNROLL
			if ((flag_val[i][c-1] == flag_val[i][c]) && flag_val[i][c]>0)
			{
				count++;
				if (count > PSize/2)
				{
					iscorner = 1; // Candidate pixel is a corner
				}
			}
			else
			{
				count=1;
			}
		} // Corner position computation complete
		// NMS Score Computation
		if(iscorner)
		{
			xFCoreScore(flag_d[i],_threshold, &core);
			pack_corners.range(ix+7,ix) = 255;
		}
		else
			pack_corners.range(ix+7,ix) = 0;
		ix+=8;
		// Pack the 8-bit score values into 64-bit words
		tbuf_temp = core;   // Set bits in a range of positions.
		kx += 8;
	}
	//return tbuf_temp;



	OutputValues[0] = tbuf_temp;//array[(WIN_SZ_SQ)>>1];
	return;
}

template<int ROWS, int COLS, int DEPTH, int NPC, int WORDWIDTH, int TC, int WIN_SZ, int WIN_SZ_SQ>
void ProcessFast(hls::stream< ap_axiu<8,1,1,1> > & _src_mat,
		hls::stream< ap_uint<16> > & _out_mat,
		unsigned char buf[WIN_SZ][(COLS >> XF_BITSHIFT(NPC))],
		unsigned char src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)],
		unsigned char OutputValues[XF_NPIXPERCYCLE(NPC)],
		XF_SNAME(WORDWIDTH) &P0, uint16_t img_width,  uint16_t img_height, uint16_t &shift_x,  ap_uint<13> row_ind[WIN_SZ], ap_uint<13> row, ap_uint<8> win_size,uchar_t _threshold,XF_PTNAME(DEPTH) &pack_corners)
{
#pragma HLS INLINE

	unsigned char buf_cop[WIN_SZ];
#pragma HLS ARRAY_PARTITION variable=buf_cop complete dim=1

	uint16_t npc = XF_NPIXPERCYCLE(NPC);
	uint16_t col_loop_var = 0;
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
			buf[row_ind[win_size-1]][col] = (_src_mat.read()).data; // Read data


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
				}
				else
				{
					src_buf[extract_px][win_size-1] = src_buf[extract_px][win_size-2];
				}
			}

			if((col<(img_width) && row<(img_height)) && col>=6 && row>=6)
			{
				xFfastProc<NPC, WORDWIDTH,DEPTH, WIN_SZ, WIN_SZ_SQ>(OutputValues,src_buf, win_size,_threshold,pack_corners);
			}

			if(row>=img_height || col>=img_width)
			{
				OutputValues[0]=0;
			}

			if(col >= (WIN_SZ>>1))
			{
				ap_uint<16> temp;
				temp.range(15,8) = OutputValues[0];
				temp.range(7,0) = src_buf[3][3];
				_out_mat.write(temp);
			}
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
void xFfast7x7(hls::stream< ap_axiu<8,1,1,1> > &_src_mat,
		hls::stream< ap_uint<16> > &_out_mat, ap_uint<8> win_size,
		uint16_t img_height, uint16_t img_width,uchar_t _threshold)
{
	ap_uint<13> row_ind[WIN_SZ];
#pragma HLS ARRAY_PARTITION variable=row_ind complete dim=1

	XF_PTNAME(DEPTH) pack_corners;

	uint16_t shift_x = 0;
	ap_uint<13> row, col;
	unsigned char OutputValues[XF_NPIXPERCYCLE(NPC)];
#pragma HLS ARRAY_PARTITION variable=OutputValues complete dim=1


	unsigned char src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)];
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=1
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=2
	// src_buf1 et al merged
	XF_SNAME(WORDWIDTH) P0;

	unsigned char buf[WIN_SZ][(COLS >> XF_BITSHIFT(NPC))];
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
			buf[init_buf][col] = (_src_mat.read()).data;
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

		P0 = 0;
		ProcessFast<ROWS, COLS, DEPTH, NPC, WORDWIDTH, TC, WIN_SZ, WIN_SZ_SQ>(_src_mat, _out_mat, buf, src_buf,OutputValues, P0, img_width, img_height, shift_x, row_ind, row,win_size,_threshold,pack_corners);

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


template<int NPC,int DEPTH, int WIN_SZ, int WIN_SZ_SQ>
void xFnmsProc(
		unsigned char OutputValues[XF_NPIXPERCYCLE(NPC)],
		ap_uint<16> src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)],
		ap_uint<8> win_size
)
{
#pragma HLS INLINE


	unsigned char pix = 0;
	unsigned char val0 = src_buf[14][14].range(15,8);
	unsigned char val1 = src_buf[14][15].range(15,8);
	unsigned char val2 = src_buf[14][16].range(15,8);
	unsigned char val3 = src_buf[15][14].range(15,8);
	unsigned char val4 = src_buf[15][15].range(15,8);
	unsigned char val5 = src_buf[15][16].range(15,8);
	unsigned char val6 = src_buf[16][14].range(15,8);
	unsigned char val7 = src_buf[16][15].range(15,8);
	unsigned char val8 = src_buf[16][16].range(15,8);

	// Comparing scores of the candidate pixel with neighbors in a 3x3 window
	if (val4 != 0){ // if score of candidate pixel != 0

		if (
				(val4 > val0) &&
				(val4 > val1) &&
				(val4 > val2) &&
				(val4 > val3) &&
				(val4 > val5) &&
				(val4 > val6) &&
				(val4 > val7) &&
				(val4 > val8)
				)
		{
			pix = 255;
		}
		else
		{
			pix = 127;
		}
	}
	else
	{
		pix = 127;
	}

	OutputValues[0] = pix;//array[(WIN_SZ_SQ)>>1];
	return;

}

template<int ROWS, int COLS, int DEPTH, int NPC, int WORDWIDTH, int TC, int WIN_SZ, int WIN_SZ_SQ>
void Processfastnms(
		hls::stream<ap_uint<16> > &_src_mat,
		hls::stream<ap_uint<256> > & datapackStreamOut,
		ap_uint<16> buf[WIN_SZ][(COLS >> XF_BITSHIFT(NPC))],
		ap_uint<16> src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)],
		unsigned char OutputValues[XF_NPIXPERCYCLE(NPC)],
		uint16_t img_width,  uint16_t img_height, uint16_t &shift_x,  ap_uint<13> row_ind[WIN_SZ], ap_uint<13> row, ap_uint<8> win_size
		)
{
#pragma HLS INLINE

	ap_uint<16> buf_cop[WIN_SZ];
#pragma HLS ARRAY_PARTITION variable=buf_cop complete dim=1
	uint16_t npc = XF_NPIXPERCYCLE(NPC);
	uint16_t col_loop_var = 0;
	ap_uint<248> winVal = 0;
	unsigned char validFlag = 0;
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
					winVal.range((extract_px<<3)+7,extract_px<<3) = buf_cop[extract_px].range(7,0);
				}
				else
				{
					src_buf[extract_px][win_size-1] = src_buf[extract_px][win_size-2];
					winVal.range((extract_px<<3)+7,extract_px<<3) = src_buf[extract_px][win_size-2].range(7,0);
				}
			}
			xFnmsProc<NPC, DEPTH, WIN_SZ, WIN_SZ_SQ>(OutputValues,src_buf, win_size);
			if(col >= (WIN_SZ>>1))
			{
				validFlag = OutputValues[0];
			}
			else
			{
				validFlag = 0;
			}
			ap_uint<256> temp;
			temp.range(247,0) = winVal;
			temp.range(255,248) = validFlag;
			datapackStreamOut.write(temp);

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
void xFfastnms(
		hls::stream<ap_uint<16> > &_src_mat,
		hls::stream<ap_uint<256> > &datapackStreamOut,
		ap_uint<8> win_size,
		uint16_t img_height, uint16_t img_width
		)
{
	ap_uint<13> row_ind[WIN_SZ];
#pragma HLS ARRAY_PARTITION variable=row_ind complete dim=1

	uint16_t shift_x = 0;
	ap_uint<13> row, col;
	unsigned char OutputValues[XF_NPIXPERCYCLE(NPC)];
#pragma HLS ARRAY_PARTITION variable=OutputValues complete dim=1


	ap_uint<16> src_buf[WIN_SZ][XF_NPIXPERCYCLE(NPC)+(WIN_SZ-1)];
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=1
#pragma HLS ARRAY_PARTITION variable=src_buf complete dim=2
	// src_buf1 et al merged

	ap_uint<16> buf[WIN_SZ][(COLS >> XF_BITSHIFT(NPC))];
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
			buf[init_buf][col] = _src_mat.read();
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
			buf[init_buf][col] = buf[row_ind[win_size>>1]][col];
		}
	}

	Row_Loop:
	for(row = (win_size>>1); row < img_height+(win_size>>1); row++)
	{
#pragma HLS LOOP_TRIPCOUNT min=ROWS max=ROWS

		Processfastnms<ROWS, COLS, DEPTH, NPC, WORDWIDTH, TC, WIN_SZ, WIN_SZ_SQ>( _src_mat,datapackStreamOut, buf, src_buf,OutputValues, img_width, img_height, shift_x, row_ind, row,win_size);

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

template<int ROWS,int COLS,int DEPTH,int NPC,int WORDWIDTH_SRC,int WORDWIDTH_DST,int NMSVAL>
void xFFastCornerDetection(hls::stream<ap_axiu<8,1,1,1> > & _strm_in,
		hls::stream<ap_uint<80> >& MomentsStreamOut,
		unsigned short _image_height,unsigned short _image_width)
{
    hls::stream<ap_uint<16> > datapackStream0;
    hls::stream<ap_uint<256> > datapackStream1;
   hls::stream<ap_uint<56> > datapackStream2;

#pragma HLS DATAFLOW
    xFfast7x7<ROWS,COLS,DEPTH,NPC,WORDWIDTH_SRC,(COLS>>XF_BITSHIFT(NPC))+(7>>1),7, 7*7>(_strm_in, datapackStream0,7,_image_height,_image_width,20);
	xFfastnms<ROWS,COLS,DEPTH,NPC,WORDWIDTH_SRC,(COLS>>XF_BITSHIFT(NPC))+(31>>1),31, 31*31>(datapackStream0,datapackStream1,31,_image_height,_image_width);
	Moments(datapackStream1,datapackStream2);
	MCFilter(datapackStream2,MomentsStreamOut);
}


template<int NMS,int SRC_T,int ROWS, int COLS,int NPC=1>
void myFAST(hls::stream<ap_axiu<8,1,1,1> > &src,hls::stream<ap_uint<80> >& MomentsStreamOut)
{

#pragma HLS inline off
#pragma HLS DATAFLOW

	xFFastCornerDetection<ROWS,COLS,XF_DEPTH(SRC_T,NPC),NPC,XF_WORDWIDTH(SRC_T,NPC),XF_32UW,NMS>(src,MomentsStreamOut,ROWS,COLS);
}

void fast_accel(hls::stream<ap_axiu<8,1,1,1> > &srcStream,hls::stream<ap_uint<80> >& MomentsStreamOut)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=MomentsStreamOut
#pragma HLS INTERFACE axis register both port=dstStream
#pragma HLS INTERFACE axis register both port=srcStream

	myFAST<1,XF_8UC1,HEIGHT,WIDTH,NPC1 >(srcStream,MomentsStreamOut);
}
