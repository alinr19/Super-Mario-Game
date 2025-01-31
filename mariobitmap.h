
#include "marduinotypes.h"
#ifndef MARIOBITMAP_H
#define MARIOBITMAP_H

BMP gameLogo[] = { 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xf8, 0x93, 0x0c, 0x61, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xf3, 0x93, 0x24, 0xe4, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xf1, 0x93, 0x24, 0xe4, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xf8, 0x93, 0x0c, 0x61, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xfc, 0x93, 0x3c, 0xe1, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xfc, 0x93, 0x3c, 0xe4, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xf1, 0xc7, 0x3c, 0x64, 0xff, 0xff, 0xff, 0xf0, 
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x01, 0xce, 0x07, 0x8f, 0xe7, 0xe3, 0xcf, 0x7b, 0x9c, 0x3e, 0x00, 
		0x03, 0xcf, 0x07, 0x8f, 0xf7, 0xf3, 0xcf, 0x7b, 0x9c, 0xfe, 0x00, 
		0x03, 0xff, 0x0f, 0x8f, 0xf7, 0xfb, 0xcf, 0x7b, 0x9d, 0xff, 0x00, 
		0x07, 0xff, 0x1c, 0xce, 0x77, 0x3b, 0xcf, 0x7b, 0xdd, 0xe7, 0x80, 
		0x07, 0xff, 0x9c, 0xce, 0x77, 0x3b, 0xcf, 0x7b, 0xfd, 0xc3, 0x80, 
		0x0f, 0x77, 0xbf, 0xee, 0x77, 0x3b, 0xcf, 0x7b, 0xfd, 0xc3, 0x80, 
		0x1f, 0x27, 0x8f, 0xe7, 0xe7, 0x3b, 0xcf, 0x7b, 0xbd, 0xe7, 0x80, 
		0x1e, 0x53, 0xef, 0xf7, 0xf7, 0xfb, 0xff, 0x7b, 0x9c, 0xff, 0x80, 
		0x3e, 0xab, 0xe8, 0xf7, 0x77, 0xf9, 0xfe, 0x7b, 0x9d, 0x7f, 0x00, 
		0x0d, 0x0b, 0xe6, 0xe7, 0x3b, 0xe2, 0xfd, 0x7b, 0x9c, 0xb8, 0x80, 
		0x22, 0x04, 0x09, 0x10, 0x44, 0x19, 0x02, 0x00, 0x60, 0x47, 0x00, 
		0x1c, 0x03, 0xe0, 0xe7, 0xbb, 0xe0, 0xfc, 0x7b, 0x9c, 0x38, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	};

BMP frameMario0[] = { 
	0x00, 0x00, 
	0x07, 0xe0, 
	0x08, 0x18, 
	0x13, 0xc4, 
	0x1c, 0xb8, 
	0x26, 0x84, 
	0x26, 0x44, 
	0x18, 0xf8, 
	0x0c, 0x10, 
	0x13, 0xe0, 
	0x21, 0x90, 
	0x2f, 0xf0, 
	0x11, 0xb0, 
	0x12, 0x70, 
	0x0c, 0x20, 
	0x07, 0xc0	};

BMP frameMario1[] = { 
	0x07, 0xc0, 
	0x08, 0x38, 
	0x13, 0xc4, 
	0x1c, 0xb8, 
	0x26, 0x84, 
	0x26, 0x44, 
	0x18, 0xf8, 
	0x1c, 0x10, 
	0x63, 0xf8, 
	0x91, 0x9c, 
	0x8b, 0xfa, 
	0x4f, 0x6a, 
	0x3f, 0xf4, 
	0x4f, 0xc4, 
	0x44, 0x88, 
	0x38, 0x70	};

BMP frameMario2[] = { 
	0x07, 0xc0, 
	0x08, 0x38, 
	0x13, 0xc4, 
	0x1c, 0xb8, 
	0x26, 0x84, 
	0x26, 0x44, 
	0x18, 0xf8, 
	0x7c, 0x1e, 
	0x93, 0xe9, 
	0x91, 0x99, 
	0x53, 0xfa, 
	0x3f, 0x6c, 
	0x3f, 0xf4, 
	0x4f, 0xc4, 
	0x44, 0x88, 
	0x38, 0x70	};

BMP frameMario3[] = { 
	0x07, 0xce, 
	0x08, 0x31, 
	0x11, 0xc9, 
	0x1e, 0xba, 
	0x26, 0x86, 
	0x26, 0x46, 
	0x18, 0xfc, 
	0x0c, 0x14, 
	0x3f, 0xe8, 
	0x71, 0x9e, 
	0x89, 0x69, 
	0x8b, 0xf1, 
	0x7f, 0xf2, 
	0x8f, 0xf2, 
	0x9f, 0x8c, 
	0x6e, 0x00	};

BMP frameMario4[] = { 
	0x00, 0x00, 
	0x07, 0xe0, 
	0x18, 0x10, 
	0x23, 0xc8, 
	0x1d, 0x38, 
	0x21, 0x64, 
	0x22, 0x64, 
	0x1f, 0x18, 
	0x08, 0x30, 
	0x07, 0xc8, 
	0x09, 0x84, 
	0x0f, 0xf4, 
	0x0d, 0x88, 
	0x0e, 0x48, 
	0x04, 0x30, 
	0x03, 0xe0	};

BMP frameMario5[] = { 
	0x03, 0xe0, 
	0x1c, 0x10, 
	0x23, 0xc8, 
	0x1d, 0x38, 
	0x21, 0x64, 
	0x22, 0x64, 
	0x1f, 0x18, 
	0x08, 0x38, 
	0x1f, 0xc6, 
	0x39, 0x89, 
	0x5f, 0xd1, 
	0x56, 0xf2, 
	0x2f, 0xfc, 
	0x23, 0xf2, 
	0x11, 0x22, 
	0x0e, 0x1c	};

BMP frameMario6[] = { 
	0x03, 0xe0, 
	0x1c, 0x10, 
	0x23, 0xc8, 
	0x1d, 0x38, 
	0x21, 0x64, 
	0x22, 0x64, 
	0x1f, 0x18, 
	0x78, 0x3e, 
	0x97, 0xc9, 
	0x99, 0x89, 
	0x5f, 0xca, 
	0x36, 0xfc, 
	0x2f, 0xfc, 
	0x23, 0xf2, 
	0x11, 0x22, 
	0x0e, 0x1c	};

BMP frameMario7[] = { 
	0x73, 0xe0, 
	0x8c, 0x10, 
	0x93, 0x88, 
	0x5d, 0x78, 
	0x61, 0x64, 
	0x62, 0x64, 
	0x3f, 0x18, 
	0x28, 0x30, 
	0x17, 0xfc, 
	0x79, 0x8e, 
	0x96, 0x91, 
	0x8f, 0xd1, 
	0x4f, 0xfe, 
	0x4f, 0xf1, 
	0x31, 0xf9, 
	0x00, 0x76	};

#endif
