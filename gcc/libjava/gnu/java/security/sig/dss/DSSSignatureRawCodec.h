
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_security_sig_dss_DSSSignatureRawCodec__
#define __gnu_java_security_sig_dss_DSSSignatureRawCodec__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace security
      {
        namespace sig
        {
          namespace dss
          {
              class DSSSignatureRawCodec;
          }
        }
      }
    }
  }
}

class gnu::java::security::sig::dss::DSSSignatureRawCodec : public ::java::lang::Object
{

public:
  DSSSignatureRawCodec();
  virtual jint getFormatID();
  virtual JArray< jbyte > * encodeSignature(::java::lang::Object *);
  virtual ::java::lang::Object * decodeSignature(JArray< jbyte > *);
  static ::java::lang::Class class$;
};

#endif // __gnu_java_security_sig_dss_DSSSignatureRawCodec__
