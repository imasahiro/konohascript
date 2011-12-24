#include "konoha.hpp"
boost::shared_ptr<konoha::System> System;
konoha::Int fib(konoha::Int ival1_0) {
  konoha::Int ival2_2;
  L_0: {
    konoha::Int ival2_0 = 0;
    konoha::Int ival5_0 = 3;
    konoha::Boolean bval3_0 = ival1_0 < ival5_0;
    if (bval3_0) {
        goto L_1;
    } else {
        goto L_2;
    }
  }
  L_1: {
    konoha::Int ival2_1 = 1;
    ival2_2 = ival2_1;
    goto L_3;
  }
  L_2: {
    konoha::Int ival11_0 = 1;
    konoha::Int ival9_0 = ival1_0 - ival11_0;
    konoha::Int ival4_0 = fib(ival9_0);
    konoha::Int ival12_0 = 2;
    konoha::Int ival10_0 = ival1_0 - ival12_0;
    konoha::Int ival5_1 = fib(ival10_0);
    konoha::Int ival3_0 = ival4_0 + ival5_1;
    ival2_2 = ival3_0;
    goto L_3;
  }
  L_3: {
    return ival2_2;
  }
}

void main_(boost::shared_ptr<konoha::Array<boost::shared_ptr<konoha::String > > > ary1_0) {
  konoha::Int ival2_2;
  L_0: {
    boost::shared_ptr<konoha::OutputStream > ous6_0 = System->getOut();
    konoha::Int ival12_0 = 40;
    konoha::Int ival7_0 = fib(ival12_0);
    boost::shared_ptr<konoha::Object > obj7_0 = konoha::cast<konoha::Object>(ival7_0);
    ous6_0->println(obj7_0);
    return ;
  }
}

int main (int argc, const char **argv) {
  boost::shared_ptr<konoha::Array<boost::shared_ptr<konoha::String> > > args(new konoha::Array<boost::shared_ptr<konoha::String> >());
  System.reset(new konoha::System());
  for (int i=0; i < argc; i++) {
      boost::shared_ptr<konoha::String> s(new konoha::String(argv[i]));
      args->append(s);
  }
  main_(args);
  return 0;
}

