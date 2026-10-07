/* misc.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSH.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


#ifndef _WOLFSSH_MISC_H_
#define _WOLFSSH_MISC_H_


#ifdef __cplusplus
    extern "C" {
#endif


#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/memory.h>
#include <wolfssl/version.h>
#include <wolfssh/settings.h>
#include <wolfssh/port.h>


#define WOLFSSL_V5_8_4 0x05008004

#if (LIBWOLFSSL_VERSION_HEX < WOLFSSL_V5_8_4) || \
    defined(WOLFSSL_NO_FORCE_ZERO)
    #define WOLFSSH_NO_FORCEZERO
#endif

#ifdef WOLFSSH_NO_FORCEZERO
    #define WS_FORCEZERO(mem, len) wolfSSH_ForceZero((mem), (len))
#else
    #define WS_FORCEZERO(mem, len) wc_ForceZero((mem), (len))
#endif


#ifdef NO_INLINE


#ifndef min
WOLFSSH_LOCAL word32 min(word32 a, word32 b);
#endif /* min */

WOLFSSH_LOCAL void ato32(const byte* c, word32* u32);
WOLFSSH_LOCAL void c32toa(word32 u32, byte* c);
WOLFSSH_LOCAL int ConstantCompare(const byte* a, const byte* b, word32 length);
#ifdef WOLFSSH_NO_FORCEZERO
WOLFSSH_LOCAL void wolfSSH_ForceZero(void* mem, size_t len);
#endif


#endif /* NO_INLINE */


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* _WOLFSSH_MISC_H_ */

