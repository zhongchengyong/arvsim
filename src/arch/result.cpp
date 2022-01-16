//
// Created by zhong on 1/3/22.
//

#include "result.hh"

void RfResult::Do() {
  m_state.m_xpr.Write(m_rf, m_value);
}
