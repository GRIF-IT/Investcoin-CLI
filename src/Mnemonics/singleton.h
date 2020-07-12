// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

/*!
 * \file singleton.h
 * 
 * \brief A singleton helper class based on template.
 */

/*!
 * \namespace Language
 * \brief Mnemonic language related namespace.
 */
namespace Language
{
  /*!
   * \class Singleton
   * 
   * \brief Single helper class.
   * 
   * Do Language::Singleton<YourClass>::instance() to create a singleton instance
   * of `YourClass`.
   */
  template <class T>
  class Singleton
  {
    Singleton() {}
    Singleton(Singleton &s) {}
    Singleton& operator=(const Singleton&) {}
  public:
    static T* instance()
    {
      static T* obj = new T;
      return obj;
    }
  };
}
