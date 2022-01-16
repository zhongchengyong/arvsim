//
// Created by zhong on 9/20/21.
//
#include "encoding.hh"

#include "instr.hh"

ResultUP AddInstruction::Execute() {
  return std::make_unique<RfResult>(m_state, rd, m_state.m_xpr[rs1] + m_state.m_xpr[rs2]);
}
