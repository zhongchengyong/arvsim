//
// Created by zhong on 12/19/21.
//

#include "decode.hh"
#include "processor.hh"

void arv_core::Decode::Tick() {
  m_processor.FromFetch();
}
