/*
* TLS Cipher Suites
* (C) 2004-2011 Jack Lloyd
*
* Released under the terms of the Botan license
*/

#ifndef BOTAN_TLS_CIPHER_SUITES_H__
#define BOTAN_TLS_CIPHER_SUITES_H__

#include <botan/types.h>
#include <botan/tls_magic.h>
#include <string>

namespace Botan {

/**
* Ciphersuite Information
*/
class BOTAN_DLL TLS_Ciphersuite
   {
   public:
      static TLS_Ciphersuite lookup_ciphersuite(u16bit suite);

      const std::string kex_algo() const { return m_kex_algo; }
      const std::string sig_algo() const { return m_sig_algo; }

      std::string cipher_algo() const { return m_cipher_algo; }
      std::string mac_algo() const { return m_mac_algo; }

      size_t cipher_keylen() const { return m_cipher_keylen; }

      TLS_Ciphersuite() : m_cipher_keylen(0) {}

      TLS_Ciphersuite(const std::string& sig_algo,
                      const std::string& kex_algo,
                      const std::string& mac_algo,
                      const std::string& cipher_algo,
                      size_t cipher_algo_keylen);
   private:
      std::string m_sig_algo, m_kex_algo, m_mac_algo, m_cipher_algo;
      size_t m_cipher_keylen;
   };

}

#endif
