
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_DiffieHellman__
#define __gnu_javax_net_ssl_provider_DiffieHellman__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace crypto
      {
        namespace key
        {
          namespace dh
          {
              class GnuDHPrivateKey;
          }
        }
      }
      namespace net
      {
        namespace ssl
        {
          namespace provider
          {
              class DiffieHellman;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace math
    {
        class BigInteger;
    }
  }
}

class gnu::javax::net::ssl::provider::DiffieHellman : public ::java::lang::Object
{

public: // actually package-private
  DiffieHellman();
  static ::gnu::javax::crypto::key::dh::GnuDHPrivateKey * getParams();
  static ::java::math::BigInteger * DH_G;
  static ::java::math::BigInteger * GROUP_1;
  static ::java::math::BigInteger * GROUP_2;
  static ::java::math::BigInteger * GROUP_5;
  static ::java::math::BigInteger * GROUP_14;
  static ::java::math::BigInteger * GROUP_15;
  static ::java::math::BigInteger * GROUP_16;
  static ::java::math::BigInteger * GROUP_17;
  static ::java::math::BigInteger * GROUP_18;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_DiffieHellman__
