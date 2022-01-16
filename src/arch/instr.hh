//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_INSTR_INSTR_HH_
#define ARVSIM_SRC_INSTR_INSTR_HH_

#include "state.hh"
#include "result.hh"

#include <cstdint>
#include <memory>

class Instruction;
using InstrUP = std::unique_ptr<Instruction>;

/**
 * @brief Instruction model, which contains:
 * a) instruction execution.
 */
class Instruction {
 public:
  Instruction() : opcode{} {};
  virtual ResultUP Execute() {};
 private:
  uint32_t opcode;
};

class AddInstruction : public Instruction {
 public:
  explicit AddInstruction(State &state) : m_state{state}, rs1{}, rs2{}, rd{} {}
  ResultUP Execute() override;
 private:
  State m_state;
  uint32_t rs1;
  uint32_t rs2;
  uint32_t rd;
};

#endif //ARVSIM_SRC_INSTR_INSTR_HH_
