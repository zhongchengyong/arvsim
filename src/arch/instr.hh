//
// Created by zhong on 9/20/21.
//

#ifndef ARVSIM_SRC_INSTR_INSTR_HH_
#define ARVSIM_SRC_INSTR_INSTR_HH_

#include <cstdint>

/**
 * @brief Instruction model, which contains:
 * a) instruction execution.
 */
class Instruction {
 public:
  virtual void Execute() = 0;
 private:
  uint32_t opcode;
};

class AddInstruction : public Instruction {
 public:
  void Execute() override;
 private:
  uint32_t rs1;
  uint32_t rs2;
  uint32_t rd;
};

#endif //ARVSIM_SRC_INSTR_INSTR_HH_
