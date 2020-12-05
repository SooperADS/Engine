#pragma once

#ifndef SDI_libBasicTypesHeader_incleder
#define SDI_libBasicTypesHeader_incleder
#include "../libCore.h"

namespace SDI
{	typedef			char16_t					longChar,
												lChar,
												lchar,
												longByte, 
												lByte,
												lbyte;

	typedef			char32_t					bigChar,
												veryLongChar,
												bigByte,
												veryLongByte,
												bchar, 
												bbyte,
												vlbyte, 
												vlchar, 
												vlongChar, 
												vLongByte;

	typedef			unsigned char				uchar,
												plusChar,
												ubytec,
												plusBytec;

	typedef			signed char					bytec,
												sBytec;

	typedef			unsigned __int8				ubyte,
												plusByte;

	typedef			signed __int8				byte,
												sByte;

	typedef			unsigned short				ushort,
												plusShort;

	typedef			unsigned int				uint,
												plusInt;

	typedef			unsigned long				ulong,
												plusLong;

	typedef			unsigned long long			uvlong,
												plusVLong,
												uverylong,
												plusVeryLong,
												ulonglong,
												plusLongLong;

	typedef			signed long long			vlong,
												vLong,
												verylong,
												veryLong,
												longlong, 
												longLong;

	typedef			long double					ldouble,
												longDouble,
												dicenate;

	typedef			void*						varptr,
												varPtr,
												varPointer,
												pointer,
												Pointer;

	typedef			bool						boolean,
												logic,
												lBitValue; 

	typedef	const	char16_t					cLongChar,
												cLChar,
												cLchar,
												cLongByte,
												cLByte,
												cLbyte;

	typedef	const	char32_t					cBigChar,
												cVeryLongChar,
												cBigByte,
												cVeryLongByte,
												cBchar,
												cBbyte,
												cVlbyte,
												cVlchar,
												cVlongChar,
												cVLongByte;

	typedef	const	unsigned char				cUchar,
												cPlusChar,
												cUbytec,
												cPlusBytec;
												
	typedef	const	signed char					cBytec,
												cSBytec;
												
	typedef	const	unsigned __int8				cUbyte,
												cPlusByte;
												
	typedef	const	signed __int8				cByte,
												cSByte;
												
	typedef	const	unsigned short				cUshort,
												cPlusShort;
												
	typedef	const	unsigned int				cUint,
												cPlusInt;
												
	typedef	const	unsigned long				cUlong,
												cPlusLong;
												
	typedef	const	unsigned long long			cUvlong,
												cPlusVLong,
												cUverylong,
												cPlusVeryLong,
												cUlonglong,
												cPlusLongLong;
												
	typedef	const	signed long long			cVlong,
												cVLong,
												cVerylong,
												cVeryLong,
												cLonglong,
												cLongLong;
												
	typedef	const	long double					cLdouble,
												cLongDouble,
												cDicenate;
												
	typedef	const	void* 						cVarptr,
												cVarPtr,
												cVarPointer,
												cPointer,
												cPointer;
												
	typedef	const	bool						cBoolean,
												cLogic,
												cLBitValue; }

#endif // !SDI_libBasicObjectsHeader_incleder