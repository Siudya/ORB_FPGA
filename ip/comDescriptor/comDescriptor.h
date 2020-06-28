#ifndef _COMDESCRIPTOR_H_
#define _COMDESCRIPTOR_H_

#include "hls_stream.h"
#include "common/xf_common.h"
#include "common/xf_utility.h"
#include "ap_int.h"
#include "hls_math.h"
#include "ap_fixed.h"
#include "ap_axi_sdata.h"

#define __MIN(a,b) ((a < b) ? a : b)
#define __MAX(a,b) ((a > b) ? a : b)

#define PSize       16
#define NUM         25

#define WIDTH 	640
#define HEIGHT	480

void comDescriptor_accel(hls::stream<ap_uint<8> > &srcStream,hls::stream<ap_uint<80> > & dataStreamIn,hls::stream<ap_axiu<32,1,1,1> > & descriptor_out);

#endif
