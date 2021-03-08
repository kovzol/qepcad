#ifndef _LITTLE_ENDIAN_
#define _LITTLE_ENDIAN_
#endif
#undef _BIG_ENDIAN_
#ifndef _WIN32
#ifndef __APPLE__
#define _X86_LINUX_
#endif // __APPLE__
#endif // _WIN32

#ifdef _WIN32
#define __WORDSIZE 32
#else
#define __WORDSIZE 64
#endif // _WIN32

#ifdef __APPLE__
#define _MAC_OSX_
#endif
