#ifndef _BE_ST_EGA_LOOKUP_TABLES_
#define _BE_ST_EGA_LOOKUP_TABLES_

// Currently used internally in one compilation unit only

#include "be_cross.h"

static const uint64_t g_be_st_lookup_repeat[256] = {
	// These are endianness-independent
	0x0000000000000000,
	0x0101010101010101,
	0x0202020202020202,
	0x0303030303030303,
	0x0404040404040404,
	0x0505050505050505,
	0x0606060606060606,
	0x0707070707070707,
	0x0808080808080808,
	0x0909090909090909,
	0x0a0a0a0a0a0a0a0a,
	0x0b0b0b0b0b0b0b0b,
	0x0c0c0c0c0c0c0c0c,
	0x0d0d0d0d0d0d0d0d,
	0x0e0e0e0e0e0e0e0e,
	0x0f0f0f0f0f0f0f0f,
	0x1010101010101010,
	0x1111111111111111,
	0x1212121212121212,
	0x1313131313131313,
	0x1414141414141414,
	0x1515151515151515,
	0x1616161616161616,
	0x1717171717171717,
	0x1818181818181818,
	0x1919191919191919,
	0x1a1a1a1a1a1a1a1a,
	0x1b1b1b1b1b1b1b1b,
	0x1c1c1c1c1c1c1c1c,
	0x1d1d1d1d1d1d1d1d,
	0x1e1e1e1e1e1e1e1e,
	0x1f1f1f1f1f1f1f1f,
	0x2020202020202020,
	0x2121212121212121,
	0x2222222222222222,
	0x2323232323232323,
	0x2424242424242424,
	0x2525252525252525,
	0x2626262626262626,
	0x2727272727272727,
	0x2828282828282828,
	0x2929292929292929,
	0x2a2a2a2a2a2a2a2a,
	0x2b2b2b2b2b2b2b2b,
	0x2c2c2c2c2c2c2c2c,
	0x2d2d2d2d2d2d2d2d,
	0x2e2e2e2e2e2e2e2e,
	0x2f2f2f2f2f2f2f2f,
	0x3030303030303030,
	0x3131313131313131,
	0x3232323232323232,
	0x3333333333333333,
	0x3434343434343434,
	0x3535353535353535,
	0x3636363636363636,
	0x3737373737373737,
	0x3838383838383838,
	0x3939393939393939,
	0x3a3a3a3a3a3a3a3a,
	0x3b3b3b3b3b3b3b3b,
	0x3c3c3c3c3c3c3c3c,
	0x3d3d3d3d3d3d3d3d,
	0x3e3e3e3e3e3e3e3e,
	0x3f3f3f3f3f3f3f3f,
	0x4040404040404040,
	0x4141414141414141,
	0x4242424242424242,
	0x4343434343434343,
	0x4444444444444444,
	0x4545454545454545,
	0x4646464646464646,
	0x4747474747474747,
	0x4848484848484848,
	0x4949494949494949,
	0x4a4a4a4a4a4a4a4a,
	0x4b4b4b4b4b4b4b4b,
	0x4c4c4c4c4c4c4c4c,
	0x4d4d4d4d4d4d4d4d,
	0x4e4e4e4e4e4e4e4e,
	0x4f4f4f4f4f4f4f4f,
	0x5050505050505050,
	0x5151515151515151,
	0x5252525252525252,
	0x5353535353535353,
	0x5454545454545454,
	0x5555555555555555,
	0x5656565656565656,
	0x5757575757575757,
	0x5858585858585858,
	0x5959595959595959,
	0x5a5a5a5a5a5a5a5a,
	0x5b5b5b5b5b5b5b5b,
	0x5c5c5c5c5c5c5c5c,
	0x5d5d5d5d5d5d5d5d,
	0x5e5e5e5e5e5e5e5e,
	0x5f5f5f5f5f5f5f5f,
	0x6060606060606060,
	0x6161616161616161,
	0x6262626262626262,
	0x6363636363636363,
	0x6464646464646464,
	0x6565656565656565,
	0x6666666666666666,
	0x6767676767676767,
	0x6868686868686868,
	0x6969696969696969,
	0x6a6a6a6a6a6a6a6a,
	0x6b6b6b6b6b6b6b6b,
	0x6c6c6c6c6c6c6c6c,
	0x6d6d6d6d6d6d6d6d,
	0x6e6e6e6e6e6e6e6e,
	0x6f6f6f6f6f6f6f6f,
	0x7070707070707070,
	0x7171717171717171,
	0x7272727272727272,
	0x7373737373737373,
	0x7474747474747474,
	0x7575757575757575,
	0x7676767676767676,
	0x7777777777777777,
	0x7878787878787878,
	0x7979797979797979,
	0x7a7a7a7a7a7a7a7a,
	0x7b7b7b7b7b7b7b7b,
	0x7c7c7c7c7c7c7c7c,
	0x7d7d7d7d7d7d7d7d,
	0x7e7e7e7e7e7e7e7e,
	0x7f7f7f7f7f7f7f7f,
	0x8080808080808080,
	0x8181818181818181,
	0x8282828282828282,
	0x8383838383838383,
	0x8484848484848484,
	0x8585858585858585,
	0x8686868686868686,
	0x8787878787878787,
	0x8888888888888888,
	0x8989898989898989,
	0x8a8a8a8a8a8a8a8a,
	0x8b8b8b8b8b8b8b8b,
	0x8c8c8c8c8c8c8c8c,
	0x8d8d8d8d8d8d8d8d,
	0x8e8e8e8e8e8e8e8e,
	0x8f8f8f8f8f8f8f8f,
	0x9090909090909090,
	0x9191919191919191,
	0x9292929292929292,
	0x9393939393939393,
	0x9494949494949494,
	0x9595959595959595,
	0x9696969696969696,
	0x9797979797979797,
	0x9898989898989898,
	0x9999999999999999,
	0x9a9a9a9a9a9a9a9a,
	0x9b9b9b9b9b9b9b9b,
	0x9c9c9c9c9c9c9c9c,
	0x9d9d9d9d9d9d9d9d,
	0x9e9e9e9e9e9e9e9e,
	0x9f9f9f9f9f9f9f9f,
	0xa0a0a0a0a0a0a0a0,
	0xa1a1a1a1a1a1a1a1,
	0xa2a2a2a2a2a2a2a2,
	0xa3a3a3a3a3a3a3a3,
	0xa4a4a4a4a4a4a4a4,
	0xa5a5a5a5a5a5a5a5,
	0xa6a6a6a6a6a6a6a6,
	0xa7a7a7a7a7a7a7a7,
	0xa8a8a8a8a8a8a8a8,
	0xa9a9a9a9a9a9a9a9,
	0xaaaaaaaaaaaaaaaa,
	0xabababababababab,
	0xacacacacacacacac,
	0xadadadadadadadad,
	0xaeaeaeaeaeaeaeae,
	0xafafafafafafafaf,
	0xb0b0b0b0b0b0b0b0,
	0xb1b1b1b1b1b1b1b1,
	0xb2b2b2b2b2b2b2b2,
	0xb3b3b3b3b3b3b3b3,
	0xb4b4b4b4b4b4b4b4,
	0xb5b5b5b5b5b5b5b5,
	0xb6b6b6b6b6b6b6b6,
	0xb7b7b7b7b7b7b7b7,
	0xb8b8b8b8b8b8b8b8,
	0xb9b9b9b9b9b9b9b9,
	0xbabababababababa,
	0xbbbbbbbbbbbbbbbb,
	0xbcbcbcbcbcbcbcbc,
	0xbdbdbdbdbdbdbdbd,
	0xbebebebebebebebe,
	0xbfbfbfbfbfbfbfbf,
	0xc0c0c0c0c0c0c0c0,
	0xc1c1c1c1c1c1c1c1,
	0xc2c2c2c2c2c2c2c2,
	0xc3c3c3c3c3c3c3c3,
	0xc4c4c4c4c4c4c4c4,
	0xc5c5c5c5c5c5c5c5,
	0xc6c6c6c6c6c6c6c6,
	0xc7c7c7c7c7c7c7c7,
	0xc8c8c8c8c8c8c8c8,
	0xc9c9c9c9c9c9c9c9,
	0xcacacacacacacaca,
	0xcbcbcbcbcbcbcbcb,
	0xcccccccccccccccc,
	0xcdcdcdcdcdcdcdcd,
	0xcececececececece,
	0xcfcfcfcfcfcfcfcf,
	0xd0d0d0d0d0d0d0d0,
	0xd1d1d1d1d1d1d1d1,
	0xd2d2d2d2d2d2d2d2,
	0xd3d3d3d3d3d3d3d3,
	0xd4d4d4d4d4d4d4d4,
	0xd5d5d5d5d5d5d5d5,
	0xd6d6d6d6d6d6d6d6,
	0xd7d7d7d7d7d7d7d7,
	0xd8d8d8d8d8d8d8d8,
	0xd9d9d9d9d9d9d9d9,
	0xdadadadadadadada,
	0xdbdbdbdbdbdbdbdb,
	0xdcdcdcdcdcdcdcdc,
	0xdddddddddddddddd,
	0xdededededededede,
	0xdfdfdfdfdfdfdfdf,
	0xe0e0e0e0e0e0e0e0,
	0xe1e1e1e1e1e1e1e1,
	0xe2e2e2e2e2e2e2e2,
	0xe3e3e3e3e3e3e3e3,
	0xe4e4e4e4e4e4e4e4,
	0xe5e5e5e5e5e5e5e5,
	0xe6e6e6e6e6e6e6e6,
	0xe7e7e7e7e7e7e7e7,
	0xe8e8e8e8e8e8e8e8,
	0xe9e9e9e9e9e9e9e9,
	0xeaeaeaeaeaeaeaea,
	0xebebebebebebebeb,
	0xecececececececec,
	0xedededededededed,
	0xeeeeeeeeeeeeeeee,
	0xefefefefefefefef,
	0xf0f0f0f0f0f0f0f0,
	0xf1f1f1f1f1f1f1f1,
	0xf2f2f2f2f2f2f2f2,
	0xf3f3f3f3f3f3f3f3,
	0xf4f4f4f4f4f4f4f4,
	0xf5f5f5f5f5f5f5f5,
	0xf6f6f6f6f6f6f6f6,
	0xf7f7f7f7f7f7f7f7,
	0xf8f8f8f8f8f8f8f8,
	0xf9f9f9f9f9f9f9f9,
	0xfafafafafafafafa,
	0xfbfbfbfbfbfbfbfb,
	0xfcfcfcfcfcfcfcfc,
	0xfdfdfdfdfdfdfdfd,
	0xfefefefefefefefe,
	0xffffffffffffffff,
};

static const uint64_t g_be_st_lookup_linear_to_egaplane[256] = {
	BE_Cross_Swap64LE(0x0000000000000000),
	BE_Cross_Swap64LE(0x0100000000000000),
	BE_Cross_Swap64LE(0x0001000000000000),
	BE_Cross_Swap64LE(0x0101000000000000),
	BE_Cross_Swap64LE(0x0000010000000000),
	BE_Cross_Swap64LE(0x0100010000000000),
	BE_Cross_Swap64LE(0x0001010000000000),
	BE_Cross_Swap64LE(0x0101010000000000),
	BE_Cross_Swap64LE(0x0000000100000000),
	BE_Cross_Swap64LE(0x0100000100000000),
	BE_Cross_Swap64LE(0x0001000100000000),
	BE_Cross_Swap64LE(0x0101000100000000),
	BE_Cross_Swap64LE(0x0000010100000000),
	BE_Cross_Swap64LE(0x0100010100000000),
	BE_Cross_Swap64LE(0x0001010100000000),
	BE_Cross_Swap64LE(0x0101010100000000),
	BE_Cross_Swap64LE(0x0000000001000000),
	BE_Cross_Swap64LE(0x0100000001000000),
	BE_Cross_Swap64LE(0x0001000001000000),
	BE_Cross_Swap64LE(0x0101000001000000),
	BE_Cross_Swap64LE(0x0000010001000000),
	BE_Cross_Swap64LE(0x0100010001000000),
	BE_Cross_Swap64LE(0x0001010001000000),
	BE_Cross_Swap64LE(0x0101010001000000),
	BE_Cross_Swap64LE(0x0000000101000000),
	BE_Cross_Swap64LE(0x0100000101000000),
	BE_Cross_Swap64LE(0x0001000101000000),
	BE_Cross_Swap64LE(0x0101000101000000),
	BE_Cross_Swap64LE(0x0000010101000000),
	BE_Cross_Swap64LE(0x0100010101000000),
	BE_Cross_Swap64LE(0x0001010101000000),
	BE_Cross_Swap64LE(0x0101010101000000),
	BE_Cross_Swap64LE(0x0000000000010000),
	BE_Cross_Swap64LE(0x0100000000010000),
	BE_Cross_Swap64LE(0x0001000000010000),
	BE_Cross_Swap64LE(0x0101000000010000),
	BE_Cross_Swap64LE(0x0000010000010000),
	BE_Cross_Swap64LE(0x0100010000010000),
	BE_Cross_Swap64LE(0x0001010000010000),
	BE_Cross_Swap64LE(0x0101010000010000),
	BE_Cross_Swap64LE(0x0000000100010000),
	BE_Cross_Swap64LE(0x0100000100010000),
	BE_Cross_Swap64LE(0x0001000100010000),
	BE_Cross_Swap64LE(0x0101000100010000),
	BE_Cross_Swap64LE(0x0000010100010000),
	BE_Cross_Swap64LE(0x0100010100010000),
	BE_Cross_Swap64LE(0x0001010100010000),
	BE_Cross_Swap64LE(0x0101010100010000),
	BE_Cross_Swap64LE(0x0000000001010000),
	BE_Cross_Swap64LE(0x0100000001010000),
	BE_Cross_Swap64LE(0x0001000001010000),
	BE_Cross_Swap64LE(0x0101000001010000),
	BE_Cross_Swap64LE(0x0000010001010000),
	BE_Cross_Swap64LE(0x0100010001010000),
	BE_Cross_Swap64LE(0x0001010001010000),
	BE_Cross_Swap64LE(0x0101010001010000),
	BE_Cross_Swap64LE(0x0000000101010000),
	BE_Cross_Swap64LE(0x0100000101010000),
	BE_Cross_Swap64LE(0x0001000101010000),
	BE_Cross_Swap64LE(0x0101000101010000),
	BE_Cross_Swap64LE(0x0000010101010000),
	BE_Cross_Swap64LE(0x0100010101010000),
	BE_Cross_Swap64LE(0x0001010101010000),
	BE_Cross_Swap64LE(0x0101010101010000),
	BE_Cross_Swap64LE(0x0000000000000100),
	BE_Cross_Swap64LE(0x0100000000000100),
	BE_Cross_Swap64LE(0x0001000000000100),
	BE_Cross_Swap64LE(0x0101000000000100),
	BE_Cross_Swap64LE(0x0000010000000100),
	BE_Cross_Swap64LE(0x0100010000000100),
	BE_Cross_Swap64LE(0x0001010000000100),
	BE_Cross_Swap64LE(0x0101010000000100),
	BE_Cross_Swap64LE(0x0000000100000100),
	BE_Cross_Swap64LE(0x0100000100000100),
	BE_Cross_Swap64LE(0x0001000100000100),
	BE_Cross_Swap64LE(0x0101000100000100),
	BE_Cross_Swap64LE(0x0000010100000100),
	BE_Cross_Swap64LE(0x0100010100000100),
	BE_Cross_Swap64LE(0x0001010100000100),
	BE_Cross_Swap64LE(0x0101010100000100),
	BE_Cross_Swap64LE(0x0000000001000100),
	BE_Cross_Swap64LE(0x0100000001000100),
	BE_Cross_Swap64LE(0x0001000001000100),
	BE_Cross_Swap64LE(0x0101000001000100),
	BE_Cross_Swap64LE(0x0000010001000100),
	BE_Cross_Swap64LE(0x0100010001000100),
	BE_Cross_Swap64LE(0x0001010001000100),
	BE_Cross_Swap64LE(0x0101010001000100),
	BE_Cross_Swap64LE(0x0000000101000100),
	BE_Cross_Swap64LE(0x0100000101000100),
	BE_Cross_Swap64LE(0x0001000101000100),
	BE_Cross_Swap64LE(0x0101000101000100),
	BE_Cross_Swap64LE(0x0000010101000100),
	BE_Cross_Swap64LE(0x0100010101000100),
	BE_Cross_Swap64LE(0x0001010101000100),
	BE_Cross_Swap64LE(0x0101010101000100),
	BE_Cross_Swap64LE(0x0000000000010100),
	BE_Cross_Swap64LE(0x0100000000010100),
	BE_Cross_Swap64LE(0x0001000000010100),
	BE_Cross_Swap64LE(0x0101000000010100),
	BE_Cross_Swap64LE(0x0000010000010100),
	BE_Cross_Swap64LE(0x0100010000010100),
	BE_Cross_Swap64LE(0x0001010000010100),
	BE_Cross_Swap64LE(0x0101010000010100),
	BE_Cross_Swap64LE(0x0000000100010100),
	BE_Cross_Swap64LE(0x0100000100010100),
	BE_Cross_Swap64LE(0x0001000100010100),
	BE_Cross_Swap64LE(0x0101000100010100),
	BE_Cross_Swap64LE(0x0000010100010100),
	BE_Cross_Swap64LE(0x0100010100010100),
	BE_Cross_Swap64LE(0x0001010100010100),
	BE_Cross_Swap64LE(0x0101010100010100),
	BE_Cross_Swap64LE(0x0000000001010100),
	BE_Cross_Swap64LE(0x0100000001010100),
	BE_Cross_Swap64LE(0x0001000001010100),
	BE_Cross_Swap64LE(0x0101000001010100),
	BE_Cross_Swap64LE(0x0000010001010100),
	BE_Cross_Swap64LE(0x0100010001010100),
	BE_Cross_Swap64LE(0x0001010001010100),
	BE_Cross_Swap64LE(0x0101010001010100),
	BE_Cross_Swap64LE(0x0000000101010100),
	BE_Cross_Swap64LE(0x0100000101010100),
	BE_Cross_Swap64LE(0x0001000101010100),
	BE_Cross_Swap64LE(0x0101000101010100),
	BE_Cross_Swap64LE(0x0000010101010100),
	BE_Cross_Swap64LE(0x0100010101010100),
	BE_Cross_Swap64LE(0x0001010101010100),
	BE_Cross_Swap64LE(0x0101010101010100),
	BE_Cross_Swap64LE(0x0000000000000001),
	BE_Cross_Swap64LE(0x0100000000000001),
	BE_Cross_Swap64LE(0x0001000000000001),
	BE_Cross_Swap64LE(0x0101000000000001),
	BE_Cross_Swap64LE(0x0000010000000001),
	BE_Cross_Swap64LE(0x0100010000000001),
	BE_Cross_Swap64LE(0x0001010000000001),
	BE_Cross_Swap64LE(0x0101010000000001),
	BE_Cross_Swap64LE(0x0000000100000001),
	BE_Cross_Swap64LE(0x0100000100000001),
	BE_Cross_Swap64LE(0x0001000100000001),
	BE_Cross_Swap64LE(0x0101000100000001),
	BE_Cross_Swap64LE(0x0000010100000001),
	BE_Cross_Swap64LE(0x0100010100000001),
	BE_Cross_Swap64LE(0x0001010100000001),
	BE_Cross_Swap64LE(0x0101010100000001),
	BE_Cross_Swap64LE(0x0000000001000001),
	BE_Cross_Swap64LE(0x0100000001000001),
	BE_Cross_Swap64LE(0x0001000001000001),
	BE_Cross_Swap64LE(0x0101000001000001),
	BE_Cross_Swap64LE(0x0000010001000001),
	BE_Cross_Swap64LE(0x0100010001000001),
	BE_Cross_Swap64LE(0x0001010001000001),
	BE_Cross_Swap64LE(0x0101010001000001),
	BE_Cross_Swap64LE(0x0000000101000001),
	BE_Cross_Swap64LE(0x0100000101000001),
	BE_Cross_Swap64LE(0x0001000101000001),
	BE_Cross_Swap64LE(0x0101000101000001),
	BE_Cross_Swap64LE(0x0000010101000001),
	BE_Cross_Swap64LE(0x0100010101000001),
	BE_Cross_Swap64LE(0x0001010101000001),
	BE_Cross_Swap64LE(0x0101010101000001),
	BE_Cross_Swap64LE(0x0000000000010001),
	BE_Cross_Swap64LE(0x0100000000010001),
	BE_Cross_Swap64LE(0x0001000000010001),
	BE_Cross_Swap64LE(0x0101000000010001),
	BE_Cross_Swap64LE(0x0000010000010001),
	BE_Cross_Swap64LE(0x0100010000010001),
	BE_Cross_Swap64LE(0x0001010000010001),
	BE_Cross_Swap64LE(0x0101010000010001),
	BE_Cross_Swap64LE(0x0000000100010001),
	BE_Cross_Swap64LE(0x0100000100010001),
	BE_Cross_Swap64LE(0x0001000100010001),
	BE_Cross_Swap64LE(0x0101000100010001),
	BE_Cross_Swap64LE(0x0000010100010001),
	BE_Cross_Swap64LE(0x0100010100010001),
	BE_Cross_Swap64LE(0x0001010100010001),
	BE_Cross_Swap64LE(0x0101010100010001),
	BE_Cross_Swap64LE(0x0000000001010001),
	BE_Cross_Swap64LE(0x0100000001010001),
	BE_Cross_Swap64LE(0x0001000001010001),
	BE_Cross_Swap64LE(0x0101000001010001),
	BE_Cross_Swap64LE(0x0000010001010001),
	BE_Cross_Swap64LE(0x0100010001010001),
	BE_Cross_Swap64LE(0x0001010001010001),
	BE_Cross_Swap64LE(0x0101010001010001),
	BE_Cross_Swap64LE(0x0000000101010001),
	BE_Cross_Swap64LE(0x0100000101010001),
	BE_Cross_Swap64LE(0x0001000101010001),
	BE_Cross_Swap64LE(0x0101000101010001),
	BE_Cross_Swap64LE(0x0000010101010001),
	BE_Cross_Swap64LE(0x0100010101010001),
	BE_Cross_Swap64LE(0x0001010101010001),
	BE_Cross_Swap64LE(0x0101010101010001),
	BE_Cross_Swap64LE(0x0000000000000101),
	BE_Cross_Swap64LE(0x0100000000000101),
	BE_Cross_Swap64LE(0x0001000000000101),
	BE_Cross_Swap64LE(0x0101000000000101),
	BE_Cross_Swap64LE(0x0000010000000101),
	BE_Cross_Swap64LE(0x0100010000000101),
	BE_Cross_Swap64LE(0x0001010000000101),
	BE_Cross_Swap64LE(0x0101010000000101),
	BE_Cross_Swap64LE(0x0000000100000101),
	BE_Cross_Swap64LE(0x0100000100000101),
	BE_Cross_Swap64LE(0x0001000100000101),
	BE_Cross_Swap64LE(0x0101000100000101),
	BE_Cross_Swap64LE(0x0000010100000101),
	BE_Cross_Swap64LE(0x0100010100000101),
	BE_Cross_Swap64LE(0x0001010100000101),
	BE_Cross_Swap64LE(0x0101010100000101),
	BE_Cross_Swap64LE(0x0000000001000101),
	BE_Cross_Swap64LE(0x0100000001000101),
	BE_Cross_Swap64LE(0x0001000001000101),
	BE_Cross_Swap64LE(0x0101000001000101),
	BE_Cross_Swap64LE(0x0000010001000101),
	BE_Cross_Swap64LE(0x0100010001000101),
	BE_Cross_Swap64LE(0x0001010001000101),
	BE_Cross_Swap64LE(0x0101010001000101),
	BE_Cross_Swap64LE(0x0000000101000101),
	BE_Cross_Swap64LE(0x0100000101000101),
	BE_Cross_Swap64LE(0x0001000101000101),
	BE_Cross_Swap64LE(0x0101000101000101),
	BE_Cross_Swap64LE(0x0000010101000101),
	BE_Cross_Swap64LE(0x0100010101000101),
	BE_Cross_Swap64LE(0x0001010101000101),
	BE_Cross_Swap64LE(0x0101010101000101),
	BE_Cross_Swap64LE(0x0000000000010101),
	BE_Cross_Swap64LE(0x0100000000010101),
	BE_Cross_Swap64LE(0x0001000000010101),
	BE_Cross_Swap64LE(0x0101000000010101),
	BE_Cross_Swap64LE(0x0000010000010101),
	BE_Cross_Swap64LE(0x0100010000010101),
	BE_Cross_Swap64LE(0x0001010000010101),
	BE_Cross_Swap64LE(0x0101010000010101),
	BE_Cross_Swap64LE(0x0000000100010101),
	BE_Cross_Swap64LE(0x0100000100010101),
	BE_Cross_Swap64LE(0x0001000100010101),
	BE_Cross_Swap64LE(0x0101000100010101),
	BE_Cross_Swap64LE(0x0000010100010101),
	BE_Cross_Swap64LE(0x0100010100010101),
	BE_Cross_Swap64LE(0x0001010100010101),
	BE_Cross_Swap64LE(0x0101010100010101),
	BE_Cross_Swap64LE(0x0000000001010101),
	BE_Cross_Swap64LE(0x0100000001010101),
	BE_Cross_Swap64LE(0x0001000001010101),
	BE_Cross_Swap64LE(0x0101000001010101),
	BE_Cross_Swap64LE(0x0000010001010101),
	BE_Cross_Swap64LE(0x0100010001010101),
	BE_Cross_Swap64LE(0x0001010001010101),
	BE_Cross_Swap64LE(0x0101010001010101),
	BE_Cross_Swap64LE(0x0000000101010101),
	BE_Cross_Swap64LE(0x0100000101010101),
	BE_Cross_Swap64LE(0x0001000101010101),
	BE_Cross_Swap64LE(0x0101000101010101),
	BE_Cross_Swap64LE(0x0000010101010101),
	BE_Cross_Swap64LE(0x0100010101010101),
	BE_Cross_Swap64LE(0x0001010101010101),
	BE_Cross_Swap64LE(0x0101010101010101),
};

// Not exactly a lookup table, but shouldn't be used often
static uint8_t BEL_ST_Lookup_EGAPlaneToLinear(uint64_t val)
{
	val &= 0x0101010101010101ULL;
	// Thanks to cast, this is system endianess independent
	// (assuming a specific internal byte-order for the *input*)
	const uint8_t *valBuffer = (uint8_t *)&val;
	return (
		(valBuffer[0] << 7) |
		(valBuffer[1] << 6) |
		(valBuffer[2] << 5) |
		(valBuffer[3] << 4) |
		(valBuffer[4] << 3) |
		(valBuffer[5] << 2) |
		(valBuffer[6] << 1) |
		(valBuffer[7])
	);
}

static const uint64_t g_be_st_lookup_bitsmask[256] = {
	BE_Cross_Swap64LE(0x0000000000000000),
	BE_Cross_Swap64LE(0xff00000000000000),
	BE_Cross_Swap64LE(0x00ff000000000000),
	BE_Cross_Swap64LE(0xffff000000000000),
	BE_Cross_Swap64LE(0x0000ff0000000000),
	BE_Cross_Swap64LE(0xff00ff0000000000),
	BE_Cross_Swap64LE(0x00ffff0000000000),
	BE_Cross_Swap64LE(0xffffff0000000000),
	BE_Cross_Swap64LE(0x000000ff00000000),
	BE_Cross_Swap64LE(0xff0000ff00000000),
	BE_Cross_Swap64LE(0x00ff00ff00000000),
	BE_Cross_Swap64LE(0xffff00ff00000000),
	BE_Cross_Swap64LE(0x0000ffff00000000),
	BE_Cross_Swap64LE(0xff00ffff00000000),
	BE_Cross_Swap64LE(0x00ffffff00000000),
	BE_Cross_Swap64LE(0xffffffff00000000),
	BE_Cross_Swap64LE(0x00000000ff000000),
	BE_Cross_Swap64LE(0xff000000ff000000),
	BE_Cross_Swap64LE(0x00ff0000ff000000),
	BE_Cross_Swap64LE(0xffff0000ff000000),
	BE_Cross_Swap64LE(0x0000ff00ff000000),
	BE_Cross_Swap64LE(0xff00ff00ff000000),
	BE_Cross_Swap64LE(0x00ffff00ff000000),
	BE_Cross_Swap64LE(0xffffff00ff000000),
	BE_Cross_Swap64LE(0x000000ffff000000),
	BE_Cross_Swap64LE(0xff0000ffff000000),
	BE_Cross_Swap64LE(0x00ff00ffff000000),
	BE_Cross_Swap64LE(0xffff00ffff000000),
	BE_Cross_Swap64LE(0x0000ffffff000000),
	BE_Cross_Swap64LE(0xff00ffffff000000),
	BE_Cross_Swap64LE(0x00ffffffff000000),
	BE_Cross_Swap64LE(0xffffffffff000000),
	BE_Cross_Swap64LE(0x0000000000ff0000),
	BE_Cross_Swap64LE(0xff00000000ff0000),
	BE_Cross_Swap64LE(0x00ff000000ff0000),
	BE_Cross_Swap64LE(0xffff000000ff0000),
	BE_Cross_Swap64LE(0x0000ff0000ff0000),
	BE_Cross_Swap64LE(0xff00ff0000ff0000),
	BE_Cross_Swap64LE(0x00ffff0000ff0000),
	BE_Cross_Swap64LE(0xffffff0000ff0000),
	BE_Cross_Swap64LE(0x000000ff00ff0000),
	BE_Cross_Swap64LE(0xff0000ff00ff0000),
	BE_Cross_Swap64LE(0x00ff00ff00ff0000),
	BE_Cross_Swap64LE(0xffff00ff00ff0000),
	BE_Cross_Swap64LE(0x0000ffff00ff0000),
	BE_Cross_Swap64LE(0xff00ffff00ff0000),
	BE_Cross_Swap64LE(0x00ffffff00ff0000),
	BE_Cross_Swap64LE(0xffffffff00ff0000),
	BE_Cross_Swap64LE(0x00000000ffff0000),
	BE_Cross_Swap64LE(0xff000000ffff0000),
	BE_Cross_Swap64LE(0x00ff0000ffff0000),
	BE_Cross_Swap64LE(0xffff0000ffff0000),
	BE_Cross_Swap64LE(0x0000ff00ffff0000),
	BE_Cross_Swap64LE(0xff00ff00ffff0000),
	BE_Cross_Swap64LE(0x00ffff00ffff0000),
	BE_Cross_Swap64LE(0xffffff00ffff0000),
	BE_Cross_Swap64LE(0x000000ffffff0000),
	BE_Cross_Swap64LE(0xff0000ffffff0000),
	BE_Cross_Swap64LE(0x00ff00ffffff0000),
	BE_Cross_Swap64LE(0xffff00ffffff0000),
	BE_Cross_Swap64LE(0x0000ffffffff0000),
	BE_Cross_Swap64LE(0xff00ffffffff0000),
	BE_Cross_Swap64LE(0x00ffffffffff0000),
	BE_Cross_Swap64LE(0xffffffffffff0000),
	BE_Cross_Swap64LE(0x000000000000ff00),
	BE_Cross_Swap64LE(0xff0000000000ff00),
	BE_Cross_Swap64LE(0x00ff00000000ff00),
	BE_Cross_Swap64LE(0xffff00000000ff00),
	BE_Cross_Swap64LE(0x0000ff000000ff00),
	BE_Cross_Swap64LE(0xff00ff000000ff00),
	BE_Cross_Swap64LE(0x00ffff000000ff00),
	BE_Cross_Swap64LE(0xffffff000000ff00),
	BE_Cross_Swap64LE(0x000000ff0000ff00),
	BE_Cross_Swap64LE(0xff0000ff0000ff00),
	BE_Cross_Swap64LE(0x00ff00ff0000ff00),
	BE_Cross_Swap64LE(0xffff00ff0000ff00),
	BE_Cross_Swap64LE(0x0000ffff0000ff00),
	BE_Cross_Swap64LE(0xff00ffff0000ff00),
	BE_Cross_Swap64LE(0x00ffffff0000ff00),
	BE_Cross_Swap64LE(0xffffffff0000ff00),
	BE_Cross_Swap64LE(0x00000000ff00ff00),
	BE_Cross_Swap64LE(0xff000000ff00ff00),
	BE_Cross_Swap64LE(0x00ff0000ff00ff00),
	BE_Cross_Swap64LE(0xffff0000ff00ff00),
	BE_Cross_Swap64LE(0x0000ff00ff00ff00),
	BE_Cross_Swap64LE(0xff00ff00ff00ff00),
	BE_Cross_Swap64LE(0x00ffff00ff00ff00),
	BE_Cross_Swap64LE(0xffffff00ff00ff00),
	BE_Cross_Swap64LE(0x000000ffff00ff00),
	BE_Cross_Swap64LE(0xff0000ffff00ff00),
	BE_Cross_Swap64LE(0x00ff00ffff00ff00),
	BE_Cross_Swap64LE(0xffff00ffff00ff00),
	BE_Cross_Swap64LE(0x0000ffffff00ff00),
	BE_Cross_Swap64LE(0xff00ffffff00ff00),
	BE_Cross_Swap64LE(0x00ffffffff00ff00),
	BE_Cross_Swap64LE(0xffffffffff00ff00),
	BE_Cross_Swap64LE(0x0000000000ffff00),
	BE_Cross_Swap64LE(0xff00000000ffff00),
	BE_Cross_Swap64LE(0x00ff000000ffff00),
	BE_Cross_Swap64LE(0xffff000000ffff00),
	BE_Cross_Swap64LE(0x0000ff0000ffff00),
	BE_Cross_Swap64LE(0xff00ff0000ffff00),
	BE_Cross_Swap64LE(0x00ffff0000ffff00),
	BE_Cross_Swap64LE(0xffffff0000ffff00),
	BE_Cross_Swap64LE(0x000000ff00ffff00),
	BE_Cross_Swap64LE(0xff0000ff00ffff00),
	BE_Cross_Swap64LE(0x00ff00ff00ffff00),
	BE_Cross_Swap64LE(0xffff00ff00ffff00),
	BE_Cross_Swap64LE(0x0000ffff00ffff00),
	BE_Cross_Swap64LE(0xff00ffff00ffff00),
	BE_Cross_Swap64LE(0x00ffffff00ffff00),
	BE_Cross_Swap64LE(0xffffffff00ffff00),
	BE_Cross_Swap64LE(0x00000000ffffff00),
	BE_Cross_Swap64LE(0xff000000ffffff00),
	BE_Cross_Swap64LE(0x00ff0000ffffff00),
	BE_Cross_Swap64LE(0xffff0000ffffff00),
	BE_Cross_Swap64LE(0x0000ff00ffffff00),
	BE_Cross_Swap64LE(0xff00ff00ffffff00),
	BE_Cross_Swap64LE(0x00ffff00ffffff00),
	BE_Cross_Swap64LE(0xffffff00ffffff00),
	BE_Cross_Swap64LE(0x000000ffffffff00),
	BE_Cross_Swap64LE(0xff0000ffffffff00),
	BE_Cross_Swap64LE(0x00ff00ffffffff00),
	BE_Cross_Swap64LE(0xffff00ffffffff00),
	BE_Cross_Swap64LE(0x0000ffffffffff00),
	BE_Cross_Swap64LE(0xff00ffffffffff00),
	BE_Cross_Swap64LE(0x00ffffffffffff00),
	BE_Cross_Swap64LE(0xffffffffffffff00),
	BE_Cross_Swap64LE(0x00000000000000ff),
	BE_Cross_Swap64LE(0xff000000000000ff),
	BE_Cross_Swap64LE(0x00ff0000000000ff),
	BE_Cross_Swap64LE(0xffff0000000000ff),
	BE_Cross_Swap64LE(0x0000ff00000000ff),
	BE_Cross_Swap64LE(0xff00ff00000000ff),
	BE_Cross_Swap64LE(0x00ffff00000000ff),
	BE_Cross_Swap64LE(0xffffff00000000ff),
	BE_Cross_Swap64LE(0x000000ff000000ff),
	BE_Cross_Swap64LE(0xff0000ff000000ff),
	BE_Cross_Swap64LE(0x00ff00ff000000ff),
	BE_Cross_Swap64LE(0xffff00ff000000ff),
	BE_Cross_Swap64LE(0x0000ffff000000ff),
	BE_Cross_Swap64LE(0xff00ffff000000ff),
	BE_Cross_Swap64LE(0x00ffffff000000ff),
	BE_Cross_Swap64LE(0xffffffff000000ff),
	BE_Cross_Swap64LE(0x00000000ff0000ff),
	BE_Cross_Swap64LE(0xff000000ff0000ff),
	BE_Cross_Swap64LE(0x00ff0000ff0000ff),
	BE_Cross_Swap64LE(0xffff0000ff0000ff),
	BE_Cross_Swap64LE(0x0000ff00ff0000ff),
	BE_Cross_Swap64LE(0xff00ff00ff0000ff),
	BE_Cross_Swap64LE(0x00ffff00ff0000ff),
	BE_Cross_Swap64LE(0xffffff00ff0000ff),
	BE_Cross_Swap64LE(0x000000ffff0000ff),
	BE_Cross_Swap64LE(0xff0000ffff0000ff),
	BE_Cross_Swap64LE(0x00ff00ffff0000ff),
	BE_Cross_Swap64LE(0xffff00ffff0000ff),
	BE_Cross_Swap64LE(0x0000ffffff0000ff),
	BE_Cross_Swap64LE(0xff00ffffff0000ff),
	BE_Cross_Swap64LE(0x00ffffffff0000ff),
	BE_Cross_Swap64LE(0xffffffffff0000ff),
	BE_Cross_Swap64LE(0x0000000000ff00ff),
	BE_Cross_Swap64LE(0xff00000000ff00ff),
	BE_Cross_Swap64LE(0x00ff000000ff00ff),
	BE_Cross_Swap64LE(0xffff000000ff00ff),
	BE_Cross_Swap64LE(0x0000ff0000ff00ff),
	BE_Cross_Swap64LE(0xff00ff0000ff00ff),
	BE_Cross_Swap64LE(0x00ffff0000ff00ff),
	BE_Cross_Swap64LE(0xffffff0000ff00ff),
	BE_Cross_Swap64LE(0x000000ff00ff00ff),
	BE_Cross_Swap64LE(0xff0000ff00ff00ff),
	BE_Cross_Swap64LE(0x00ff00ff00ff00ff),
	BE_Cross_Swap64LE(0xffff00ff00ff00ff),
	BE_Cross_Swap64LE(0x0000ffff00ff00ff),
	BE_Cross_Swap64LE(0xff00ffff00ff00ff),
	BE_Cross_Swap64LE(0x00ffffff00ff00ff),
	BE_Cross_Swap64LE(0xffffffff00ff00ff),
	BE_Cross_Swap64LE(0x00000000ffff00ff),
	BE_Cross_Swap64LE(0xff000000ffff00ff),
	BE_Cross_Swap64LE(0x00ff0000ffff00ff),
	BE_Cross_Swap64LE(0xffff0000ffff00ff),
	BE_Cross_Swap64LE(0x0000ff00ffff00ff),
	BE_Cross_Swap64LE(0xff00ff00ffff00ff),
	BE_Cross_Swap64LE(0x00ffff00ffff00ff),
	BE_Cross_Swap64LE(0xffffff00ffff00ff),
	BE_Cross_Swap64LE(0x000000ffffff00ff),
	BE_Cross_Swap64LE(0xff0000ffffff00ff),
	BE_Cross_Swap64LE(0x00ff00ffffff00ff),
	BE_Cross_Swap64LE(0xffff00ffffff00ff),
	BE_Cross_Swap64LE(0x0000ffffffff00ff),
	BE_Cross_Swap64LE(0xff00ffffffff00ff),
	BE_Cross_Swap64LE(0x00ffffffffff00ff),
	BE_Cross_Swap64LE(0xffffffffffff00ff),
	BE_Cross_Swap64LE(0x000000000000ffff),
	BE_Cross_Swap64LE(0xff0000000000ffff),
	BE_Cross_Swap64LE(0x00ff00000000ffff),
	BE_Cross_Swap64LE(0xffff00000000ffff),
	BE_Cross_Swap64LE(0x0000ff000000ffff),
	BE_Cross_Swap64LE(0xff00ff000000ffff),
	BE_Cross_Swap64LE(0x00ffff000000ffff),
	BE_Cross_Swap64LE(0xffffff000000ffff),
	BE_Cross_Swap64LE(0x000000ff0000ffff),
	BE_Cross_Swap64LE(0xff0000ff0000ffff),
	BE_Cross_Swap64LE(0x00ff00ff0000ffff),
	BE_Cross_Swap64LE(0xffff00ff0000ffff),
	BE_Cross_Swap64LE(0x0000ffff0000ffff),
	BE_Cross_Swap64LE(0xff00ffff0000ffff),
	BE_Cross_Swap64LE(0x00ffffff0000ffff),
	BE_Cross_Swap64LE(0xffffffff0000ffff),
	BE_Cross_Swap64LE(0x00000000ff00ffff),
	BE_Cross_Swap64LE(0xff000000ff00ffff),
	BE_Cross_Swap64LE(0x00ff0000ff00ffff),
	BE_Cross_Swap64LE(0xffff0000ff00ffff),
	BE_Cross_Swap64LE(0x0000ff00ff00ffff),
	BE_Cross_Swap64LE(0xff00ff00ff00ffff),
	BE_Cross_Swap64LE(0x00ffff00ff00ffff),
	BE_Cross_Swap64LE(0xffffff00ff00ffff),
	BE_Cross_Swap64LE(0x000000ffff00ffff),
	BE_Cross_Swap64LE(0xff0000ffff00ffff),
	BE_Cross_Swap64LE(0x00ff00ffff00ffff),
	BE_Cross_Swap64LE(0xffff00ffff00ffff),
	BE_Cross_Swap64LE(0x0000ffffff00ffff),
	BE_Cross_Swap64LE(0xff00ffffff00ffff),
	BE_Cross_Swap64LE(0x00ffffffff00ffff),
	BE_Cross_Swap64LE(0xffffffffff00ffff),
	BE_Cross_Swap64LE(0x0000000000ffffff),
	BE_Cross_Swap64LE(0xff00000000ffffff),
	BE_Cross_Swap64LE(0x00ff000000ffffff),
	BE_Cross_Swap64LE(0xffff000000ffffff),
	BE_Cross_Swap64LE(0x0000ff0000ffffff),
	BE_Cross_Swap64LE(0xff00ff0000ffffff),
	BE_Cross_Swap64LE(0x00ffff0000ffffff),
	BE_Cross_Swap64LE(0xffffff0000ffffff),
	BE_Cross_Swap64LE(0x000000ff00ffffff),
	BE_Cross_Swap64LE(0xff0000ff00ffffff),
	BE_Cross_Swap64LE(0x00ff00ff00ffffff),
	BE_Cross_Swap64LE(0xffff00ff00ffffff),
	BE_Cross_Swap64LE(0x0000ffff00ffffff),
	BE_Cross_Swap64LE(0xff00ffff00ffffff),
	BE_Cross_Swap64LE(0x00ffffff00ffffff),
	BE_Cross_Swap64LE(0xffffffff00ffffff),
	BE_Cross_Swap64LE(0x00000000ffffffff),
	BE_Cross_Swap64LE(0xff000000ffffffff),
	BE_Cross_Swap64LE(0x00ff0000ffffffff),
	BE_Cross_Swap64LE(0xffff0000ffffffff),
	BE_Cross_Swap64LE(0x0000ff00ffffffff),
	BE_Cross_Swap64LE(0xff00ff00ffffffff),
	BE_Cross_Swap64LE(0x00ffff00ffffffff),
	BE_Cross_Swap64LE(0xffffff00ffffffff),
	BE_Cross_Swap64LE(0x000000ffffffffff),
	BE_Cross_Swap64LE(0xff0000ffffffffff),
	BE_Cross_Swap64LE(0x00ff00ffffffffff),
	BE_Cross_Swap64LE(0xffff00ffffffffff),
	BE_Cross_Swap64LE(0x0000ffffffffffff),
	BE_Cross_Swap64LE(0xff00ffffffffffff),
	BE_Cross_Swap64LE(0x00ffffffffffffff),
	BE_Cross_Swap64LE(0xffffffffffffffff),
};

#endif // _BE_ST_EGA_LOOKUP_TABLES_
