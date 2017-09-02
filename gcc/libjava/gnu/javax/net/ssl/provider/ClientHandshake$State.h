
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_ClientHandshake$State__
#define __gnu_javax_net_ssl_provider_ClientHandshake$State__

#pragma interface

#include <java/lang/Enum.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace net
      {
        namespace ssl
        {
          namespace provider
          {
              class ClientHandshake$State;
          }
        }
      }
    }
  }
}

class gnu::javax::net::ssl::provider::ClientHandshake$State : public ::java::lang::Enum
{

  ClientHandshake$State(::java::lang::String *, jint, jboolean, jboolean);
public: // actually package-private
  jboolean isReadState();
  jboolean isWriteState();
public:
  static JArray< ::gnu::javax::net::ssl::provider::ClientHandshake$State * > * values();
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * valueOf(::java::lang::String *);
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * WRITE_CLIENT_HELLO;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * READ_SERVER_HELLO;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * READ_CERTIFICATE;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * READ_SERVER_KEY_EXCHANGE;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * READ_CERTIFICATE_REQUEST;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * READ_SERVER_HELLO_DONE;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * WRITE_CERTIFICATE;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * WRITE_CLIENT_KEY_EXCHANGE;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * WRITE_CERTIFICATE_VERIFY;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * WRITE_FINISHED;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * READ_FINISHED;
  static ::gnu::javax::net::ssl::provider::ClientHandshake$State * DONE;
private:
  jboolean __attribute__((aligned(__alignof__( ::java::lang::Enum)))) isWriteState__;
  jboolean isReadState__;
  static JArray< ::gnu::javax::net::ssl::provider::ClientHandshake$State * > * ENUM$VALUES;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_ClientHandshake$State__
