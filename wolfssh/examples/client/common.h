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

#ifndef WOLFSSH_COMMON_H
#define WOLFSSH_COMMON_H

#include <wolfssh/ssh.h>
#ifdef WOLFSSH_WINDOWS_CERT_STORE
    #include <wchar.h>
#endif

int ClientLoadCA(WOLFSSH_CTX* ctx, const char* caCert);
int ClientUsePubKey(const char* pubKeyName, int userEcc, void* heap);
int ClientSetPrivateKey(const char* privKeyName, int userEcc,
        void* heap, const char* tpmKeyAuth);
int ClientUseCert(const char* certName, void* heap);
int ClientSetEcho(int type);
int ClientUserAuth(byte authType,
        WS_UserAuthData* authData, void* ctx);
int ClientPublicKeyCheck(const byte* pubKey, word32 pubKeySz, void* ctx);
void ClientIPOverride(int flag);
void ClientFreeBuffers(const char* pubKeyName, const char* privKeyName,
        void* heap);
#ifdef WOLFSSH_TPM
int ClientSetTpm(WOLFSSH* ssh);
#endif
#ifdef WOLFSSH_WINDOWS_CERT_STORE
int ClientSetPrivateKeyFromStore(WOLFSSH_CTX* ctx,
        const wchar_t* storeName, word32 dwFlags, const wchar_t* subjectName);
/* Supersedes ClientUseCert()/ClientUsePubKey()/ClientSetPrivateKey(), any key
 * they loaded is released. Copies the certificate out of ctx; call
 * ClientFreeBuffers() to release the copy. heap must be the same heap
 * previously passed to those loaders and later to ClientFreeBuffers(),
 * since buffers they allocated are freed here. */
int ClientSetupCertStoreAuth(WOLFSSH_CTX* ctx, void* heap);
#endif /* WOLFSSH_WINDOWS_CERT_STORE */

#endif /* WOLFSSH_COMMON_H */

