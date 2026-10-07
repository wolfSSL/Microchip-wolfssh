/* common.h
 *
 * Copyright (C) 2014-2026 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSH.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#ifndef APPS_WOLFSSH_COMMON_H
#define APPS_WOLFSSH_COMMON_H

WOLFSSH_LOCAL int ClientLoadCA(WOLFSSH_CTX* ctx, const char* caCert);
WOLFSSH_LOCAL int ClientUsePubKey(const char* pubKeyName);
WOLFSSH_LOCAL int ClientSetPrivateKey(const char* privKeyName);
WOLFSSH_LOCAL int ClientUseCert(const char* certName);
WOLFSSH_LOCAL int ClientSetEcho(int type);
WOLFSSH_LOCAL int ClientUserAuth(byte authType, WS_UserAuthData* authData,
        void* ctx);
WOLFSSH_LOCAL int ClientPublicKeyCheck(const byte* pubKey, word32 pubKeySz,
        void* ctx);
WOLFSSH_LOCAL void ClientIPOverride(int flag);
WOLFSSH_LOCAL void ClientFreeBuffers(void);
WOLFSSH_LOCAL int ClientParseDestination(const char* in, char** user,
        char** hostname, word16* port);
#ifdef WOLFSSH_TEST_INTERNAL
WOLFSSH_LOCAL int wolfSSH_TestAppendKeyToFile(const char* filename,
        const char* name, const char* type, const char* key);
#endif

#endif /* APPS_WOLFSSH_COMMON_H */
