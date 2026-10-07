/* keygen.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSH.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */


/*
 * The keygen module contains utility functions wrapping the wolfCrypt
 * key generation functions to product SSH friendly keys.
 */


#ifndef _WOLFSSH_KEYGEN_H_
#define _WOLFSSH_KEYGEN_H_

#include <wolfssh/settings.h>
#include <wolfssh/port.h>

#ifdef __cplusplus
extern "C" {
#endif


#define WOLFSSH_RSAKEY_DEFAULT_SZ 2048
#define WOLFSSH_RSAKEY_DEFAULT_E  65537
#define WOLFSSH_ECDSAKEY_PRIME256 256
#define WOLFSSH_ECDSAKEY_PRIME384 384
#define WOLFSSH_ECDSAKEY_PRIME521 521
#define WOLFSSH_ED25519KEY        256
#define WOLFSSH_MLDSAKEY_44       44
#define WOLFSSH_MLDSAKEY_65       65
#define WOLFSSH_MLDSAKEY_87       87

/* Trad algo paired with ML-DSA level; see WS_GetCompositeParams(). */
#define WOLFSSH_COMPOSITE_TRAD_ECDSA     1
#define WOLFSSH_COMPOSITE_TRAD_ED25519   2
#define WOLFSSH_COMPOSITE_TRAD_ED448     3


WOLFSSH_API int wolfSSH_MakeRsaKey(byte* out, word32 outSz,
        word32 size, word32 e);
WOLFSSH_API int wolfSSH_MakeEcdsaKey(byte* out, word32 outSz, word32 size);
WOLFSSH_API int wolfSSH_MakeEd25519Key(byte* out, word32 outSz, word32 size);
WOLFSSH_API int wolfSSH_MakeMlDsaKey(byte* out, word32 outSz, word32 level);
/* Generate ML-DSA composite key. out=NULL queries length. */
WOLFSSH_API int wolfSSH_MakeMlDsaCompositeKey(byte* out, word32 outSz,
        word32 level, word32 tradType);


#ifdef __cplusplus
}
#endif

#endif /* _WOLFSSH_KEYGEN_H_ */

