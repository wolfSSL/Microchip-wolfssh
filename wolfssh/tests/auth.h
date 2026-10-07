/* auth.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSH.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef _WOLFSSH_TESTS_AUTH_H_
#define _WOLFSSH_TESTS_AUTH_H_

#include <wolfssh/test.h>

int wolfSSH_AuthTest(int argc, char** argv);

typedef struct thread_args {
    int return_code;
    tcp_ready* signal;
    void* pubkeyServerCtx;      /* server callback context for pubkey tests */
    WS_CallbackUserAuth userAuth; /* server userAuth callback; NULL = none */
    const byte* caCert;           /* CA cert for AddRootCert; NULL = skip */
    word32      caCertSz;
    const byte* hostKeyBuf;     /* server host key; NULL = use load_key() */
    word32      hostKeyBufSz;
} thread_args;

#endif /* _WOLFSSH_TESTS_AUTH_H_ */
