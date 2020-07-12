// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "CryptoNoteCore/Account.h"
#include "CryptoNoteBoostSerialization.h"

//namespace CryptoNote {
namespace boost
{
  namespace serialization
  {
    template <class Archive>
    inline void serialize(Archive &a, CryptoNote::AccountKeys &x, const boost::serialization::version_type ver)
    {
      a & x.address;
      a & x.spendSecretKey;
      a & x.viewSecretKey;
    }

    template <class Archive>
    inline void serialize(Archive &a, CryptoNote::AccountPublicAddress &x, const boost::serialization::version_type ver)
    {
      a & x.spendPublicKey;
      a & x.viewPublicKey;
    }

  }
}
