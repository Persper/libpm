
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_JRadioButton__
#define __javax_swing_JRadioButton__

#pragma interface

#include <javax/swing/JToggleButton.h>
extern "Java"
{
  namespace javax
  {
    namespace accessibility
    {
        class AccessibleContext;
    }
    namespace swing
    {
        class Action;
        class Icon;
        class JRadioButton;
    }
  }
}

class javax::swing::JRadioButton : public ::javax::swing::JToggleButton
{

public:
  JRadioButton();
  JRadioButton(::javax::swing::Action *);
  JRadioButton(::javax::swing::Icon *);
  JRadioButton(::javax::swing::Icon *, jboolean);
  JRadioButton(::java::lang::String *);
  JRadioButton(::java::lang::String *, jboolean);
  JRadioButton(::java::lang::String *, ::javax::swing::Icon *);
  JRadioButton(::java::lang::String *, ::javax::swing::Icon *, jboolean);
  virtual ::javax::accessibility::AccessibleContext * getAccessibleContext();
  virtual ::java::lang::String * getUIClassID();
public: // actually protected
  virtual ::java::lang::String * paramString();
public:
  virtual void updateUI();
private:
  static const jlong serialVersionUID = 7751949583255506856LL;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_JRadioButton__